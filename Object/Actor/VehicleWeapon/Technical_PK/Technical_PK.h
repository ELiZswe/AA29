// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "Technical_PK.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATechnical_PK : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	ATechnical_PK();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

};
