// All the original content belonged to the US Army

#include "AA29/Object/MatObject/MatSubAction/SubActionOrientation/SubActionOrientation.h"

USubActionOrientation::USubActionOrientation()
{
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionOrientation_Mat.SubActionOrientation_Mat'"), NULL, LOAD_None, NULL);
	Desc = "Orientation";
}
