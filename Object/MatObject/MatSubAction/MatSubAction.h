// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatObject.h"
#include "AA29/MyEnums.h"
#include "MatSubAction.generated.h"

UCLASS()
class UMatSubAction : public UMatObject
{
	GENERATED_BODY()
public:
	UMatSubAction();

	UPROPERTY()											float PctDuration;							//var transient float PctDuration;
	UPROPERTY()											float PctEnding;							//var transient float PctEnding;
	UPROPERTY()											float PctStarting;							//var transient float PctStarting;
	UPROPERTY()											FString Desc;								//var localized string Desc;
	UPROPERTY()											ESAStatus Status;							//var ESAStatus Status;
	UPROPERTY()											UMaterialInstance* Icon;					//var Texture Icon;
	UPROPERTY(EditAnywhere, Category = "Time")			float Duration;								//var(Time) float Duration;
	UPROPERTY(EditAnywhere, Category = "Time")			float Delay;								//var(Time) float Delay;
};
