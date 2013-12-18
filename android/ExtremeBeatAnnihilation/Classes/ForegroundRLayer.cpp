#include "ForegroundRLayer.h"

using namespace cocos2d;

// externs defined in Global.h
extern std::vector<Obstacle*> Right_Obstacles;

// Initialize the right player's foreground (obstacles, player) for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool ForegroundRLayer::init()
{
    CCSize screenSize;                         // the size of the window
    CCSize layerSize;                          // size of this layer

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

    // create the player and add it
    m_player = PlayerR::create();
    m_player->setPosition( ccp(layerSize.width/4 * 3, layerSize.height * PLAYER_Y_POS) );
    m_player->setScale(PLAYER_SCALE);
    addChild(m_player);

    return true;
}

void ForegroundRLayer::UpdateLayer(float delta)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//Update the locations of each, and remove as need
	for(std::vector<Obstacle*>::size_type i = 0; i != Right_Obstacles.size();)
	{
		if(Right_Obstacles[i])
		{
			Right_Obstacles[i]->setPosition(ccp(Right_Obstacles[i]->getPosition().x + OBSTACLE_VELOCITY, Right_Obstacles[i]->getPosition().y));

			if(Right_Obstacles[i]->getPosition().x > size.width + OFFSET)
			{
					Obstacle* temp = Right_Obstacles[i];
					Right_Obstacles.erase(Right_Obstacles.begin() + i);
					CC_SAFE_DELETE(temp);
			}
			else
			{
				++i;
			}
		}
	}

	// Collision detection here
}

// Needs description
//
// touches [in] -
// event   [in] -
void ForegroundRLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    CCSize        size            = CCDirector::sharedDirector()->getWinSize();
    CCSetIterator it              = touches->begin();
    CCPoint       currentLocation;
    CCTouch*      touch;
    CCRect*       topRight        = new CCRect(size.width / 2, 0, size.width / 2, size.height/2);
    CCRect*       bottomRight     = new CCRect(size.width / 2, size.height/2, size.width / 2, size.height / 2);

    for(int i = 0; i < touches->count(); i++)
    {
        touch = (CCTouch*)(*it);
        if(touch)
        {
			currentLocation = touch->getLocationInView();

			if(bottomRight->containsPoint(currentLocation))          // right player slide
			{
				 m_player->Slide();
			}
			else if(topRight->containsPoint(currentLocation))        // right player jump
			{
				m_player->Jump();
			}
        }
        it++;
    }
}

// Spawns a sliding obstacle
void ForegroundRLayer::SpawnSlideObstacle(void)
{
	Obstacle* slideObstacle = new Obstacle();
	slideObstacle->InitWithPositionAndType(-OFFSET, SLIDING_OBSTACLE);
	addChild(slideObstacle);
	CC_SAFE_RETAIN(slideObstacle);
	Right_Obstacles.push_back(slideObstacle);
}

// Spawn a jumping obstacle
void ForegroundRLayer::SpawnJumpObstacle(void)
{;
	Obstacle* jumpObstacle = new Obstacle();

	jumpObstacle->InitWithPositionAndType(-OFFSET, JUMPING_OBSTACLE);
	addChild(jumpObstacle);
	CC_SAFE_RETAIN(jumpObstacle);
	Right_Obstacles.push_back(jumpObstacle);
}
