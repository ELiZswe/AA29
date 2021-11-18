// All the original content belonged to the US Army


#include "AA29/Object/MatObject/MatSubAction/SubActionTrigger/SubActionTrigger.h"

USubActionTrigger::USubActionTrigger()
{
	Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionTrigger.SubActionTrigger'"), NULL, LOAD_None, NULL);
	Desc = "Trigger";
}