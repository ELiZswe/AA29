// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"
#include "NPCDoorEntryPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCDoorEntryPathNode : public ANPCWaypointPathNode
{
	GENERATED_BODY()
public:
	ANPCDoorEntryPathNode();

	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				FName nameDoorToOpen;				//var(NPCDoorOption) name nameDoorToOpen;
	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				float fpTimeToWaitForOpenDoor;		//var(NPCDoorOption) float fpTimeToWaitForOpenDoor;
	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				bool bDoorCanBeBreached;			//var(NPCDoorOption) bool bDoorCanBeBreached;
	UPROPERTY(EditAnywhere, Category = "NPCDoorOption")				bool bNPCHasKey;					//var(NPCDoorOption) bool bNPCHasKey;
};
