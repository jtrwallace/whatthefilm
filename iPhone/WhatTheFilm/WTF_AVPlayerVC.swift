//
//  WTF_AVPlayerVC.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 5/13/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import UIKit
import AVKit
import AVFoundation

protocol WTF_AVPLayerVCDelegate: class {
    func lastPlayerCurrentTime(time: CMTime)
}

class WTF_AVPlayerVC: AVPlayerViewController {
    
    var lastCurrentTime: CMTime!
    var movieDidFinish = false
    
    weak var wtfAVPlayerVCDelegate: WTF_AVPLayerVCDelegate? = nil
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Setting self as observer for when video finishes playing
        NSNotificationCenter.defaultCenter().addObserver(self, selector: #selector(WTF_AVPlayerVC.playerItemDidReachEnd), name: AVPlayerItemDidPlayToEndTimeNotification, object: player?.currentItem)
    }
    
    override func viewWillDisappear(animated: Bool) {
        print("av player done button pressed")
        print(player?.currentTime())
        
        if !movieDidFinish {
            let currTime = player?.currentTime()
            let secs = Double((currTime?.value)!) / Double((currTime?.timescale)!)
            // Tested case with seconds being a negative number and there are no problems
            // clip still starts at 0:0 mark
            let currTimeMinus2Seconds = CMTime(seconds: secs-2, preferredTimescale: (currTime?.timescale)!)
            lastCurrentTime = currTimeMinus2Seconds
        }
        wtfAVPlayerVCDelegate?.lastPlayerCurrentTime(lastCurrentTime)
    }

    // Only allow landscape when playing video
    override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return [UIInterfaceOrientationMask.LandscapeLeft, UIInterfaceOrientationMask.LandscapeRight]
    }
    
    func playerItemDidReachEnd() {
        movieDidFinish = true
        lastCurrentTime = kCMTimeZero
        NSNotificationCenter.defaultCenter().removeObserver(self)
        dismissViewControllerAnimated(true, completion: nil)
    }
    
}


