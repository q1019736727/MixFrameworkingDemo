//
//  CYTest.swift
//  QYTestSDK
//
//  Created by 邱勇 on 2022/7/1.
//

import UIKit
import Alamofire

open class CYTest: NSObject {
    public override init() {
        super.init()
        
    }
    
    @objc public func GetClassFromString(_ classString: String) -> AnyClass? {
        guard let bundleName: String = Bundle.main.object(forInfoDictionaryKey: "CFBundleName") as? String else {
            return nil
        }
            
        var anyClass: AnyClass? = NSClassFromString(bundleName + "." + classString)
        if (anyClass == nil) {
            anyClass = NSClassFromString(classString)
        }
        return anyClass
    }
}
