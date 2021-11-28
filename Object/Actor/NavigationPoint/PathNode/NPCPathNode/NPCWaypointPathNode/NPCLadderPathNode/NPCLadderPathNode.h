// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"
#include "NPCLadderPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCLadderPathNode : public ANPCWaypointPathNode
{
	GENERATED_BODY()
public:
	ANPCLadderPathNode();

	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				FName nameLadderNodeToExitFrom;			//var(NPCLadderNodeOptions) name nameLadderNodeToExitFrom;
	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				FName nameLadderVolumeToUse;			//var(NPCLadderNodeOptions) name nameLadderVolumeToUse;
	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				bool bNearLadderTop;					//var(NPCLadderNodeOptions) bool bNearLadderTop;
	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				bool bNearLadderBase;					//var(NPCLadderNodeOptions) bool bNearLadderBase;
};
