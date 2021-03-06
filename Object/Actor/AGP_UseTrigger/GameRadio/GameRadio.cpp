// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_UseTrigger/GameRadio/GameRadio.h"

AGameRadio::AGameRadio()
{
	GameRadioHelp.SetNum(12);
	GameRadioHelp = {"A radio with changeable stations. Load up the ","RadioChannels array with your desired sounds.","","[RadioChannels] The sounds that represent radio channels.","[SwitchNoises] The sounds that represent changing stations.","[OffSound] The sound to make when radio turns off.","[StartIndex] The channel index to start out with.","[bStartOn] Whether the radio should play on level load.","[bRandomChannel] Whether changing stations picks random channels.","[bCanTurnOff] Whether user can turn off radio.","[bQuickChange] Whether channels can be changed while switch","noises are playing."};

	SwitchNoises = {
		LoadObject<USoundBase>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_AA2_UseTrigger.S_AA2_UseTrigger'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_AA2_UseTrigger.S_AA2_UseTrigger'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_AA2_UseTrigger.S_AA2_UseTrigger'"), NULL, LOAD_None, NULL)
	};
	bStartOn = true;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/electronics/eqp_electronics_amradio.eqp_electronics_amradio'"), NULL, LOAD_None, NULL);
	//bHidden = false;
	//DrawScale = 2;
}

void AGameRadio::BeginPlay()
{
	CurrentChannel = StartIndex;
	if (bStartOn)
	{
		if (bRandomChannel)
		{
			//ChangeStation(Rand(RadioChannels.Num()), true);
		}
		else
		{
			//ChangeStation(CurrentChannel, true);
		}
	}
	else
	{
		//AmbientSound = nullptr;
	}
}

bool AGameRadio::UsedBy(APawn* User)
{
	if (bDisabled)
	{
		return true;
	}
	if (!bQuickChange)
	{
		bDisabled = true;
	}
	if (bRandomChannel)
	{
		//ChangeStation(Rand(RadioChannels.Num()));
	}
	else
	{
		CurrentChannel++;
		if (CurrentChannel >= RadioChannels.Num())
		{
			if (bCanTurnOff)
			{
				CurrentChannel = -1;
			}
			else
			{
				CurrentChannel = 0;
			}
		}
		ChangeStation(CurrentChannel,false);
		//Log("GameRadio::UsedBy(): Current channel is: " @ FString::FromInt(CurrentChannel));
	}
	return false;    //FAKE   /ELiZ
}

void AGameRadio::ChangeStation(int32 Channel, bool bNoStatic)
{
	USoundBase* CurrentNoise = nullptr;
	float SoundDuration = 0;
	/*
	if ((Channel >= RadioChannels.Num()) || (Channel < 0))
	{
		if (bCanTurnOff && (Channel == -1))
		{
			if (OffSound != nullptr)
			{
				SetTimer(0, false);
				AmbientSound = nullptr;
				PlaySound(OffSound);
				return;
			}
			else
			{
				Log("GameRadio::ChangeStation(): OffSound not set");
				return;
			}
		}
		else
		{
			Log("GameRadio::ChangeStation(): Channel index " + FString::FromInt(Channel) + " out of range");
			return;
		}
	}
	else
	{
		if (bNoStatic)
		{
			SetTimer(0.01, false);
			return;
		}
		CurrentNoise = SwitchNoises[Rand(SwitchNoises.Num())];
		SoundDuration = GetSoundDuration(CurrentNoise);
		AmbientSound = CurrentNoise;
		SetTimer(SoundDuration, false);
	}
	*/
}

void AGameRadio::Timer()
{
	//AmbientSound = RadioChannels[CurrentChannel];
	bDisabled = false;
}
