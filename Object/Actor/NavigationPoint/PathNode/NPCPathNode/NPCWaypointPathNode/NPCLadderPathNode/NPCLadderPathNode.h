// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"
#include "NPCLadderPathNode.generated.h"

UCLASS()
class ANPCLadderPathNode : public ANPCWaypointPathNode
{
	GENERATED_BODY()
public:
	ANPCLadderPathNode();

	UPROPERTY(EditAnywhere, Category = "NPCLadderNodeOptions")				FName nameLadderNodeToExitFrom;			//var(NPCLadderNodeOptions) name nameLadderNodeToExitFrom;
	UPROPERTY(EditAnywhere, Category = "NPCLadderNodeOptions")				FName nameLadderVolumeToUse;			//var(NPCLadderNodeOptions) name nameLadderVolumeToUse;
	UPROPERTY(EditAnywhere, Category = "NPCLadderNodeOptions")				bool bNearLadderTop;					//var(NPCLadderNodeOptions) bool bNearLadderTop;
	UPROPERTY(EditAnywhere, Category = "NPCLadderNodeOptions")				bool bNearLadderBase;					//var(NPCLadderNodeOptions) bool bNearLadderBase;

	void BeginPlay();
};
