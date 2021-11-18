// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_PLAYAMBIENTSOUND/Action_PLAYAMBIENTSOUND.h"

UAction_PLAYAMBIENTSOUND::UAction_PLAYAMBIENTSOUND()
{
	SoundVolume = 128;
	SoundPitch = 64;
	SoundRadius = 64;
	ActionString = "play ambient sound";

}

bool UAction_PLAYAMBIENTSOUND::InitActionFor(UScriptedController* C)
{
	/*
	if (AmbientSound != None)
	{
		C.SequenceScript.AmbientSound = AmbientSound;
		C.SequenceScript.SoundVolume = SoundVolume;
		C.SequenceScript.SoundPitch = SoundPitch;
		C.SequenceScript.SoundRadius = SoundRadius;
	}
	*/
	return false;
}

FString UAction_PLAYAMBIENTSOUND::GetActionString()
{
	//return ActionString @ AmbientSound;
	return "";    //FAKE   /ELiZ
}