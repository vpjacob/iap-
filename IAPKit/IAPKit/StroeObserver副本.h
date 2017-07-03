//
//  StroeObserver.h
//  ThinkSNS（探索版）
//
//  Created by 乔乔智祥 on 17/1/6.
//  Copyright © 2017年 zhishi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import <StoreKit/SKPaymentTransaction.h>
#import <UIKit/UIKit.h>
#define PRODUCTID @"123456789" //商品ID（请填写你商品的id）


#define kProductsLoadedNotification         @"ProductsLoaded"
#define kProductPurchaseFailedNotification  @"ProductPurchaseFailed"
#define kProductPurchasedNotification       @"ProductPurchased"
#define kProductPurchasedButtonOpenNotification  @"ButtonOpen"
#define kProductsLoadedFallNotification     @"ProductsLoadedfail"
#define kProducts1Notification     @"Products1"
#define kProducts2Notification     @"Products2"
#define kProducts3Notification     @"Products3"
#define kProducts4Notification     @"Products4"
#define kProductsNotificationComplete     @"Complete"
@interface StroeObserver : NSObject<SKPaymentTransactionObserver,SKProductsRequestDelegate>
{
    int buyType;
}

-(void)Create;
-(void)Destroy;

-(void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions;
-(void)PurchasedTransaction: (SKPaymentTransaction *)transaction;
-(void)completeTransaction: (SKPaymentTransaction *)transaction;
-(void)failedTransaction: (SKPaymentTransaction *)transaction;
-(void)paymentQueueRestoreCompletedTransactionsFinished: (SKPaymentTransaction *)transaction;
-(void)paymentQueue:(SKPaymentQueue *) paymentQueue restoreCompletedTransactionsFailedWithError:(NSError *)error;

-(void)Buy:(int)type;
-(bool)CanMakePay;
-(void)RequestProductData;
-(void)restoreTransaction: (SKPaymentTransaction *)transaction;

-(void)addProductToPaymentQueue:(int)ProductType;
+(StroeObserver *)shareStoreObserver;
@end
