// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/SceneSubtitles/SceneSubtitles.h"

ASceneSubtitles::ASceneSubtitles()
{
	CurrentIndex = -1;
	//bStatic = true;
	//bNoDelete = true;
}

//native final Function ProcessEvent(ESST_Mode Mode);
/*
void ASceneSubtitles::ProcessEvent(ESST_Mode Mode)
{
}
*/

FString ASceneSubtitles::GetSubTitles()
{
	/*
	if (CurrentIndex >= SubTitles.Length)
	{
		CurrentIndex = -1;
	}
	if (CurrentIndex >= 0)
	{
		return SubTitles[CurrentIndex];
	}
	*/
	return "";
}

void ASceneSubtitles::Reset()
{
	Super::Reset();
	CurrentIndex = -1;
}
