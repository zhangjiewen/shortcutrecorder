//
//  PTHotKey.h
//  Protein
//
//  Created by Quentin Carnicelli on Sat Aug 02 2003.
//  Copyright (c) 2003 Quentin D. Carnicelli. All rights reserved.
//
//  Contributors:
// 		Andy Kim

#import <Foundation/Foundation.h>
#import <Carbon/Carbon.h>
#import "PTKeyCombo.h"

@interface PTHotKey : NSObject
{
}

- (instancetype)initWithIdentifier:(id)identifier keyCombo:(PTKeyCombo*)combo;
- (instancetype)init;

@property (nonatomic, strong, readonly) id identifier;

@property (nonatomic, strong) PTKeyCombo *keyCombo;
@property (nonatomic, weak) id target;
@property (nonatomic) SEL action;

@property (nonatomic) UInt32 carbonHotKeyID;
@property (nonatomic) EventHotKeyRef carbonEventHotKeyRef;

- (void)invoke;

@end