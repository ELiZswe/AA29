// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_SubTitles/ACTION_SubTitles.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_SubTitles::UACTION_SubTitles()
{
	ActionString = "SubTitles";
}

bool UACTION_SubTitles::InitActionFor(AScriptedController* C)
{
	//C.Level.GetLocalPlayerController().myHUD.SubTitles.ProcessEvent(SubTitleMode);
	return false;
}
FString UACTION_SubTitles::GetActionString()
{
	return ActionString;
}
