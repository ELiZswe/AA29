// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "CrosshairPack.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCrosshairPack : public UObject
{
	GENERATED_BODY()
public:
	UCrosshairPack();


	UPROPERTY(EditAnywhere)								TArray<FCrosshairItem> CrossHair;						//var() const array<CrosshairItem> CrossHair;
};
