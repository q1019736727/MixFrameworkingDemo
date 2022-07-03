//
//  QYTools.swift
//  QYTestSDK
//
//  Created by 邱勇 on 2022/7/1.
//

import UIKit

@objc
@objcMembers
open class QYTools: NSObject {
    
    public static let shared = QYTools()
    
    public override init() {
        super.init()
    }
    
    open func changeColor(_ vc:UIViewController){
        vc.view.backgroundColor = .purple
        TMToast.tm_ShowCenter(withText: "改变颜色了")
        
    }
    
}

