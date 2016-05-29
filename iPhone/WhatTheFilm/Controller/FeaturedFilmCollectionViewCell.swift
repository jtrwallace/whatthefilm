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
    
    weak var currentVC: UIViewController!
    
}


