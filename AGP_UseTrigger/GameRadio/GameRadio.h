// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_UseTrigger/AGP_UseTrigger.h"
#include "GameRadio.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGameRadio : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	AGameRadio();

	UPROPERTY()									int32 CurrentChannel;					//var int CurrentChannel;
	UPROPERTY(EditAnywhere)						bool bQuickChange;						//var() bool bQuickChange;
	UPROPERTY(EditAnywhere)						bool bCanTurnOff;						//var() bool bCanTurnOff;
	UPROPERTY(EditAnywhere)						bool bRandomChannel;					//var() bool bRandomChannel;
	UPROPERTY(EditAnywhere)						bool bStartOn;							//var() bool bStartOn;
	UPROPERTY(EditAnywhere)						int32 StartIndex;						//var() int StartIndex;
	UPROPERTY(EditAnywhere)						USoundBase* OffSound;					//var() Sound OffSound;
	UPROPERTY(EditAnywhere)						TArray<USoundBase*> SwitchNoises;		//var() array<Sound> SwitchNoises;
	UPROPERTY(EditAnywhere)						TArray<USoundBase*> RadioChannels;		//var() array<Sound> RadioChannels;
	UPROPERTY(EditAnywhere)						TArray<FString> GameRadioHelp;			//var(aaHelp) const editconst string GameRadioHelp;
};
