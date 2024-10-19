#include "SoundManager.h"

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{

}

/// <summary>
/// Ÿ��ƲBGM
/// </summary>
void SoundManager::PlayTitleBGM()
{
	PlaySound(TEXT("..\\TitleBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// ����BGM
/// </summary>
void SoundManager::PlayVillageBGM()
{
	PlaySound(TEXT("..\\VillageBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// ���ϸ� ����BGM
/// </summary>
void SoundManager::PlayPoketmonCenterBGM()
{
	PlaySound(TEXT("..\\PoketmonCenterBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// ����BGM
/// </summary>
void SoundManager::PlayBattleBGM()
{
	PlaySound(TEXT("..\\Battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// ü����BGM
/// </summary>
void SoundManager::PlayChampionBGM()
{
	PlaySound(TEXT("..\\ChampionBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// ���ϸ� ġ��BGM
/// </summary>
void SoundManager::PlayPoketmonHeal()
{
	PlaySound(TEXT("..\\PoketmonHeal.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// �¸� BGM
/// </summary>
void SoundManager::PlayVitory()
{
	PlaySound(TEXT("..\\Vitory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
