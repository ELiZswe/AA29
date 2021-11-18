// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_CHANGELEVEL/Action_CHANGELEVEL.h"

UAction_CHANGELEVEL::UAction_CHANGELEVEL()
{
	ActionString = "Change level";
}

bool UAction_CHANGELEVEL::InitActionFor(UScriptedController* C)
{
	/*
	if (bShowLoadingMessage)
	{
		C.Level.ServerTravel(URL, False);
	}
	else
	{
		C.Level.ServerTravel(URL $ "?quiet", False);
	}
	*/
	return true;
}
FString UAction_CHANGELEVEL::GetActionString()
{
	return ActionString;
}