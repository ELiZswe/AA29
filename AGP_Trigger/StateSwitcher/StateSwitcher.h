// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "StateSwitcher.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AStateSwitcher : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	AStateSwitcher();

	UPROPERTY()									FName OriginalState;						//var name OriginalState;
	UPROPERTY()									AController* C;								//var Controller C;
	UPROPERTY()									bool bSwitch;								//var bool bSwitch;
	UPROPERTY(EditAnywhere)						bool bToggle;								//var() bool bToggle;
	UPROPERTY(EditAnywhere)						bool bReturnToOriginal;						//var() bool bReturnToOriginal;
	UPROPERTY(EditAnywhere)						FName ReturnState;							//var() name ReturnState;
	UPROPERTY(EditAnywhere)						FName SwitchState;							//var() name SwitchState;



	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
	bool IsError();

};
