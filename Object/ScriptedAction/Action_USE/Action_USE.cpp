// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_USE/Action_USE.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_USE::UAction_USE()
{

}

bool UAction_USE::InitActionFor(AScriptedController* C)
{
	/*
	local Actor A;
	local Vehicle DrivenVehicle;
	C.bChangingPawns = true;
	DrivenVehicle = Vehicle(C.Pawn);
	if (DrivenVehicle != nullptr)
	{
		DrivenVehicle.KDriverLeave(false);
		C.bChangingPawns = false;
		return false;
	}
	ForEach C.Pawn.VisibleCollidingActors(Class'Vehicle', DrivenVehicle, 500)
	{
		DrivenVehicle.UsedBy(C.Pawn);
		C.bChangingPawns = false;
		return false;
	}
	ForEach C.Pawn.TouchingActors(Class'Actor', A)
	{
		A.UsedBy(C.Pawn);
	}
	if (C.Pawn.Base != nullptr)
	{
		C.Pawn.Base.UsedBy(C.Pawn);
	}
	C.bChangingPawns = false;
	*/
	return false;
}
