// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/BlackHawkPickupZoneVolume/BlackHawkPickupZoneVolume.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

ABlackHawkPickupZoneVolume::ABlackHawkPickupZoneVolume()
{
	sPlayerEntryMessage = "You have entered the pickup zone and can call in the Blackhawk.";
	//bProp = true;
}

void ABlackHawkPickupZoneVolume::Touch(AActor* Other)
{
	/*
	if ((Other->IsA(AAGP_Pawn::StaticClass()) && (Cast<AAGP_Pawn>(Other).Controller != nullptr)) && Cast<AAGP_Pawn>(Other).Controller->IsA(AHumanController::StaticClass()))
	{
		Cast<AHumanController>(Cast<AAGP_Pawn>(Other).Controller).SignalEnteredPickupZone();
		if (Len(sPlayerEntryMessage) > 0)
		{
			Cast<AHumanController>(Cast<AAGP_Pawn>(Other).Controller).NotifyAdminMessage(sPlayerEntryMessage);
		}
	}
	Super::Touch(Other);
	*/
}

void ABlackHawkPickupZoneVolume::UnTouch(AActor* Other)
{
	//Super::UnTouch(Other);
}
