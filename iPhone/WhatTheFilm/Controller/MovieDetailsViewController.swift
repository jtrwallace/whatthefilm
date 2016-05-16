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

class MovieDetailsViewController: UIViewController, WTF_AVPLayerVCDelegate {

//    var avPlayerVC: AVPlayerViewController!
    var avPLayerVC: WTF_AVPlayerVC!
    var avPlayer: AVPlayer!
    
    var movieURL: NSURL!
    
    var testValue: Int!
    
    var testCmTime: CMTime!

    @IBOutlet weak var testLabel: UILabel!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if testValue != nil {
            testLabel.text = "The title of the movie goes here: \(testValue)"
        }
        
        
//        movieURL = NSURL(string: "http://jplayer.org/video/m4v/Big_Buck_Bunny_Trailer.m4v")
//        movieURL = NSURL(string: "https://www.dropbox.com/s/q2nsrel0v1u5d0l/Discretion.mp4?dl=1")
        
        movieURL = NSURL(string: "https://www.dropbox.com/s/kbkqxvpw4fl67u7/Discretion.mp4?dl=1")
    
    }
    
    func currentTimeUpdate(time: CMTime) {
        testCmTime = time
    }
    
    
    override func viewDidAppear(animated: Bool) {
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
