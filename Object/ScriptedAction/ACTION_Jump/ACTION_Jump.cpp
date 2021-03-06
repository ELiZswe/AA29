// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_Jump/ACTION_Jump.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_Jump::UACTION_Jump()
{
	ActionString = "Jump";
}

bool UACTION_Jump::InitActionFor(AScriptedController* C)
{
	if (C->GetPawn() == nullptr)
	{
		return false;
	}
	//C->GetPawn()->SetPhysics(1);
	switch(JumpAction)
	{
		case EJumpType::JUMP_Normal:
			//C->Pawn->DoJump(false);
			break;
		case EJumpType::JUMP_Double:
			//C->Pawn->DoJump(false);
			C->bPendingDoubleJump = true;
			C->bNotifyApex = true;
			break;
		case EJumpType::JUMP_DodgeLeft:
			//C->Pawn->Dodge(1);
			break;
		case EJumpType::JUMP_DodgeRight:
			//C->Pawn->Dodge(2);
			break;
		default:
			break;
	}
	return false;
}
