// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYLOCALSOUND/Action_PLAYLOCALSOUND.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_PLAYLOCALSOUND::UAction_PLAYLOCALSOUND()
{
	ActionString = "play sound";
}

bool UAction_PLAYLOCALSOUND::InitActionFor(AScriptedController* C)
{
	APlayerController* p = nullptr;
	/*
	ForEach C.DynamicActors(Class'PlayerController', p)
	{
		p.ClientPlaySound(Sound);
	}
	*/
	return false;
}

FString UAction_PLAYLOCALSOUND::GetActionString()
{
	//return ActionString @ Sound;
	return "";    //FAKE   /ELiZ
}
