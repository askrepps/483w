#include "ForegroundRLayer.h"

using namespace cocos2d;

// externs defined in Global.h
extern std::vector<Obstacle*> Right_Obstacles;
extern bool Is_Single_Player;      // Are we playing in single player?
extern int	Player_One_Score;      // Score for player one (or the score for single player)
extern int 	Player_Two_Score;	   // Score for player two (for multiplayer)
extern int  Jump_Y_Pos;            // The jumping position
extern int  Slide_Y_Pos;           // The sliding position

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

    // create the clip node and add it
    m_clipNode = new ClipNode();
    m_clipNode->autorelease();
    m_clipNode->setPosition(0, 0);
    m_clipNode->setClipsToBounds(true);
    m_clipNode->setClippingRegion( CCRect(screenSize.width, 0, layerSize.width, layerSize.height) );
	addChild(m_clipNode);

    // create the player and add it
    m_player = PlayerR::create();
    m_player->setPosition( ccp(layerSize.width/4 * 3, layerSize.height * PLAYER_Y_POS) );
    m_clipNode->addChild(m_player);

    Jump_Y_Pos  = m_player->getPosition().y - m_player->getContentSize().height / 2 - SLIDING_OFFSET;
    Slide_Y_Pos = m_player->getPosition().y + m_player->getContentSize().height / 2 + JUMPING_OFFSET;

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
void ForegroundRLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    CCSize size            = CCDirector::sharedDirector()->getWinSize();
    CCRect rightTouchBound = CCRectMake(size.width * POS_HALF_SCREEN, 0, size.width * POS_HALF_SCREEN, size.height);

    // user swiped right side of screen
    if(rightTouchBound.containsPoint(touch->getStartLocation()))
    {
        if(touch->getLocation().y - touch->getStartLocation().y >= 0) // swiped up, so right player jump
        {
            m_player->Jump();
        }
        else                                           // swiped down, so right player slide
        {
            m_player->Slide();
        }
    }
}

// update movement of the player and obstacles in the layer and check for collisions
//
// delta [in] - time since the last update
void ForegroundRLayer::UpdateLayer(float delta)
{
    CCSize size         = CCDirector::sharedDirector()->getWinSize();    // size of screen window
    CCRect playerRect   = m_player->boundingBox();             // the bounding rectangle of the player
	CCRect obstacleRect;                                       // the bounding rectangle of an obstacle

	// scale the player on the first update; has to be done here as the init doesn't have the bounding
    //   box set yet
    if(m_firstUpdate)
    {
        m_player->setScale(size.height * PLAYER_SCALE / playerRect.size.height);
        m_firstUpdate = false;
    }

	// Update the locations of each, and remove as need
	for(std::vector<Obstacle*>::size_type i = 0; i != Right_Obstacles.size(); ++i)
	{
		if(Right_Obstacles[i])
		{
			Right_Obstacles[i]->setPosition(ccp(Right_Obstacles[i]->getPosition().x + VELOCITY*delta,
												                  Right_Obstacles[i]->getPosition().y));
		}

		// Collision detection
		if(m_player->CanCollide())
		{
			obstacleRect = Right_Obstacles[i]->boundingBox();

			// Collision occured, deduct points and flag as can't collide
			if(obstacleRect.intersectsRect(playerRect))
			{
				// Hit an object, deduct score
				m_player->Blink();

				if(Is_Single_Player)
				{
					Player_One_Score += SINGLE_PLAYER_DEDUCTION;
				}
				else
				{
					Player_Two_Score += MULTI_PLAYER_DEDUCTION;
				}
			}
		}
	}

	for(std::vector<Obstacle*>::size_type i = 0; i != Right_Obstacles.size();)
	{
		if(Right_Obstacles[i])
		{
			if(Right_Obstacles[i]->getPosition().x > size.width + OFFSET)
			{
                Right_Obstacles.erase(Right_Obstacles.begin() + i);
			}
			else
			{
				++i;
			}
		}
	}
}

// Spawns a sliding obstacle
void ForegroundRLayer::SpawnSlideObstacle(void)
{
	Obstacle* slideObstacle = new Obstacle();
	slideObstacle->InitWithPositionAndType(-OFFSET, SLIDING_OBSTACLE);
	m_clipNode->addChild(slideObstacle);
	CC_SAFE_RETAIN(slideObstacle);
	Right_Obstacles.push_back(slideObstacle);
}

// Spawn a jumping obstacle
void ForegroundRLayer::SpawnJumpObstacle(void)
{
	Obstacle* jumpObstacle = new Obstacle();
	jumpObstacle->InitWithPositionAndType(-OFFSET, JUMPING_OBSTACLE);
	m_clipNode->addChild(jumpObstacle);
	CC_SAFE_RETAIN(jumpObstacle);
	Right_Obstacles.push_back(jumpObstacle);
}
