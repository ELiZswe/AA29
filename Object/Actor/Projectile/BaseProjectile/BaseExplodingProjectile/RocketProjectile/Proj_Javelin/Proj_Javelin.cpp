// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_Javelin/Proj_Javelin.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/RocketExplosionDamage/RocketJavelinDamage/RocketJavelinDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType\RocketFragDamage\JavelinFragDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType\RocketImpact\JavelinImpactDamage.h"
#include "AA29/Object/Actor/Jav_Target/Jav_Target.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/Projector/BaseContactProjector/de_bt_javimpact/de_bt_javimpact.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_Javelinexplosion/em_bt_Javelinexplosion.h"
#include "AA29/Object/Actor/Emitter/JavMissilePuff/JavMissilePuff.h"
#include "AA29/Object/Actor/Emitter/JavMissileSmoke/JavMissileSmoke.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"

AProj_Javelin::AProj_Javelin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cJavPuff = AJavMissilePuff::StaticClass()
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
	//ExplosionEmitter = Aem_bt_Javelinexplosion::StaticClass()
	ExplosionSoundRadius  = 10000;
	//cTrailEmitterClass = AJavMissileSmoke::StaticClass()
	ExplosionSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Missile_Explosion_Cue.S_Armo_Javelin_Missile_Explosion_Cue'"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_Javelin::StaticClass();
	Speed                 = 1125;
	MaxSpeed              = 4000;
	Damage                = 100;
	MyDamageType          = URocketJavelinDamage::StaticClass();
	//ExplosionDecal = Ade_bt_javimpact::StaticClass()
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/missile.missile"), NULL, LOAD_None, NULL);
	//Physics             = 2;
	NetPriority           = 3;
	LifeSpan              = 30;
	DrawScale             = 1.13;
}


/*
replication
{
	reliable if((Role == ROLE_Authority))
		bHasCollided, J_Target, TargetLoc;
}
*/



/*
auto State FirstStage extends Flying
{
	simulated Function BeginState()
	{
		Super::BeginState();
		if ((! IsZero(Velocity)) && (GetNetMode() != ENetMode::NM_Client))
		{
			SetActorRotation((rotator(Velocity) + FRotator(-16384,0,0)));
			bSetRotation=false;
		}
	}
	simulated Function ProcessTouch(AActor* Other, Vector HitLocation)
	{
		FVector HitNormal = FVector(0,0,0);
		if (Other == nullptr)
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
		if (cTrailEmitterClass != nullptr)
		{
			TrailEmitter=Spawn(cTrailEmitterClass,Self,,Location,Rotation);
			TrailEmitter.SetBase(this);
			TrailEmitter.SetRelativeLocation(RocketTrailOffset);
		}
		if (GetNetMode() != ENetMode::NM_Client)
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
		if (((GetNetMode() != ENetMode::NM_Client) && (J_Target != nullptr)) && (! bHasCollided))
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
			TargetLoc=(SeekTarget.Location + (FVector(0,0,1) * NewHeight));
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

void AProj_Javelin::BeginPlay()
{
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		mygun = WEAPON_Javelin(GetOwner());
		bDirectFire = mygun.GetbDirectFire();
		HomingTarget = mygun.GetHomingTarget();
		Gun_J_Target = mygun.GetJ_Target();
		J_Target = Spawn(AJav_Target::StaticClass(), this, , Gun_J_Target->GetActorLocation(), Gun_J_Target.Rotation);
		J_Target.SetBase(HomingTarget);
		if (!FastTrace(HomingTarget->GetActorLocation(), Location))
		{
			SeekTarget = J_Target;
		}
		else
		{
			SeekTarget = HomingTarget;
		}
		StartLocation = Location;
		TargetLoc = SeekTarget.Location;
		TargetLoc.Z = StartLocation.Z;
		TargetRange = VSize((TargetLoc - StartLocation));
		DetermineMaxHeight();
		if (mygun.GetbTooClose())
		{
			ArmingTimeRange = LongArmingTimeRange;
		}
	}
	BeginPlay();
	Speed = InitialSpeed;
	SetTimer(0.5, false);
	*/
}

void AProj_Javelin::DetermineMaxHeight()
{
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		if (bDirectFire)
		{
			if ((FMath::Abs((SeekTarget.Location.Z - StartLocation.Z)) * *2) > VSizeSquared((TargetLoc - StartLocation)))
			{
				MaxHeight = float(HeightDirSteep);
			}
			else
			{
				if ((SeekTarget.Location.Z - StartLocation.Z) >= 0)
				{
					if ((float(MaxHeightDir) - (SeekTarget.Location.Z - StartLocation.Z)) > float(MinHeightDir))
					{
						MaxHeight = (float(MaxHeightDir) - (SeekTarget.Location.Z - StartLocation.Z));
					}
					else
					{
						MaxHeight = float(MinHeightDir);
					}
				}
				else
				{
					if ((float(MaxHeightDir) + (SeekTarget.Location.Z - StartLocation.Z)) > float(MinHeightDir))
					{
						MaxHeight = (float(MaxHeightDir) + (SeekTarget.Location.Z - StartLocation.Z));
					}
					else
					{
						MaxHeight = float(MinHeightDir);
					}
				}
			}
		}
		else
		{
			if (((SeekTarget.Location.Z - StartLocation.Z) * *2) > VSizeSquared((TargetLoc - StartLocation)))
			{
				MaxHeight = float(HeightTopSteep);
			}
			else
			{
				if ((SeekTarget.Location.Z - StartLocation.Z) >= 0)
				{
					if ((float(MaxHeightTop) - (SeekTarget.Location.Z - StartLocation.Z)) > float(MinHeightTop))
					{
						MaxHeight = (float(MaxHeightTop) - (SeekTarget.Location.Z - StartLocation.Z));
					}
					else
					{
						MaxHeight = float(MinHeightTop);
					}
				}
				else
				{
					if ((float(MaxHeightTop) + (SeekTarget.Location.Z - StartLocation.Z)) > float(MinHeightTop))
					{
						MaxHeight = (float(MaxHeightTop) + (SeekTarget.Location.Z - StartLocation.Z));
					}
					else
					{
						MaxHeight = float(MinHeightTop);
					}
				}
			}
			FallDist = float(Min(int((0.5 * TargetRange)), 3000));
		}
	}
	*/
}

void AProj_Javelin::SetupProjectile()
{
	MaybeSetStaticMesh();
}

void AProj_Javelin::Timer()
{
	if (bHasCollided)
	{
		Super::Timer();
	}
	else
	{
		/*
		if ((!IsZero(Velocity)) && (GetNetMode() != ENetMode::NM_Client))
		{
			GotoState("SecondStage");
		}
		*/
	}
}

void AProj_Javelin::Destroyed()
{
	StopTrail();
	if (J_Target != nullptr)
	{
		J_Target->Destroy();
	}
	if (Gun_J_Target != nullptr)
	{
		Gun_J_Target->Destroy();
	}
	Super::Destroyed();
}

void AProj_Javelin::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	APlayerController* PC = nullptr;
	bReachedCollision = true;
	/*
	if (IsInstigator(HitActor) && (ProjState != 2))
	{
		if (Level.debugGrenade)
		{
			Log("Skip collision - Hit instigator before dudding");
		}
		return;
	}
	if ((((!bHasCollided) && (GetNetMode() != ENetMode::NM_Client)) && (Instigator != nullptr)) && (Instigator.Controller != nullptr))
	{
		PC = Cast<APlayerController>(Instigator.Controller);
		if (((Level.Game.Stats != nullptr) && (PC != nullptr)) && (PC.PlayerStatsIndex >= 0))
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitRocket();
		}
	}
	*/
	bHasCollided = true;
	Super::Collision(HitActor, HitLocation, HitNormal, HitMaterial, Type);
	if (J_Target != nullptr)
	{
		J_Target->Destroy();
	}
}

float AProj_Javelin::DetermineNewHeight()
{
	return ((MaxHeight * TargetDist) / TargetRange);
}

bool AProj_Javelin::IsInstigator(AActor* Other)
{
	/*
	if (((Other != nullptr) && Other->IsA(AAuxCollisionCylinder::StaticClass())) && ((Default.LifeSpan - LifeSpan) < 0.5))
	{
		return true;
	}
	else
	{
		return Super::IsInstigator(Other);
	}
	*/
	return false;    //FAKE   /ELiZ
}
