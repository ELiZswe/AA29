// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_LocalizedMessage/ACTION_LocalizedMessage.h"

UACTION_LocalizedMessage::UACTION_LocalizedMessage()
{
	//MessageClass = class'GamePlay.ActionMessage';
	ActionString = "Localized Message";
}

bool UACTION_LocalizedMessage::InitActionFor(UScriptedController* C)
{
	//C.BroadcastLocalizedMessage(MessageClass, MessageNum, None, None, None);
	return false;
}

FString UACTION_LocalizedMessage::GetActionString()
{
	//Return ActionString @ MessageClass.GetString(MessageNum);
	return "";    //FAKE   /ELiZ
}