// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "stryker.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API Astryker : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	Astryker();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

};
