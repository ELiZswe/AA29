// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "M1083_FMTV.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM1083_FMTV : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	AM1083_FMTV();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

};
