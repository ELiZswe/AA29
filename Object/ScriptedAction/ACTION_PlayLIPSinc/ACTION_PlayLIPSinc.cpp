// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_PlayLIPSinc/ACTION_PlayLIPSinc.h"

UACTION_PlayLIPSinc::UACTION_PlayLIPSinc()
{
	Volume = 1;
	Radius = 80;
	Pitch = 1;
	ActionString = "Play LIPSinc";
}

bool UACTION_PlayLIPSinc::InitActionFor(UScriptedController* C)
{
	//C.Pawn.PlayLIPSincAnim(LIPSincAnimName, Volume, Radius, Pitch);
	return false;
}
FString UACTION_PlayLIPSinc::GetActionString()
{
	return ActionString;
}