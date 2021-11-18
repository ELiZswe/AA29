// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_UseTrigger/AGP_UseTrigger.h"
#include "TriggerUI.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATriggerUI : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	ATriggerUI();

	UPROPERTY(EditAnywhere)						FString UIPage;							//var() string UIPage;
	UPROPERTY(EditAnywhere)						FString UIParam1;						//var() string UIParam1;
	UPROPERTY(EditAnywhere)						FString UIParam2;						//var() string UIParam2;
	UPROPERTY(EditAnywhere)						bool bDisconnect;						//var() bool bDisconnect;
	UPROPERTY()									bool bDebug;							//var bool bDebug;

};
