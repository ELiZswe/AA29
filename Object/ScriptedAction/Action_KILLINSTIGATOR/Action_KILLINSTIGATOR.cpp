// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_KILLINSTIGATOR/Action_KILLINSTIGATOR.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/DamageType/Crushed/Crushed.h"

UAction_KILLINSTIGATOR::UAction_KILLINSTIGATOR()
{
	//DamageType = ACrushed::StaticClass()
	ActionString = "Damage instigator";
}

bool UAction_KILLINSTIGATOR::InitActionFor(AScriptedController* C)
{
	//C.GetInstigator().Died(None, DamageType, C.Instigator.Location);
	return false;
}
FString UAction_KILLINSTIGATOR::GetActionString()
{
	//return ActionString @ DamageType;
	return "";     //FAKE   /ELiZ
}
