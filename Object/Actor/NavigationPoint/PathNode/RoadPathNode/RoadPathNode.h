// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "RoadPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARoadPathNode : public APathNode
{
	GENERATED_BODY()
public:
	ARoadPathNode();


	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bSafeToUnloadNPCs;									//var(NPCNodeOptions) bool bSafeToUnloadNPCs;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bNeverRandomSpawnHere;								//var(NPCNodeOptions) bool bNeverRandomSpawnHere;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bPathBranchDesc;									//var(NPCNodeOptins) bool bPathBranchDesc;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bPathBranchAsc;									//var(NPCNodeOptions) bool bPathBranchAsc;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					int32 iBranchIndex;										//var(NPCNodeOptions) int iBranchIndex;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bFiringNode;										//var(NPCNodeOptions) bool bFiringNode;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleOptions")					bool bStopHere;											//var(NPCVehicleOptions) bool bStopHere;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleOptions")					float fpDesiredSpeed;									//var(NPCVehicleOptions) float fpDesiredSpeed;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleOptions")					float fpMaxDesiredSpeed;								//var(NPCVehicleOptions) float fpMaxDesiredSpeed;
	UPROPERTY(EditAnywhere)													bool bIgnoreRegularPathnodes;							//var() bool bIgnoreRegularPathnodes;
	UPROPERTY(EditAnywhere)													float MaxRoadDist;										//var() float MaxRoadDist;

};
