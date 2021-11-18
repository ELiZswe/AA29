// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_PLAYLOCALSOUND/Action_PLAYLOCALSOUND.h"

UAction_PLAYLOCALSOUND::UAction_PLAYLOCALSOUND()
{
	ActionString = "play sound";
}

bool UAction_PLAYLOCALSOUND::InitActionFor(UScriptedController* C)
{
	/*
	local PlayerController p;
	ForEach C.DynamicActors(Class'PlayerController', p)
	{
		p.ClientPlaySound(Sound);
	}
	*/
	return false;
}
FString UAction_PLAYLOCALSOUND::GetActionString()
{
	//Return ActionString @ Sound;
	return "";    //FAKE   /ELiZ
}