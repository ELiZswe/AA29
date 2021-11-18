// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BodyPanel/BodyPanel.h"
#include "CROWS_Camera_BodyPanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACROWS_Camera_BodyPanel : public ABodyPanel
{
	GENERATED_BODY()
public:
	ACROWS_Camera_BodyPanel();

	UPROPERTY()					FName nmAttachBone;								//var name nmAttachBone

	void PostNetBeginPlay();
};
