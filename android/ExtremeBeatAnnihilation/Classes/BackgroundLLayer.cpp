#include "BackgroundLLayer.h"

using namespace cocos2d;

// Initialize the left player's background for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool BackgroundLLayer::init()
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
    //   the left side of the screen
    layerSize.setSize(screenSize.width * POS_HALF_SCREEN, screenSize.height);
    setContentSize(layerSize);
    setPosition(0, 0);

    // create the clip node and add it
    clipNode = new ClipNode();
    clipNode->autorelease();
    clipNode->setPosition(0, 0);
    clipNode->setClipsToBounds(true);
    clipNode->setClippingRegion( CCRect(0, 0, layerSize.width, layerSize.height) );
    addChild(clipNode);

    // create and add the first background sprite
    m_background1 = CCSprite::create(BACKGROUND);
    m_background1->setPosition( ccp(0, screenSize.height * POS_HALF_SCREEN) );
    clipNode->addChild(m_background1);

    // create, position after first background, and add the second background
    m_background2 = CCSprite::create(BACKGROUND);
    m_background2->setPosition( ccp(m_background1->boundingBox().size.width, screenSize.height * POS_HALF_SCREEN) );
    clipNode->addChild(m_background2);

    return true;
}

// shift the background sprites on every frame update
//
// delta [in] - time since last update?
void BackgroundLLayer::update(float delta)
{
    CCSize size;                    // the size of the window

    // if first background is off the screen, place it in front of the second background
    if (m_background1->getPosition().x < -m_background1->boundingBox().size.width)
    {
        m_background1->setPosition( ccp(m_background2->getPosition().x + m_background2->boundingBox().size.width,
                                                                                      m_background1->getPosition().y) );
    }

    // if second background is off the screen, place it in front of the first background
    if (m_background2->getPosition().x < -m_background2->boundingBox().size.width)
    {
        m_background2->setPosition( ccp(m_background1->getPosition().x + m_background1->boundingBox().size.width,
                                                                                      m_background2->getPosition().y) );
    }

    // shift the backgrounds to the left by the velocity amount
    m_background1->setPosition( ccp(m_background1->getPosition().x - VELOCITY*delta, m_background1->getPosition().y) );
    m_background2->setPosition( ccp(m_background2->getPosition().x - VELOCITY*delta, m_background2->getPosition().y) );
}
