// All the original content belonged to the US Army

#include "AA29/Object/MatObject/MatSubAction/SubActionGameSpeed/SubActionGameSpeed.h"

USubActionGameSpeed::USubActionGameSpeed()
{
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionGameSpeed_Mat.SubActionGameSpeed_Mat'"), NULL, LOAD_None, NULL);
	Desc = "Game Speed";
}
