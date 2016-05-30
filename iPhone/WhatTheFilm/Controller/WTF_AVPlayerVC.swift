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

// Not used anymore. Instead of passing value to movieDetailsVC, it is storing it to userdefaults
//protocol WTF_AVPLayerVCDelegate: class {
//    func lastPlayerCurrentTime(time: CMTime)
//}

class WTF_AVPlayerVC: AVPlayerViewController {
    
    var movieDidFinish = false
    var defaults: NSUserDefaults!
    var keyForDefaults: String!
    
//    var lastCurrentTime: CMTime!
//    weak var wtfAVPlayerVCDelegate: WTF_AVPLayerVCDelegate? = nil
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Setting 'self' as observer for when video finishes playing
        NSNotificationCenter.defaultCenter().addObserver(self, selector: #selector(WTF_AVPlayerVC.playerItemDidReachEnd), name: AVPlayerItemDidPlayToEndTimeNotification, object: player?.currentItem)
        
        player?.play()
        // If movie was in progress then restore to the last time
        defaults = NSUserDefaults.standardUserDefaults()
        if let obj = defaults.objectForKey(keyForDefaults) as? [Int]{
            let secs = Double(obj[0] / obj[1])
            let currTimeMinus2Seconds = CMTime(seconds: secs-2, preferredTimescale: (CMTimeScale(obj[1])))
            player?.seekToTime(currTimeMinus2Seconds)
        }
    }
    
    override func viewWillDisappear(animated: Bool) {
        
        if !movieDidFinish {
            let currTime = player?.currentTime()
            let obj = [Int((currTime?.value)!), Int((currTime?.timescale)!)]
            defaults.setObject(obj, forKey: keyForDefaults)
            
            // Tested case with seconds being a negative number and there are no problems
            // clip still starts at 0:0 mark
//            let secs = Double((currTime?.value)!) / Double((currTime?.timescale)!)
//            let currTimeMinus2Seconds = CMTime(seconds: secs-2, preferredTimescale: (currTime?.timescale)!)
//            lastCurrentTime = currTimeMinus2Seconds
        }
//        wtfAVPlayerVCDelegate?.lastPlayerCurrentTime(lastCurrentTime)
    }

    // Only allow landscape when playing video
    override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return [UIInterfaceOrientationMask.LandscapeLeft, UIInterfaceOrientationMask.LandscapeRight]
    }
    
    func playerItemDidReachEnd() {
        movieDidFinish = true
//        lastCurrentTime = kCMTimeZero
        defaults.removeObjectForKey(keyForDefaults)
        NSNotificationCenter.defaultCenter().removeObserver(self)
        dismissViewControllerAnimated(true, completion: nil)
    }
    
}


