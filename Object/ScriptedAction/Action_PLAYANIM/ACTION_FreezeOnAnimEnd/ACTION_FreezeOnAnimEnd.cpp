// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYANIM/ACTION_FreezeOnAnimEnd/ACTION_FreezeOnAnimEnd.h"

UACTION_FreezeOnAnimEnd::UACTION_FreezeOnAnimEnd()
{

}

bool UACTION_FreezeOnAnimEnd::InitActionFor(AScriptedController* C)
{
	//C.CurrentAnimation = Self;
	return true;
}
void UACTION_FreezeOnAnimEnd::SetCurrentAnimationFor(AScriptedController* C)
{
	//C.CurrentAnimation = Self;
}
bool UACTION_FreezeOnAnimEnd::PawnPlayBaseAnim(AScriptedController* C, bool bFirstPlay)
{
	/*
	if (C.Pawn != None)
	{
		C.Pawn.bPhysicsAnimUpdate = False;
		C.Pawn.StopAnimating();
		C.Pawn.SetPhysics(0);
	}
	*/
	return true;
}
