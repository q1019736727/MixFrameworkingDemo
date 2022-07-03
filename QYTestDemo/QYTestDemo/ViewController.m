//
//  ViewController.m
//  QYTestDemo
//
//  Created by 邱勇 on 2022/7/1.
//

#import "ViewController.h"
#import <QYTestSDK/QYTestSDK.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}
-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    QYViewController * vc = [[QYViewController alloc]init];
    UINavigationController * nav = [[UINavigationController alloc]initWithRootViewController:vc];
    [self presentViewController:nav animated:true completion:nil];
}


@end
