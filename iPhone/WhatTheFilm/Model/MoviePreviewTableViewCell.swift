//
//  MoviePreviewTableViewCell.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/8/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import UIKit
import AVFoundation

class MoviePreviewTableViewCell: UITableViewCell {
    

    @IBOutlet weak var testview: PlayerView!
    var playerItem:AVPlayerItem?
    var player:AVPlayer?
    
    var playButton: UIButton!


    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
        
        let url = NSURL(string: "https://www.dropbox.com/s/6luttidlmdwjkfa/discretion2.mp4?dl=1")!
        
        print()
        print(testview.bounds.size.width)
        print(testview.bounds.size.height)
        print()
        print(contentView.bounds.size.width)
        print(contentView.bounds.size.height)
        
        playerItem = AVPlayerItem(URL: url)
        player=AVPlayer(playerItem: playerItem!)
//        let playerLayer=AVPlayerLayer(player: player!)
//        playerLayer.frame = testview.bounds
//        playerLayer.frame=CGRectMake(0, 0, testview.bounds.size.width-10, testview.bounds.size.height-10)
//        testview.layer.addSublayer(playerLayer)
        
        testview.playerLayer.player = player
        testview.playerLayer.videoGravity = AVLayerVideoGravityResizeAspectFill
        
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

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
