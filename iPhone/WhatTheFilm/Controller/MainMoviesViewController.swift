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
    
    // Property categories will contain an 'empty' on index0 and every other '3rd' value. ["empty",cat1,cat2,"empty",cat3,cat4,"empty",cat5...]
    // This is to show a movie preview on every 3rd row i.e. row1:categories, row2:categories, row3:moviePreview.
    var categories = [String]()
    
    var movies: [String : [Movie]] = [:]
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.registerNib(UINib(nibName: "MoviePreviewCell", bundle: nil), forCellReuseIdentifier: "moviePreviewCell")
        
        fetchCategories()
    }

    override func viewDidAppear(animated: Bool) {
        print(tableViewHeader.frame.size.height)
        print(tableViewHeader.frame.size.width)
    }
    
    
    
    func fetchCategories() {
        Alamofire.request(.GET, API_Helper.requestCategories).responseJSON { (response) in
            switch response.result {
            case .Success:
                if let value = response.result.value {
                    print("json: \(JSON(value))")
                    // Iterating through JSON obj array and mapping it to a string array
                    let catsOnServer = (JSON(value).array?.map { $0.string! })!
                    self.orderCategoriesWithEmptyValues(catsOnServer)
                    
                    //# TODO:
                    // THIS NEEDS TO BE MOVED TO AFTER FETCHING THE MOVIES FROM FIRST CATEGORY
                    self.tableView.reloadData()
                    
                    // Sorts array of categories ignoring upper/lower case
                    // self.categories.sortInPlace { $0.localizedCompare($1) == NSComparisonResult.OrderedAscending }
                    self.fetchMoviesFromCategories()
                }
            case .Failure(let error):
                print(error)
            }
        }
    }
    
    func fetchMoviesFromCategories() {
        for category in categories {
            fetchMoviesFromCategory(category)
        }
    }
    
    func fetchMoviesFromCategory(category: String) {
        let url = "\(API_Helper.requestCategories)\(category)"
        Alamofire.request(.GET, url).responseJSON { (response) in
            switch response.result {
            case .Success:
                if let value = response.result.value {
                    print("json: \(JSON(value))")
                    let moviesJSON = JSON(value).array
                    var movies = [Movie]()
                    for movie in moviesJSON! {
                        movies.append(Movie(json: movie))
                    }
                    
                    for mov in movies {
                        mov.output()
                    }
                }
            case .Failure(let error):
                print(error)
            }
        }

    }
    
    // Arranges categories string array with "empty" on '3rd' values
    // @param : array of categories as fetched from the server
    // @post : local categories with "empty" on every 3rd value
    // i.e. ["empty",cat1,cat2,"empty",cat3,cat4,"empty"...]
    func orderCategoriesWithEmptyValues(arr: [String]) {
        for (i, cat) in arr.enumerate() {
            if i % 2 == 0 {
                categories.append("empty")
                categories.append(cat)
                
            } else {
                categories.append(cat)
            }
        }
        if categories.count % 3 == 0 {
            categories.append("empty")
        }
    }
    
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        
        if segue.identifier == "MovieDetails" {
            if let cell = sender as? CategoryRowTableViewCell {
                
                let destination = segue.destinationViewController as! MovieDetailsViewController
                destination.testValue = cell.selectedMovie
                
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
        // I am ignoring the first row, index = 0
        if indexPath.row == 0 {
            return UITableViewCell()
        } else {
            if indexPath.row % 3 == 0 {
                let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
                return cell
            } else {
                let cell = tableView.dequeueReusableCellWithIdentifier("categoryCell") as! CategoryRowTableViewCell
                cell
                cell.currentVC = self
                return cell
            }
        }
    }
    
    
}

extension MainMoviesViewController: UITableViewDelegate {
    
    func tableView(tableView: UITableView, willDisplayCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
        if indexPath.section == 1 {
            let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
            if cell.player!.rate == 0.0 {
                // Not playing forward, so play.
//                if currentTime == duration {
//                    // At end, so got back to begining.
//                    currentTime = 0.0
//                }
                
                cell.player!.play()
            }
//            else {
//                // Playing, so pause.
//                cell.player!.pause()
//            }
        }
    }
    
    func tableView(tableView: UITableView, didEndDisplayingCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
        if indexPath.section == 1 {
            let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
            //            cell.player.
            
            if cell.player!.rate == 1.0 {
                // Not playing forward, so play.
                //                if currentTime == duration {
                //                    // At end, so got back to begining.
                //                    currentTime = 0.0
                //                }
                
                cell.player!.pause()
            }
//            else {
//                // Playing, so pause.
//                cell.player!.pause()
//            }
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
    
//    func tableView(tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
//        return 35
//    }
    
//    func tableView(tableView: UITableView, willDisplayHeaderView view: UIView, forSection section: Int) {
//        
//        
//        
//        let sectionHeader: UITableViewHeaderFooterView = view as! UITableViewHeaderFooterView
//        sectionHeader.contentView.backgroundColor = StyleConstants.black25
//        sectionHeader.textLabel?.textColor = UIColor.whiteColor()
//        
//        
//    }
    
//    func tableView(tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
//        return 20
//    }
    
}

