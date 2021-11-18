// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Action/ActionTakeCover/ActionTakeCover.h"

AActionTakeCover::AActionTakeCover()
{

}

float AActionTakeCover::evaluateAction()
{
	float stance=0;
	/*
	localCover = GoalSurvive(my_goal).cover;
	if (Controller.Pawn.bIsProne)
	{
		stance = 0;
	}
	else
	{
		if (Controller.Pawn.bIsCrouched)
		{
			stance = 0.5;
		}
		else
		{
			stance = 1;
		}
	}
	return FClamp(stance - localCover, 0, 1);
	*/
	return 0;     //FAKE   /ELiZ
}
void AActionTakeCover::executeAction()
{
	/*
	Controller.registerNotification(Self);
	if (!Controller.Pawn.bIsProne && !Controller.Pawn.bIsCrouched)
	{
		Controller.TakeCover(False);
	}
	else
	{
		Controller.TakeCover(True);
	}
	*/
}
