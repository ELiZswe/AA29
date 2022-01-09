// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyEnums.h"
#include "SoundParameters.generated.h"

UCLASS()
class USoundParameters : public UObject
{
	GENERATED_BODY()
public:
	USoundParameters();

	UPROPERTY(EditAnywhere)						bool bAttenuate;								//var() bool bAttenuate;
	UPROPERTY(EditAnywhere)						float Pitch;									//var() float Pitch;
	UPROPERTY(EditAnywhere)						float Radius;									//var() float Radius;
	UPROPERTY(EditAnywhere)						bool bNoOverride;								//var() bool bNoOverride;
	UPROPERTY(EditAnywhere)						float Volume;									//var() float Volume;
	UPROPERTY(EditAnywhere)						ESoundSlot Slot;								//var() Object.ESoundSlot Slot;
	UPROPERTY(EditAnywhere)						USoundBase* SoundPtr;							//var() Sound SoundPtr;
};
