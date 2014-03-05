# BRYHashCodeBuilder

Utility for determining object hash code, based on Apache Commons [HashCodeBuilder](http://commons.apache.org/proper/commons-lang/apidocs/org/apache/commons/lang3/builder/HashCodeBuilder.html).

```objectivec
- (NSUInteger)hash {
    return [[[[[BRYHashCodeBuilder builderWithInitialValue:17 multiplier:37]
               appendObject:self.name]
              appendBool:self.isHidden]
             appendFloat:self.width]
            appendInteger:self.index].hashCode;
}
```

## License

Available for use under the MIT license: [http://bryan.mit-license.org](http://bryan.mit-license.org)
