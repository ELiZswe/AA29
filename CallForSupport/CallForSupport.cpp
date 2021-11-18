// All the original content belonged to the US Army


#include "CallForSupport.h"

// Sets default values
ACallForSupport::ACallForSupport()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	TeamNumber = 255;
	
	RadioSound						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone.commo_keymicrophone'"), NULL, LOAD_None, NULL);								//RadioSound = Sound'S_AA2_PlayerCommo.General.commo_keymicrophone'
	RequestSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_CoverMe.Voice1_Radio_CoverMe'"), NULL, LOAD_None, NULL);								//RequestSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_CoverMe'
	ConfirmSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Roger.Voice1_Radio_Roger'"), NULL, LOAD_None, NULL);									//ConfirmSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_Roger'
	AvailableSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Hooah.Voice1_Radio_Hooah'"), NULL, LOAD_None, NULL);									//AvailableSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_Hooah'
	AcknowledgeSound				= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemySpotted.Voice1_Radio_EnemySpotted'"), NULL, LOAD_None, NULL);					//AcknowledgeSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_EnemySpotted'
	RespondSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_TakeCover.Voice1_Radio_TakeCover'"), NULL, LOAD_None, NULL);							//RespondSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_TakeCover'
	StrikeSound						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemyDown.Voice1_Radio_EnemyDown'"), NULL, LOAD_None, NULL);							//StrikeSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_EnemyDown'
	ReadySound						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Ready.Voice1_Radio_Ready'"), NULL, LOAD_None, NULL);									//ReadySound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_Ready'
	HooahSound						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Hooah.Voice1_Radio_Hooah'"), NULL, LOAD_None, NULL);									//HooahSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_Hooah'
	RogerSound						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Roger.Voice1_Radio_Roger'"), NULL, LOAD_None, NULL);									//RogerSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_Roger'
	AreaSecureSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_AreaSecure.Voice1_Radio_AreaSecure'"), NULL, LOAD_None, NULL);						//AreaSecureSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_AreaSecure'
	CoverMeSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_CoverMe.Voice1_Radio_CoverMe'"), NULL, LOAD_None, NULL);								//CoverMeSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_CoverMe'
	TakeCoverSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_TakeCover.Voice1_Radio_TakeCover'"), NULL, LOAD_None, NULL);							//TakeCoverSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_TakeCover'
	EnemySpottedSound				= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemySpotted.Voice1_Radio_EnemySpotted'"), NULL, LOAD_None, NULL);					//EnemySpottedSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_EnemySpotted'
	EnemyDownSound					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemyDown.Voice1_Radio_EnemyDown'"), NULL, LOAD_None, NULL);							//EnemyDownSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_EnemyDown'
	SquadLeaderHooahSound			= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Hooah.Voice1_Radio_Hooah'"), NULL, LOAD_None, NULL);									//SquadLeaderHooahSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_Hooah'
	SquadLeaderRogerSound			= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_Roger.Voice1_Radio_Roger'"), NULL, LOAD_None, NULL);									//SquadLeaderRogerSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_Roger'
	SquadLeaderAreaSecureSound		= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_AreaSecure.Voice1_Radio_AreaSecure'"), NULL, LOAD_None, NULL);						//SquadLeaderAreaSecureSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_AreaSecure'
	SquadLeaderCoverMeSound			= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_CoverMe.Voice1_Radio_CoverMe'"), NULL, LOAD_None, NULL);								//SquadLeaderCoverMeSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_CoverMe'
	SquadLeaderTakeCoverSound		= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_TakeCover.Voice1_Radio_TakeCover'"), NULL, LOAD_None, NULL);							//SquadLeaderTakeCoverSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_TakeCover'
	SquadLeaderEnemySpottedSound	= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemySpotted.Voice1_Radio_EnemySpotted'"), NULL, LOAD_None, NULL);					//SquadLeaderEnemySpottedSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_EnemySpotted'
	SquadLeaderEnemyDownSound		= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Radio_EnemyDown.Voice1_Radio_EnemyDown'"), NULL, LOAD_None, NULL);							//SquadLeaderEnemyDownSound = Sound'S_AA2_PlayerCommo.voice1.Voice1_Radio_EnemyDown'
	SquadLeaderEnemyEliminatedSound	= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_OpposingForcesEliminated.SquadLeader_Radio_OpposingForcesEliminated'"), NULL, LOAD_None, NULL);					//SquadLeaderEnemyEliminatedSound = Sound'S_AA2_PlayerCommo.SquadLeader.SquadLeader_Radio_OpposingForcesEliminated'
	bAlwaysRelevant = true;
	//bOnlyDirtyReplication = true;
	//Texture = Texture'T_AA2_Editor.Engine.AGP_Objective'
	//Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_fill.hud_goal_fill'"), NULL, LOAD_None, NULL),
	//SoundVolume = 0;
}

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

