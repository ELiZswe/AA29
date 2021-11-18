// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_SubTitles/ACTION_SubTitles.h"

UACTION_SubTitles::UACTION_SubTitles()
{
	ActionString = "SubTitles";
}




bool UACTION_SubTitles::InitActionFor(UScriptedController* C)
{
	//C.Level.GetLocalPlayerController().myHUD.SubTitles.ProcessEvent(SubTitleMode);
	return false;
}
FString UACTION_SubTitles::GetActionString()
{
	return ActionString;
}
