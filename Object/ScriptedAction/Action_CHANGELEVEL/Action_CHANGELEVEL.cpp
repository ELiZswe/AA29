// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_CHANGELEVEL/Action_CHANGELEVEL.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_CHANGELEVEL::UAction_CHANGELEVEL()
{
	ActionString = "Change level";
}

bool UAction_CHANGELEVEL::InitActionFor(AScriptedController* C)
{
	if (bShowLoadingMessage)
	{
		//C->Level->ServerTravel(URL, false);
	}
	else
	{
		//C->Level->ServerTravel(URL + "?quiet", false);
	}
	return true;
}

FString UAction_CHANGELEVEL::GetActionString()
{
	return ActionString;
}
