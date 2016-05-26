//
//  MoviePreviewTableViewCell.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/8/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import UIKit
import CoreMedia
import AVFoundation

class MoviePreviewTableViewCell: UITableViewCell {
    

    @IBOutlet weak var movieStill: UIImageView!
    @IBOutlet weak var playerView: PlayerView!
    
    
    
    var playerItem:AVPlayerItem?
    var player:AVPlayer?
    
    var playButton: UIButton!


    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
        
        
        let url = NSURL(string: "https://www.dropbox.com/s/ede0aqfcxisxk3b/discretion3.mp4?dl=1")!
        
        print()
        print(playerView.bounds.size.width)
        print(playerView.bounds.size.height)
        print()
        print(contentView.bounds.size.width)
        print(contentView.bounds.size.height)
        
        playerItem = AVPlayerItem(URL: url)
        player=AVPlayer(playerItem: playerItem!)
//        let playerLayer=AVPlayerLayer(player: player!)
//        playerLayer.frame = testview.bounds
//        playerLayer.frame=CGRectMake(0, 0, testview.bounds.size.width-10, testview.bounds.size.height-10)
//        testview.layer.addSublayer(playerLayer)
        
        playerView.playerLayer.player = player
        playerView.playerLayer.videoGravity = AVLayerVideoGravityResizeAspectFill
        
        //ENABLE
        player?.play()
        
        
        
        
        
        let cmTime  = CMTimeMake(1, 3) // 1/3 of a second
        let cmValue = NSValue(CMTime: cmTime)
        
        // Since a UIImage of a movie still is on top of AVPlayer I'm adding observer to find
        // out when clip started playing so I can hide image and video therefore is shown
        var timeObserver: AnyObject!
        timeObserver = player?.addBoundaryTimeObserverForTimes([cmValue], queue: nil, usingBlock: {
            self.movieStill.hidden = true
            self.player?.removeTimeObserver(timeObserver)
        })
        
        
        
        NSNotificationCenter.defaultCenter().addObserver(self,
                                                         selector: #selector(TestVideoViewController.playerItemDidReachEnd),
                                                         name: AVPlayerItemDidPlayToEndTimeNotification,
                                                         object: self.player!.currentItem)
        
        
    }
    
    func playerItemDidReachEnd() {
        self.player!.seekToTime(kCMTimeZero)
        self.player!.play()
    }
    @IBAction func movieStillButtonPressed(sender: AnyObject) {
        print("need to segue to movie details")
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
