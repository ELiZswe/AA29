// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AmbientSound/RandomSound/RandomSound.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"

ARandomSound::ARandomSound()
{

}

void ARandomSound::PreBeginPlay()
{
	/*
	if ((((fMaxRepeat >= 0) && (fMinRepeat >= 0)) && (fMaxRepeat >= fMinRepeat)) && (MySound != nullptr))
	{
		_setTimer();
		_fClipLength = GetSoundDuration(MySound);
	}
	else
	{
		DebugLog(DEBUG_Warn, "RandomSound::PreBeginPlay()	Unable to initialize RandomSound " + FString::FromInt(MySound));
		if (fMaxRepeat < fMinRepeat)
		{
			DebugLog(DEBUG_Warn, "RandomSound::PreBeginPlay()  max<min");
		}
		if (MySound == nullptr)
		{
			DebugLog(DEBUG_Warn, "RandomSound::PreBeginPlay()  sound is none");
		}
	}
	*/
}

void ARandomSound::BeginPlay()
{
	//SetSound(MySound);
	//Sound = MySound;

}

void ARandomSound::_setTimer()
{
	
	float _time;
	_time = (FMath::FRand() * (fMaxRepeat - fMinRepeat)) + fMinRepeat;
	_time += _fClipLength;

	GetWorld()->GetTimerManager().SetTimer(THSound, this, &ARandomSound::PlaySound, _time, true);
	GetWorld()->GetTimerManager().UnPauseTimer(THSound);
}

void ARandomSound::Timer()
{
	//Super::Timer;
	AActor* soundsource = nullptr;
	AActor* listener = nullptr;
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		return;
	}
	/*
	if (bEnabled)
	{
		listener = Level.GetClientController();
		if (listener != nullptr && Cast<AController>(listener).Pawn != nullptr)
		{
			listener = Cast<AController>(listener).Pawn;
		}
		switch(eZoneFilter)
		{
				case 1:
					if (!listener.Region.Zone.bIndoorZone)
					{
						_setTimer();
						return;
					}
					break;
				case 2:
					if (listener.Region.Zone.bIndoorZone)
					{
						_setTimer();
						return;
					}
					break;
				case 3:
					if (optionalSource == nullptr)
					{
						if (listener.Region.ZoneNumber != Region.ZoneNumber)
						{
							_setTimer();
							return;
						}
					}
					else
					{
						if (listener.Region.ZoneNumber != optionalSource.Region.ZoneNumber)
						{
							_setTimer();
							return;
						}
					}
				default:
		}
		if (optionalSource == nullptr)
		{
			soundsource = this;
		}
		else
		{
			soundsource = optionalSource;
		}
		if (bPlayerLocal)
		{
			Level.GetClientPawn().PlaySound(MySound, 0, SoundVolume / 255, false, SoundRadius, SoundPitch / 64);
		}
		else
		{
			soundsource.PlayOwnedSound(MySound, 0, SoundVolume / 255, false, SoundRadius, SoundPitch / 64);
		}
		_setTimer();
	}
	*/
}

void ARandomSound::PlaySound()
{
	float SoundVolume = 255;
	float SoundPitch = 64;

	USoundAttenuation* AS = LoadObject<USoundAttenuation>(NULL, TEXT("SoundAttenuation'/Game/AmericasArmy/Sounds/AA2_DefaultAttenuation.AA2_DefaultAttenuation'"), NULL, LOAD_None, NULL);

	GetWorld()->GetTimerManager().PauseTimer(THSound);
	UGameplayStatics::SpawnSoundAttached(MySound, this->GetRootComponent(), NAME_None, FVector(0, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, AS, nullptr, true);
	//UGameplayStatics::SpawnSoundAttached(MySound, this->GetRootComponent(), NAME_None, FVector(0, 0, 0), EAttachLocation::KeepWorldPosition, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
	
	_setTimer();
}

void ARandomSound::EnableSound()
{
	if (!bEnabled)
	{
		bEnabled = true;
		//_setTimer();
	}
}
void ARandomSound::DisableSound()
{
	if (bEnabled)
	{
		bEnabled = false;
		//SetTimer(0, false);
	}
}
