// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BodyPanel/BodyPanel.h"
#include "CROWS_Main_BodyPanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACROWS_Main_BodyPanel : public ABodyPanel
{
	GENERATED_BODY()
public:
	ACROWS_Main_BodyPanel();

	UPROPERTY()					FName nmAttachBone;								//var name nmAttachBone

	void PostNetBeginPlay();

};
