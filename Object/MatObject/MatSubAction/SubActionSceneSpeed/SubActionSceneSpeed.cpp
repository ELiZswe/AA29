// All the original content belonged to the US Army

#include "AA29/Object/MatObject/MatSubAction/SubActionSceneSpeed/SubActionSceneSpeed.h"

USubActionSceneSpeed::USubActionSceneSpeed()
{
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionSceneSpeed_Mat.SubActionSceneSpeed_Mat'"), NULL, LOAD_None, NULL);
	Desc = "Scene Speed";
}
