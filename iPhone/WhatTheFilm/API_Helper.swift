//
//  API_Helper.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/18/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import Foundation

struct API_Helper {
    
    // Returns list of all films
    static let requestFilms = "http://whatthefilm.us-west-1.elasticbeanstalk.com/api/films/"
    // Returns list of all categories
    static let requestCategories = "http://whatthefilm.us-west-1.elasticbeanstalk.com/api/categories/"
    // Returns list of all genres
    static let requestGenres = "http://whatthefilm.us-west-1.elasticbeanstalk.com/api/genres/"
    
    
    // Returns list of all movies under the category
    // "http://whatthefilm.us-west-1.elasticbeanstalk.com/api/categories/[category]"
    // So /api/categories/lgbt returns the Discretion JSON object among others
    
    // Returns list of all movies under the genre
    // "http://whatthefilm.us-west-1.elasticbeanstalk.com/api/genres/[genre]"
    // So /api/genres/drama returns the Discretion JSON object among others
    
}


