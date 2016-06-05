//
//  MainMoviesViewController
//  WhatTheFilm
//
//  Created by Julio Franco on 4/18/16.
//  Copyright (c) 2016 Julio Franco. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON

class MainMoviesViewController: UIViewController {
    
    @IBOutlet weak var blurredViewLoading: UIView!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var tableViewHeader: UIView!
    
    @IBOutlet weak var featuredCollectionView: UICollectionView!
    var featuredTimer: NSTimer!
    @IBOutlet weak var pageControl: UIPageControl!
    
    var moviePreviewPaused = false
    
    // Property categories will contain an 'empty' and every other 'rth' value.
    // This is to show a movie preview, i.e. [cat1,cat2,cat3,"empty",cat4,cat5,cat6,"empty"...]
    // This is to show a  on every 3rd row i.e. row1:categories, row2:categories, row3:moviePreview.
    var categories: [String] = []
    // Keeps the CGPoint-X positions of the categories cell
    var categoriesScrolledPositions: [CGFloat]!
    
    var features: [(feature: Featured, movie: Movie)] = []
    var selectedFeature: Movie!
    
    var movies: [String : [Movie]] = [:]
    var isIphone4s = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.registerNib(UINib(nibName: "MoviePreviewCell", bundle: nil), forCellReuseIdentifier: "moviePreviewCell")
        
        fetchEverything()
        
        if view.bounds.size.height == 480 {
            isIphone4s = true
        }
        
        if isIphone4s {
            tableViewHeader.frame.size.height = 235
        } else {
            tableViewHeader.frame.size.height = (view.bounds.size.height * 0.42)
        }
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: #selector(scrollingCategoryCell), name: "ScrollingCategoryCell", object: nil)
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: #selector(sendingAppToBackground), name: UIApplicationWillResignActiveNotification, object: nil)
        NSNotificationCenter.defaultCenter().addObserver(self, selector: #selector(appEnteringForeground), name: UIApplicationDidBecomeActiveNotification, object: nil)
    }
    
    override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return UIInterfaceOrientationMask.Portrait
    }

    override func viewDidAppear(animated: Bool) {
        resumeMoviePreview()
    }
    
    override func viewWillAppear(animated: Bool) {
        fireFeaturedFilmsTimer()
    }
    
    override func viewWillDisappear(animated: Bool) {
        invalidateFeaturedFilmsTimer()
        pauseMoviePreview()
    }
    
    func fetchEverything() {
        API_Helper.fetchGenres { (response, categories) in
            if response == 1 {
                self.categories = categories
                self.categoriesScrolledPositions = [CGFloat](count: self.categories.count, repeatedValue: 0.0)
//                print(categories)
//                print(self.categoriesScrolledPositions)
                
                API_Helper.fetchFeatured { (response) in
                    self.features = response
                    self.fireFeaturedFilmsTimer()
                    self.addMoreFeaturesIfNeeded()
                    self.featuredCollectionView.reloadData()
                }
                
                // For all the genres available, download the movies that
                // belong to it and create a dictioary entry with them
                for (i, cat) in categories.enumerate() {
                    if (cat != "empty_ShowMoviePreview") {
                        API_Helper.fetchMovies(fromCategory: cat, completionBlock: { (movies) in
                            self.movies[cat] = movies[cat]
                            
                            // If we finish fetching films for all Genres, then enable screen
                            if i+1 == categories.count {
                                self.tableView.reloadData()
                                self.blurredViewLoading.hidden = true
                                self.activityIndicator.hidden = true
                            }
                        })
                    }
                }
            } else {
                self.showAlert(withTitle: "Error", andMsg: categories[0])
            }
        }
    }
    
    
    func sendingAppToBackground() {
        invalidateFeaturedFilmsTimer()
        pauseMoviePreview()
    }
    
    func appEnteringForeground() {
        fireFeaturedFilmsTimer()
        resumeMoviePreview()
    }
    
    func invalidateFeaturedFilmsTimer() {
        if featuredTimer != nil {
            featuredTimer.invalidate()
            featuredTimer = nil
        }
    }
    
    func fireFeaturedFilmsTimer() {
        if !features.isEmpty {
            if featuredTimer == nil {
                featuredTimer = NSTimer.scheduledTimerWithTimeInterval(6.5, target: self, selector: #selector(autoFeaturedFilmsScrolling), userInfo: nil, repeats: false)
            }
        }
    }

    func autoFeaturedFilmsScrolling() {
        // Grab visible featured film
        let visibleItemsIndexPath = featuredCollectionView.indexPathsForVisibleItems()
        let currentItem = visibleItemsIndexPath[0]
        var nextItem = Int()
        // If displaying last featured film, then go to beginning, otherwise go to next one
        if currentItem.item+1 == featuredCollectionView.numberOfItemsInSection(0) {
            nextItem = 0
        } else {
            nextItem = currentItem.item + 1
        }
        let nextFeatureIndex = NSIndexPath(forItem: nextItem, inSection: 0)
        featuredCollectionView.scrollToItemAtIndexPath(nextFeatureIndex, atScrollPosition: UICollectionViewScrollPosition.CenteredHorizontally, animated: true)
        featuredTimer = NSTimer.scheduledTimerWithTimeInterval(6.5, target: self, selector: #selector(autoFeaturedFilmsScrolling), userInfo: nil, repeats: false)
    }
    
    // The featuredFilms header on top is locked to count of 3
    // But the moviePreviews also depends on the features array, so we 
    // might repeat more features if necessary
    func addMoreFeaturesIfNeeded() {
        // There is one featuredFilm every 3 categories, therefore divide by 4
        let featCountInCategories = Int(floor(Double(categories.count/4)))
        
        // If there are less featuredFilms on server, then we double and 
        // repeat the featuredFilms so there is no problem scrolling and 
        // showing the moviePreviews
        if features.count < featCountInCategories {
            features += features
        }
    }
    
    func pauseMoviePreview() {
        // Pause movie preview if necessary
        let visibleCells = tableView.visibleCells
        for cell in visibleCells {
            if let previewCell = cell as? MoviePreviewTableViewCell {
                if previewCell.player!.rate == 1.0 {
                    previewCell.player!.pause()
                    moviePreviewPaused = true
                }
            }
        }
    }
    
    func resumeMoviePreview() {
        // Resume movie preview if necessary
        if moviePreviewPaused {
            let visibleCells = tableView.visibleCells
            for cell in visibleCells {
                if let previewCell = cell as? MoviePreviewTableViewCell {
                    if previewCell.player!.rate == 0.0 {
                        previewCell.player!.play()
                        moviePreviewPaused = false
                    }
                }
            }
        }
    }
    
    // Keeping track of the last position scrolled on the category cell
    func scrollingCategoryCell(notification: NSNotification) {
        let row = notification.userInfo!["row"] as! Int
        let pointX = notification.userInfo!["pointX"] as! CGFloat
        categoriesScrolledPositions[row] = pointX
    }
    
    func showAlert(withTitle title: String, andMsg msg: String) {
        let alertController = UIAlertController(title: title, message: msg, preferredStyle: UIAlertControllerStyle.Alert)
        let okAction = UIAlertAction(title: "Ok", style: UIAlertActionStyle.Default) { action in
            NSTimer.scheduledTimerWithTimeInterval(5, target: self, selector: #selector(self.fetchEverything), userInfo: nil, repeats: false)
        }
        let retryAction = UIAlertAction(title: "Retry", style: UIAlertActionStyle.Default) { (action) in
            self.fetchEverything()
        }
        alertController.addAction(okAction)
        alertController.addAction(retryAction)
        presentViewController(alertController, animated: true, completion: nil)
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "MovieDetails" {
            if let cell = sender as? CategoryRowTableViewCell {
                let destination = segue.destinationViewController as! MovieDetailsViewController
                destination.movie = cell.selectedMovie
            }
            
            if sender is FeaturedFilmCollectionViewCell {
                let destination = segue.destinationViewController as! MovieDetailsViewController
                destination.movie = selectedFeature
            }
            
            if let cell = sender as? MoviePreviewTableViewCell {
                let destination = segue.destinationViewController as! MovieDetailsViewController
                destination.movie = cell.movie
            }
        }
    }
    
}


extension MainMoviesViewController: UITableViewDataSource {
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return categories.count
    }

    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        if categories[indexPath.row] == "empty_ShowMoviePreview" {
            let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
            cell.currentVC = self
            let featIndex = Int(floor(Double(indexPath.row/4)))
            cell.movie = features[featIndex].movie
            cell.feature = features[featIndex].feature
            cell.activityIndicator.startAnimating()
            cell.playPreview()
            
            // Movie Preview image still download
            cell.movieStill.image = nil
            cell.movieStill.hidden = false
            let url = NSURL(string: cell.feature.videoStill)
            cell.movieStill.sd_setImageWithURL(url)
            
            return cell
        } else {
            let cell = tableView.dequeueReusableCellWithIdentifier("categoryCell") as! CategoryRowTableViewCell
            cell.currentVC = self
            cell.currentRow = indexPath.row
            cell.categoryTitle.text = "        \(categories[indexPath.row])"
            
            // Green triangle on genre header
            cell.leftTriangle.hidden = false
            cell.rightTriangle.hidden = false
            if indexPath.row % 2 == 0 {
                cell.leftTriangle.hidden = true
            } else {
                cell.rightTriangle.hidden = true
            }
            
            // Loading movies
            if let movies = movies[categories[indexPath.row]] {
                cell.movies = movies
            } else {
                cell.movies = []
            }
            cell.collectionView.reloadData()
            let pointXY = CGPoint(x: categoriesScrolledPositions[indexPath.row], y: 0.0)
            cell.collectionView.setContentOffset(pointXY, animated: false)
            return cell
        }
    }
    
}


extension MainMoviesViewController: UITableViewDelegate {
    
    func tableView(tableView: UITableView, didEndDisplayingCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
        if let preview = cell as? MoviePreviewTableViewCell {
            if let player = preview.player {
                if player.rate == 1.0 {
                    player.pause()
                    preview.movieStill.hidden = false
                }
            }
        }
    }
    
//    func tableView(tableView: UITableView, willDisplayCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
//        if indexPath.row == 0{
//            print("cell size: \(cell.frame.size.height)")
//        } else if indexPath.row == 3 {
//            print("cell size: \(cell.frame.size.height)")
//        }
//    }
    
    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        if categories[indexPath.row] == "empty_ShowMoviePreview" {
            if isIphone4s {
                return 245
            } else {
                return (view.bounds.size.height * 0.44)
            }
            
        } else {
            if isIphone4s {
                return 195
            } else {
                return (view.bounds.size.height * 0.35)
            }
        }
    }
}

extension MainMoviesViewController: UIScrollViewDelegate {
    func scrollViewDidScroll(scrollView: UIScrollView) {
//        print(scrollView.contentOffset)
//        let row = scrollView as! UITableView
//        let indexpath = row.indexPathForRowAtPoint(scrollView.contentOffset)
//        print(indexpath?.row)
    }
}


// MARK: Featured Films

extension MainMoviesViewController: UICollectionViewDataSource {
    
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        // Only show first 3 featured films or none, DB should always have at least 3
        return (features.count >= 3) ? 3 : 0
    }
    
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCellWithReuseIdentifier("featuredCell", forIndexPath: indexPath) as! FeaturedFilmCollectionViewCell
        cell.movie = features[indexPath.row].movie
        cell.feature = features[indexPath.row].feature
        cell.title.text = cell.movie.title
        cell.year.text = cell.movie.year.description
        cell.director.text = cell.movie.director
        
        // Feature image download
        cell.filmImage.image = nil
        let url = NSURL(string: cell.movie.videoStillLink)
        cell.filmImage.sd_setImageWithURL(url, placeholderImage: nil, options: SDWebImageOptions.RetryFailed) { (image, error, type, nsurl) in
            // hide activity indicator maybe??
        }
        return cell
    }
}


extension MainMoviesViewController: UICollectionViewDelegate {
    
    func collectionView(collectionView: UICollectionView, didEndDisplayingCell cell: UICollectionViewCell, forItemAtIndexPath indexPath: NSIndexPath) {
        // Used to highlight the proper item on the UIPageControl
        let visible = collectionView.indexPathsForVisibleItems()
        for index in visible {
            pageControl.currentPage = index.row
        }
    }
    
    func collectionView(collectionView: UICollectionView, didSelectItemAtIndexPath indexPath: NSIndexPath) {
        let cell = collectionView.cellForItemAtIndexPath(indexPath) as! FeaturedFilmCollectionViewCell
        selectedFeature = cell.movie
        performSegueWithIdentifier("MovieDetails", sender: cell)
    }
}


extension MainMoviesViewController: UICollectionViewDelegateFlowLayout {
    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: NSIndexPath) -> CGSize {
        return CGSize(width: collectionView.bounds.width, height: collectionView.bounds.height)
    }
}


