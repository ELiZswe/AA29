// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_FADEVIEW/Action_FADEVIEW.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_FADEVIEW::UAction_FADEVIEW()
{
	FadeTime = 5;
	TargetFlash = FVector(-2, -2, -2);
	ActionString = "fade view";
}

bool UAction_FADEVIEW::InitActionFor(AScriptedController* C)
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

bool UAction_FADEVIEW::StillTicking(AScriptedController* C, float DeltaTime)
{
	bool bXDone = false;
	bool bYDone = false;
	bool bZDone = false;
	FVector V = FVector(0,0,0);
	/*
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
		return false;
	}
	*/
	return true;
}
