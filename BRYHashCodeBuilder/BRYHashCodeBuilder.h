//
//  BRYHashCodeBuilder.h
//  BRYHashCodeBuilder
//
//  Created by Bryan Irace on 2/23/14.
//  Copyright (c) 2014 Bryan Irace. All rights reserved.
//

@import Foundation;
@import CoreGraphics;

/**
 Utility for determining object hash codes, based on Apache Commons [HashCodeBuilder](https://commons.apache.org/proper/commons-lang/javadocs/api-3.1/org/apache/commons/lang3/builder/HashCodeBuilder.html). Useful for implemeting `-[NSObject hash]` methods.
 
 - (NSUInteger)hash {
     return [[[[[BRYHashCodeBuilder builderWithInitialValue:17 multiplier:37]
                appendObject:self.name]
               appendBool:self.isHidden]
              appendFloat:self.width]
             appendInteger:self.index].hashCode;
 }
 */
@interface BRYHashCodeBuilder : NSObject

@property (nonatomic, readonly) NSUInteger hashCode;

/**
 Factory method for acquiring a `BRYHashCodeBuilder` instance.
 
 @param initial Randomly chosen, non-zero, odd number. Ideally different for each class, however this is not vital. Preferably prime.
 @param multiplier Randomly chosen, non-zero, odd number. Ideally different for each class, however this is not vital. Preferably prime.
 @return `BRYHashCodeBuilder` instance seeded with the initial value and multiplier
 */
+ (instancetype)builderWithInitialValue:(NSUInteger)initial multiplier:(NSUInteger)multiplier;

- (BRYHashCodeBuilder *)appendObject:(id <NSObject>)object;

- (BRYHashCodeBuilder *)appendInteger:(NSInteger)integer;

- (BRYHashCodeBuilder *)appendUnsignedInteger:(NSUInteger)unsignedInteger;

- (BRYHashCodeBuilder *)appendBool:(BOOL)boolean;

- (BRYHashCodeBuilder *)appendFloat:(CGFloat)floatValue;

@end
