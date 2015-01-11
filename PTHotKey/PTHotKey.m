//
//  PTHotKey.m
//  Protein
//
//  Created by Quentin Carnicelli on Sat Aug 02 2003.
//  Copyright (c) 2003 Quentin D. Carnicelli. All rights reserved.
//

#import "PTHotKey.h"

#import "PTHotKeyCenter.h"
#import "PTKeyCombo.h"

@interface PTHotKey ()

@property (nonatomic, strong, readwrite) id identifier;
@property (nonatomic, strong, readwrite) PTKeyCombo *keyCombo;

@end

@implementation PTHotKey

- (instancetype)init
{
	return [self initWithIdentifier: nil keyCombo: nil];
}

- (instancetype)initWithIdentifier: (id)identifier keyCombo: (PTKeyCombo*)combo
{
	self = [super init];
	
	if( self )
	{
		[self setIdentifier: identifier];
		[self setKeyCombo: combo];
	}
	
	return self;
}

- (NSString*)description
{
	return [NSString stringWithFormat: @"<%@: %@, %@>", NSStringFromClass( [self class] ), [self identifier], [self keyCombo]];
}

#pragma mark -

- (void)setKeyCombo: (PTKeyCombo*)combo
{
	if( combo == nil )
		combo = [PTKeyCombo clearKeyCombo];
	
	_keyCombo = combo;
}

#pragma mark -

- (void)invoke
{
	NSMethodSignature *signature  = [_target methodSignatureForSelector:_action];
	NSInvocation      *invocation = [NSInvocation invocationWithMethodSignature:signature];
	
	__weak PTHotKey *weakSelf = self;
	[invocation setTarget:_target];
	[invocation setSelector:_action];
	[invocation setArgument:&weakSelf atIndex:2];
	
	[invocation invoke];
}

@end