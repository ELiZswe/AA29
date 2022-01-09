// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "KarmaBoostDest.generated.h"

//class UReachSpec;

UCLASS()
class AKarmaBoostDest : public ANavigationPoint
{
	GENERATED_BODY()
public:
	AKarmaBoostDest();

	//int32 SpecialCost(APawn* Other, UReachSpec* Path);
	
};
