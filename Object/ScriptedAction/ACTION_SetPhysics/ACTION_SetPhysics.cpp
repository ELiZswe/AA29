// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_SetPhysics/ACTION_SetPhysics.h"

UACTION_SetPhysics::UACTION_SetPhysics()
{
	ActionString = "change physics to ";
}



bool UACTION_SetPhysics::InitActionFor(UScriptedController* C)
{
	//C.GetInstigator().SetPhysics(NewPhysicsMode);
	return false;
}
FString UACTION_SetPhysics::GetActionString()
{
	//return ActionString @ NewPhysicsMode;
	return "";    //FAKE   /ELiZ
}