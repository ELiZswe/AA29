// All the original content belonged to the US Army

#include "AA29/Object/MatObject/MatSubAction/SubActionFOV/SubActionFOV.h"

USubActionFOV::USubActionFOV()
{
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionFOV_Mat.SubActionFOV_Mat'"), NULL, LOAD_None, NULL);
	Desc = "FOV";
}
