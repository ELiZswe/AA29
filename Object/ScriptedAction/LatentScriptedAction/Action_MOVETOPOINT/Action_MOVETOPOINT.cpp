// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_MOVETOPOINT/Action_MOVETOPOINT.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Keypoint/AIScript/AIScript.h"

UAction_MOVETOPOINT::UAction_MOVETOPOINT()
{
	ActionString = "Move to point";
	bValidForTrigger = false;
}

bool UAction_MOVETOPOINT::MoveToGoal()
{
	return true;
}

AActor* UAction_MOVETOPOINT::GetMoveTargetFor(AScriptedController* C)
{
	/*
	if (MoveTarget != nullptr)
	{
		return MoveTarget;
	}
	MoveTarget = C.SequenceScript.GetMoveTarget();
	if (DestinationTag != "None")
	{
		ForEach C.AllActors(Class'Actor', MoveTarget, DestinationTag)
		{
		}
	}
	if (Cast<AAIScript>(MoveTarget) != nullptr)
	{
		MoveTarget = AIScript(MoveTarget).GetMoveTarget();
	}
	*/
	return MoveTarget;
}
FString UAction_MOVETOPOINT::GetActionString()
{
	//return ActionString @ DestinationTag;
	return "";   //FAKE  /ELiZ
}
