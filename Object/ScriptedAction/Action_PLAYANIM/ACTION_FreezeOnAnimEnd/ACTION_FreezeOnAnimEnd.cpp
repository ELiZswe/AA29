// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYANIM/ACTION_FreezeOnAnimEnd/ACTION_FreezeOnAnimEnd.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_FreezeOnAnimEnd::UACTION_FreezeOnAnimEnd()
{

}

bool UACTION_FreezeOnAnimEnd::InitActionFor(AScriptedController* C)
{
	//C.CurrentAnimation = this;
	return true;
}
void UACTION_FreezeOnAnimEnd::SetCurrentAnimationFor(AScriptedController* C)
{
	//C.CurrentAnimation = this;
}
bool UACTION_FreezeOnAnimEnd::PawnPlayBaseAnim(AScriptedController* C, bool bFirstPlay)
{
	/*
	if (C.Pawn != nullptr)
	{
		C.Pawn.bPhysicsAnimUpdate = false;
		C.Pawn.StopAnimating();
		C.Pawn.SetPhysics(0);
	}
	*/
	return true;
}
