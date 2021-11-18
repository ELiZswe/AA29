// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BaseScope/BaseScope.h"
#include "ScopeW_M203_Gren.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AScopeW_M203_Gren : public ABaseScope
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* tAuxZoomOverlay;						//var Texture tAuxZoomOverlay;
	AScopeW_M203_Gren();
};
