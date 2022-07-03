//
//  test.swift
//  OCSwiftTest
//
//  Created by 邱勇 on 2022/6/30.
//

import Foundation
import QYTestSDK
import Alamofire

@objcMembers
class test:NSObject {
    override init() {
        super.init()
    }
    open func changColor(_ vc:UIViewController){
        QYTools.shared.changeColor(vc)
    }
}
