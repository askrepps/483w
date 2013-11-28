//
//  ClippingNode.h
//
//  Created by Steffen Itterheim
//

#import "cocos2d.h"

/** Restricts (clips) drawing of all children to a specific region. */
@interface ClippingNode : CCNode
{
    CGRect clippingRegionInNodeCoordinates;
    CGRect clippingRegion;
}

@property (nonatomic) CGRect clippingRegion;

@end
