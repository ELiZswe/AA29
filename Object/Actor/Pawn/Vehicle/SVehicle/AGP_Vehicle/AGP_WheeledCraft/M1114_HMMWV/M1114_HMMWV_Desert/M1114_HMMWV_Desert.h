// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1114_HMMWV/M1114_HMMWV.h"
#include "M1114_HMMWV_Desert.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM1114_HMMWV_Desert : public AM1114_HMMWV
{
	GENERATED_BODY()
public:
	AM1114_HMMWV_Desert();

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
};
