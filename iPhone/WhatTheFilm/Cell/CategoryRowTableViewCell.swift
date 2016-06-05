//
//  CategoryRowTableViewCell.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 4/18/16.
//  Copyright (c) 2016 Julio Franco. All rights reserved.
//

import UIKit

class CategoryRowTableViewCell: UITableViewCell {
    
    @IBOutlet weak var categoryTitle: UILabel!
    @IBOutlet weak var collectionView: UICollectionView!
    
    @IBOutlet weak var genreTitle: UILabel!
    @IBOutlet weak var leftTriangle: UIView!
    @IBOutlet weak var rightTriangle: UIView!

    var movies: [Movie] = []
    var selectedMovie: Movie!
    
    weak var currentVC: UIViewController!

    override func awakeFromNib() {
        super.awakeFromNib()
        
        genreTitle.backgroundColor = StyleConstants.greenForGenres
    }
}


extension CategoryRowTableViewCell: UICollectionViewDataSource {
    
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return movies.count
    }
    
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCellWithReuseIdentifier("movieTitleCollectionViewCell", forIndexPath: indexPath) as! MovieTitlesCollectionViewCell
        
        // Movie cover download
        cell.movieCover.image = nil
        let url = NSURL(string: movies[indexPath.row].posterLink)
        cell.movieCover.sd_setImageWithURL(url, placeholderImage: nil, options: SDWebImageOptions.RetryFailed) { (image, error, type, nsurl) in
            // hide activity indicator maybe??
        }
        return cell
    }
    
}


extension CategoryRowTableViewCell: UICollectionViewDelegateFlowLayout {
    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: NSIndexPath) -> CGSize {
        let itemsPerRow:CGFloat = 2.75
        let hardCodedPadding:CGFloat = 5
        let itemWidth = (collectionView.bounds.width / itemsPerRow) - hardCodedPadding
        let itemHeight = collectionView.bounds.height - (2 * hardCodedPadding)
        return CGSize(width: itemWidth, height: itemHeight)
//        return CGSize(width: 115, height: 165)
    }
}

extension CategoryRowTableViewCell: UICollectionViewDelegate {

    func collectionView(collectionView: UICollectionView, didSelectItemAtIndexPath indexPath: NSIndexPath) {
        selectedMovie = movies[indexPath.row]
        currentVC.performSegueWithIdentifier("MovieDetails", sender: self)
    }
}


