//
//  ADYServiceParameters.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A collection of arbitrary parameters used during the initialization of the ADYService class.
 
 @note The following parameters are required for the usage of the SDK:
 <pre>
 - threeDS2DirectoryServerInformation (group):
    - directoryServerId
    - publicKey
 </pre>
 
 @note This class corresponds to the `ConfigParameters` class in the specification.
 */
@interface ADYServiceParameters : NSObject

/**
 Initializes the service parameters with the additional data retrieved from the initial PaymentRequest to Adyen.
 This is a convenience initializer used to fill the service parameters with the required parameters. It will iterate of the passed additional data and copy the contents of all the keys that start with `threeds2.`.
 Usage of this initializer is optional.

 @param additionalData The additional data retrieved from the initial PaymentRequest to Adyen.
 @return Initialized service paramaters with the contents of the additional data.
 */
- (instancetype)initWithAdditionalData:(NSDictionary *)additionalData;

/**
 Returns the value associated with a given key in the default group.

 @param key The key for which to return the corresponding value.
 @return The value associated with @p key, or @p nil if no value was set.
 */
- (nullable NSString *)valueForKey:(NSString *)key;

/**
 Returns the value associated with a given key in a specific group.

 @param key The key for which to return the corresponding value.
 @param group The group from which the value should be retrieved, or @p nil if the default group should be used.
 @return The value associated with @p key, or @p nil if no value was set.
 */
- (nullable NSString *)valueForKey:(NSString *)key inGroup:(nullable NSString *)group;


/**
 Sets the value for a given key in the default group.

 @param value The value to set, or @p nil to remove the value.
 @param key The key for @p value.
 */
- (void)setValue:(nullable NSString *)value forKey:(NSString *)key;

/**
 Sets the value for a given key in a specific group.

 @param value The value to set, or @p nil to remove the value.
 @param key The key for @p value.
 @param group The group in which to set the value, or @p nil if the default group should be used.
 */
- (void)setValue:(nullable NSString *)value forKey:(NSString *)key inGroup:(nullable NSString *)group;

/**
 Removes the given key and its associated value from the default group.

 @param key The key to remove along with its associated value.
 */
- (void)removeValueForKey:(NSString *)key;

/**
 Removes the given key and its associated value from a specific group.

 @param key The key to remove along with its associated value.
 @param group The group from which to remove the key and its associated value, or @p if the default group should be used.
 */
- (void)removeValueForKey:(NSString *)key inGroup:(nullable NSString *)group;

@end

NS_ASSUME_NONNULL_END
