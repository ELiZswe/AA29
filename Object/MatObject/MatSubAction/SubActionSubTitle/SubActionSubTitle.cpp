// All the original content belonged to the US Army

#include "AA29/Object/MatObject/MatSubAction/SubActionSubTitle/SubActionSubTitle.h"

USubActionSubTitle::USubActionSubTitle()
{
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionTrigger_Mat.SubActionTrigger_Mat'"), NULL, LOAD_None, NULL);
	Desc = "SubTitle";
}
