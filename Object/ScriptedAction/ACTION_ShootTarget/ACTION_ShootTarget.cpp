// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_ShootTarget/ACTION_ShootTarget.h"

UACTION_ShootTarget::UACTION_ShootTarget()
{
	ActionString = "shoot target";
}

bool InitActionFor(UScriptedController* C)
{
	/*
	C.NumShots = NumShots;
	C.FiringMode = FiringMode;
	C.bShootTarget = true;
	C.bShootSpray = bSpray;
	*/
	return false;
}