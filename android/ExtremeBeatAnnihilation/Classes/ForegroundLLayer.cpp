#include "ForegroundLLayer.h"

using namespace cocos2d;

// externs defined in Global.h
extern std::vector<Obstacle*> Left_Obstacles;
extern bool Is_Single_Player;      // Are we playing in single player?
extern int	Player_One_Score;      // Score for player one (or the score for single player)
extern int 	Player_Two_Score;	   // Score for player two (for multiplayer)

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

    // create the clip node and add it
    m_clipNode = new ClipNode();
    m_clipNode->autorelease();
    m_clipNode->setPosition(0, 0);
    m_clipNode->setClipsToBounds(true);
    m_clipNode->setClippingRegion( CCRect(0, 0, layerSize.width, layerSize.height) );
	addChild(m_clipNode);

    // create the player and add it
    m_player = PlayerL::create();
    m_player->setPosition( ccp(layerSize.width/4, layerSize.height * PLAYER_Y_POS) );
    m_clipNode->addChild(m_player);

    // mark the next call to update as the first
    m_firstUpdate = true;

    // enable screen touches to be detected
    setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);

    return true;
}

// handles touches to the screen
//
// touch [in] - info of the touch that occurred
// event [in] - ?
void ForegroundLLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    CCSize size           = CCDirector::sharedDirector()->getWinSize();
    CCRect leftTouchBound = CCRectMake(0, 0, size.width * POS_HALF_SCREEN, size.height);

    // user swiped left side of screen
    if(leftTouchBound.containsPoint(touch->getStartLocation()))
    {
        if(touch->getLocation().y - touch->getStartLocation().y >= 0)  // swiped up, so left player jump
        {
            m_player->Jump();
        }
        else                                         // swiped down, so left player slide
        {
            m_player->Slide();
        }
    }
}

// update movement of the player and obstacles in the layer and check for collisions
//
// delta [in] - time since the last update
void ForegroundLLayer::UpdateLayer(float delta)
{
	CCSize size         = CCDirector::sharedDirector()->getWinSize();   // size of the screen window
	CCRect playerRect   = m_player->boundingBox();        // bounding rectangle of player
	CCRect obstacleRect;                                  // bounding rectangle of an obstacle

	// scale the player on the first update; has to be done here as the init doesn't have the bounding
	//   box set yet
	if(m_firstUpdate)
	{
	    m_firstUpdate = false;
	    m_player->setScale(size.height * PLAYER_SCALE / playerRect.size.height);
	}

	// Update the locations of each, and remove as need
	for(std::vector<Obstacle*>::size_type i = 0; i != Left_Obstacles.size(); ++i)
	{
		if(Left_Obstacles[i])
		{
			Left_Obstacles[i]->setPosition(ccp(Left_Obstacles[i]->getPosition().x - VELOCITY*delta,
											                     Left_Obstacles[i]->getPosition().y));
		}

		// Collision detection
		if(m_player->CanCollide())
		{
			obstacleRect = Left_Obstacles[i]->boundingBox();

			// Collision occured, deduct points and flag as can't collide
			if(obstacleRect.intersectsRect(playerRect))
			{
				m_player->Blink();

				if(Is_Single_Player)
				{
					Player_One_Score += SINGLE_PLAYER_DEDUCTION;
				}
				else
				{
					Player_One_Score += MULTI_PLAYER_DEDUCTION;
				}
			}
		}
	}

	for(std::vector<Obstacle*>::size_type i = 0; i != Left_Obstacles.size();)
	{
		if(Left_Obstacles[i])
		{
			if(Left_Obstacles[i]->getPosition().x > size.width + OFFSET)
			{
                Left_Obstacles.erase(Left_Obstacles.begin() + i);
			}
			else
			{
				++i;
			}
		}
	}
}

// Spawns a sliding obstacle
void ForegroundLLayer::SpawnSlideObstacle(void)
{
	CCSize    size          = CCDirector::sharedDirector()->getWinSize();
	Obstacle* slideObstacle = new Obstacle();

	slideObstacle->InitWithPositionAndType(size.width + OFFSET, SLIDING_OBSTACLE);
	slideObstacle->setScale(size.height * SLIDE_OBSTACLE_SCALE / slideObstacle->boundingBox().size.height);
	m_clipNode->addChild(slideObstacle);
	CC_SAFE_RETAIN(slideObstacle);
	Left_Obstacles.push_back(slideObstacle);
}

// Spawn a jumping obstacle
void ForegroundLLayer::SpawnJumpObstacle(void)
{
	CCSize    size         = CCDirector::sharedDirector()->getWinSize();
	Obstacle* jumpObstacle = new Obstacle();

	m_clipNode->addChild(jumpObstacle);
	jumpObstacle->InitWithPositionAndType(size.width + OFFSET, JUMPING_OBSTACLE);
	jumpObstacle->setScale(size.height * JUMP_OBSTACLE_SCALE / jumpObstacle->boundingBox().size.height);
	CC_SAFE_RETAIN(jumpObstacle);
	Left_Obstacles.push_back(jumpObstacle);
}
