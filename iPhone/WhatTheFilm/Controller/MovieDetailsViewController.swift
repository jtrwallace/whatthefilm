    //
//  MovieDetailsViewController.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 4/18/16.
//  Copyright (c) 2016 Julio Franco. All rights reserved.
//

import UIKit
import AVKit
import AVFoundation
import Alamofire
import SwiftyJSON
    
    

class MovieDetailsViewController: UIViewController, WTF_AVPLayerVCDelegate {

//    var avPlayerVC: AVPlayerViewController!
    var avPLayerVC: WTF_AVPlayerVC!
    var avPlayer: AVPlayer!
    
    var movieURL: NSURL!
    
    var testValue: Int!
    
    var testCmTime: CMTime!
    @IBOutlet weak var movieImage: UIImageView!

    @IBOutlet weak var testLabel: UILabel!
    var arrRes = [[String:AnyObject]]() //Array of dictionary
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if testValue != nil {
            testLabel.text = "The title of the movie goes here: \(testValue)"
        }
        
        
//        movieURL = NSURL(string: "http://jplayer.org/video/m4v/Big_Buck_Bunny_Trailer.m4v")
//        movieURL = NSURL(string: "https://www.dropbox.com/s/q2nsrel0v1u5d0l/Discretion.mp4?dl=1")
        
        movieURL = NSURL(string: "https://www.dropbox.com/s/kbkqxvpw4fl67u7/Discretion.mp4?dl=1")
        
        
//        Alamofire.request(.GET, "http://api.androidhive.info/contacts/").response { (req, res, data, error) -> Void in
//            print(res)
//            let outputString = NSString(data: data!, encoding:NSUTF8StringEncoding)
//            print(outputString)
//        }
//        
//        
//        
//        Alamofire.request(.GET, "http://api.androidhive.info/contacts/").responseJSON { (responseData) -> Void in
//            if((responseData.result.value) != nil) {
//                let swiftyJsonVar = JSON(responseData.result.value!)
//                
//                if let resData = swiftyJsonVar["contacts"].arrayObject {
//                    self.arrRes = resData as! [[String:AnyObject]]
//                    print(self.arrRes)
//                }
//                if self.arrRes.count > 0 {
////                    self.tblJSON.reloadData()
//                }
//            }
//        }
        
//        let films = "http://whatthefilm.us-west-1.elasticbeanstalk.com/api/films/"
        let categories = "http://whatthefilm.us-west-1.elasticbeanstalk.com/api/categories/"
        
        Alamofire.request(.GET, categories).responseJSON { (response) in
            switch response.result{
            case .Success:
                print("response.request: \(response.request)")  // original URL request
                print("response.response: \(response.response)") // URL response
//                print("response.data: \(response.data)")     // server data
                print("response.result: \(response.result)")   // result of response serialization
                print("response.result: \(response.result.value)")   // result of response serialization

                if let value = response.result.value {
                    let json = JSON(value)
                    print("JSON: \(json)")
                    let contactsArr = json["contacts"].array
                    let testemail = contactsArr![0]["email"].string
                    for contact in contactsArr! {
                        print(contact["email"].string)
                    }
                    
                    print("test: \(testemail)")
                }
            case .Failure(let error):
                print(error)
                
            }
        }
        
    
    }
    
    func currentTimeUpdate(time: CMTime) {
        testCmTime = time
    }
    
    
    override func viewDidAppear(animated: Bool) {
        
        
        let url = NSURL(string: "http://s.imgur.com/images/logo-1200-630.jpg")
        
        movieImage.sd_setImageWithURL(url) { (image, error, type, nsurl) in
            print("might use complete block to stop activity indicator")
        }
        
        print("movie details: \(testCmTime)")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func backButtonPressed(sender: AnyObject) {
        dismissViewControllerAnimated(true, completion: nil)
    }

    @IBAction func playButtonPressed(sender: AnyObject) {
        avPlayer = AVPlayer(URL: movieURL)
        avPLayerVC = WTF_AVPlayerVC()
        avPLayerVC.player = avPlayer
//        avPlayerVC = AVPlayerViewController()
//        avPlayerVC.player = avPlayer
    
        presentViewController(avPLayerVC, animated: true) {
            self.avPLayerVC.wtfDelegate = self
            self.avPLayerVC.player?.play()
            
            if let time = self.testCmTime {
                self.avPLayerVC.player?.seekToTime(time)
            }
            
//            self.avPLayerVC.player?.seekToTime(self.testCmTime)
        }
    }
    

}
