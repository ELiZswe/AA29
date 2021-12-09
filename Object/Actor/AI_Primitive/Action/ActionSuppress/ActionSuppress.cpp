// All the original content belonged to the US Army


#include "AA29/Object/Actor/AI_Primitive/Action/ActionSuppress/ActionSuppress.h"

AActionSuppress::AActionSuppress()
{

}

float AActionSuppress::evaluateAction()
{
	/*
	local Pickup p;
	local AGP.ThrowWeaponPickup TP;
	local Object.Vector TestLoc;
	local float chance;
	chance = 0.4;
	if (checkFailure())
	{
		Return 0;
	}
	SuppressionTarget = None;
	p = Level.PickupList;
	if (p != None)
	{
		TP = ThrowWeaponPickup(p);
		if (TP != None && TP._bBlewUpProcessed)
		{
			TestLoc = TP.Location;
			TestLoc.Z += 10;
			if (FastTrace(TestLoc, getPawn().Location))
			{
				if (FRand() < chance)
				{
					SuppressionTarget = TP;
				}
				chance = chance / 1 + chance;
			}
		}
		p = p.Next;
	}
	if (SuppressionTarget != None)
	{
		DebugLog(DEBUG_Always, "ActionSuppress::evaluateAction()	" $ SuppressionTarget);
		Return 0.2;
	}
	else
	{
		Return 0;
	}
	*/
	return 0;     //FAKE    /ELiZ
}
void AActionSuppress::executeAction()
{
	//Controller.registerNotification(Self);
	//Controller.Suppress(SuppressionTarget);
}
