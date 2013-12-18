#include "ForegroundLLayer.h"

using namespace cocos2d;

// externs defined in Global.h
extern std::vector<Obstacle*> Left_Obstacles;

// Initialize the left player's foreground (obstacles, player) for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool ForegroundLLayer::init()
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
    //   the left side of the screen
    layerSize.setSize(screenSize.width * POS_HALF_SCREEN, screenSize.height);
    setContentSize(layerSize);
    setPosition(0, 0);

    // create the player and add it
    m_player = PlayerL::create();
    m_player->setPosition( ccp(layerSize.width/4, layerSize.height * PLAYER_Y_POS) );
    m_player->setScale(PLAYER_SCALE);
    addChild(m_player);

    return true;
}

// handles touches in the foreground
//
// touches [in] -
// event   [in] -
void ForegroundLLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    CCSize        size            = CCDirector::sharedDirector()->getWinSize();
    CCSetIterator it              = touches->begin();
    CCPoint       currentLocation;
    CCTouch*      touch;
    CCRect*       topLeft         = new CCRect(0, 0, size.width / 2, size.height/2);
    CCRect*       bottomLeft      = new CCRect(0, size.height/2, size.width / 2, size.height / 2);

    for(int i = 0; i < touches->count(); i++)
    {
        touch = (CCTouch*)(*it);
        if(touch)
        {
			currentLocation = touch->getLocationInView();

			if(bottomLeft->containsPoint(currentLocation))        // left player slide
			{
				m_player->Slide();
			}
			else if(topLeft->containsPoint(currentLocation))      // left player jump
			{
				m_player->Jump();
			}
        }

        it++;
    }
}

void ForegroundLLayer::UpdateLayer(float delta)
{
	//Update the locations of each, and remove as need
	for(std::vector<Obstacle*>::size_type i = 0; i != Left_Obstacles.size();)
	{
		if(Left_Obstacles[i])
		{
			Left_Obstacles[i]->setPosition(ccp(Left_Obstacles[i]->getPosition().x - OBSTACLE_VELOCITY, Left_Obstacles[i]->getPosition().y));

			if(Left_Obstacles[i]->getPosition().x < -OFFSET)
			{
					Obstacle* temp = Left_Obstacles[i];
					Left_Obstacles.erase(Left_Obstacles.begin() + i);
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

// Spawns a sliding obstacle
void ForegroundLLayer::SpawnSlideObstacle(void)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	Obstacle* slideObstacle = new Obstacle();
	slideObstacle->InitWithPositionAndType(size.width + OFFSET, SLIDING_OBSTACLE);
	addChild(slideObstacle);
	CC_SAFE_RETAIN(slideObstacle);
	Left_Obstacles.push_back(slideObstacle);
}

// Spawn a jumping obstacle
void ForegroundLLayer::SpawnJumpObstacle(void)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	Obstacle* jumpObstacle = new Obstacle();
	addChild(jumpObstacle);
	jumpObstacle->InitWithPositionAndType(size.width + OFFSET, JUMPING_OBSTACLE);
	CC_SAFE_RETAIN(jumpObstacle);
	Left_Obstacles.push_back(jumpObstacle);
}
