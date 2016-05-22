//
//  API_Helper.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/18/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import Foundation
import Alamofire
import SwiftyJSON

class API_Helper {
    
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
    
    
    // Queries DB to get the array of categories
    // A new array is returned in callback which contains 'empty' on every
    // 3rd value.
    class func fetchCategories(completionBlock: ([String])->Void) {
        Alamofire.request(.GET, API_Helper.requestCategories).responseJSON { (response) in
            switch response.result {
            case .Success:
                if let value = response.result.value {
                    // print("json: \(JSON(value))")
                    // Iterating through JSON obj array and mapping it to a string array
                    let catsOnServer = (JSON(value).array?.map { $0.string! })!
                    
                    // Sorts array of categories ignoring upper/lower case
                    // self.categories.sortInPlace { $0.localizedCompare($1) == NSComparisonResult.OrderedAscending }
                    
                    completionBlock(self.categoriesWithEmptyValues(fromArr: catsOnServer))
                }
            case .Failure(let error):
                print(error)
                //send notification to be caught by moviesVC to display alert error
                // since i dont want to pass VC to show alert from this helper class
            }
        }
    }

    
    // Queries DB for the movies in a certain category
    // Returns in the callback a dict with the key as category and
    // the value as an array of Movie objs
    class func fetchMovies(fromCategory category: String, completionBlock: ([String: [Movie]])->Void) {
        let url = "\(requestCategories)\(category)"
        Alamofire.request(.GET, url).responseJSON { (response) in
            switch response.result {
            case .Success:
                if let value = response.result.value {
                    print("json: \(JSON(value))")
                    let moviesJSON = JSON(value).array
                    var moviesArr = [Movie]()
                    for movie in moviesJSON! {
                        moviesArr.append(Movie(json: movie))
                    }
                    
                    var movies = [String: [Movie]]()
                    movies[category] = moviesArr
                    completionBlock(movies)
                }
            case .Failure(let error):
                print(error)
            }
        }
    }
    
    
    // Returns categories string array with "empty" on '3rd' values 
    // (to show movie preview on every 3rd row)
    // i.e. ["empty",cat1,cat2,"empty",cat3,cat4,"empty"...]
    // @param : array of categories as fetched from the server
    class func categoriesWithEmptyValues(fromArr arr: [String]) -> [String] {
        var categories = [String]()
        for (i, cat) in arr.enumerate() {
            if i % 2 == 0 {
                categories.append("empty")
                categories.append(cat)
                
            } else {
                categories.append(cat)
            }
        }
        // Base case for when fetched arr has 2 elements
        // for-loop above adds the first empty, and this next condition adds the 3rd
        // thus [cat1, cat2] becomes [empty,cat1,cat2,empty]
        if categories.count % 3 == 0 {
            categories.append("empty")
        }
        return categories
    }
    
}


