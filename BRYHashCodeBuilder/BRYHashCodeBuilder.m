//
//  BRYHashCodeBuilder.m
//  BRYHashCodeBuilder
//
//  Created by Bryan Irace on 2/23/14.
//  Copyright (c) 2014 Bryan Irace. All rights reserved.
//

#import "BRYHashCodeBuilder.h"

@interface BRYHashCodeBuilder()

@property (nonatomic) NSUInteger hashCode;
@property (nonatomic, readonly) NSUInteger constant;

@end

@implementation BRYHashCodeBuilder

#pragma mark - Initialization

+ (instancetype)builderWithInitialValue:(NSUInteger)initial multiplier:(NSUInteger)multiplier {
    return [[self alloc] initWithInitialValue:initial multiplier:multiplier];
}

- (instancetype)initWithInitialValue:(NSUInteger)initial multiplier:(NSUInteger)multiplier {
    if (self = [super init]) {
        _hashCode = initial;
        _constant = multiplier;
    }
    
    return self;
}

- (id)init {
    return [self initWithInitialValue:17 multiplier:37];
}

#pragma mark - Value comparison

- (BRYHashCodeBuilder *)appendUnsignedInteger:(NSUInteger)unsignedInteger {
    return [self appendInteger:unsignedInteger];
}

- (BRYHashCodeBuilder *)appendBool:(BOOL)boolean {
    return [self appendInteger:boolean ? 1 : 0];
}

- (BRYHashCodeBuilder *)appendFloat:(CGFloat)floatValue {
    return [self appendObject:@(floatValue)];
}

- (BRYHashCodeBuilder *)appendObject:(id)object {
    return [self appendInteger:[object hash]];
}

- (BRYHashCodeBuilder *)appendInteger:(NSInteger)integer {
    self.hashCode = self.hashCode * self.constant + integer;
    return self;
}

@end
