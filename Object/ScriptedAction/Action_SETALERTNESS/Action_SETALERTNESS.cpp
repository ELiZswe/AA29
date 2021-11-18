// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_SETALERTNESS/Action_SETALERTNESS.h"

UAction_SETALERTNESS::UAction_SETALERTNESS()
{
	ActionString = "set alertness";
	bValidForTrigger = false;
}

bool UAction_SETALERTNESS::InitActionFor(UScriptedController* C)
{
	//C.SetEnemyReaction(Alertness);
	return false;
}
FString UAction_SETALERTNESS::GetActionString()
{
	/*
	local string S;
	Switch(Alertness)
	{
			case 0:
				S = "Ignore all";
				break;
			case 1:
				S = "Ignore enemies";
				break;
			case 2:
				S = "Stay on script";
				break;
			case 3:
				S = "Leave script for combat";
				break;
			default:
	}
	return ActionString @ S;
	*/
	return "";   //FAKE   /ELiZ
}