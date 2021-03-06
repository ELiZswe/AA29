// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AlternatePath.generated.h"

UCLASS()
class AAlternatePath : public ANavigationPoint
{
	GENERATED_BODY()
public:
	AAlternatePath();

	UPROPERTY(EditAnywhere)													bool bReturnOnly;						//var() bool bReturnOnly;
	UPROPERTY(EditAnywhere)													float SelectionWeight;					//var() float SelectionWeight;
	UPROPERTY(EditAnywhere)													uint8 Team;								//var() byte Team;
};
