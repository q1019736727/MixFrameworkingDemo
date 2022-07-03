//
//  TianmaSwift.swift
//  TMProject
//
//  Created by 邱勇 on 2022/7/3.
//  Copyright © 2022 Tianma. All rights reserved.
//

import UIKit
import Alamofire

class TianmaSwift: NSObject {

    override init() {
        super.init()
        let url = URL(string: "https://www.baidu.com")
        guard let url = url else {
            return
        }
        AF.request(url, method: .get).responseJSON { requestData in
            print("-----百度结果--------")
            print(requestData)
        }
    }
}
