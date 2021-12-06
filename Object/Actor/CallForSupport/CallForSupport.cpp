// All the original content belonged to the US Army


#include "CallForSupport.h"

// Sets default values
ACallForSupport::ACallForSupport()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TeamNumber = 255;
	RadioSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Que.commo_keymicrophone_Que'"), NULL, LOAD_None, NULL);
	RequestSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_CoverMe_Que.Voice1_Radio_CoverMe_Que'"), NULL, LOAD_None, NULL);
	ConfirmSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Roger_Que.Voice1_Radio_Roger_Que'"), NULL, LOAD_None, NULL);
	AvailableSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Hooah_Que.Voice1_Radio_Hooah_Que'"), NULL, LOAD_None, NULL);
	AcknowledgeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemySpotted_Que.Voice1_Radio_EnemySpotted_Que'"), NULL, LOAD_None, NULL);
	RespondSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_TakeCover_Que.Voice1_Radio_TakeCover_Que'"), NULL, LOAD_None, NULL);
	StrikeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemyDown_Que.Voice1_Radio_EnemyDown_Que'"), NULL, LOAD_None, NULL);
	ReadySound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Ready_Que.Voice1_Radio_Ready_Que'"), NULL, LOAD_None, NULL);
	HooahSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Hooah_Que.Voice1_Radio_Hooah_Que'"), NULL, LOAD_None, NULL);
	RogerSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Roger_Que.Voice1_Radio_Roger_Que'"), NULL, LOAD_None, NULL);
	AreaSecureSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_AreaSecure_Que.Voice1_Radio_AreaSecure_Que'"), NULL, LOAD_None, NULL);
	CoverMeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_CoverMe_Que.Voice1_Radio_CoverMe_Que'"), NULL, LOAD_None, NULL);
	TakeCoverSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_TakeCover_Que.Voice1_Radio_TakeCover_Que'"), NULL, LOAD_None, NULL);
	EnemySpottedSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemySpotted_Que.Voice1_Radio_EnemySpotted_Que'"), NULL, LOAD_None, NULL);
	EnemyDownSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemyDown_Que.Voice1_Radio_EnemyDown_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderHooahSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Hooah_Que.Voice1_Radio_Hooah_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderRogerSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Roger_Que.Voice1_Radio_Roger_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderAreaSecureSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_AreaSecure_Que.Voice1_Radio_AreaSecure_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderCoverMeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_CoverMe_Que.Voice1_Radio_CoverMe_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderTakeCoverSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_TakeCover_Que.Voice1_Radio_TakeCover_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderEnemySpottedSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemySpotted_Que.Voice1_Radio_EnemySpotted_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderEnemyDownSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemyDown_Que.Voice1_Radio_EnemyDown_Que'"), NULL, LOAD_None, NULL);
	SquadLeaderEnemyEliminatedSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_OpposingForcesEliminated_Que.SquadLeader_Radio_OpposingForcesEliminated_Que'"), NULL, LOAD_None, NULL);
	bAlwaysRelevant = true;
	//bOnlyDirtyReplication = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Objective_Mat.AGP_Objective_Mat'"), NULL, LOAD_None, NULL);
	//SoundVolume = 0;
}

/*
auto State Waiting
{
	simulated Function bool CheckMark(Pawn Aimer, Vector TestMark, bool bFire)
	{
		return true;
	}
	Function BeginState()
	{
		bAvailable=false;
		bReady=false;
		bFiring=false;
	}
	Function EndState()
	{
		bAvailable=true;
	}
Begin:
	Sleep(RandRange(ArrivalTime,float(Rand(int(ArrivalTime)))));
	if (StrikesAvailable > 0)
	{
		GetInPosition();
		GotoState('Available');
	}
}
State Available
{
	Function BeginState()
	{
	}
	Function CallForSupport(PlayerController PC)
	{
		Caller=PC;
		Acknowledge();
		GotoState('Ready');
	}
	Function EndState()
	{
		bReady=true;
	}
}
State Ready
{
	Function BeginState()
	{
	}
	Function CallForSupport(PlayerController PC)
	{
		Caller=PC;
		Respond();
		GotoState('FireSequence');
	}
	Function EndState()
	{
		StrikesAvailable --;
		bFiring=true;
	}
}
State FireSequence
{
	Function BeginState()
	{
	}
	simulated Function bool IsFiring()
	{
		return true;
	}
	Function CallForSupport(PlayerController PC)
	{
		if (IsFiring())
		{
			return;
		}
	}
	Function EndState()
	{
	}
Begin:
	Sleep(RandRange(ArrivalTime,float(Rand(int(ArrivalTime)))));
	Strike();
	Sleep(RandRange(ArrivalTime,float(Rand(int(ArrivalTime)))));
	GotoState('Waiting');
}
*/

// Called when the game starts or when spawned
void ACallForSupport::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACallForSupport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ACallForSupport::Reset()
{
	Super::Reset();
	StrikesAvailable = InitialStrikesAvailable;
}
void ACallForSupport::GetInPosition()
{
	if (Caller != NULL)
	{
		//Caller.PlayOwnedSound(AvailableSound,5,SoundVolume,,,,False,False);
	}
}
void ACallForSupport::Acknowledge()
{
	if (Caller != NULL)
	{
		//Caller.PlayOwnedSound(AcknowledgeSound,5,SoundVolume,,,,False,False);
	}
}
void ACallForSupport::Respond()
{
	if (Caller != NULL)
	{
		//Caller.PlayOwnedSound(RespondSound,5,SoundVolume,,,,False,False);
	}
}
void ACallForSupport::Strike()
{
	if (Caller != NULL)
	{
		//Caller.PlayOwnedSound(StrikeSound,5,SoundVolume,,,,False,False);
	}
}
void ACallForSupport::CallForSupport(APlayerController* PC)
{
	Caller=PC;
}
bool ACallForSupport::CheckMark(APawn* Aimer, FVector TestMark, bool bFire)
{
	return true;
}
bool ACallForSupport::IsFiring()
{
	return bFiring;
}
bool ACallForSupport::IsReady()
{
	return bReady;
}
bool ACallForSupport::IsAvailable()
{
	return bAvailable;
}
int32 ACallForSupport::GetNumStrikesAvailable()
{
	return StrikesAvailable;
}
uint8 ACallForSupport::GetTeamNumber()
{
	return TeamNumber;
}

