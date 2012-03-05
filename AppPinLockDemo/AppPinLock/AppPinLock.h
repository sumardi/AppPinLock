//
//  AppPinLock.h
//
//  This fork version is maintained by Sumardi Shukor <me@sumardi.net>
//  http://github.com/sumardi/AppPinLock
//
//  Version 1.2.1
//
//  Original Version Created by Aron Bury on 09/09/2011.
//  Copyright 2011 Aron Bury. All rights reserved.
//
//  Forked from ABPadLockScreen:
//  https://github.com/abury/ABPadLockScreen
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

#import <UIKit/UIKit.h>
#import <CommonCrypto/CommonDigest.h>
@protocol AppPinLockDelegate
@required
- (void)unlockWasSuccessful;
- (void)unlockWasUnsuccessful:(int)falseEntryCode afterAttemptNumber:(int)attemptNumber;
- (void)unlockWasCancelled;

@optional
- (void)attemptsExpired;
@end

@protocol AppPinLockDataSource
@required
- (int)unlockPasscode;
- (NSString *)padLockScreenTitleText;
- (NSString *)padLockScreenSubtitleText;
- (BOOL)hasAttemptLimit;

@optional
- (int)attemptLimit;

@end

@interface AppPinLock : UIViewController
@property (nonatomic, unsafe_unretained) id<AppPinLockDelegate> delegate;
@property (nonatomic, unsafe_unretained) id<AppPinLockDataSource> dataSource;

- (id)initWithDelegate:(id<AppPinLockDelegate>)aDelegate withDataSource:(id<AppPinLockDataSource>)aDataSource;
- (void)resetAttempts;
- (void)resetLockScreen;
+ (NSString *)getMD5FromString:(NSString *)source;

@end
