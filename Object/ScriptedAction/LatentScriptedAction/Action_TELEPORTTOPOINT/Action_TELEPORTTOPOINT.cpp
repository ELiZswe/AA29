// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_TELEPORTTOPOINT/Action_TELEPORTTOPOINT.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_TELEPORTTOPOINT::UAction_TELEPORTTOPOINT()
{

}

bool UAction_TELEPORTTOPOINT::InitActionFor(AScriptedController* C)
{
	APawn* p = nullptr;
	/*
	Dest = C.SequenceScript.GetMoveTarget();
	if (DestinationTag != "None")
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
		p.PlayTeleportEffect(false, true);
	}
	*/
	return false;
}
