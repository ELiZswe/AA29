// All the original content belonged to the US Army


#include "AA29/Info/AnnouncerVoice/AnnouncerVoice.h"

AAnnouncerVoice::AAnnouncerVoice()
{
	AlternateFallbackSoundPackage = "AnnouncerAssault";
}


void AAnnouncerVoice::GetSound(FName AName)
{
	/*
	local Sound NewSound;
	local int i;
	for (i = 0; i < CachedSounds.Length; i++)
	{
		if (AName == CachedSounds[i].CacheName)
		{
			Return CachedSounds[i].CacheSound;
		}
	}
	NewSound = Sound(DynamicLoadObject(SoundPackage $ "." $ AName, 'Sound', true));
	if (NewSound == None)
	{
		NewSound = PrecacheSound(AName);
	}
	Return NewSound;
	*/
}
void AAnnouncerVoice::PrecacheSound(FName AName)
{
	/*
	local Sound NewSound;
	NewSound = Sound(DynamicLoadObject(SoundPackage $ "." $ AName, 'Sound', true));
	if (NewSound == None && FallbackSoundPackage != "")
	{
		NewSound = PrecacheFallbackPackage(FallbackSoundPackage, AName);
	}
	if (NewSound == None && AlternateFallbackSoundPackage != "")
	{
		NewSound = PrecacheFallbackPackage(AlternateFallbackSoundPackage, AName);
	}
	if (NewSound == None)
	{
		Warn("Could not find " $ AName $ " in " $ SoundPackage $ " nor in fallback package " $ FallbackSoundPackage $ "nor in Alternate" $ AlternateFallbackSoundPackage);
	}
	Return NewSound;
	*/
}
void AAnnouncerVoice::PrecacheFallbackPackage(FString Package, FName AName)
{
	/*
	local Sound NewSound;
	local int i;
	NewSound = Sound(DynamicLoadObject(Package $ "." $ AName, 'Sound', true));
	if (NewSound != None)
	{
		for (i = 0; i < CachedSounds.Length; i++)
		{
			if (CachedSounds[i].CacheName == AName)
			{
				CachedSounds[i].CacheSound = NewSound;
				Return NewSound;
			}
		}
		CachedSounds.Length = CachedSounds.Length + 1;
		CachedSounds[CachedSounds.Length - 1].CacheName = AName;
		CachedSounds[CachedSounds.Length - 1].CacheSound = NewSound;
		Return NewSound;
	}
	Return None;
	*/
}
void AAnnouncerVoice::PrecacheAnnouncements(bool bRewardSounds)
{
	/*
	local class<GameInfo>  GameClass;
	local Actor A;
	if (!bPrecachedGameSounds)
	{
		bPrecachedGameSounds = Level.GRI != None && Level.GRI.GameClass != "";
		GameClass = Level.GetGameClass();
		GameClass.PrecacheGameAnnouncements(Self, bRewardSounds);
	}
	ForEach DynamicActors('Actor', A)
	{
		A.PrecacheAnnouncer(Self, bRewardSounds);
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
