// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_MOVETOPOINT/Action_MOVETOPOINT.h"

UAction_MOVETOPOINT::UAction_MOVETOPOINT()
{
	ActionString = "Move to point";
	bValidForTrigger = false;
}


bool UAction_MOVETOPOINT::MoveToGoal()
{
	return true;
}

AActor* UAction_MOVETOPOINT::GetMoveTargetFor(UScriptedController* C)
{
	/*
	if (MoveTarget != None)
	{
		Return MoveTarget;
	}
	MoveTarget = C.SequenceScript.GetMoveTarget();
	if (DestinationTag != 'None')
	{
		ForEach C.AllActors(Class'Actor', MoveTarget, DestinationTag)
		{
		}
	}
	if (AIScript(MoveTarget) != None)
	{
		MoveTarget = AIScript(MoveTarget).GetMoveTarget();
	}
	*/
	return MoveTarget;
}
FString UAction_MOVETOPOINT::GetActionString()
{
	//Return ActionString @ DestinationTag;
	return "";   //FAKE  /ELiZ
}