// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "AnimEditProps.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimEditProps : public UObject
{
	GENERATED_BODY()
public:
	UAnimEditProps();


	UPROPERTY(EditAnywhere, Category="Compression")				float GlobalCompression;									//var(Compression) float GlobalCompression;
	UPROPERTY()													Fpointer WBrowserAnimationPtr;								//var const transient pointer WBrowserAnimationPtr;
};
