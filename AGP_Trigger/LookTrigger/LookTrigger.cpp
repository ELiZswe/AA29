// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/LookTrigger/LookTrigger.h"

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
		Player = AGP_Pawn(Level.GetClientPawn());
	}
	if (bActive)
	{
		TrackPlayer(DeltaTime);
	}
	else
	{
		LookTime = 0;
		bPlayerIsLooking = False;
	}
	*/
}
void ALookTrigger::TrackPlayer(float DeltaTime)
{
	/*
	local bool bDist;
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
		bPlayerIsLooking = False;
	}
	*/
}
void ALookTrigger::TargetLooking(APawn* Target)
{
	/*
	local FVector TargetRotation;
	local FVector MyLocation;
	TargetRotation = Normal(Vector(Target.GetViewRotation()));
	MyLocation = Normal(Location - Target.EyePosition());
	Return MyLocation Dot TargetRotation >= TargetAngle;
	*/
}
void ALookTrigger::CanSeeTarget(APawn* Target)
{
	//Return FastTrace(Location, Target.EyePosition());
}
void ALookTrigger::TriggerAction()
{
	/*
	TriggerEvent(Event, Self, Player);
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 4, Player, "");
	}
	if (bTriggerOnce)
	{
		SetActive(False);
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
