// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/PickupMessagePlus/PickupMessagePlus.h"

APickupMessagePlus::APickupMessagePlus()
{
	bIsUnique = true;
	bFadeMessage = true;
	PosY = 0.9;
}



void APickupMessagePlus::ClientReceive(APlayerController*, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (class<Pickup>(OptionalObject) == None)
	{
		Return;
	}
	if (p.MyHUD != None)
	{
		class<Pickup>(OptionalObject).UpdateHUD(p.MyHUD);
	}
	if (p.bEnablePickupForceFeedback)
	{
		p.ClientPlayForceFeedback(class<Pickup>(OptionalObject).Default.PickupForce);
	}
	*/
}