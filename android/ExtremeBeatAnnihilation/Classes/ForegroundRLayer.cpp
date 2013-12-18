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
    m_player->setScale(PLAYER_SCALE);
    m_clipNode->addChild(m_player);

    Jump_Y_Pos  = m_player->getPosition().y - m_player->getContentSize().height / 2 - SLIDING_OFFSET;
    Slide_Y_Pos = m_player->getPosition().y + m_player->getContentSize().height / 2 + JUMPING_OFFSET;

    m_delta = 0.0;

    return true;
}

void ForegroundRLayer::UpdateLayer(float delta)
{
	CCRect obstacleRect;
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCRect playerRect = CCRectMake(
										m_player->getPosition().x - (m_player->getContentSize().width/2),
										m_player->getPosition().y - (m_player->getContentSize().height/2),
										m_player->getContentSize().width,
										m_player->getContentSize().height
								  );

	//Update the locations of each, and remove as need
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
			obstacleRect = CCRectMake(
											Right_Obstacles[i]->getPosition().x - (Right_Obstacles[i]->getContentSize().width/2),
											Right_Obstacles[i]->getPosition().y - (Right_Obstacles[i]->getContentSize().height/2),
											Right_Obstacles[i]->getContentSize().width,
											Right_Obstacles[i]->getContentSize().height
									  );

			// Collision occured, deduct points and flag as can't collide
			if(obstacleRect.intersectsRect(playerRect))
			{
				// Hit an object, deduct score
				m_player->Blink();
				if(Is_Single_Player)
					Player_One_Score += SINGLE_PLAYER_DEDUCTION;
				else
					Player_Two_Score += MULTI_PLAYER_DEDUCTION;
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
	m_clipNode->addChild(slideObstacle);
	CC_SAFE_RETAIN(slideObstacle);
	Right_Obstacles.push_back(slideObstacle);
}

// Spawn a jumping obstacle
void ForegroundRLayer::SpawnJumpObstacle(void)
{;
	Obstacle* jumpObstacle = new Obstacle();

	jumpObstacle->InitWithPositionAndType(-OFFSET, JUMPING_OBSTACLE);
	m_clipNode->addChild(jumpObstacle);
	CC_SAFE_RETAIN(jumpObstacle);
	Right_Obstacles.push_back(jumpObstacle);
}
