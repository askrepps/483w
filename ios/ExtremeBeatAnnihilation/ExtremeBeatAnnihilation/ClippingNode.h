//
//  ClippingNode.h
//
//  Created by Steffen Itterheim
//  http://www.learn-cocos2d.com/2011/01/cocos2d-gem-clippingnode/
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
