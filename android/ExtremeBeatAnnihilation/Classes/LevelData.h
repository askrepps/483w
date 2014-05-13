#ifndef _LEVEL_DATA_H
#define _LEVEL_DATA_H

#include "Global.h"
#include <algorithm>    // std::sort

extern std::vector<SoundEvent> Events;

typedef struct
{
	unsigned int  sample;
	float amp;
	float freq;
} Peak;

class LevelData
{
public:
	LevelData();
	~LevelData();
	void InitWithDefaults(void);
private:
	void SetStats();
	unsigned int m_numSamples;
	float m_q1Freq;
	float m_medianFreq;
	float m_q3Freq;
	int m_sampleRate;
};

#endif // _LEVEL_DATA_H
