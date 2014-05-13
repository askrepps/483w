#include "LevelData.h"

LevelData::LevelData()
{
	this->InitWithDefaults();
}

LevelData::~LevelData()
{

}

void LevelData::InitWithDefaults()
{
	m_numSamples = 410000;

	m_sampleRate = 44100;
	srand(time(NULL));
	for(int i = 0; i < NUM_OBSTACLES; i++)
	{
		SoundEvent event;
		event.InitWithSample((i+1)*44100, rand() % 4 );
		Events.push_back(event);
	}

	this->SetStats();

	for(std::vector<SoundEvent>::iterator it = Events.begin(); it != Events.end(); ++it)
	{
		(*it).SetAttributesWithQ1(m_q1Freq, m_medianFreq, m_q3Freq);
	}
}

void LevelData::SetStats()
{
	std::vector<float> freqs;
	for(std::vector<SoundEvent>::iterator it = Events.begin(); it != Events.end(); ++it)
	{
		freqs.push_back((*it).GetFreq());
	}

	std::sort(freqs.begin(), freqs.end());

	unsigned int median = freqs.size() / 2;
	unsigned int q1 = median / 2;
	unsigned int q3 = q1 + median;

	m_q1Freq = freqs[q1];
	m_medianFreq = freqs[median];
	m_q3Freq = freqs[q3];
}

