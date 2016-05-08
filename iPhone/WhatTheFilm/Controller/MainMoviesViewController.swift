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
    
    @IBOutlet weak var navBar: UINavigationBar!
    @IBOutlet weak var navItem: UINavigationItem!
    
    @IBOutlet weak var testview: UIView!
    
    var categories = ["Action", "Drama", "Science Fiction", "Kids", "Horror"]

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let logoContainer = UIView(frame: CGRect(x: 0, y: 0, width: 50, height: 30))
        let test = UIImageView(image: UIImage(named: "horiz.png"))
        test.frame = CGRectMake(0, 0, logoContainer.frame.width, logoContainer.frame.height)
//        test.image = UIImage(named: "horiz.png")
        
//        let another = UIImage(named: "horiz.png")
        
        
        var titleView = UIView(frame: CGRectMake(0, 0, view.bounds.width/2, 30))
        var titleImageView = UIImageView(image: UIImage(named: "horiz.png"))
        titleImageView.frame = CGRectMake(0, 0, titleView.frame.width, titleView.frame.height)
        titleView.addSubview(titleImageView)
        
        
        test.backgroundColor = UIColor.redColor()
        test.clipsToBounds = true
        test.contentMode = UIViewContentMode.ScaleAspectFit
//        test.sizeToFit()
        
        logoContainer.addSubview(test)
        
        
//        navItem.titleView = logoContainer
        
//        navBar.setBackgroundImage(UIImage(), forBarMetrics: .Default)
//        navBar.shadowImage = UIImage()
//        navBar.backgroundColor = UIColor.clearColor()
//        navBar.tintColor = UIColor(red: 0.0, green: 0.0, blue: 0.0, alpha: 0.0)
//        navBar.translucent = true
        
//        navBar.setBackgroundImage(UIImage(), forBarMetrics: .Default)
        navBar.shadowImage = UIImage()
        navBar.tintColor = StyleConstants.black25
        navBar.translucent = true
        navBar.backgroundColor = .clearColor()
        
        let lightBlur = UIBlurEffect(style: .Light)
        let lightBlurView = UIVisualEffectView(effect: lightBlur)
        lightBlurView.frame = navBar.bounds
//        navBar.addSubview(lightBlurView)
        
        let lightVibrancyView = vibrancyEffectView(forBlurEffectView: lightBlurView)
        lightBlurView.contentView.addSubview(lightVibrancyView)
        
//        view.bringSubviewToFront(navBar)
        
        
//        let squiggle = UILabel()
//        let attributedString = NSMutableAttributedString(string: "Squiggle")
//        let textRange = NSRange(location: 0, length: 8) // Length of word Squiggle
//        attributedString.addAttributes([NSFontAttributeName: UIFont.systemFontOfSize(25), NSForegroundColorAttributeName: UIColor.whiteColor()], range: textRange)
//        attributedString.addAttribute(NSKernAttributeName, value: CGFloat(1.7), range: textRange) // Spacing between letters
//        squiggle.attributedText = attributedString
//        squiggle.sizeToFit()
//        navItem.titleView = squiggle
    }
    
    private func vibrancyEffectView(forBlurEffectView blurEffectView:UIVisualEffectView) -> UIVisualEffectView {
        let vibrancy = UIVibrancyEffect(forBlurEffect: blurEffectView.effect as! UIBlurEffect)
        let vibrancyView = UIVisualEffectView(effect: vibrancy)
        vibrancyView.frame = blurEffectView.bounds
        vibrancyView.autoresizingMask = [.FlexibleWidth, .FlexibleHeight]
        return vibrancyView
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
                print("clicked on categoryRow \(indexPath!.section)")
//                if let indexPath = self.tableView.indexPathForSelectedRow() {
//                    println("clicked on categoryRow \(indexPath.row)")
//                    println("clicked on categoryRow \(indexPath.section)")
//                }
                
                
            }
        }
    }


}




extension MainMoviesViewController: UITableViewDataSource {
    
//    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
//        return categories.count
//    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return categories.count
    }
    
//    func tableView(tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
//        return categories[section]
//    }
    
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("genreCell") as! CategoryRowTableViewCell
        cell.currentVC = self
        return cell
    }
}

extension MainMoviesViewController: UITableViewDelegate {
    
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

