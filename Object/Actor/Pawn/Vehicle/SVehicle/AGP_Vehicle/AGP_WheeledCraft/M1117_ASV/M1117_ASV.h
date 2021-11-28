// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "M1117_ASV.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM1117_ASV : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	AM1117_ASV();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

};
