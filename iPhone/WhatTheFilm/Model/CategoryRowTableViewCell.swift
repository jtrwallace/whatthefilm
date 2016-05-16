//
//  CategoryRowTableViewCell.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 4/18/16.
//  Copyright (c) 2016 Julio Franco. All rights reserved.
//

import UIKit

class CategoryRowTableViewCell: UITableViewCell {
    
    var selectedMovie: Int!
    
    @IBOutlet weak var collectionView: UICollectionView!
    
    
    
    weak var currentVC: UIViewController!

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}


extension CategoryRowTableViewCell: UICollectionViewDataSource {
    
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 12
    }
    
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCellWithReuseIdentifier("movieTitleCollectionView", forIndexPath: indexPath) as! MovieTitlesCollectionViewCell
        cell.testLabel.text = "\(indexPath.row)"
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
//        return CGSize(width: 90, height: 100)
    }
}

extension CategoryRowTableViewCell: UICollectionViewDelegate {

    
    func collectionView(collectionView: UICollectionView, didSelectItemAtIndexPath indexPath: NSIndexPath) {
        selectedMovie = indexPath.row
        currentVC.performSegueWithIdentifier("MovieDetails", sender: self)
    }
}


