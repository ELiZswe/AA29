// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYSOUND/Action_PLAYSOUND.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_PLAYSOUND::UAction_PLAYSOUND()
{
	Volume = 1;
	Pitch = 1;
	bAttenuate = true;
	ActionString = "play sound";
}

bool UAction_PLAYSOUND::InitActionFor(AScriptedController* C)
{
	/*
	if (Sound != nullptr)
	{
		C.GetSoundSource().PlaySound(Sound, 3, Volume, True, , Pitch, bAttenuate);
	}
	*/
	return false;
}
FString UAction_PLAYSOUND::GetActionString()
{
	//return ActionString @ Sound;
	return "";    //FAKE   /ELiZ
}
