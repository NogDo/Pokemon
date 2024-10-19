#include "SoundManager.h"

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{

}

/// <summary>
/// 타이틀BGM
/// </summary>
void SoundManager::PlayTitleBGM()
{
	PlaySound(TEXT("..\\TitleBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// 마을BGM
/// </summary>
void SoundManager::PlayVillageBGM()
{
	PlaySound(TEXT("..\\VillageBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// 포켓몬 센터BGM
/// </summary>
void SoundManager::PlayPoketmonCenterBGM()
{
	PlaySound(TEXT("..\\PoketmonCenterBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// 전투BGM
/// </summary>
void SoundManager::PlayBattleBGM()
{
	PlaySound(TEXT("..\\Battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// 체육관BGM
/// </summary>
void SoundManager::PlayChampionBGM()
{
	PlaySound(TEXT("..\\ChampionBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// 포켓몬 치료BGM
/// </summary>
void SoundManager::PlayPoketmonHeal()
{
	PlaySound(TEXT("..\\PoketmonHeal.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// 승리 BGM
/// </summary>
void SoundManager::PlayVitory()
{
	PlaySound(TEXT("..\\Vitory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
