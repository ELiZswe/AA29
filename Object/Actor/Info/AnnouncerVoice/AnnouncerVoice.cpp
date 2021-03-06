// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/AnnouncerVoice/AnnouncerVoice.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"

AAnnouncerVoice::AAnnouncerVoice()
{
	AlternateFallbackSoundPackage = "AnnouncerAssault";
}

USoundBase* AAnnouncerVoice::GetSound(FName AName)
{
	USoundBase* NewSound = nullptr;
	int32 i = 0;
	/*
	for (i = 0; i < CachedSounds.Num(); i++)
	{
		if (AName == CachedSounds[i].CacheName)
		{
			return CachedSounds[i].CacheSound;
		}
	}
	NewSound = Sound(DynamicLoadObject(SoundPackage + "." + AName, 'Sound', true));
	if (NewSound == nullptr)
	{
		NewSound = PrecacheSound(AName);
	}
	*/
	return NewSound;
}

USoundBase* AAnnouncerVoice::PrecacheSound(FName AName)
{
	USoundBase* NewSound = nullptr;
	/*
	if (NewSound == nullptr && FallbackSoundPackage != "")
	{
		NewSound = PrecacheFallbackPackage(FallbackSoundPackage, AName);
	}
	if (NewSound == nullptr && AlternateFallbackSoundPackage != "")
	{
		NewSound = PrecacheFallbackPackage(AlternateFallbackSoundPackage, AName);
	}
	if (NewSound == nullptr)
	{
		Warn("Could not find " + AName + " in " + SoundPackage + " nor in fallback package " + FallbackSoundPackage + "nor in Alternate" + AlternateFallbackSoundPackage);
	}
	*/
	return NewSound;
}

USoundBase* AAnnouncerVoice::PrecacheFallbackPackage(FString Package, FName AName)
{
	USoundBase* NewSound = nullptr;
	int32 i = 0;
	/*
	NewSound = Sound(DynamicLoadObject(Package + "." + AName, 'Sound', true));
	if (NewSound != nullptr)
	{
		for (i = 0; i < CachedSounds.Num(); i++)
		{
			if (CachedSounds[i].CacheName == AName)
			{
				CachedSounds[i].CacheSound = NewSound;
				return NewSound;
			}
		}
		CachedSounds.Num() = CachedSounds.Num() + 1;
		CachedSounds[CachedSounds.Num() - 1].CacheName = AName;
		CachedSounds[CachedSounds.Num() - 1].CacheSound = NewSound;
		return NewSound;
	}
	*/
	return nullptr;
}

void AAnnouncerVoice::PrecacheAnnouncements(bool bRewardSounds)
{
	AGameInfo* GameClass = nullptr;
	AActor* A = nullptr;
	/*
	if (!bPrecachedGameSounds)
	{
		bPrecachedGameSounds = Level.GRI != nullptr && Level.GRI.GameClass != "";
		GameClass = Level.GetGameClass();
		GameClass.PrecacheGameAnnouncements(this, bRewardSounds);
	}
	ForEach DynamicActors('Actor', A)
	{
		A.PrecacheAnnouncer(this, bRewardSounds);
	}
	if (!bPrecachedBaseSounds)
	{
		bPrecachedBaseSounds = true;
		if (bRewardSounds)
		{
			PrecacheSound('Headshot');
			PrecacheSound('Headhunter');
			PrecacheSound('Berzerk');
			PrecacheSound('Booster');
			PrecacheSound('FlackMonkey');
			PrecacheSound('Combowhore');
			PrecacheSound('Invisible');
			PrecacheSound('Speed');
			PrecacheSound('Camouflaged');
			PrecacheSound('Pint_sized');
			PrecacheSound('first_blood');
			PrecacheSound('adrenalin');
			PrecacheSound('Double_Kill');
			PrecacheSound('MultiKill');
			PrecacheSound('MegaKill');
			PrecacheSound('UltraKill');
			PrecacheSound('MonsterKill_F');
			PrecacheSound('LudicrousKill_F');
			PrecacheSound('HolyShit_F');
			PrecacheSound('Killing_Spree');
			PrecacheSound('Rampage');
			PrecacheSound('Dominating');
			PrecacheSound('Unstoppable');
			PrecacheSound('GodLike');
			PrecacheSound('WhickedSick');
		}
		else
		{
			PrecacheSound('one');
			PrecacheSound('two');
			PrecacheSound('three');
			PrecacheSound('four');
			PrecacheSound('five');
			PrecacheSound('six');
			PrecacheSound('seven');
			PrecacheSound('eight');
			PrecacheSound('nine');
			PrecacheSound('ten');
		}
	}
	*/
}
