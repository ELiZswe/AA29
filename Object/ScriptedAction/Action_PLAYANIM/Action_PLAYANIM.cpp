// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_PLAYANIM/Action_PLAYANIM.h"

UAction_PLAYANIM::UAction_PLAYANIM()
{
	BlendInTime = 0.2;
	BlendOutTime = 0.2;
	AnimRate = 1;
	ActionString = "play animation";
	bValidForTrigger = false;
}



bool UAction_PLAYANIM::InitActionFor(UScriptedController* C)
{
	/*
	C.AnimsRemaining = AnimIterations;
	if (PawnPlayBaseAnim(C, True))
	{
		C.CurrentAnimation = Self;
	}
	*/
	return false;
}
void UAction_PLAYANIM::SetCurrentAnimationFor(UScriptedController* C)
{
	/*
	if (C.Pawn.IsAnimating(0))
	{
		C.CurrentAnimation = Self;
	}
	else
	{
		C.CurrentAnimation = None;
	}
	*/
}
bool UAction_PLAYANIM::PawnPlayBaseAnim(UScriptedController* C, bool bFirstPlay)
{
	/*
	if (BaseAnim == 'None')
	{
		Return False;
	}
	C.bControlAnimations = true;
	if (bFirstPlay)
	{
		if (C.Level.NetMode == 1 || C.Level.NetMode == 2)
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
			Return False;
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