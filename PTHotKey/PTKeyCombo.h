//
//  PTKeyCombo.h
//  Protein
//
//  Created by Quentin Carnicelli on Sat Aug 02 2003.
//  Copyright (c) 2003 Quentin D. Carnicelli. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface PTKeyCombo : NSObject <NSCopying>
{
}

+ (id)clearKeyCombo;
+ (instancetype)keyComboWithKeyCode: (NSInteger)keyCode modifiers: (NSUInteger)modifiers;
- (instancetype)initWithKeyCode: (NSInteger)keyCode modifiers: (NSUInteger)modifiers;

- (instancetype)initWithPlistRepresentation: (id)plist;
@property (nonatomic, readonly, strong) id plistRepresentation;

- (BOOL)isEqual: (PTKeyCombo*)combo;

@property (nonatomic, readonly) NSInteger keyCode;
@property (nonatomic, readonly) NSUInteger modifiers;

@property (nonatomic, getter=isValidHotKeyCombo, readonly) BOOL validHotKeyCombo;

@end


@interface PTKeyCombo (UserDisplayAdditions)

@property (nonatomic, readonly, copy) NSString *keyCodeString;
@property (nonatomic, readonly) NSUInteger modifierMask;

@end
