// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ShootTarget/ACTION_ShootTarget.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_ShootTarget::UACTION_ShootTarget()
{
	ActionString = "shoot target";
}

bool UACTION_ShootTarget::InitActionFor(AScriptedController* C)
{
	C->NumShots = NumShots;
	C->FiringMode = FiringMode;
	C->bShootTarget = true;
	C->bShootSpray = bSpray;
	return false;
}
