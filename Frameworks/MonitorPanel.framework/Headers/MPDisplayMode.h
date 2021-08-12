//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class MPDisplay, NSNumber, NSString;

@interface MPDisplayMode : NSObject
{
    MPDisplay *_display;
    struct _CGSDisplayModeDescription _desc;
    NSString *_rateString;
    unsigned int _tvMode;
}

+ (id)modeWithDescription:(struct _CGSDisplayModeDescription *)arg1 forDisplay:(id)arg2;
@property(readonly) MPDisplay *display; // @synthesize display=_display;
@property(readonly) NSString *refreshString;
@property(readonly) NSString *resolutionString;
- (id)resolutionFormat;
@property(readonly) BOOL isSafeMode;
- (id)description;
- (void)getModeDescription:(struct _CGSDisplayModeDescription *)arg1;
- (BOOL)modeResolutionMatches:(id)arg1;
- (BOOL)resolutionMatches:(struct _CGSDisplayModeDescription *)arg1;
@property(readonly) unsigned int tvModeEquiv;
@property(readonly) unsigned int tvMode;
@property(readonly) BOOL isTVMode;
@property(readonly) BOOL isSimulscan;
@property(readonly) BOOL isInterlaced;
@property(readonly) BOOL isNativeMode;
@property(readonly) BOOL isDefaultMode;
@property(readonly) BOOL isStretched;
@property(readonly) BOOL isUserVisible;
@property(readonly) BOOL isHiDPI;
@property(readonly) BOOL isRetina;
@property(readonly) NSNumber *scanRate;
@property(readonly) int roundedScanRate;
@property(readonly) float scale;
@property(readonly) float aspectRatio;
@property(readonly) int fixPtRefreshRate;
@property(readonly) int refreshRate;
@property(readonly) int dotsPerInch;
@property(readonly) int vertDPI;
@property(readonly) int horizDPI;
@property(readonly) int pixelsHigh;
@property(readonly) int pixelsWide;
@property(readonly) int height;
@property(readonly) int width;
@property(readonly) int modeNumber;
@property(readonly) struct _CGSDisplayModeDescription *modeDescription;
- (void)dealloc;
- (id)initWithModeDescription:(struct _CGSDisplayModeDescription *)arg1 forDisplay:(id)arg2;

@end

