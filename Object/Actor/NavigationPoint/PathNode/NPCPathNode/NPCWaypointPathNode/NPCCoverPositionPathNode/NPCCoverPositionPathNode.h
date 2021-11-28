// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"
#include "NPCCoverPositionPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCCoverPositionPathNode : public ANPCWaypointPathNode
{
	GENERATED_BODY()
public:
	ANPCCoverPositionPathNode();


	UPROPERTY(EditAnywhere, Category = "NPCCoverNodeOptions")				float fpMaxVerticalDeltaToFind;			//var(NPCCoverNodeOptions) float fpMaxVerticalDeltaToFind;
	UPROPERTY(EditAnywhere, Category = "NPCCoverNodeOptions")				bool bSafeFromVehiclesImpact;			//var(NPCCoverNodeOptions) bool bSafeFromVehiclesImpact;
	UPROPERTY(EditAnywhere, Category = "NPCCoverNodeOptions")				USoundBase* soundToPlay;				//var(NPCCoverNodeOptions) Sound soundToPlay;
	UPROPERTY(EditAnywhere, Category = "NPCCoverNodeOptions")				FName nameAnimationToPlay;				//var(NPCCoverNodeOptions) name nameAnimationToPlay;
	UPROPERTY(EditAnywhere, Category = "NPCCoverNodeOptions")				bool bCrouchForCover;					//var(NPCCoverNodeOptions) bool bCrouchForCover;
	UPROPERTY(EditAnywhere, Category = "NPCCoverNodeOptions")				bool bProneForCover;					//var(NPCCoverNodeOptions) bool bProneForCover;
};
