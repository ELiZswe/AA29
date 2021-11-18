// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "AA29/MyStructs.h"
#include "SubActionCameraShake.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USubActionCameraShake : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionCameraShake();

	//UPROPERTY(EditAnywhere, Category = "Shake")										FRangeVector Shake;								//var(Shake) Object.RangeVector Shake;
};
