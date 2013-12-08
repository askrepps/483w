#include "ClipNode.h"

namespace cocos2d
{
    ClipNode::ClipNode()
    { }

    ClipNode::~ClipNode()
    { }

    void ClipNode::setClippingRegion(CCRect region)
    {
        clippingRegionInNodeCoordinates = region;

        this->setContentSize(region.size);

        // respect scaling but don't convert points to pixels
        scissorRect = CCRect((region.origin.x * getScaleX())/2.0f, (region.origin.y * getScaleY())/2.0f,
                                     region.size.width * getScaleX(), region.size.height * getScaleY());
    }

    void ClipNode::setScale(float newscale)
    {
        CCLOG("ClipNode::setScale %f", newscale);

        CCNode::setScale(newscale);

        // re-adjust the clipping region according to the current scale factor
        setClippingRegion(clippingRegionInNodeCoordinates);
    }

    void ClipNode::visit()
    {
        if (clipsToBounds)
        {
            glEnable(GL_SCISSOR_TEST);

            // glScissor(scissorRect.origin.x,scissorRect.origin.y,scissorRect.size.width,scissorRect.size.height);
            CCEGLView::sharedOpenGLView()->setScissorInPoints(scissorRect.origin.x,scissorRect.origin.y,
                                                        scissorRect.size.width,scissorRect.size.height);
        }

        CCNode::visit();

        if (clipsToBounds)
            glDisable(GL_SCISSOR_TEST);
    }
} // namespace cocos2d

