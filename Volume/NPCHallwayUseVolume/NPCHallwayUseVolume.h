// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Volume/AA2_Volume.h"
#include "NPCHallwayUseVolume.generated.h"

class ANPCPathNode;

UCLASS()
class AA29_API ANPCHallwayUseVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	ANPCHallwayUseVolume();

	UPROPERTY(EditAnywhere, Category = "NPCHallwayInfo")			FName anameHallwayNodes;							//var(NPCHallwayInfo) name anameHallwayNodes;
	UPROPERTY()														ANPCPathNode* anpcEntryNodes;							//var NPCPathNode anpcEntryNodes;
};
