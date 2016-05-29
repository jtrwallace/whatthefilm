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
    
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var tableViewHeader: UIView!
    
    @IBOutlet weak var featuredCollectionView: UICollectionView!
    
    @IBOutlet weak var pageControl: UIPageControl!
    
    
    var moviePreviewPaused = false
    
    
    
    // Property categories will contain an 'empty' on index0 and every other '3rd' value. ["empty",cat1,cat2,"empty",cat3,cat4,"empty",cat5...]
    // This is to show a movie preview on every 3rd row i.e. row1:categories, row2:categories, row3:moviePreview.
    var categories: [String] = []
    
    var movies: [String : [Movie]] = [:]
    
    var features: [(feature: Featured, movie: Movie)] = []
    var selectedFeature: Movie!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.registerNib(UINib(nibName: "MoviePreviewCell", bundle: nil), forCellReuseIdentifier: "moviePreviewCell")
        
        API_Helper.fetchFeatured { (response) in
            self.features = response
            self.featuredCollectionView.reloadData()
        }
        
        API_Helper.fetchCategories { (response, categories) in
            if response == 1 {
                self.categories = categories
                print(categories)
                
                // Fetch movies from the first 5 categories (+2 indeces with 'empty', thus i=7)
                // The rest will be fetched when actually scrolling through tableview
                // MARK: TODO - make sure categories >5 get downloaded 
                for (i, cat) in categories.enumerate() {
                    if (cat != "empty") && (i < 7) {
                        API_Helper.fetchMovies(fromCategory: cat, completionBlock: { (movies) in
                            self.movies[cat] = movies[cat]
                            self.tableView.reloadData()
                        })
                    }
                }
            } else {
                self.showAlert(withTitle: "Error", andMsg: categories[0])
            }
            
            
        }
        
    }

    override func viewDidAppear(animated: Bool) {
        print("tableview header height \(tableViewHeader.frame.size.height)")
        print("tableview header width \(tableViewHeader.frame.size.width)")
        
        print("scrollview height \(featuredCollectionView.frame.size.height)")
        print("scrollview width \(featuredCollectionView.frame.size.width)")

    }
    
    override func viewWillAppear(animated: Bool) {
        if moviePreviewPaused {
            let visibleCells = tableView.visibleCells
            for cell in visibleCells {
                if cell is MoviePreviewTableViewCell {
                    let previewCell = cell as! MoviePreviewTableViewCell
                    if previewCell.player!.rate == 0.0 {
                        previewCell.player!.play()
                        moviePreviewPaused = false
                    }
                }
            }
        }
    }
    
    override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return UIInterfaceOrientationMask.Portrait
    }
    
    @IBAction func test(sender: AnyObject) {
        print("button pressed")
    }
    
    
    @IBAction func headerButton(sender: AnyObject) {
        print("categories: \(categories)")
        print("movie dict count: \(movies.count)")
        
        for (key, value) in movies {
            print("the key is: \(key)")
            for val in value {
                val.output()
            }
        }
        
        
        
    }
    
    func showAlert(withTitle title: String, andMsg msg: String) {
        let alertController = UIAlertController(title: title, message: msg, preferredStyle: UIAlertControllerStyle.Alert)
        let okAction = UIAlertAction(title: "Ok", style: UIAlertActionStyle.Default, handler: nil)
        alertController.addAction(okAction)
        presentViewController(alertController, animated: true, completion: nil)
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "MovieDetails" {
            if let cell = sender as? CategoryRowTableViewCell {
                
                let destination = segue.destinationViewController as! MovieDetailsViewController
                destination.movie = cell.selectedMovie
                
//                if let collecCell = 
//                cell.collectionView.indexPathForCell(collecCell)

                
                let indexPath = self.tableView.indexPathForCell(cell)
                print("clicked on categoryRow \(indexPath!.row)")
                print("clicked on categorySection \(indexPath!.section)")
//                if let indexPath = self.tableView.indexPathForSelectedRow() {
//                    println("clicked on categoryRow \(indexPath.row)")
//                    println("clicked on categoryRow \(indexPath.section)")
//                }
                
                
            }
            
            if sender is FeaturedFilmCollectionViewCell {
                let destination = segue.destinationViewController as! MovieDetailsViewController
                destination.movie = selectedFeature
            }
        }
        
        // Do this no matter the segue
        // If there is a moviePreviewCell playing, it needs to be paused before segue
        let visibleCells = tableView.visibleCells
        for cell in visibleCells {
            if cell is MoviePreviewTableViewCell {
                let previewCell = cell as! MoviePreviewTableViewCell
                if previewCell.player!.rate == 1.0 {
                    previewCell.player!.pause()
                    moviePreviewPaused = true
                }
            }
        }
        
        
        
    }


}




extension MainMoviesViewController: UITableViewDataSource {
    
    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return categories.count
    }

    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        if indexPath.row == 0 {
            return UITableViewCell()
        } else {
            if indexPath.row % 3 == 0 {
                let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
                return cell
            } else {
                let cell = tableView.dequeueReusableCellWithIdentifier("categoryCell") as! CategoryRowTableViewCell
                cell.currentVC = self
                cell.categoryTitle.text = categories[indexPath.row]
                
                if let movies = movies[categories[indexPath.row]] {
                    print("the row is : \(indexPath.row) and the cat is \(categories[indexPath.row])")
                    cell.movies = movies
                    cell.collectionView.reloadData()
                }
//                cell.movies = movies[categories[indexPath.row]]!
                return cell
            }
        }
    }
    
}


extension MainMoviesViewController: UITableViewDelegate {
    
    func tableView(tableView: UITableView, didEndDisplayingCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
        
        if indexPath.row % 3 == 0 {
            let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
            if cell.player!.rate == 1.0 {
                cell.player!.pause()
                cell.movieStill.hidden = false
            }
        }
    }
    
    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        if indexPath.row == 0 {
            return 0
        } else if indexPath.row % 3 == 0{
            return 250
        } else {
            return 200
        }
    }
}


extension MainMoviesViewController: UICollectionViewDataSource {
    
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return (features.count >= 3) ? 3 : 0
    }
    
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCellWithReuseIdentifier("featuredCell", forIndexPath: indexPath) as! FeaturedFilmCollectionViewCell
        cell.movie = features[indexPath.row].movie
        cell.feature = features[indexPath.row].feature
        
        print("cell height \(cell.filmImage.frame.size.height)")
        print("cell width \(cell.filmImage.frame.size.width)")
        
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
        // Used to highlight the proper item from the UIPageControl
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
        return CGSize(width: collectionView.bounds.width, height: 181)
    }
}


