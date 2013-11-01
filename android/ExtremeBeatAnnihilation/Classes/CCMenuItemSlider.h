/****************************************************************************
Copyright (c) Sonic Zhao | weibo:http://weibo.com/transong
Objc version authro pmanna | links:http://www.cocos2d-iphone.org/wiki/doku.php/tips:slider_widget
*/

#ifndef __CCMENU_ITEM_SLIDER_H__
#define __CCMENU_ITEM_SLIDER_H__

#include "CCMenu.h"
#include "CCLabelTTF.h"

using namespace cocos2d;

class CCMenuItemSlider : public CCMenuItem, public CCRGBAProtocol
{

public:
	//properties
	void setMinValue(float minV){ m_minValue = minV; }
	void setMaxValue(float maxV){ m_maxValue = maxV; }
	void setValue(float v);

	float getMinValue(){ return m_minValue; }
	float getMaxValue(){ return m_maxValue; }
	float getValue(){ return m_value; }
	CCNode* getKnobImage(){ return m_knobImage; }
    //
    
	void selected()
	{
		m_knobImage->convertToRGBAProtocol()->setColor(ccc3(150,150,150));
	}
	void unselected()
	{
		m_knobImage->convertToRGBAProtocol()->setColor(ccc3(255,255,255));
	}
	void setIsEnabled(bool bEnabled)
	{

		m_bIsEnabled = bEnabled;
		if(bEnabled)
			setColor(ccc3(255,255,255));
		else
			setColor(ccc3(200,200,200));
	}

	//RGBAProtocol
    void setColor(const ccColor3B& color);
    const ccColor3B& getColor(void);

	GLubyte getOpacity(void);
    void setOpacity(GLubyte opacity);
    //
    //the reason to use CCNode instead of string is it's efficient to generate a ccsprite from a spritesheet
	static CCMenuItemSlider* itemFromNormalSprite(CCNode* trackSprite, CCNode* knobSprite);	
	static CCMenuItemSlider* itemFromNormalSprite(CCNode* trackSprite, CCNode* knobSprite, SelectorProtocol* target, SEL_MenuHandler selector);	
	bool initFromNormalSprite(CCNode* trackSprite, CCNode* knobSprite, SelectorProtocol* target, SEL_MenuHandler selector);

	void dragToPoint(CCPoint aPoint);
protected:
private:
	float			m_minValue;
	float			m_maxValue;
	float			m_value;

	bool			m_isVertical;
    
	CCNode*         m_trackImage;
	CCNode*         m_knobImage;

	//you can remove it if you like
	CCLabelTTF*     m_labelValue;

};

class CCMenuSlider : public CCMenu
{
public:
    
	static CCMenuSlider* menuWithItems(CCMenuItemSlider* item, ...);
	static CCMenuSlider*menuWithItem(CCMenuItemSlider* item);
    
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);

	CCMenuItemSlider* itemForTouch(CCTouch * touch);
protected:
private:
};

#endif //__CCMENU_ITEM_SLIDER_H__