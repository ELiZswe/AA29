// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYMUSIC/Action_PLAYMUSIC.h"

UAction_PLAYMUSIC::UAction_PLAYMUSIC()
{
	//Transition = 3;
	bAffectAllPlayers = true;
	ActionString = "play song";
}

bool UAction_PLAYMUSIC::InitActionFor(AScriptedController* C)
{
	/*
	local PlayerController p;
	local Controller A;
	if (bAffectAllPlayers)
	{
		A = C.Level.ControllerList;
		if (A != None)
		{
			if (A.IsA('PlayerController'))
			{
				PlayerController(A).ClientSetMusic(Song, Transition);
			}
			A = A.nextController;
		}
	}
	else
	{
		p = PlayerController(C.GetInstigator().Controller);
		if (p == None)
		{
			return false;
		}
		p.ClientSetMusic(Song, Transition);
	}
	*/
	return false;
}
FString UAction_PLAYMUSIC::GetActionString()
{
	//Return ActionString @ Song;
	return "";    //FAKE   /ELiZ

}
