//
//  UIVIew+Extension.swift
//  WhatTheFilm
//
//  Created by Julio Franco on 6/3/16.
//  Copyright © 2016 Julio Franco. All rights reserved.
//

import UIKit

class TriangleLeftView: UIView {
    
    override func drawRect(rect: CGRect) {
        // Get Height and Width
        let layerHeight = self.layer.frame.height
        let layerWidth = self.layer.frame.width
        
        // Create Path
        let bezierPath = UIBezierPath()
        
        // Draw Points
        bezierPath.moveToPoint(CGPointMake(0, 0))
        bezierPath.addLineToPoint(CGPointMake(layerWidth, 0))
        bezierPath.addLineToPoint(CGPointMake(0, layerHeight))
        bezierPath.addLineToPoint(CGPointMake(0, 0))
        bezierPath.closePath()
        
        
        // Apply Color
        StyleConstants.greenForGenres.setFill()
        bezierPath.fill()
        
        // Mask to Path
        let shapeLayer = CAShapeLayer()
        shapeLayer.path = bezierPath.CGPath
        self.layer.mask = shapeLayer
    }
}

class TriangleRightView: UIView {
    
    override func drawRect(rect: CGRect) {
        // Get Height and Width
        let layerHeight = self.layer.frame.height
        let layerWidth = self.layer.frame.width
        
        // Create Path
        let bezierPath = UIBezierPath()
        
        // Draw Points
        bezierPath.moveToPoint(CGPointMake(0, 0))
        bezierPath.addLineToPoint(CGPointMake(layerWidth, 0))
        bezierPath.addLineToPoint(CGPointMake(layerWidth, layerHeight))
        bezierPath.addLineToPoint(CGPointMake(0, 0))
        bezierPath.closePath()
        
        // Apply Color
        StyleConstants.greenForGenres.setFill()
        bezierPath.fill()
        
        // Mask to Path
        let shapeLayer = CAShapeLayer()
        shapeLayer.path = bezierPath.CGPath
        self.layer.mask = shapeLayer
    }
}


