// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "SubActionOrientation.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USubActionOrientation : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionOrientation();

	//UPROPERTY(EditAnywhere, Category = "Orientation")										FOrientation CamOrientation;							//var(Orientation) MatObject.Orientation CamOrientation;
};
