// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_LocalizedMessage/ACTION_LocalizedMessage.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_LocalizedMessage::UACTION_LocalizedMessage()
{
	//MessageClass = class'GamePlay.ActionMessage';
	ActionString = "Localized Message";
}

bool UACTION_LocalizedMessage::InitActionFor(AScriptedController* C)
{
	//C.BroadcastLocalizedMessage(MessageClass, MessageNum, None, None, None);
	return false;
}

FString UACTION_LocalizedMessage::GetActionString()
{
	//return ActionString @ MessageClass.GetString(MessageNum);
	return "";    //FAKE   /ELiZ
}
