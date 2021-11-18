// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "AnnouncerVoice.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAnnouncerVoice : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAnnouncerVoice();

	UPROPERTY()			bool bEnglishOnly;							//var const bool bEnglishOnly;
	UPROPERTY()			bool bPrecachedGameSounds;							//var bool bPrecachedGameSounds;
	UPROPERTY()			bool bPrecachedBaseSounds;							//var bool bPrecachedBaseSounds;
	UPROPERTY()			TArray<FCachedSound> CachedSounds;							//var array<CachedSound> CachedSounds;
	UPROPERTY()			FString AnnouncerName;							//var localized string AnnouncerName;
	UPROPERTY()			FString AlternateFallbackSoundPackage;							//var string AlternateFallbackSoundPackage;
	UPROPERTY()			FString FallbackSoundPackage;							//var string FallbackSoundPackage;
	UPROPERTY()			FString SoundPackage;							//var string SoundPackage;


	void GetSound(FName AName);
	void PrecacheSound(FName AName);
	void PrecacheFallbackPackage(FString Package, FName AName);
	void PrecacheAnnouncements(bool bRewardSounds);



};
