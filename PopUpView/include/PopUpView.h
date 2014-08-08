//
//  PopUpView.h
//  PopUpView
//
//  Created by Prajwal S on 16/07/14.
//  Copyright (c) 2014 Robosoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <Accelerate/Accelerate.h>


/*
 Sample usage:
 //call from a parent viewcontroller (on any action to pop up)
 
 ESPopImageViewer *popImageView = [[ESPopImageViewer alloc] init];
 [popImageView showInViewController:self center:CGPointMake(self.view.bounds.size.width/2.f, self.view.bounds.size.height/2.f)];
 */

@interface PopUpView : UIViewController

// The background color of the main view (note this is a UIViewController subclass)
// default black with 0.7 alpha
@property (nonatomic, strong) UIColor *backgroundColor;

// defaults to nil, the path to be applied as a mask to the background image. if this path is set, cornerRadius is ignored
@property (nonatomic, strong) UIBezierPath *backgroundPath;

// defaults to 8 (only applied if backgroundPath == nil)
@property (nonatomic, assign) CGFloat cornerRadius;

// The level of blur for the background image. Range is 0.0 to 1.0
// default 0.3
@property (nonatomic, assign) CGFloat blurLevel;

// defaults to nil ( == the whole background gets blurred)
@property (nonatomic, strong) UIBezierPath *blurExclusionPath;

// The time in seconds for the show and dismiss animation
// default 0.25f
@property (nonatomic, assign) CGFloat animationDuration;

// An optional block that gets executed before the gridMenu gets dismissed
@property (nonatomic, copy) dispatch_block_t dismissAction;

// Determine whether or not to bounce in the animation
// default YES
@property (nonatomic, assign) BOOL bounces;

// Show the menu
- (void)showInViewController:(UIViewController *)parentViewController center:(CGPoint)center;

// Dismiss the menu
// This is called when the window is tapped. If tapped inside the view an item will be selected.
// If tapped outside the view, the menu is simply dismissed.
- (void)dismissAnimated:(BOOL)animated;

- (UIImage *) getImage;

@end
