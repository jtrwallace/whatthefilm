//
//  SearchViewController.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/30/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import UIKit

class SearchViewController: UIViewController {

    @IBOutlet weak var searchBar: UISearchBar!
    var searchCancelButton: UIButton!
    var searchTextField: UITextField!
    
    @IBOutlet weak var collectionView: UICollectionView!
    @IBOutlet weak var flowLayout: UICollectionViewFlowLayout!
    
    var isIphone4s = false
    
    var movies = [Movie]()
    var selectedMovie: Movie!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        setSearchBarUI()
        
        if view.bounds.size.height == 480 {
            isIphone4s = true
        }
        
    }
    
    override func viewDidAppear(animated: Bool) {
        searchBar.becomeFirstResponder()
    }
    
    override func viewWillDisappear(animated: Bool) {
        searchBar.resignFirstResponder()
    }
    
    func setSearchBarUI() {
        searchBar.keyboardAppearance = UIKeyboardAppearance.Dark
        searchBar.setShowsCancelButton(true, animated: false)
        searchBar.placeholder = "Search"
        searchBar.barTintColor = StyleConstants.black25
        // To get rid 1px black line under searchBar
        searchBar.backgroundImage = UIImage()
//        OR
//        searchBar.layer.borderWidth = 1
//        searchBar.layer.borderColor = StyleConstants.black25.CGColor
        
        searchCancelButton = searchBar.valueForKey("cancelButton") as! UIButton
        searchCancelButton.tintColor = UIColor.whiteColor()
        searchCancelButton.titleLabel?.font = UIFont.systemFontOfSize(14)
        searchCancelButton.enabled = true
        
        searchTextField = searchBar.valueForKey("searchField") as! UITextField
        searchTextField.backgroundColor = StyleConstants.black50
        searchTextField.textColor = UIColor.whiteColor()
    }
    
    
    // MARK: - Navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "MovieDetails" {
            let destination = segue.destinationViewController as! MovieDetailsViewController
            destination.movie = selectedMovie
        }
        // Dismising keyboard here otherwise keyboard bugs out when coming back
        searchBar.resignFirstResponder()
    }
}


extension SearchViewController: UISearchBarDelegate {

    func searchBarCancelButtonClicked(searchBar: UISearchBar) {
        dismissViewControllerAnimated(false, completion: nil)
    }
    
    func searchBar(searchBar: UISearchBar, textDidChange searchText: String) {
        // searchText<3 -> string too short, ignore
        if (searchText == "") || ((searchText.characters.count) < 3) {
            // Need to set results back to empty
            movies = []
            collectionView.reloadData()
            
        // searchText>=3 -> query db, show results
        } else {
            API_Helper.searchWithString(searchText, completionBlock: { (movies) in
                self.movies = movies
                self.collectionView.reloadData()
            })
        }
    }
}


extension SearchViewController: UICollectionViewDataSource {
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return movies.count
    }
    
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCellWithReuseIdentifier("searchResultCell", forIndexPath: indexPath) as! SearchResultCollectionViewCell
        
        // Movie cover download
        cell.movieCover.image = nil
        let url = NSURL(string: movies[indexPath.row].posterLink)
        cell.movieCover.sd_setImageWithURL(url, placeholderImage: nil, options: SDWebImageOptions.RetryFailed) { (image, error, type, nsurl) in
            // hide activity indicator maybe??
        }
        return cell
    }
}


extension SearchViewController: UICollectionViewDelegate {
    func scrollViewWillBeginDragging(scrollView: UIScrollView) {
        searchBar.resignFirstResponder()
        searchCancelButton.enabled = true
    }
    
    func collectionView(collectionView: UICollectionView, didSelectItemAtIndexPath indexPath: NSIndexPath) {
        selectedMovie = movies[indexPath.row]
        performSegueWithIdentifier("MovieDetails", sender: self)
    }

}


extension SearchViewController: UICollectionViewDelegateFlowLayout {
    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: NSIndexPath) -> CGSize {
        
        if isIphone4s {
            return CGSize(width: 96, height: 142) // static size for iphone4s/5s
        } else {
            let itemsPerRow:CGFloat = 3
            let hardCodedPadding:CGFloat = 10
            let itemWidth = (collectionView.bounds.width / itemsPerRow) - hardCodedPadding
            let itemHeight = (collectionView.bounds.height * 0.28)
            // 0.28 was determined doing 142/503 (503 is height of collectionView in iphone5s)
            return CGSize(width: itemWidth, height: itemHeight)
        }
    }
}


