//
//  MWPhoto.h
//  MWPhotoBrowser
//
//  Created by Michael Waterfall on 17/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MWPhotoProtocol.h"
#import "SDWebImageDecoder.h"
#import "SDWebImageManager.h"

// This class models a photo/image and it's caption
// If you want to handle photos, caching, decompression
// yourself then you can simply ensure your custom data model
// conforms to MWPhotoProtocol

@protocol MWPhotoDelegate;

@class LSCollectionViewImage;
@class DBMetadata;

@interface MWPhoto : NSObject <MWPhoto, SDWebImageManagerDelegate, SDWebImageDecoderDelegate>

// Properties
@property (nonatomic, retain) NSString *caption;

// Class
+ (MWPhoto *)photoWithImage:(UIImage *)image;
+ (MWPhoto *)photoWithFilePath:(NSString *)path;
+ (MWPhoto *)photoWithURL:(NSURL *)url;
+ (MWPhoto *)photoWithCollectionImage:(LSCollectionViewImage *)collectionImage;

// Init
- (id)initWithImage:(UIImage *)image;
- (id)initWithFilePath:(NSString *)path;
- (id)initWithURL:(NSURL *)url;

@property (nonatomic, strong) id<MWPhotoDelegate> delegate;
@property (nonatomic, strong) LSCollectionViewImage *collectionImage;

@end

@protocol MWPhotoDelegate <NSObject>

- (void)photo:(MWPhoto *)photo requestLoadImageWithCompletionBlock:(void (^)(NSString *contentType, DBMetadata *metadata, NSError *error))completionBlock;

@end