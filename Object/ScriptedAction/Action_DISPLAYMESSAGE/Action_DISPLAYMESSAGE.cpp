// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_DISPLAYMESSAGE/Action_DISPLAYMESSAGE.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_DISPLAYMESSAGE::UAction_DISPLAYMESSAGE()
{
	messagetype = "CriticalEvent";
	ActionString = "display message";
}

bool UAction_DISPLAYMESSAGE::InitActionFor(AScriptedController* C)
{
	APawn* p = nullptr;
	/*
	p = C.GetInstigator();
	if (bBroadcast)
	{
		C.Level.Game.Broadcast(p, Message, messagetype);
	}
	else
	{
		if (p != nullptr)
		{
			p.ClientMessage(Message, messagetype);
		}
	}
	*/
	return false;
}
FString UAction_DISPLAYMESSAGE::GetActionString()
{
	//return ActionString @ Message;
	return "";    //FAKE   /ELiZ
}
