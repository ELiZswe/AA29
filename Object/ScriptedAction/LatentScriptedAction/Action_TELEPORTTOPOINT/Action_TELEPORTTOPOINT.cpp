// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_TELEPORTTOPOINT/Action_TELEPORTTOPOINT.h"

UAction_TELEPORTTOPOINT::UAction_TELEPORTTOPOINT()
{

}


bool UAction_TELEPORTTOPOINT::InitActionFor(UScriptedController* C)
{
	/*
	local Pawn p;
	Dest = C.SequenceScript.GetMoveTarget();
	if (DestinationTag != 'None')
	{
		ForEach C.AllActors(Class'Actor', Dest, DestinationTag)
		{
		}
	}
	p = C.GetInstigator();
	p.SetLocation(Dest.Location);
	p.SetRotation(Dest.Rotation);
	p.OldRotYaw = p.Rotation.Yaw;
	if (bPlaySpawnEffect)
	{
		p.PlayTeleportEffect(False, True);
	}
	*/
	return false;
}