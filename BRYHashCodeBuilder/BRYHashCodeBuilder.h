//
//  BRYHashCodeBuilder.h
//  BRYHashCodeBuilder
//
//  Created by Bryan Irace on 2/23/14.
//  Copyright (c) 2014 Bryan Irace. All rights reserved.
//

@import Foundation;
@import CoreGraphics;

// https://commons.apache.org/proper/commons-lang/javadocs/api-3.1/org/apache/commons/lang3/builder/HashCodeBuilder.html
@interface BRYHashCodeBuilder : NSObject

@property (nonatomic, readonly) NSUInteger hashCode;

+ (instancetype)builderWithInitialValue:(NSUInteger)initial multiplier:(NSUInteger)multiplier;

- (BRYHashCodeBuilder *)appendObject:(id)object;

- (BRYHashCodeBuilder *)appendInteger:(NSInteger)integer;

- (BRYHashCodeBuilder *)appendUnsignedInteger:(NSUInteger)unsignedInteger;

- (BRYHashCodeBuilder *)appendBool:(BOOL)boolean;

- (BRYHashCodeBuilder *)appendFloat:(CGFloat)floatValue;

@end
