// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCFirePositionPathNode.h"
#include "NPCCamperFirePositionPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCCamperFirePositionPathNode : public ANPCFirePositionPathNode
{
	GENERATED_BODY()
public:
	ANPCCamperFirePositionPathNode();

	UPROPERTY(EditAnywhere, Category = "NPCAmbushPosition")				int32 iSquadAmbushSet;												//var(NPCAmbushPosition) int iSquadAmbushSet;
	UPROPERTY(EditAnywhere, Category = "NPCSpotter")					bool bVehicleFireOnly;												//var(NPCSpotter) bool bVehicleFireOnly;
	UPROPERTY(EditAnywhere, Category = "NPCSpotter")					float fpMinPlayersToSee;											//var(NPCSpotter) float fpMinPlayersToSee;
	UPROPERTY(EditAnywhere, Category = "NPCSpotter")					float fpMaxRangeMeters;												//var(NPCSpotter) float fpMaxRangeMeters;
	UPROPERTY(EditAnywhere, Category = "NPCSpotter")					float fpMinRangeMeters;												//var(NPCSpotter) float fpMinRangeMeters;
	UPROPERTY(EditAnywhere, Category = "NPCSpotter")					bool bSpotterPosition;												//var(NPCSpotter) bool bSpotterPosition;
	UPROPERTY(EditAnywhere, Category = "NPCAmbushPosition")				float fpAmbushRange;												//var(NPCAmbushPosition) float fpAmbushRange;
};
