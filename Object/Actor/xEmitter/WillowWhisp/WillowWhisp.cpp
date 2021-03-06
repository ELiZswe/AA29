// All the original content belonged to the US Army

#include "AA29/Object/Actor/xEmitter/WillowWhisp/WillowWhisp.h"

AWillowWhisp::AWillowWhisp()
{
	WayPoints.SetNum(11);
	mStartParticles = 0;
	mMaxParticles = 150;
	mLifeRange = { 1.25, 1.25 };
	mRegenRange = { 90, 90 };
	mSpeedRange = { 0, 0 };
	mMassRange = { -0.03, -0.01 };
	mRandOrient = true;
	mSpinRange = { -75, 75 };
	mSizeRange = { 15, 20 };
	mGrowthRate = 13;
	mColorRange = { FColor(210, 210, 255, 255) };
	mAttenFunc = EAttenFunc::ATF_ExpInOut;
	mRandTextures = true;
	//bHidden = true;
	//Physics = 6;
	//RemoteRole = 2;
	//LifeSpan = 10;
	//Skins(0) = Texture'Engine.S_Pawn';
	//Style = 6;
	//bIgnoreOutOfWorld = true;
}

/*
auto State Pathing
{
	simulated Function Tick(float DeltaTime)
	{
		if (LifeLeft > 0)
		{
			(LifeLeft -= DeltaTime);
			if (LifeLeft <= 0)
			{
				Destroy();
				return;
			}
			return;
		}
		Acceleration=(float(1200) * Normal((Destination - Location)));
		Velocity=(Velocity + (DeltaTime * Acceleration));
		if (! bHeadedRight)
		{
			bHeadedRight=((Velocity Dot Acceleration) > 0);
		}
		else
		{
			if ((Velocity Dot Acceleration) < 0)
			{
				StartNextPath();
			}
		}
		if (VSize((Destination - Location)) < float(80))
		{
			StartNextPath();
		}
	}
}
*/

void AWillowWhisp::PostBeginPlay()
{
	int32 i = 0;
	int32 Start = 0;
	AController* C = nullptr;
	AActor* HitActor = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	//Super::PostBeginPlay();
	C = Cast<AController>(GetOwner());
	/*
	if (C.Pawn == nullptr)
	{
		return;
	}
	SetActorLocation(C.Pawn.Location);
	WayPoints[0] = C.Pawn.Location + C.Pawn.CollisionHeight * FVector(0 0 1) + 200 * Vector(C.Rotation);
	HitActor = Trace(HitLocation, HitNormal, WayPoints[0], C.Pawn->GetActorLocation(), false);
	if (HitActor != nullptr)
	{
		WayPoints[0] = HitLocation;
	}
	NumPoints++;
	if (C.RouteCache[i] != nullptr && C.actorReachable(C.RouteCache[1]))
	{
		Start = 1;
	}
	i = Start;
	if (i < Start + 10)
	{
		if (C.RouteCache[i] == nullptr)
		{
		}
		else
		{
			WayPoints[NumPoints] = C.RouteCache[i].Location + C.Pawn.CollisionHeight * FVector(0 0 1);
			NumPoints++;
		}
		i++;
	}
	Velocity = 500 * Normal(WayPoints[0] - Location) + C.Pawn.Velocity;
	*/
}

void AWillowWhisp::PostNetBeginPlay()
{
	/*
	if (GetNetMode() == ENetMode::NM_Standalone || GetNetMode() == ENetMode::NM_Client)
	{
		bHidden = false;
		StartNextPath();
	}
	else
	{
		if (GetNetMode() == ENetMode::NM_ListenServer && Viewport(Cast<APlayerController>(GetOwner())->Player) != nullptr)
		{
			bHidden = false;
			RemoteRole = 0;
			StartNextPath();
		}
		else
		{
			LifeSpan = 0.5;
		}
	}
	*/
}

void AWillowWhisp::StartNextPath()
{
	if (Position >= NumPoints)
	{
		mRegen = false;
		//LifeSpan = 1.5;
		LifeLeft = 1.5;
		//Velocity = FVector(0,0,0);
		//Acceleration = FVector(0,0,0);
		return;
	}
	bHeadedRight = false;
	Destination = WayPoints[Position];
	//Acceleration = 1200 * Normal(Destination - Location);
	//Velocity *= 0.5;
	//Velocity.Z = 0.5 * Velocity.Z + Acceleration.Z;
	//SetRotation(Acceleration);
	Position++;
}
