// All the original content belonged to the US Army


#include "AA2_GameMode.h"
#include "AA29/HUD/AGP_HUD/AGP_HUD.h"
#include "Kismet/GameplayStatics.h"


#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"

#include "AA29/AA2_GameState.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"

#include "AA29/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_M24_Sniper.h"
#include "Engine/World.h"

#include "AA29.h"

AAA2_GameMode::AAA2_GameMode()
{
	DefaultPawnClass = AAGP_Character::StaticClass();
	HUDClass = AAGP_HUD::StaticClass();
	PlayerControllerClass = AHumanController::StaticClass();
	GameStateClass = AAA2_GameState::StaticClass();
	PlayerStateClass = AAA2_PlayerState::StaticClass();
	//SaveConfig();
}

void AAA2_GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
void AAA2_GameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Yellow, TEXT("AA2_GameMode::StartPlay"));
	}
}
void AAA2_GameMode::StartRound()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Yellow, TEXT("AA2_GameMode::StartRound"));
	}
}

void AAA2_GameMode::StartMatch()
{
	StartRound();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Yellow, TEXT("AA2_GameMode::StartMatch"));
	}
}


void AAA2_GameMode::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AAA2_GameMode::BeginPlay()"));
	Super::BeginPlay();
}

AActor* AAA2_GameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	TArray<AActor*> PlayerStarts;
	FString myName;
	TSubclassOf <class ASoldierClass> myClass;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAGP_PlayerStart::StaticClass(), PlayerStarts);
	for (int32 i = 0; i < PlayerStarts.Num(); i++)
	{
		AAGP_PlayerStart* TestStart = Cast<AAGP_PlayerStart>(PlayerStarts[i]);
		if (TestStart->bUsed == false)
		{
			TestStart->bUsed = true;
			AHumanController* OwnerController = Cast<AHumanController>(Player);
			if (OwnerController != NULL)
			{
				AAA2_PlayerState* PlayerState = Cast<AAA2_PlayerState>(OwnerController->PlayerState);
				if (PlayerState != NULL)
				{
					PlayerState->TeamID          = TestStart->TeamNumber;
					PlayerState->SpawnClass      = TestStart->GetSpawnClass();
					//PlayerState->CurrentWeapon   = TestStart->GetSpawnClass();
				}
			}

			if (GEngine)
			{
				myClass = TestStart->GetSpawnClass();
				if(myClass != NULL)
				{
					myName = "";
					myName = TestStart->GetSpawnClass()->GetName();
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("This playerstart is a %s"), *myName));
				}
			}
			return TestStart;
		}
	}
	return NULL;
}

bool AAA2_GameMode::IsRequireAuthorization()
{
	return true;
}

FString AAA2_GameMode::StripColor(FString S)
{
	int32 p;
	S.FindChar(TCHAR(27), p);		//	p = InStr(S, chr(27));
	while (p >= 0)
	{
		S.RemoveAt(p, 4);			//	S = left(S, p)$mid(S, p + 4);
		S.FindChar(TCHAR(27), p);	//p = InStr(S, Chr(27));
	}
	return S;
}

//from GameInfo
bool AAA2_GameMode::CheatsDisabled()
{
	return false;    //FAKE  /ELiZ
}