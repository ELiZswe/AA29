// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYANIM/Action_PLAYANIM.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_PLAYANIM::UAction_PLAYANIM()
{
	BlendInTime = 0.2;
	BlendOutTime = 0.2;
	AnimRate = 1;
	ActionString = "play animation";
	bValidForTrigger = false;
}

bool UAction_PLAYANIM::InitActionFor(AScriptedController* C)
{
	/*
	C.AnimsRemaining = AnimIterations;
	if (PawnPlayBaseAnim(C, True))
	{
		C.CurrentAnimation = this;
	}
	*/
	return false;
}
void UAction_PLAYANIM::SetCurrentAnimationFor(AScriptedController* C)
{
	/*
	if (C.Pawn.IsAnimating(0))
	{
		C.CurrentAnimation = this;
	}
	else
	{
		C.CurrentAnimation = nullptr;
	}
	*/
}
bool UAction_PLAYANIM::PawnPlayBaseAnim(AScriptedController* C, bool bFirstPlay)
{
	/*
	if (BaseAnim == "None")
	{
		return false;
	}
	C.bControlAnimations = true;
	if (bFirstPlay)
	{
		if (C.GetWorld()->GetNetMode() == 1 || C.GetWorld()->GetNetMode() == 2)
		{
			C.Pawn.SetAnimAction(BaseAnim);
		}
		else
		{
			C.Pawn.PlayAnim(BaseAnim, AnimRate, BlendInTime);
		}
	}
	else
	{
		if (bLoopAnim || C.AnimsRemaining > 0)
		{
			C.Pawn.LoopAnim(BaseAnim, AnimRate);
		}
		else
		{
			return false;
		}
	}
	if (StartFrame > 0)
	{
		C.Pawn.SetAnimFrame(StartFrame, 0, 1);
	}
	*/
	return true;
}
FString UAction_PLAYANIM::GetActionString()
{
	//return ActionString @ BaseAnim;
	return "";    //FAKE   /ELiZ
}
