// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_SetPhysics/ACTION_SetPhysics.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_SetPhysics::UACTION_SetPhysics()
{
	ActionString = "change physics to ";
}

bool UACTION_SetPhysics::InitActionFor(AScriptedController* C)
{
	//C.GetInstigator().SetPhysics(NewPhysicsMode);
	return false;
}
FString UACTION_SetPhysics::GetActionString()
{
	//return ActionString @ NewPhysicsMode;
	return "";    //FAKE   /ELiZ
}
