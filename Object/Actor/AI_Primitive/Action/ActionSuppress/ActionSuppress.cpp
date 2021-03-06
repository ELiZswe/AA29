// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Action/ActionSuppress/ActionSuppress.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"

AActionSuppress::AActionSuppress()
{

}

float AActionSuppress::evaluateAction()
{
	APickup* p = nullptr;
	AThrowWeaponPickup* TP = nullptr;
	FVector TestLoc = FVector(0,0,0);
	float chance = 0;
	chance=0.4;
	if (checkFailure())
	{
		return 0;
	}
	SuppressionTarget=nullptr;
	/*
	for (p=Level.PickupList; p!=nullptr; p=p.Next)
	{
		TP=ThrowWeaponPickup(p);
		if ((TP != nullptr) && TP._bBlewUpProcessed)
		{
			TestLoc=TP.Location;
			TestLoc.Z += float(10);
			if (FastTrace(TestLoc,getPawn().Location))
			{
				if (FMath::FRand() < chance)
				{
					SuppressionTarget=TP;
				}
				chance=(chance / (1 + chance));
			}
		}
	}
	*/
	if (SuppressionTarget != nullptr)
	{
		//DebugLog(DEBUG_Always,"ActionSuppress::evaluateAction()	" + FString::FromInt(SuppressionTarget));
		return 0.2;
	}
	else
	{
		return 0;
	}
}
void AActionSuppress::executeAction()
{
	//Controller.registerNotification(this);
	//Controller.Suppress(SuppressionTarget);
}
