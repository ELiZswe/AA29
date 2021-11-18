// All the original content belonged to the US Army


#include "AA29/Object/MatObject/MatSubAction/SubActionCameraEffect/SubActionCameraEffect.h"

USubActionCameraEffect::USubActionCameraEffect()
{
	EndAlpha = 1;
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionFade.SubActionFade'"), NULL, LOAD_None, NULL);
	Desc = "Camera effect";
}