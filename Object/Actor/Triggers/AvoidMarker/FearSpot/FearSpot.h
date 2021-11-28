// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/AvoidMarker/AvoidMarker.h"
#include "FearSpot.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFearSpot : public AAvoidMarker
{
	GENERATED_BODY()
public:
	AFearSpot();

	UPROPERTY(EditAnywhere)			bool					bInitiallyActive;			//var() bool bInitiallyActive;

	void Touch(AActor* Other);
	void Trigger(AActor* Other, APawn* EventInstigator);
};
