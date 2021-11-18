// All the original content belonged to the US Army


#include "AA29/Object/MatObject/MatSubAction/SubActionCameraShake/SubActionCameraShake.h"

USubActionCameraShake::USubActionCameraShake()
{
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionCameraShake.SubActionCameraShake'"), NULL, LOAD_None, NULL);
	Desc = "Shake";
}