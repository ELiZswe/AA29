// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "TurretTrigger.generated.h"

class AHumanController;

UCLASS()
class ATurretTrigger : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	ATurretTrigger();

	UPROPERTY()						AActor*				AssociatedActor;		//var Actor AssociatedActor;
	UPROPERTY()						AController*		C;						//var Controller C;
	UPROPERTY()						AHumanController*	HC;						//var AGP.HumanController HC;
	UPROPERTY()						bool				bSwitch;				//var bool bSwitch;
	UPROPERTY(EditAnywhere)			FName				ReturnState;			//var() name ReturnState;
	UPROPERTY(EditAnywhere)			FName				SwitchState;			//var() name SwitchState;
	UPROPERTY(EditAnywhere)			bool				bToggle;				//var() bool bToggle;
	UPROPERTY(EditAnywhere)			bool				bUseTriggered;			//var() bool bUseTriggered;
	UPROPERTY(EditAnywhere)			int32				UseFOV;					//var() int UseFOV;
	UPROPERTY(EditAnywhere)			FName				ViewActorTag;			//var() name ViewActorTag;

	void SetActive(bool Active);
	bool IsActive();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
	bool UsedBy(APawn* User);
	bool IsError();
	FRotator LookRotation(FVector LookActorLoc, FVector TargetActorLoc);
};
