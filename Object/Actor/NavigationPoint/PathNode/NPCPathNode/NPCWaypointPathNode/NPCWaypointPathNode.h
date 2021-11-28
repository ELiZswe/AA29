// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"
#include "NPCWaypointPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCWaypointPathNode : public ANPCPathNode
{
	GENERATED_BODY()
public:
	ANPCWaypointPathNode();

	UPROPERTY(EditAnywhere, Category = "NPCWaypointOptions")				bool bSearchForItemsOfInterest;					//var(NPCWaypointOptions) bool bSearchForItemsOfInterest;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bNeverRandomSpawnHere;						//var(NPCNodeOptions) bool bNeverRandomSpawnHere;
};
