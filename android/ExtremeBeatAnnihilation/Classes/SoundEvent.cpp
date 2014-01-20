#include "SoundEvent.h"

using namespace cocos2d;

// needs description
//
// s [in] - ?
// f [in] - ?
void SoundEvent::InitWithSample(unsigned int s, float f)
{
    m_sample = s;
    m_freq   = f;
}

// needs description
//
// q1Freq     [in] - ?
// medianFreq [in] - ?
// q3Freq     [in] - ?
void SoundEvent::SetAttributesWithQ1(float q1Freq, float medianFreq, float q3Freq)
{
    if (m_freq <= q1Freq)                // needs description
    {
        m_side = LEFT;
        m_type = SLIDE;
    }
    else if (m_freq <= medianFreq)       // needs description
    {
        m_side = LEFT;
        m_type = JUMP;
    }
    else if (m_freq <= q3Freq)           // needs description
    {
        m_side = RIGHT;
        m_type = SLIDE;
    }
    else                                 // needs description
    {
        m_side = RIGHT;
        m_type = JUMP;
    }
}

float SoundEvent::GetFreq(void)
{
	return m_freq;
}
