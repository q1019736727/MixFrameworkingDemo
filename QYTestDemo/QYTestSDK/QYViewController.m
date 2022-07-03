//
//  QYViewController.m
//  QYTestSDK
//
//  Created by 邱勇 on 2022/7/1.
//

#import "QYViewController.h"
#import <QYTestSDK/QYTestSDK-Swift.h>

@interface QYViewController ()

@end

@implementation QYViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor grayColor];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [[QYTools shared]changeColor:self];
}


@end
