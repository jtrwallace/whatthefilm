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
    
    @IBOutlet weak var playerView: PlayerView!
    var player:AVPlayer?
    var playerItem:AVPlayerItem?

    @IBOutlet weak var movieStill: UIImageView!
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    var movie: Movie!
    var feature: Featured!
    weak var currentVC: UIViewController!

    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
        
        activityIndicator.hidesWhenStopped = true
    }
    
    func playPreview() {
        let url = NSURL(string: feature.videoLink)!
        playerItem = AVPlayerItem(URL: url)
        player=AVPlayer(playerItem: playerItem!)
        playerView.playerLayer.player = player
        playerView.playerLayer.videoGravity = AVLayerVideoGravityResizeAspectFill
        player?.play()
        
        let cmTime  = CMTimeMake(1, 3) // 1/3 of a second
        let cmValue = NSValue(CMTime: cmTime)
        // Since a UIImage of a movie still is on top of AVPlayer I'm adding observer to find
        // out when clip started playing so I can hide image, therefore showing the video
        var timeObserver: AnyObject!
        timeObserver = player?.addBoundaryTimeObserverForTimes([cmValue], queue: nil, usingBlock: {
            self.movieStill.hidden = true
            self.activityIndicator.stopAnimating()
            self.player?.removeTimeObserver(timeObserver)
        })
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: #selector(MoviePreviewTableViewCell.playerItemDidReachEnd), name: AVPlayerItemDidPlayToEndTimeNotification, object: player?.currentItem)
    }
    
    func playerItemDidReachEnd() {
        player!.seekToTime(kCMTimeZero)
        player!.play()
    }
    
    @IBAction func movieStillButtonPressed(sender: AnyObject) {
        currentVC.performSegueWithIdentifier("MovieDetails", sender: self)
    }

}


