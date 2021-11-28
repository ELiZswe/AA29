// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "BlockedPath.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABlockedPath : public ANavigationPoint
{
	GENERATED_BODY()
public:
	ABlockedPath();

	UPROPERTY()													bool bStartBlocked;								//var bool bStartBlocked;

	void PostBeginPlay();
	void Reset();
	void Trigger(AActor* Other, APawn* EventInstigator);

};
