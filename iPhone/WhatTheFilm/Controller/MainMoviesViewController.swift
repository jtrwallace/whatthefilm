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
    var categories: [String] = []
    
    var movies: [String : [Movie]] = [:]
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.registerNib(UINib(nibName: "MoviePreviewCell", bundle: nil), forCellReuseIdentifier: "moviePreviewCell")
        
        API_Helper.fetchCategories { (response, categories) in
            if response == 1 {
                self.categories = categories
                
                // Fetch movies from the first 5 categories (+2 indeces with 'empty', thus i=7)
                // The rest will be fetched when actually scrolling through tableview
                for (i, cat) in categories.enumerate() {
                    if (cat != "empty") && (i < 7) {
                        API_Helper.fetchMovies(fromCategory: cat, completionBlock: { (movies) in
                            self.movies[cat] = movies[cat]
                            self.tableView.reloadData()
                        })
                    }
                }
            } else {
                self.showAlert(withTitle: "Error", andMsg: categories[0])
            }
            
            
        }
        
    }

    override func viewDidAppear(animated: Bool) {
        print(tableViewHeader.frame.size.height)
        print(tableViewHeader.frame.size.width)
    }
    
    
    
    
    @IBAction func headerButton(sender: AnyObject) {
        print("categories: \(categories)")
        print("movie dict count: \(movies.count)")
        
        for (key, value) in movies {
            print("the key is: \(key)")
            for val in value {
                val.output()
            }
        }
        
        
        
    }
    
    func showAlert(withTitle title: String, andMsg msg: String) {
        let alertController = UIAlertController(title: title, message: msg, preferredStyle: UIAlertControllerStyle.Alert)
        let okAction = UIAlertAction(title: "Ok", style: UIAlertActionStyle.Default, handler: nil)
        alertController.addAction(okAction)
        presentViewController(alertController, animated: true, completion: nil)
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
        if indexPath.row == 0 {
            return UITableViewCell()
        } else {
            if indexPath.row % 3 == 0 {
                let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
                return cell
            } else {
                let cell = tableView.dequeueReusableCellWithIdentifier("categoryCell") as! CategoryRowTableViewCell
                cell.currentVC = self
                cell.categoryTitle.text = categories[indexPath.row]
                
                if let movies = movies[categories[indexPath.row]] {
                    print("the row is : \(indexPath.row) and the cat is \(categories[indexPath.row])")
                    cell.movies = movies
                    cell.collectionView.reloadData()
                }
//                cell.movies = movies[categories[indexPath.row]]!
                return cell
            }
        }
    }
    
}


extension MainMoviesViewController: UITableViewDelegate {
    
//    func tableView(tableView: UITableView, willDisplayCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
//        if indexPath.section == 1 {
//            let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
//            if cell.player!.rate == 0.0 {
//                // Not playing forward, so play.
////                if currentTime == duration {
////                    // At end, so got back to begining.
////                    currentTime = 0.0
////                }
//                
//                cell.player!.play()
//            }
////            else {
////                // Playing, so pause.
////                cell.player!.pause()
////            }
//        }
//    }
    
    func tableView(tableView: UITableView, didEndDisplayingCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
        
        if indexPath.row % 3 == 0 {
            let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
            if cell.player!.rate == 1.0 {
                cell.player!.pause()
                cell.movieStill.hidden = false
            }
        }
        
        
        
//        if indexPath.section == 1 {
//            let cell = tableView.dequeueReusableCellWithIdentifier("moviePreviewCell") as! MoviePreviewTableViewCell
//            //            cell.player.
//            
//            if cell.player!.rate == 1.0 {
//                // Not playing forward, so play.
//                //                if currentTime == duration {
//                //                    // At end, so got back to begining.
//                //                    currentTime = 0.0
//                //                }
//                
//                cell.player!.pause()
//            }
////            else {
////                // Playing, so pause.
////                cell.player!.pause()
////            }
//        }
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

