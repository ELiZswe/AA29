// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_Jump/ACTION_Jump.h"

UACTION_Jump::UACTION_Jump()
{
	ActionString = "Jump";
}

bool UACTION_Jump::InitActionFor(UScriptedController* C)
{
	/*
	if (C.Pawn == None)
	{
		Return False;
	}
	C.Pawn.SetPhysics(1);
	Switch(JumpAction)
	{
			case 0:
				C.Pawn.DoJump(False);
				break;
			case 1:
				C.Pawn.DoJump(False);
				C.bPendingDoubleJump = true;
				C.bNotifyApex = true;
				break;
			case 2:
				C.Pawn.Dodge(1);
				break;
			case 2:
				C.Pawn.Dodge(2);
				break;
			default:
	}
	*/
	return false;
}