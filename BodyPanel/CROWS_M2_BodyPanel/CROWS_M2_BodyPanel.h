// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BodyPanel/BodyPanel.h"
#include "CROWS_M2_BodyPanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACROWS_M2_BodyPanel : public ABodyPanel
{
	GENERATED_BODY()
public:
	ACROWS_M2_BodyPanel();

	UPROPERTY()					FName nmAttachBone;								//var name nmAttachBone

	void PostNetBeginPlay();

};
