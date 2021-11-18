// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "Stryker_50Cal.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AStryker_50Cal : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	AStryker_50Cal();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

};
