// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "SFHumvee.generated.h"

class ALevelInfo;

UCLASS()
class ASFHumvee : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	ASFHumvee();

	void StaticPrecache(ALevelInfo* L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
};
