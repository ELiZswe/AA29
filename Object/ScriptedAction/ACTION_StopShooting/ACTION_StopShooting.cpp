// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_StopShooting/ACTION_StopShooting.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_StopShooting::UACTION_StopShooting()
{

}

bool UACTION_StopShooting::InitActionFor(AScriptedController* C)
{
	//C.bShootTarget = false;
	//C.bShootSpray = false;
	return false;
}
