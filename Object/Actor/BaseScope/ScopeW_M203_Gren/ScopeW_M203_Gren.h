// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseScope/BaseScope.h"
#include "ScopeW_M203_Gren.generated.h"

UCLASS()
class AScopeW_M203_Gren : public ABaseScope
{
	GENERATED_BODY()
public:
	AScopeW_M203_Gren();

	UPROPERTY(EditAnywhere)		UMaterialInstance* tAuxZoomOverlay;						//var Texture tAuxZoomOverlay;

	UMaterialInstance* GetZoomOverlay();
};
