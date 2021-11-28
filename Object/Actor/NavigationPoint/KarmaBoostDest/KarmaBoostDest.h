// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "KarmaBoostDest.generated.h"

//class AReachSpec;

UCLASS()
class AA29_API AKarmaBoostDest : public ANavigationPoint
{
	GENERATED_BODY()
public:
	AKarmaBoostDest();

	//int32 SpecialCost(APawn* Other, AReachSpec* Path);
	
};
