// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_UseTrigger/AGP_UseTrigger.h"
#include "CamTrigger.generated.h"

class AHumanController;

UCLASS()
class AA29_API ACamTrigger : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	ACamTrigger();

	UPROPERTY(EditAnywhere)											AHumanController* HC;					//var AGP.HumanController HC;
	UPROPERTY(EditAnywhere)											bool bSwitch;							//var bool bSwitch;
	UPROPERTY(EditAnywhere)											UMaterialInstance* HUDCamOverlay;		//var() Material HUDCamOverlay;
	UPROPERTY(EditAnywhere)											FName SwitchState;						//var() name SwitchState;
	UPROPERTY(EditAnywhere)											bool bUseTriggered;						//var() bool bUseTriggered;
	UPROPERTY(EditAnywhere)											int32 UseFOV;							//var() int UseFOV;
	UPROPERTY(EditAnywhere)											FName ViewActorTag;						//var() name ViewActorTag;
};
