// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "Engine/Canvas.h"

ULatentScriptedAction::ULatentScriptedAction()
{

}

void ULatentScriptedAction::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Canvas.DrawText("Action " + GetActionString(), false);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	*/
}
bool ULatentScriptedAction::InitActionFor(AScriptedController* C)
{
	//C.CurrentAction = this;
	return true;
}
bool ULatentScriptedAction::CompleteWhenTriggered()
{
	return false;
}
bool ULatentScriptedAction::CompleteOnAnim(int32 Channel)
{
	return false;
}
bool ULatentScriptedAction::CompleteOnLIPSincAnim()
{
	return false;
}
bool ULatentScriptedAction::CompleteWhenTimer()
{
	return false;
}
bool ULatentScriptedAction::WaitForPlayer()
{
	return false;
}
bool ULatentScriptedAction::TickedAction()
{
	return false;
}
bool ULatentScriptedAction::StillTicking(AScriptedController* C, float DeltaTime)
{
	return false;
}

bool ULatentScriptedAction::MoveToGoal()
{
	return false;
}

bool ULatentScriptedAction::TurnToGoal()
{
	return false;
}

AActor* ULatentScriptedAction::GetMoveTargetFor(AScriptedController* C)
{
	//return C.SequenceScript.GetMoveTarget();
	return nullptr;     //FAKE   /EliZ
}
float ULatentScriptedAction::GetDistance()
{
	return 0;
}
