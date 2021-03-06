// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "stryker.generated.h"

class ALevelInfo;

UCLASS()
class Astryker : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	Astryker();

	void StaticPrecache(ALevelInfo* L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
};
