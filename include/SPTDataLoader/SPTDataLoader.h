/*
 * Copyright (c) 2015 Spotify AB.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
@import Foundation;

#import <SPTDataLoader/SPTDataLoaderConvenience.h>

@protocol SPTDataLoaderDelegate;
@class SPTDataLoaderRequest;

#ifndef SPT_BUILDING_FRAMEWORK
#define SPT_BUILDING_FRAMEWORK 0
#endif
#if SPT_BUILDING_FRAMEWORK
//! Project version number for SPTDataLoader.
FOUNDATION_EXPORT double SPTDataLoaderVersionNumber;

//! Project version string for SPTDataLoader.
FOUNDATION_EXPORT const unsigned char SPTDataLoaderVersionString[];
#endif // SPT_BUILDING_FRAMEWORK

/**
 * The object used for performing requests
 */
@interface SPTDataLoader : NSObject

/**
 * The object listening to the data loader
 */
@property (nonatomic, weak) id<SPTDataLoaderDelegate> delegate;
/**
 * The queue to call the delegate selectors on
 * @discussion By default this is the main queue
 */
@property (nonatomic, strong) dispatch_queue_t delegateQueue;

/**
 * Performs a request
 * @param request The object describing the kind of request to be performed
 */
- (id<SPTCancellationToken>)performRequest:(SPTDataLoaderRequest *)request;
/**
 * Cancels all the currently operating and pending requests
 */
- (void)cancelAllLoads;

@end
