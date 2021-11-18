// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_USE/Action_USE.h"

UAction_USE::UAction_USE()
{

}

bool UAction_USE::InitActionFor(UScriptedController* C)
{
	/*
	local Actor A;
	local Vehicle DrivenVehicle;
	C.bChangingPawns = true;
	DrivenVehicle = Vehicle(C.Pawn);
	if (DrivenVehicle != None)
	{
		DrivenVehicle.KDriverLeave(False);
		C.bChangingPawns = False;
		Return False;
	}
	ForEach C.Pawn.VisibleCollidingActors(Class'Vehicle', DrivenVehicle, 500)
	{
		DrivenVehicle.UsedBy(C.Pawn);
		C.bChangingPawns = False;
		Return False;
	}
	ForEach C.Pawn.TouchingActors(Class'Actor', A)
	{
		A.UsedBy(C.Pawn);
	}
	if (C.Pawn.Base != None)
	{
		C.Pawn.Base.UsedBy(C.Pawn);
	}
	C.bChangingPawns = False;
	*/
	return false;
}