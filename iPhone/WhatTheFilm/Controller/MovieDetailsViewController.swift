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

    var avPLayerVC: WTF_AVPlayerVC!
    var avPlayer: AVPlayer!
    
    @IBOutlet weak var scrollView: UIScrollView!
    var dismissVCHeight: CGFloat!
    
    
    
    var testCmTime: CMTime!
    
    @IBOutlet weak var movieImage: UIImageView!
    @IBOutlet weak var movieImageTopConstraint: NSLayoutConstraint!
    @IBOutlet weak var gradientContainer: UIView!

    var movie: Movie!
    @IBOutlet weak var movieTitle: UILabel!
    @IBOutlet weak var year: UILabel!
    @IBOutlet weak var duration: UILabel!
    @IBOutlet weak var summary: UILabel!
    @IBOutlet weak var cast: UILabel!
    @IBOutlet weak var genre: UILabel!
    @IBOutlet weak var director: UILabel!
    
    @IBOutlet weak var strecherLineTopConstraint: NSLayoutConstraint!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Init misc properties
        dismissVCHeight = (-1)*(view.bounds.size.height * 0.22)
        
        // Init UI
        movieTitle.text = movie.title
        year.text = (movie.year > 0 ? movie.year.description : "")
        duration.text = (movie.duration > 0 ? timeFormatted(movie.duration) : "")
        summary.text = movie.description
        cast.text = "Cast: \(movie.actors)"
        genre.text = "Genre: \(movie.genre)"
        director.text = "Director: \(movie.director)"

        
        if movie.videoStillLink != "" {
            let url = NSURL(string: movie.videoStillLink)
            movieImage.sd_setImageWithURL(url)
        }
        
        // Add gradient behind Movie title that blends movieImage & scrollView
        let gradientLayer = CAGradientLayer().grayBehindTitle()
        gradientLayer.frame = gradientContainer.bounds
        gradientContainer.layer.insertSublayer(gradientLayer, atIndex: 0)
        
        
    }
    
    override func viewDidAppear(animated: Bool) {
        
        // To allow a scrollable VC even is there is not enough content to scroll
        // The strecherLine is fixed to bottom of contentView and has a top constraint to
        // director-UILabel which is increased to 1pt past the height of the scrollview.
        let directorLabelBottomYPostition = director.frame.origin.y + director.frame.size.height
        strecherLineTopConstraint.constant = scrollView.frame.size.height - directorLabelBottomYPostition
    }
    
    override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return UIInterfaceOrientationMask.Portrait
    }
    
    // Protocol function - WTF_AVPLayerVCDelegate
    func lastPlayerCurrentTime(time: CMTime) {
        testCmTime = time
    }
    
    @IBAction func backButtonPressed(sender: AnyObject) {
        dismissViewControllerAnimated(true, completion: nil)
    }

    @IBAction func playButtonPressed(sender: AnyObject) {
        let url = NSURL(string: movie.videoLink)
        avPlayer = AVPlayer(URL: url!)
        avPLayerVC = WTF_AVPlayerVC()
        avPLayerVC.player = avPlayer
    
        presentViewController(avPLayerVC, animated: true) {
            self.avPLayerVC.wtfAVPlayerVCDelegate = self
            self.avPLayerVC.player?.play()
            
            if let time = self.testCmTime {
                self.avPLayerVC.player?.seekToTime(time)
            }
        }
    }
    
    
    // Formats seconds to either 1h 33m or 33m 15s
    func timeFormatted(secs: Int) -> String {
        let seconds: Int = secs % 60
        let minutes: Int = (secs / 60) % 60
        let hours: Int = secs / 3600
        
        if hours > 0 {
            return "\(hours)h \(minutes)m"
        } else {
            return "\(minutes)m \(seconds)s"
        }
    }
    
}
    
    
extension MovieDetailsViewController: UIScrollViewDelegate {
    
    func scrollViewDidScroll(scrollView: UIScrollView) {
        // Zooming effect of the movie-still
        // when scrolling down only zooms for the first 40pts
        let offsetY = scrollView.contentOffset.y
        if offsetY < 0 && offsetY > -40 {
            movieImageTopConstraint.constant = offsetY
        } else if offsetY < -40 {
            movieImageTopConstraint.constant = -40
        }
        
        // Dismiss VC when the screen has been scrolled down 22% of the view's height
        if offsetY < dismissVCHeight {
            dismissViewControllerAnimated(true, completion: nil)
        }
        
    }
    
}
    
    
