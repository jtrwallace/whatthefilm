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
    func currentTimeUpdate(time: CMTime)
}


class WTF_AVPlayerVC: AVPlayerViewController {
    
    weak var wtfDelegate: WTF_AVPLayerVCDelegate? = nil
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
//    
    override func viewWillDisappear(animated: Bool) {
        print("av player done button pressed")
        print(player?.currentTime())
        
        wtfDelegate?.currentTimeUpdate((player?.currentTime())!)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return [UIInterfaceOrientationMask.LandscapeLeft, UIInterfaceOrientationMask.LandscapeRight]
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
