//
//  PTKeyCodeTranslator.h
//  Chercher
//
//  Created by Finlay Dobbie on Sat Oct 11 2003.
//  Copyright (c) 2003 Cliché Software. All rights reserved.
//

#import <Carbon/Carbon.h>

@interface PTKeyCodeTranslator : NSObject
{
    TISInputSourceRef	keyboardLayout;
    const UCKeyboardLayout	*uchrData;
    UInt32		keyTranslateState;
    UInt32		deadKeyState;
}

+ (id)currentTranslator;

- (instancetype)initWithKeyboardLayout:(TISInputSourceRef)aLayout NS_DESIGNATED_INITIALIZER;
- (NSString *)translateKeyCode:(short)keyCode;

@property (nonatomic, readonly) TISInputSourceRef keyboardLayout;

@end
