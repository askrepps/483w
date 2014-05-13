#include "BackgroundRLayer.h"

using namespace cocos2d;

// Initialize the right player's background for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool BackgroundRLayer::init()
{
    ClipNode* clipNode;               // boundary to clip the image if outside the boundary
    CCSize    screenSize;             // the size of the window
    CCSize    layerSize;              // size of this layer

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    screenSize = CCDirector::sharedDirector()->getWinSize();

    // set layerSize to be the full height and half the width of screenSize, and position the layer to
    //   the right side of the screen
    layerSize.setSize(screenSize.width * POS_HALF_SCREEN, screenSize.height);
    setContentSize(layerSize);
    setPosition(screenSize.width * POS_HALF_SCREEN, 0);

    // create the clip node and add it
    clipNode = new ClipNode();
    clipNode->autorelease();
    clipNode->setPosition(0, 0);
    clipNode->setClipsToBounds(true);
    clipNode->setClippingRegion( CCRect(screenSize.width, 0, layerSize.width, layerSize.height) );
    addChild(clipNode);

    // create and add the first background sprite
    m_background1 = CCSprite::create(RIGHT_BACKGROUND);
    m_background1->setScale(screenSize.height / m_background1->boundingBox().size.height);
    m_background1->setPosition( ccp(getPosition().x, screenSize.height * POS_HALF_SCREEN) );
    clipNode->addChild(m_background1);

    // create, position before first background, and add the second background
    m_background2 = CCSprite::create(RIGHT_BACKGROUND);
    m_background2->setScale(screenSize.height / m_background2->boundingBox().size.height);
    m_background2->setPosition( ccp(getPosition().x - m_background2->boundingBox().size.width,
                                                           screenSize.height * POS_HALF_SCREEN) );
    clipNode->addChild(m_background2);

    return true;
}

// shift the background sprites on every frame update
//
// delta [in] - time since last update?
void BackgroundRLayer::UpdateLayer(float delta)
{
    // if first background is off the screen, place it behind the second background
    if ( (m_background1->getPosition().x - m_background1->boundingBox().size.width/2) > getContentSize().width )
    {
        m_background1->setPosition( ccp(m_background2->getPosition().x - m_background1->boundingBox().size.width,
                                                                                   m_background1->getPosition().y) );
    }

    // if second background is off the screen, place it behind the first background
    if ( (m_background2->getPosition().x - m_background2->boundingBox().size.width/2) > getContentSize().width )
    {
        m_background2->setPosition( ccp(m_background1->getPosition().x - m_background2->boundingBox().size.width,
                                                                                   m_background2->getPosition().y) );
    }

    // shift the backgrounds to the right by the velocity amount
    m_background1->setPosition( ccp(m_background1->getPosition().x + VELOCITY*delta, m_background1->getPosition().y) );
    m_background2->setPosition( ccp(m_background2->getPosition().x + VELOCITY*delta, m_background2->getPosition().y) );
}
