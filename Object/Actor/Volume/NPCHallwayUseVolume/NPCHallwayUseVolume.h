// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/AA2_Volume.h"
#include "NPCHallwayUseVolume.generated.h"

class ANPCPathNode;

UCLASS()
class AA29_API ANPCHallwayUseVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	ANPCHallwayUseVolume();

	UPROPERTY()														TArray<ANPCPathNode*>	anpcEntryNodes;				//var NPCPathNode anpcEntryNodes[2];
	UPROPERTY(EditAnywhere, Category = "NPCHallwayInfo")			TArray<FName>			anameHallwayNodes;			//var(NPCHallwayInfo) FName anameHallwayNodes[2];

	void BeginPlay();
	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
