#!/bin/bash

echo "......拉取最新代码......."

path=$(cd "$(dirname "$0")"; pwd)
projrct_path=""
if git clone "http://qiuyong@192.168.10.18:8090/r/aesm/app_pb.git"
then
    echo "代码克隆完成"
else
    cd document
    if git pull
    then
    echo "代码拉取成功"
#        if git checkout -b second origin/stage3
#        then
#        echo "已切换到分支stage3"
#        else
#        echo "切换失败"
#        fi
    else
    echo "代码拉取失败"
    exit 1
    fi
fi

echo "......编译pb文件......."

cd ${path}
rm -rf "temp"
mkdir "temp"

if cp -rvf ${path}"/app_pb" ${path}"/temp"
then
    echo "pb拷贝完成....."
else
    echo "pb拷贝失败....."
    exit 2
fi

if rm -rf "app_pb"
then
    echo "删除app_pb文件完成...."
else
    echo "删除app_pb文件失败"
    exit 3
fi

cd ${path}"/temp/app_pb"

if rm -rf ".git"
then
    echo "删除.git完成...."
else
    echo "删除.git失败"
    exit 4
fi

if protoc --swift_out=. *
then
    echo "pb编译完成...."
else
    echo "pb编译失败"
    exit 5
fi

if cp  ${path}"/upload.pb.swift" ${path}"/temp/app_pb"
then
    echo "upload.pb.swift 拷贝完成....."
else
    echo "upload.pb.swift 拷贝失败....."
    exit 6
fi


cd ${path}

echo "......拷贝pb.swift到xcode......"

if xcodeproj --help
then
    echo "环境配置完成"
else
    if sudo gem install xcodeproj
    then
        echo "安装 xcodeproj 完成"
    else
        echo "环境配置失败"
        exit
    fi
fi

if ruby autopb.rb ${path}"/temp/app_pb"
then
    echo ""
else
    echo "拷贝pb.swift到xcode失败"
fi





