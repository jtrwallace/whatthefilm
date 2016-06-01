//
//  Featured.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/27/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import Foundation
import SwiftyJSON

class Featured {
    var id: Int!
    var movieID: Int!
    var imageLink: String!
    var videoLink: String!
    var videoStill: String!
    
    init(json: JSON) {
        id = json["id"].int as Int? ?? -1
        movieID = json["film_id"].int as Int? ?? -1
        imageLink = json["image"].string as String? ?? ""
        videoLink = json["video"].string as String? ?? ""
        videoStill = json["videostill"].string as String? ?? ""
    }
    
}


