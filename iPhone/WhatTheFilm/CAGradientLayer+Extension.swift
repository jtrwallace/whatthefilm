//
//  CAGradientLayer+Extension.swift
//  MatchTheEmoji
//
//  Created by Julio Franco on 3/26/16.
//  Copyright (c) 2016 Julio Franco. All rights reserved.
//

import UIKit

extension CAGradientLayer {
    
    
    func grayBehindTitle() -> CAGradientLayer {
        
        let gradientColors = [StyleConstants.gradientTopGray.CGColor, StyleConstants.gradientBottomGray.CGColor]
        let gradientLocations: [Float] = [0.0, 1.0]
        let gradientLayer = CAGradientLayer()
        gradientLayer.colors = gradientColors
        gradientLayer.locations = gradientLocations

        return gradientLayer
    }
}
