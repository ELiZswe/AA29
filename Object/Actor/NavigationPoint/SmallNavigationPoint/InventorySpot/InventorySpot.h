// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "InventorySpot.generated.h"

UCLASS()
class AA29_API AInventorySpot : public ASmallNavigationPoint
{
	GENERATED_BODY()
	
public:
	AInventorySpot();
	
	UPROPERTY()										bool bSuperPickup;						//var bool bSuperPickup;
	UPROPERTY()										AxPickUpBase* myPickupBase;				//var xPickUpBase myPickupBase;
	UPROPERTY()										APickup* markedItem;					//var Pickup markedItem;

	AActor* GetMoveTargetFor(AaAIController* B, float MaxWait);
	float DetourWeight(APawn* Other, float PathWeight);
};
