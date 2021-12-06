// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/BlackHawkPickupZoneVolume/BlackHawkPickupZoneVolume.h"

ABlackHawkPickupZoneVolume::ABlackHawkPickupZoneVolume()
{
	sPlayerEntryMessage = "You have entered the pickup zone and can call in the Blackhawk.";
	//bProp = true;
}

void ABlackHawkPickupZoneVolume::Touch(AActor* Other)
{
	/*
	if ((Other.IsA('AGP_Pawn') && (AGP_Pawn(Other).Controller != None)) && AGP_Pawn(Other).Controller.IsA('HumanController'))
	{
		HumanController(AGP_Pawn(Other).Controller).SignalEnteredPickupZone();
		if (Len(sPlayerEntryMessage) > 0)
		{
			HumanController(AGP_Pawn(Other).Controller).NotifyAdminMessage(sPlayerEntryMessage);
		}
	}
	Super::Touch(Other);
	*/
}

void ABlackHawkPickupZoneVolume::UnTouch(AActor* Other)
{
	//Super::UnTouch(Other);
}
