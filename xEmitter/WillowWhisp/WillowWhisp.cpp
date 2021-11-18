// All the original content belonged to the US Army


#include "WillowWhisp.h"

AWillowWhisp::AWillowWhisp()
{
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



void AWillowWhisp::PostBeginPlay()
{
	/*
	local int i;
	local int Start;
	local Controller C;
	local Actor HitActor;
	local FVector HitLocation;
	local FVector HitNormal;
	PostBeginPlay();
	C = Controller(Owner);
	if (C.Pawn == None)
	{
		Return;
	}
	SetLocation(C.Pawn.Location);
	WayPoints[0] = C.Pawn.Location + C.Pawn.CollisionHeight * vect(0 0 1) + 200 * Vector(C.Rotation);
	HitActor = Trace(HitLocation, HitNormal, WayPoints[0], C.Pawn.Location, false);
	if (HitActor != None)
	{
		WayPoints[0] = HitLocation;
	}
	NumPoints++;
	if (C.RouteCache[i] != None && C.actorReachable(C.RouteCache[1]))
	{
		Start = 1;
	}
	i = Start;
	if (i < Start + 10)
	{
		if (C.RouteCache[i] == None)
		{
		}
		else
		{
			WayPoints[NumPoints] = C.RouteCache[i].Location + C.Pawn.CollisionHeight * vect(0 0 1);
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
		bHidden = False;
		StartNextPath();
	}
	else
	{
		if (GetNetMode() == ENetMode::NM_ListenServer && Viewport(PlayerController(Owner).Player) != None)
		{
			bHidden = False;
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
	/*
	if (Position >= NumPoints)
	{
		mRegen = False;
		LifeSpan = 1.5;
		LifeLeft = 1.5;
		Velocity = vect(0 0 0);
		Acceleration = vect(0 0 0);
		Return;
	}
	bHeadedRight = False;
	Destination = WayPoints[Position];
	Acceleration = 1200 * Normal(Destination - Location);
	Velocity *= 0.5;
	Velocity.Z = 0.5 * Velocity.Z + Acceleration.Z;
	SetRotation(Acceleration);
	Position++;
	*/
}
