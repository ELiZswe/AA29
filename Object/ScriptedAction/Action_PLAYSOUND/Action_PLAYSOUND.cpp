// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_PLAYSOUND/Action_PLAYSOUND.h"

UAction_PLAYSOUND::UAction_PLAYSOUND()
{
	Volume = 1;
	Pitch = 1;
	bAttenuate = true;
	ActionString = "play sound";
}

bool UAction_PLAYSOUND::InitActionFor(UScriptedController* C)
{
	/*
	if (Sound != None)
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