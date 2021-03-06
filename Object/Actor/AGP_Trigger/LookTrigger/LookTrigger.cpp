// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Trigger/LookTrigger/LookTrigger.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ALookTrigger::ALookTrigger()
{
	TargetDistance = 1024;
	TargetLookTime = 1;
	TargetAngle = 0.99;
	bStartOn = true;
	//bAcceptsProjectors = false;
	//Texture = Texture'Engine.S_Actor';
	//CollisionRadius = 32;
	//CollisionHeight = 32;
	//bCollideActors = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//bDirectional = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

void ALookTrigger::PostBeginPlay()
{
	//Super::PostBeginPlay();
	SetActive(bStartOn);
}
void ALookTrigger::MatchStarting()
{
	SetActive(bStartOn);
	LookTime = 0;
	bPlayerIsLooking = false;
}
void ALookTrigger::Tick(float DeltaTime)
{
	/*
	if (!bInit)
	{
		bInit = true;
		Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
	}
	if (bActive)
	{
		TrackPlayer(DeltaTime);
	}
	else
	{
		LookTime = 0;
		bPlayerIsLooking = false;
	}
	*/
}
void ALookTrigger::TrackPlayer(float DeltaTime)
{
	bool bDist = false;
	/*
	bDist = VSize(Player.Location - Location) <= TargetDistance;
	if (bDist && TargetLooking(Player) && CanSeeTarget(Player))
	{
		LookTime += DeltaTime;
		if (LookTime >= TargetLookTime)
		{
			LookTime = 0;
			TriggerAction();
		}
		bPlayerIsLooking = true;
	}
	else
	{
		LookTime = 0;
		bPlayerIsLooking = false;
	}
	*/
}

bool ALookTrigger::TargetLooking(APawn* Target)
{
	FVector TargetRotation = FVector(0,0,0);
	FVector MyLocation = FVector(0, 0, 0);
	/*
	TargetRotation = Normal(Vector(Target.GetViewRotation()));
	MyLocation = Normal(Location - Target.EyePosition());
	return MyLocation Dot TargetRotation >= TargetAngle;
	*/
	return false;    //FAKE   /ELiZ
}

bool ALookTrigger::CanSeeTarget(APawn* Target)
{
	//return FastTrace(Location, Target.EyePosition());
	return false;    //FAKE   /ELiZ
}

void ALookTrigger::TriggerAction()
{
	/*
	TriggerEvent(Event, this, Player);
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 4, Player, "");
	}
	if (bTriggerOnce)
	{
		SetActive(false);
	}
	Log("LookTrigger::TriggerAction()");
	*/
}
void ALookTrigger::Touch(AActor* Other)
{
}
void ALookTrigger::UnTouch(AActor* Other)
{
}
void ALookTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (bActive)
	{
		SetActive(false);
	}
	else
	{
		SetActive(true);
	}
}
void ALookTrigger::UnTrigger(AActor* Other, APawn* EventInstigator)
{
}
bool ALookTrigger::PlayerIsLooking()
{
	return bPlayerIsLooking;
}
