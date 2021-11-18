// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "SkelPrefsEditProps.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USkelPrefsEditProps : public UObject
{
	GENERATED_BODY()
public:
	USkelPrefsEditProps();

	UPROPERTY(EditAnywhere, Category = "OnImport")				bool WeldDuplicateVertices;						//var(OnImport) bool WeldDuplicateVertices;
	UPROPERTY()													Fpointer WBrowserAnimationPtr;					//var const transient pointer WBrowserAnimationPtr;
};
