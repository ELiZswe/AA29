// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/AA29.h"
#include "AnnouncerVoice.generated.h"

UCLASS()
class AAnnouncerVoice : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAnnouncerVoice();

	UPROPERTY()			bool					bEnglishOnly;							//var const bool bEnglishOnly;
	UPROPERTY()			bool					bPrecachedGameSounds;					//var bool bPrecachedGameSounds;
	UPROPERTY()			bool					bPrecachedBaseSounds;					//var bool bPrecachedBaseSounds;
	UPROPERTY()			TArray<FCachedSound>	CachedSounds;							//var array<CachedSound> CachedSounds;
	UPROPERTY()			FString					AnnouncerName;							//var localized string AnnouncerName;
	UPROPERTY()			FString					AlternateFallbackSoundPackage;			//var string AlternateFallbackSoundPackage;
	UPROPERTY()			FString					FallbackSoundPackage;					//var string FallbackSoundPackage;
	UPROPERTY()			FString					SoundPackage;							//var string SoundPackage;

	USoundBase* GetSound(FName AName);
	USoundBase* PrecacheSound(FName AName);
	USoundBase* PrecacheFallbackPackage(FString Package, FName AName);
	void PrecacheAnnouncements(bool bRewardSounds);
};
