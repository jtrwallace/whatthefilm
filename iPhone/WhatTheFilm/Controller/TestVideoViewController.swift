//
//  TestVideoViewController.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/8/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import UIKit

import AVFoundation



class TestVideoViewController: UIViewController {
    
    var playerItem:AVPlayerItem?
    var player:AVPlayer?
    
    var playButton: UIButton!
    

    override func viewDidLoad() {
        super.viewDidLoad()
        
//        let url = NSURL(string: "http://jplayer.org/video/m4v/Big_Buck_Bunny_Trailer.m4v")!
        let url = NSURL(string: "https://www.dropbox.com/s/6luttidlmdwjkfa/discretion2.mp4?dl=1")!
        
        
        playerItem = AVPlayerItem(URL: url)
        player=AVPlayer(playerItem: playerItem!)
        let playerLayer=AVPlayerLayer(player: player!)
        playerLayer.frame=CGRectMake(0, 0, view.bounds.size.width, 300)
        self.view.layer.addSublayer(playerLayer)
        player?.play()
        
        NSNotificationCenter.defaultCenter().addObserver(self,
            selector: #selector(TestVideoViewController.playerItemDidReachEnd),
            name: AVPlayerItemDidPlayToEndTimeNotification,
            object: self.player!.currentItem)
        

        
    }
    
    func playerItemDidReachEnd() {
        self.player!.seekToTime(kCMTimeZero)
        self.player!.play()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
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
