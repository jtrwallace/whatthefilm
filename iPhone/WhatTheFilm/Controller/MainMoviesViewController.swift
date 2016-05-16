//
//  MainMoviesViewController
//  WhatTheFilm
//
//  Created by Julio Franco on 4/18/16.
//  Copyright (c) 2016 Julio Franco. All rights reserved.
//

import UIKit

class MainMoviesViewController: UIViewController {
    
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var tableViewHeader: UIView!
    
    var categories = ["Action", "Drama", "Science Fiction", "Kids", "Horror"]

    override func viewDidLoad() {
        super.viewDidLoad()
        

        
        tableView.registerNib(UINib(nibName: "MoviePreviewCell", bundle: nil), forCellReuseIdentifier: "MoviePreview")
            


    }
    
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewDidAppear(animated: Bool) {
//        navigationItem.ti
        
        print(tableViewHeader.frame.size.height)
        print(tableViewHeader.frame.size.width)
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
        return 3
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        var num = 0
        if section == 0 {
            num = categories.count
        } else if section == 1 {
            num = 1
        } else if section == 2 {
            num = categories.count
        }
        return num
    }
    
    func tableView(tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        
        var label = ""
        if section == 0 {
            label = "First Section"
        } else {
            label = "Second Section"
        }
        
        
        return label
    }
    
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        if indexPath.section == 0 {
            let cell = tableView.dequeueReusableCellWithIdentifier("genreCell") as! CategoryRowTableViewCell
            cell.currentVC = self
            return cell
        } else if indexPath.section == 1 {
            let cell = tableView.dequeueReusableCellWithIdentifier("MoviePreview") as! MoviePreviewTableViewCell
            return cell
        } else if indexPath.section == 2 {
            let cell = tableView.dequeueReusableCellWithIdentifier("genreCell") as! CategoryRowTableViewCell
            cell.currentVC = self
            return cell
        }
        return UITableViewCell()
        
    }
}

extension MainMoviesViewController: UITableViewDelegate {
    
//    func tableView(tableView: UITableView, willDisplayCell cell: UITableViewCell, forRowAtIndexPath indexPath: NSIndexPath) {
//        if indexPath.section == 1 {
//            let cell = tableView.dequeueReusableCellWithIdentifier("MoviewPreview") as! MoviePreviewTableViewCell
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
        if indexPath.section == 1 {
            let cell = tableView.dequeueReusableCellWithIdentifier("MoviePreview") as! MoviePreviewTableViewCell
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
    
//    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
//        if indexPath.row == 0 {
//            return 50
//        } else if indexPath.row == 1{
//            return 80
//        } else if indexPath.row == 2 {
//            return 150
//        } else {
//            return 210
//        }
//    }
    
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

