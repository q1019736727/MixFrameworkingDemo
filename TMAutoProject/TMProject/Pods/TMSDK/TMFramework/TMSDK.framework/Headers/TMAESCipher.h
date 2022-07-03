//
//  TMAESCipher.h
//  TMAESCipher
//

#import <Foundation/Foundation.h>

NSString * aesEncryptString(NSString *content, NSString *key, NSString *iv);
NSString * aesDecryptString(NSString *content, NSString *key, NSString *iv);

NSData * aesEncryptData(NSData *data, NSData *key, NSData *ivData);
NSData * aesDecryptData(NSData *data, NSData *key, NSData *ivData);
