//
//  MovieDetailsViewController.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 4/18/16.
//  Copyright (c) 2016 Julio Franco. All rights reserved.
//

import UIKit
import MediaPlayer

class MovieDetailsViewController: UIViewController {
    
    var testValue: Int!
    var moviePlayer : MPMoviePlayerController!

    @IBOutlet weak var testLabel: UILabel!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if testValue != nil {
            testLabel.text = "The title of the movie goes here: \(testValue)"
        }

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func backButtonPressed(sender: AnyObject) {
        self.dismissViewControllerAnimated(true, completion: nil)
    }

    @IBAction func playButtonPressed(sender: AnyObject) {
        
//        var url:NSURL = NSURL(string: "http://jplayer.org/video/m4v/Big_Buck_Bunny_Trailer.m4v")
        
//        moviePlayer = MPMoviePlayerController(contentURL: url)
        
        
//        let path = NSBundle.mainBundle().pathForResource("Video", ofType:"mp4")
//        let url = NSURL.fileURLWithPath(path!)
        
        
        let url : NSURL = NSURL(string: "http://jplayer.org/video/m4v/Big_Buck_Bunny_Trailer.m4v")!
//        let url : NSURL = NSURL(string: "https://www.dropbox.com/s/q2nsrel0v1u5d0l/Discretion.mp4")!
        
        
//        var url : NSURL = NSURL(string: "https://www.dropbox.com/s/suys73jwue5883v/Brown%20Noise.mp4")!
        moviePlayer = MPMoviePlayerController(contentURL: url)
        if let player = self.moviePlayer {
            player.view.frame = CGRect(x: 0, y: 0, width: self.view.frame.size.width, height: self.view.frame.size.height)
            player.view.sizeToFit()
            player.scalingMode = MPMovieScalingMode.Fill
            player.fullscreen = true
            player.controlStyle = MPMovieControlStyle.Embedded
            player.movieSourceType = MPMovieSourceType.File
            player.repeatMode = MPMovieRepeatMode.One
            player.play()
            self.view.addSubview(player.view)
        }
        
        
        
    }
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
