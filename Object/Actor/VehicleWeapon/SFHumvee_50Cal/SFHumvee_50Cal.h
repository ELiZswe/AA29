// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "SFHumvee_50Cal.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASFHumvee_50Cal : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	ASFHumvee_50Cal();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

};
