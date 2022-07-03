//
//  ViewController.m
//  OCSwiftTest
//
//  Created by 邱勇 on 2022/6/30.
//

#import "ViewController.h"
#import "OCSwiftTest-Swift.h"
//#import <QYTestSDK/QYTestSDK.h>
//#import <QYTestSDK/QYTestSDK-Swift.h>
@import QYTestSDK;
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor blueColor];
}
-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    QYViewController * vc = [[QYViewController alloc]init];
    UINavigationController * nav = [[UINavigationController alloc]initWithRootViewController:vc];
    [self presentViewController:nav animated:true completion:nil];
    test * te = [[test alloc]init];
    [te changColor:self];
}


@end
