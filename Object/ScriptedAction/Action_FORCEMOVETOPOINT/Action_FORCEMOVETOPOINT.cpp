// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_FORCEMOVETOPOINT/Action_FORCEMOVETOPOINT.h"

UAction_FORCEMOVETOPOINT::UAction_FORCEMOVETOPOINT()
{

}

bool UAction_FORCEMOVETOPOINT::InitActionFor(UScriptedController* C)
{
	/*
	Dest = C.SequenceScript.GetMoveTarget();
	if (DestinationTag != 'None')
	{
		ForEach C.AllActors(Class'Actor', Dest, DestinationTag)
		{
		}
	}
	originalPhys = C.Pawn.Physics;
	C.Pawn.SetCollision(False, False, False);
	C.Pawn.bCollideWorld = False;
	C.Pawn.SetLocation(Dest.Location);
	C.Pawn.SetRotation(Dest.Rotation);
	C.Pawn.SetPhysics(0);
	*/
	return false;
}