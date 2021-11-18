// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_FADEVIEW/Action_FADEVIEW.h"

UAction_FADEVIEW::UAction_FADEVIEW()
{
	FadeTime = 5;
	TargetFlash = FVector(-2, -2, -2);
	ActionString = "fade view";
}


bool UAction_FADEVIEW::InitActionFor(UScriptedController* C)
{
	return true;
}
FString UAction_FADEVIEW::GetActionString()
{
	//return ActionString @ FadeTime;
	return "";   //FAKE     /ELiZ
}
bool UAction_FADEVIEW::TickedAction()
{
	return true;
}
bool UAction_FADEVIEW::StillTicking(UScriptedController* C, float DeltaTime)
{
	/*
	local bool bXDone;
	local bool bYDone;
	local bool bZDone;
	local Object.Vector V;
	V = C.GetInstigator().PhysicsVolume.ViewFlash - C.Instigator.PhysicsVolume.Default.ViewFlash - TargetFlash * DeltaTime / FadeTime;
	if (V.X < TargetFlash.X)
	{
		V.X = TargetFlash.X;
		bXDone = true;
	}
	if (V.Y < TargetFlash.Y)
	{
		V.Y = TargetFlash.Y;
		bYDone = true;
	}
	if (V.Z < TargetFlash.Z)
	{
		V.Z = TargetFlash.Z;
		bZDone = true;
	}
	C.GetInstigator().PhysicsVolume.ViewFlash = V;
	if (bXDone && bYDone && bZDone)
	{
		Return False;
	}
	*/
	return true;
}