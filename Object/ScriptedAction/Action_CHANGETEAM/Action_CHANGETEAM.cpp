// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_CHANGETEAM/Action_CHANGETEAM.h"

UAction_CHANGETEAM::UAction_CHANGETEAM()
{
	ActionString = "Change Team";
}

bool UAction_CHANGETEAM::InitActionFor(AScriptedController* C)
{
	/*
	local PlayerReplicationInfo p;
	if (C.PlayerReplicationInfo == nullptr)
	{
		p = C.Spawn(Class'PlayerReplicationInfo', C, , C.Pawn.Location, C.Pawn.Rotation);
		if (p == nullptr)
		{
			return false;
		}
		C.PlayerReplicationInfo = p;
		C.Pawn.PlayerReplicationInfo = p;
		p = nullptr;
	}
	C.bIsPlayer = true;
	C.Level.Game.GameReplicationInfo.Teams[Team].AddToTeam(C);
	*/
	return false;
}
