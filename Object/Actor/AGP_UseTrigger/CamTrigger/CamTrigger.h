// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "CamTrigger.generated.h"

class AHumanController;

UCLASS()
class ACamTrigger : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	ACamTrigger();

	UPROPERTY(EditAnywhere)								FName				ViewActorTag;		//var() name ViewActorTag;
	UPROPERTY(EditAnywhere)								int32				UseFOV;				//var() int UseFOV;
	UPROPERTY(EditAnywhere)								bool				bUseTriggered;		//var() bool bUseTriggered;
	UPROPERTY(EditAnywhere)								FName				SwitchState;		//var() name SwitchState;
	UPROPERTY(EditAnywhere)								UMaterialInstance* HUDCamOverlay;		//var() Material HUDCamOverlay;
	UPROPERTY()											bool				bSwitch;			//var bool bSwitch;
	UPROPERTY()											AHumanController* HC;					//var AGP.HumanController HC;

	void SetActive(bool Active);
	bool IsActive();
	void Trigger(AActor* Other, APawn* EventInstigator);
	bool UsedBy(APawn* User);
	bool IsError();
};
