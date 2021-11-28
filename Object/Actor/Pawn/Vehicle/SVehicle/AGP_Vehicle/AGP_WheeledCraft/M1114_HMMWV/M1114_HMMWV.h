// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "M1114_HMMWV.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM1114_HMMWV : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	AM1114_HMMWV();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

};
