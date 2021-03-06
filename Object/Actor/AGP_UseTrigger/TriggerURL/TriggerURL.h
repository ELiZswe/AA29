// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "TriggerURL.generated.h"

UCLASS()
class ATriggerURL : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	ATriggerURL();

	UPROPERTY(EditAnywhere)			bool		bDisableUse;			//var() bool bDisableUse;
	UPROPERTY(EditAnywhere)			FString		DynamicLinkName;		//var() string DynamicLinkName;
	UPROPERTY(EditAnywhere)			bool		bDynamicLink;			//var() bool bDynamicLink;
	UPROPERTY(EditAnywhere)			bool		bDisconnect;			//var() bool bDisconnect;
	UPROPERTY(EditAnywhere)			FString		Caption;				//var() string Caption;
	UPROPERTY(EditAnywhere)			FString		URL;					//var() string URL;

	bool UsedBy(APawn* User);
	void Trigger(AActor* Other, APawn* EventInstigator);
};
