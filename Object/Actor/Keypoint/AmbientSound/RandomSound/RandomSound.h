// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Sound/AmbientSound.h"
#include "AA29/AA29.h"
#include "RandomSound.generated.h"

UCLASS()
class ARandomSound : public AAmbientSound
{
	GENERATED_BODY()
public:
	ARandomSound();

	UPROPERTY()																float _fClipLength;						//var float _fClipLength;
	UPROPERTY(EditAnywhere, Category = "Sound")			bool bPlayerLocal;						//var(Sound) bool bPlayerLocal;
	UPROPERTY(EditAnywhere, Category = "Sound")			AActor* optionalSource;					//var(Sound) Actor optionalSource;
	UPROPERTY(EditAnywhere, Category = "Sound")			bool bEnabled;							//var(Sound) bool bEnabled;
	UPROPERTY(EditAnywhere, Category = "Sound")			float fMaxRepeat;						//var(Sound) float fMaxRepeat;
	UPROPERTY(EditAnywhere, Category = "Sound")			float fMinRepeat;						//var(Sound) float fMinRepeat;
	UPROPERTY(EditAnywhere, Category = "Sound")			USoundBase* MySound;					//var(Sound) Sound MySound;

	//From AmbientsSounds
	UPROPERTY(EditAnywhere, Category = "Sound")			TArray<FSoundEmitter> SoundEmitters;	//var(Sound) array<SoundEmitter> SoundEmitters;


	//Mine
	FTimerHandle THSound;

	void PreBeginPlay();
	void BeginPlay();
	void _setTimer();
	void Timer();
	void EnableSound();
	void DisableSound();
	void PlaySound();
};
