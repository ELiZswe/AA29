// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "M1114_Mk19_Gun.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM1114_Mk19_Gun : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	AM1114_Mk19_Gun();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();


};
