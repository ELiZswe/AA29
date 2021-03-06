// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "Pickup_Javelin_Tube.generated.h"

class ALevelInfo;
UCLASS()
class APickup_Javelin_Tube : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	APickup_Javelin_Tube();

	void StaticPrecache(ALevelInfo* L);
};
