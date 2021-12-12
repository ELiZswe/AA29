// All the original content belonged to the US Army

#include "Proj_Javelin.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/RocketExplosionDamage/RocketJavelinDamage/RocketJavelinDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType\RocketFragDamage\JavelinFragDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType\RocketImpact\JavelinImpactDamage.h"

AProj_Javelin::AProj_Javelin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cJavPuff = class'AGP_Armory.JavMissilePuff'
	MaxHeightTop          = 12000;
	MaxHeightDir          = 2250;
	MinHeightTop          = 4500;
	MinHeightDir          = 900;
	HeightTopSteep        = 1500;
	HeightDirSteep        = 300;
	LongArmingTimeRange.Min = 30.0f;
	LongArmingTimeRange.Max = 30.0f;
	RocketTrailOffset     = FVector(0, 0, -32);
	InitialSpeed          = 1125;
	AccelRate             = 0.95;
	PropellantDuration    = 30;
	ArmingTimeRange.Min   = 1.0f;
	ArmingTimeRange.Max   = 1.0f;
	ImpactDamageType      = UJavelinImpactDamage::StaticClass();
	FragDamageType        = UJavelinFragDamage::StaticClass();
	//ExplosionEmitter = class'AGP_Armory.em_bt_Javelinexplosion'
	ExplosionSoundRadius  = 10000;
	//cTrailEmitterClass = class'AGP_Armory.JavMissileSmoke'
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Missile_Explosion.S_Armo_Javelin_Missile_Explosion"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_Javelin::StaticClass();
	Speed                 = 1125;
	MaxSpeed              = 4000;
	Damage                = 100;
	MyDamageType          = URocketJavelinDamage::StaticClass();
	//ExplosionDecal = class'AGP_Armory.de_bt_javimpact'
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/missile.missile"), NULL, LOAD_None, NULL);
	//Physics             = 2;
	NetPriority           = 3;
	LifeSpan              = 30;
	DrawScale             = 1.13;
}

/*
auto State FirstStage extends Flying
{
	simulated Function BeginState()
	{
		Super::BeginState();
		if ((! IsZero(Velocity)) && (Level.NetMode != NM_Client))
		{
			SetRotation((rotator(Velocity) + rot(-16384,0,0)));
			bSetRotation=false;
		}
	}
	simulated Function ProcessTouch(Actor Other, Vector HitLocation)
	{
		FVector HitNormal = FVector(0,0,0);
		if (Other == None)
		{
			return;
		}
		HitNormal=Normal((HitLocation - Other.Location));
		if (! IsInstigator(Other))
		{
			StopTrail();
		}
		Collision(Other,HitLocation,HitNormal,Other.Texture,3);
	}
}
*/

/*
State SecondStage extends Flying
{
	simulated Function BeginState()
	{
		Super::BeginState();
		if (cTrailEmitterClass != None)
		{
			TrailEmitter=Spawn(cTrailEmitterClass,Self,,Location,Rotation);
			TrailEmitter.SetBase(Self);
			TrailEmitter.SetRelativeLocation(RocketTrailOffset);
		}
		if (Level.NetMode != NM_Client)
		{
			SetPhysics(PHYS_Projectile);
			bSetRotation=true;
			ePuff=Spawn(cJavPuff,Self,,Location,Rotation);
			AccelRate=2.5;
		}
	}
	simulated Function Tick(float DeltaTime)
	{
		FVector ForceDir = FVector(0,0,0);
		float RealDist = 0;
		if (bOutOfPropellant)
		{
			GotoState("Flying");
		}
		if (((Level.NetMode != NM_Client) && (J_Target != None)) && (! bHasCollided))
		{
			if (! bReachedMaxSpeed)
			{
				VelMag=VSize(Velocity);
				if (VelMag > MaxSpeed)
				{
					bReachedMaxSpeed=true;
					VelMag=MaxSpeed;
				}
			}
			else
			{
				VelMag=MaxSpeed;
			}
			TargetLoc=SeekTarget.Location;
			RealDist=VSize((TargetLoc - Location));
			if (RealDist < float(1000))
			{
				NewHeight=0;
			}
			else
			{
				TargetLoc.Z=Location.Z;
				TargetDist=VSize((TargetLoc - Location));
				NewHeight=DetermineNewHeight();
			}
			TargetLoc=(SeekTarget.Location + (vect(0,0,1) * NewHeight));
			ForceDir=Normal((TargetLoc - Location));
			if (((ForceDir Dot Velocity) > 0) && (RealDist > float(1000)))
			{
				ForceDir=Normal((((ForceDir * FMax(0.5,(1 - (TargetDist / TargetRange)))) * VelMag) + Velocity));
			}
			Velocity=(VelMag * ForceDir);
		}
		Super::Tick(DeltaTime);
	}
}
*/

