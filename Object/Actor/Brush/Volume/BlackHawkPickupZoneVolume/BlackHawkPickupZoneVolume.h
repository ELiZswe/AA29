// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Brush/Volume/AA2_Volume.h"
#include "BlackHawkPickupZoneVolume.generated.h"

UCLASS()
class ABlackHawkPickupZoneVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	ABlackHawkPickupZoneVolume();

	UPROPERTY(EditAnywhere, Category ="PickupZone")		FString		sPlayerEntryMessage;		// var(PickupZone) FString sPlayerEntryMessage;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
