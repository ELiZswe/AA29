// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_CHANGETEAM/Action_CHANGETEAM.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"

UAction_CHANGETEAM::UAction_CHANGETEAM()
{
	ActionString = "Change Team";
}

bool UAction_CHANGETEAM::InitActionFor(AScriptedController* C)
{
	AAA2_PlayerState* p = nullptr;
	/*
	if (C.PlayerReplicationInfo == nullptr)
	{
		p = C.Spawn(APlayerReplicationInfo::StaticClass(), C, , C.Pawn->GetActorLocation(), C.Pawn.Rotation);
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
