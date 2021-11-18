// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"

ULatentScriptedAction::ULatentScriptedAction()
{

}


void ULatentScriptedAction::DisplayDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	/*
	Canvas.DrawText("Action " $ GetActionString(), False);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	*/
}
bool ULatentScriptedAction::InitActionFor(UScriptedController* C)
{
	//C.CurrentAction = Self;
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
bool ULatentScriptedAction::StillTicking(UScriptedController* C, float DeltaTime)
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
void ULatentScriptedAction::GetMoveTargetFor(UScriptedController* C)
{
	//Return C.SequenceScript.GetMoveTarget();
}
int32 ULatentScriptedAction::GetDistance()
{
	return 0;
}
