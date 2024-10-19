#pragma once
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class SoundManager
{
private:

public:
	void PlayTitleBGM();
	void PlayVillageBGM();
	void PlayPoketmonCenterBGM();
	void PlayBattleBGM();
	void PlayChampionBGM();
	void PlayPoketmonHeal();
	void PlayVitory();

	SoundManager();
	~SoundManager();
};