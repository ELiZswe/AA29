// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "Technical.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATechnical : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	ATechnical();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
};
