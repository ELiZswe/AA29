// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_DISPLAYMESSAGE/Action_DISPLAYMESSAGE.h"

UAction_DISPLAYMESSAGE::UAction_DISPLAYMESSAGE()
{
	messagetype = "CriticalEvent";
	ActionString = "display message";
}

bool UAction_DISPLAYMESSAGE::InitActionFor(UScriptedController* C)
{
	/*
	local Pawn p;
	p = C.GetInstigator();
	if (bBroadcast)
	{
		C.Level.Game.Broadcast(p, Message, messagetype);
	}
	else
	{
		if (p != None)
		{
			p.ClientMessage(Message, messagetype);
		}
	}
	*/
	return false;
}
FString UAction_DISPLAYMESSAGE::GetActionString()
{
	//Return ActionString @ Message;
	return "";    //FAKE   /ELiZ
}