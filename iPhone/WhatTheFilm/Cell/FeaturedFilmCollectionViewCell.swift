//
//  FeaturedFilmCollectionViewCell.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/26/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import UIKit

class FeaturedFilmCollectionViewCell: UICollectionViewCell {
    
    @IBOutlet weak var filmImage: UIImageView!
    var movie: Movie!
    var feature: Featured!
    
    
    
    @IBOutlet weak var infoContainer: UIView!
    @IBOutlet weak var title: UILabel!
    @IBOutlet weak var year: UILabel!
    @IBOutlet weak var director: UILabel!
    
    weak var currentVC: UIViewController!
    
}


