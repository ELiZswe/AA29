// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/NPCRoadPathNode/NPCRoadPathNode.h"
#include "AGP_VehicleNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_VehicleNode : public ANPCRoadPathNode
{
	GENERATED_BODY()
public:
	AAGP_VehicleNode();

	UPROPERTY()								AAGP_VehicleNode* NextNode;						//var AGP_VehicleNode NextNode;
	UPROPERTY(EditAnywhere)					FName NextNodeTag;								//var() name NextNodeTag;


	void PostBeginPlay();
};
