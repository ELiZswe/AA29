// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/DemoRecSpectator/DemoRecSpectator.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoard.h"

ADemoRecSpectator::ADemoRecSpectator()
{
	//RemoteRole = ROLE_AutonomousProxy;
	//bDemoOwner = true;
}

/*
auto State Spectating
{
	exec Function Fire(float F)
	{
		bBehindView=false;
		DemoViewNextPlayer();
	}
	exec Function AltFire(float F)
	{
		bBehindView=(! bBehindView);
	}
	Event PlayerTick(float DeltaTime)
	{
		Super::PlayerTick(DeltaTime);
		if (((Role == 3) && ((RealViewTarget == nullptr) || (RealViewTarget == this))) && (! bFoundPlayer))
		{
			DemoViewNextPlayer();
			if ((RealViewTarget != nullptr) && (RealViewTarget != Self))
			{
				bFoundPlayer=true;
			}
		}
		if ((RealViewTarget != nullptr) && (RealViewTarget.Pawn == nullptr))
		{
			if (! bBehindView)
			{
				if (! bTempBehindView)
				{
					bTempBehindView=true;
					bBehindView=true;
				}
			}
		}
		else
		{
			if (bTempBehindView)
			{
				bBehindView=false;
				bTempBehindView=false;
			}
		}
	}
}
*/

void ADemoRecSpectator::PostBeginPlay()
{
	AHUD* HudClass = nullptr;
	AScoreBoard* ScoreboardClass = nullptr;
	/*
	if ((Role == 4) && (Level.Game != nullptr))
	{
		HudClass = class<HUD>(DynamicLoadObject(Level.Game.HUDType, Class'Class'));
		if (HudClass == nullptr)
		{
			Log("Can't find HUD class " $ Level.Game.HUDType, "Error");
		}
		ScoreboardClass = class<ScoreBoard>(DynamicLoadObject(Level.Game.ScoreBoardType, Class'Class'));
		if (ScoreboardClass == nullptr)
		{
			Log("Can't find HUD class " $ Level.Game.ScoreBoardType, "Error");
		}
		ClientSetHUD(HudClass, ScoreboardClass);
	}
	Super::PostBeginPlay();
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo.bOutOfLives = true;
	}
	*/
}

void ADemoRecSpectator::InitPlayerReplicationInfo()
{
	/*
	Super::InitPlayerReplicationInfo();
	PlayerReplicationInfo->PlayerName = "DemoRecSpectator";
	PlayerReplicationInfo->bIsSpectator = true;
	PlayerReplicationInfo->bOnlySpectator = true;
	PlayerReplicationInfo->bOutOfLives = true;
	PlayerReplicationInfo->bWaitingPlayer = false;
	*/
}

void ADemoRecSpectator::ViewClass(AActor* aClass, bool bQuiet, bool bCheat)
{
	AActor* Other = nullptr;
	AActor* first = nullptr;
	bool bFound = false;
	first = nullptr;
	/*
	ForEach AllActors(aClass, Other)
	{
		if (bFound || (first == nullptr))
		{
			first = Other;
			if (bFound)
			{
			}
		}
		else
		{
			if (Other == ViewTarget)
			{
				bFound = true;
			}
		}
	}
	if (first != nullptr)
	{
		SetViewTarget(first);
		bBehindView = (ViewTarget != Self);
		if (bBehindView)
		{
			ViewTarget.BecomeViewTarget();
		}
	}
	else
	{
		SetViewTarget(this);
	}
	*/
}

void ADemoRecSpectator::DemoViewNextPlayer()
{
	AController* C = nullptr;
	AController* pick = nullptr;
	bool bFound = false;
	/*
	if (PlayerController(RealViewTarget) != nullptr)
	{
		PlayerController(RealViewTarget).DemoViewer = nullptr;
	}
	ForEach DynamicActors(Class'Controller', C)
	{
		if (((C == this) || (PlayerController(C) == nullptr)) || (!PlayerController(C).IsSpectating()))
		{
			if ((GameReplicationInfo == nullptr) && (PlayerController(C) != nullptr))
			{
				GameReplicationInfo = PlayerController(C).GameReplicationInfo;
			}
			if (pick == nullptr)
			{
				pick = C;
			}
			if (bFound)
			{
				pick = C;
			}
			else
			{
			else
			{
				bFound = ((RealViewTarget == C) || (ViewTarget == C));
			}
			}
		}
	}
	SetViewTarget(pick);
	if (PlayerController(RealViewTarget) != nullptr)
	{
		PlayerController(RealViewTarget).DemoViewer = this;
	}
	*/
}

void ADemoRecSpectator::PlayerCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation)
{
	FRotator R = FRotator(0, 0, 0);
	/*
	if (RealViewTarget != nullptr)
	{
		R = RealViewTarget.Rotation;
	}
	Super::PlayerCalcView(ViewActor, CameraLocation, CameraRotation);
	if (RealViewTarget != nullptr)
	{
		if (!bBehindView)
		{
			CameraRotation = R;
			if (Pawn(ViewTarget) != nullptr)
			{
				(CameraLocation.Z += Pawn(ViewTarget).BaseEyeHeight);
			}
		}
		RealViewTarget.SetRotation(R);
	}
	*/
}
