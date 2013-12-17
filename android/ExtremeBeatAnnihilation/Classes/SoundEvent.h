#ifndef __SOUND_EVENT_H__
#define __SOUND_EVENT_H__

#include "cocos2d.h"

typedef enum { LEFT, RIGHT } Side;
typedef enum { JUMP, SLIDE } Type;

class SoundEvent : public cocos2d::CCObject
{
public:
    void InitWithSample(unsigned int s, float f);
    void SetAttributesWithQ1(float q1Freq, float medianFreq, float q3Freq);
    float GetFreq(void);
private:
    unsigned int m_sample;           // need description
    float        m_freq;             // need description
    Side         m_side;             // need description
    Type         m_type;             // need description
};

#endif // __SOUND_EVENT_H__
