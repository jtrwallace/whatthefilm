//
//  Movie.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/18/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import Foundation
import SwiftyJSON


class Movie {
    var id: Int!
    var title: String!
    var description: String!
    var genre: String!
    var duration: Int!
    var category: String!
    var director: String!
    var actors: String!
    var year: Int!
    var studio: String!
    var summary: String!
    var videoLink: String!
    var posterLink: String!
    var videoStillLink: String!
    
    init(json: JSON) {
        id = json["id"].int as Int? ?? -1
        title = json["title"].string as String? ?? ""
        description = json["description"].string as String? ?? ""
        genre = json["genre"].string as String? ?? ""
        duration = json["duration"].int as Int? ?? -1
        category = json["category"].string as String? ?? ""
        director = json["director"].string as String? ?? ""
        actors = json["actors"].string as String? ?? ""
        year = json["year"].int as Int? ?? -1
        studio = json["studio"].string as String? ?? ""
        summary = json["summary"].string as String? ?? ""
        videoLink = json["video"].string as String? ?? ""
        posterLink = json["poster"].string as String? ?? ""
        videoStillLink = json["iphonestill"].string as String? ?? ""
    }
    
    func output() {
        print("[ID: \(id) - Title: \(title)")
        print("Genre: \(genre) - Category: \(category)")
        print("Video Link: \(videoLink)]")
    }
}


