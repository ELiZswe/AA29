// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Action/ActionMoveTo/ActionMoveTo.h"

AActionMoveTo::AActionMoveTo()
{

}

float AActionMoveTo::evaluateAction()
{
	float Score=0;
	/*
	local AGP.AGP_Weapon weap;
	local Object.Vector eLoc;
	local Object.Vector MyLoc;
	local float rangeToEnemy;
	
	local int noInfo;
	if (checkFailure())
	{
		Return 0;
	}
	if (Controller.Enemy == None)
	{
		Return 0;
	}
	else
	{
		Enemy = getMentalModel().findContact(Controller.Enemy);
	}
	if (Controller.enemyCont.isInvisible())
	{
		Return 0;
	}
	MyLoc = getPawn().Location;
	eLoc = Enemy.queryVector("position", noInfo);
	if (noInfo == 1)
	{
		Score = 0;
	}
	else
	{
		if (GetWeapon().GetCurrentAmmoType().AmmoAmount < 1)
		{
			Score = 0;
		}
		else
		{
			if (Controller.enemyCont.lineOfFireToHim(Controller.Pawn) < 0.1)
			{
				Score = 1;
			}
			else
			{
				rangeToEnemy = VSize(MyLoc - eLoc);
				weap = AGP_Weapon(GetWeapon());
				Score = FClamp(rangeToEnemy / weap.GetMaximumRange(), 0, 1);
			}
		}
	}
	*/
	return Score;
}
void AActionMoveTo::executeAction()
{
	//Controller.registerNotification(Self);
	//Controller.MoveObject = getEnemy();
	//Controller.Charge();
}
