// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/DemoRecSpectator/DemoRecSpectator.h"
#include "AA29/AA2_PlayerState.h"

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
		if (((Role == 3) && ((RealViewTarget == nullptr) || (RealViewTarget == Self))) && (! bFoundPlayer))
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
	/*
	local class<HUD>  HudClass;
	local class<ScoreBoard>  ScoreboardClass;
	if ((Role == 4) && (Level.Game != None))
	{
		HudClass = class<HUD>(DynamicLoadObject(Level.Game.HUDType, Class'Class'));
		if (HudClass == None)
		{
			Log("Can't find HUD class " $ Level.Game.HUDType, "Error");
		}
		ScoreboardClass = class<ScoreBoard>(DynamicLoadObject(Level.Game.ScoreBoardType, Class'Class'));
		if (ScoreboardClass == None)
		{
			Log("Can't find HUD class " $ Level.Game.ScoreBoardType, "Error");
		}
		ClientSetHUD(HudClass, ScoreboardClass);
	}
	Super::PostBeginPlay();
	if (PlayerReplicationInfo != None)
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
	/*
	local Actor Other;
	local Actor first;
	bool bFound = false;
	first = None;
	ForEach AllActors(aClass, Other)
	{
		if (bFound || (first == None))
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
	if (first != None)
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
		SetViewTarget(Self);
	}
	*/
}

void ADemoRecSpectator::DemoViewNextPlayer()
{
	/*
	local Controller C;
	local Controller pick;
	bool bFound = false;
	if (PlayerController(RealViewTarget) != None)
	{
		PlayerController(RealViewTarget).DemoViewer = None;
	}
	ForEach DynamicActors(Class'Controller', C)
	{
		if (((C == Self) || (PlayerController(C) == None)) || (!PlayerController(C).IsSpectating()))
		{
			if ((GameReplicationInfo == None) && (PlayerController(C) != None))
			{
				GameReplicationInfo = PlayerController(C).GameReplicationInfo;
			}
			if (pick == None)
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
	if (PlayerController(RealViewTarget) != None)
	{
		PlayerController(RealViewTarget).DemoViewer = Self;
	}
	*/
}

void ADemoRecSpectator::PlayerCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation)
{
	FRotator R = FRotator(0, 0, 0);
	/*
	if (RealViewTarget != None)
	{
		R = RealViewTarget.Rotation;
	}
	Super::PlayerCalcView(ViewActor, CameraLocation, CameraRotation);
	if (RealViewTarget != None)
	{
		if (!bBehindView)
		{
			CameraRotation = R;
			if (Pawn(ViewTarget) != None)
			{
				(CameraLocation.Z += Pawn(ViewTarget).BaseEyeHeight);
			}
		}
		RealViewTarget.SetRotation(R);
	}
	*/
}
