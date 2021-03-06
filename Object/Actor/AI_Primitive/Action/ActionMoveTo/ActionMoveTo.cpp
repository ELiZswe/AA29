// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Action/ActionMoveTo/ActionMoveTo.h"
#include "AA29/Object/Actor/AI_Primitive/Contact/Contact.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

AActionMoveTo::AActionMoveTo()
{

}

float AActionMoveTo::evaluateAction()
{
	float Score=0;
	AAGP_Weapon* weap = nullptr;
	FVector eLoc = FVector(0,0,0);
	FVector MyLoc = FVector(0,0,0);
	float rangeToEnemy = 0;
	int32 noInfo = 0;
	/*
	if (checkFailure())
	{
		return 0;
	}
	if (Controller.Enemy == nullptr)
	{
		return 0;
	}
	else
	{
		Enemy = getMentalModel().findContact(Controller.Enemy);
	}
	if (Controller.enemyCont.isInvisible())
	{
		return 0;
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
				weap = Cast<AAGP_Weapon>(GetWeapon());
				Score =FMath::Clamp(rangeToEnemy / weap.GetMaximumRange(), 0, 1);
			}
		}
	}
	*/
	return Score;
}

void AActionMoveTo::executeAction()
{
	//Controller.registerNotification(this);
	//Controller.MoveObject = getEnemy();
	//Controller.Charge();
}
