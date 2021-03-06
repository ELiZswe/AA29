// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Info/FluidSurfaceInfo/FluidSurfaceInfo.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

// Sets default values
AProjectile::AProjectile(const FObjectInitializer& ObjectInitializer)	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxSpeed         = 2000;
	TossZ            = 100;
	DamageRadius     = 220;
	MyDamageType     = UaDamageType::StaticClass();
	DrawType         = EDrawType::DT_Mesh;
	//bAcceptsProjectors = false;
	bNetTemporary    = true;
	//bReplicateInstigator = true;
	//bNetInitialRotation = true;
	//Physics = 6;
	//RemoteRole = 2;
	NetPriority      = 2.5;
	LifeSpan         = 140;
	//Texture = Texture'Engine.S_Camera'

	//bUnlit = true;
	//bGameRelevant = true;
	//bCanBeDamaged    = true;
	//bDisturbFluidSurface = true;
	//SoundVolume = 0;
	CollisionRadius  = 0;
	CollisionHeight  = 0;
	//bCollideActors = true;
	//bCollideWorld = true;
	//bUseCylinderCollision = true;

	// Use a sphere as a simple collision representation
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	RootComponent = CollisionComp;

	//RootComponent->SetNetAddressable(); // Make DSO components net addressable
	//RootComponent->SetIsReplicated(true); // Enable replication by default

	if (!StaticMesh)
	{
		StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
	}
	
	if(StaticMesh)
	{
		ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
		ProjectileMesh->SetStaticMesh(StaticMesh);
		// Attach the specified static mesh to the scene component
		ProjectileMesh->SetupAttachment(CollisionComp);
		ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		//ProjectileMesh->SetNetAddressable(); // Make DSO components net addressable
		//ProjectileMesh->SetIsReplicated(true); // Enable replication by default

	}
	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.3f;
	InitialLifeSpan = 3.0f;
	//ProjectileMovement->SetNetAddressable(); // Make DSO components net addressable
	//ProjectileMovement->SetIsReplicated(true); // Enable replication by default

	//ORg:
	/*
	MaxSpeed = 2000;
	TossZ = 100;
	DamageRadius = 220;
	MyDamageType = class'Engine.DamageType';
	DrawType = DT_Mesh;
	bAcceptsProjectors = false;
	bNetTemporary = true;
	bReplicateInstigator = true;
	bNetInitialRotation = true;
	Physics = PHYS_Projectile;
	RemoteRole = ROLE_SimulatedProxy;
	NetPriority = 2.5;
	LifeSpan = 140;
	Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_Camera_Mat.S_Camera_Mat'"), NULL, LOAD_None, NULL);
	bUnlit = true;
	bGameRelevant = true;
	bCanBeDamaged = true;
	bDisturbFluidSurface = true;
	SoundVolume = 0;
	CollisionRadius = 0;
	CollisionHeight = 0;
	bCollideActors = true;
	bCollideWorld = true;
	bUseCylinderCollision = true;
	*/

}


void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	if (!HasAnyFlags(RF_ClassDefaultObject | RF_ArchetypeObject))
	{
		OnActorHit.AddDynamic(this, &AProjectile::OnMyHit);
	}
}


void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::InitVelocity(const FVector& ShootDirection)
{
	if (ProjectileMovement)
	{
		// set the projectile's velocity to the desired direction
		ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
	}
}

void AProjectile::OnMyHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		if (OtherActor->IsA(ADecoMesh::StaticClass()))
		{
			float DamageAmount = 600.0f;
			const FDamageEvent DamageEvent;
			AController* EventInstigator = nullptr;
			AActor* DamageCauser = this;

			OtherActor->TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
		}
	}
	Destroy();
}

void AProjectile::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProjectile, ProjectileMesh);
	DOREPLIFETIME(AProjectile, ProjectileMovement);
	//DOREPLIFETIME(AProjectile, CollisionComp);

}

void AProjectile::PostBeginPlay()
{
	APlayerController* PC = nullptr;
	/*
	if (((GetRemoteRole() == ENetRole::ROLE_MAX) && (Instigator != nullptr)) && (Instigator.Controller != nullptr))
	{
		if ((Instigator.Controller.ShotTarget != nullptr) && (Instigator.Controller.ShotTarget.Controller != nullptr))
		{
			Instigator.Controller.ShotTarget.Controller.ReceiveProjectileWarning(this);
		}
		InstigatorController = Instigator.Controller;
	}
	if (bDynamicLight && (GetNetMode() != ENetMode::NM_DedicatedServer))
	{
		PC = Level.GetLocalPlayerController();
		if (((PC == nullptr) || (PC.ViewTarget == nullptr)) || (VSize((PC.ViewTarget.Location - Location)) > float(4000)))
		{
			LightType = 0;
			bDynamicLight = false;
		}
	}
	bReadyToSplash = true;
	*/
}

bool AProjectile::SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation, bool bBehindView)
{
	return false;    //FAKE   /EliZ
}

bool AProjectile::CanSplash()
{
	return bReadyToSplash;
}

void AProjectile::Reset()
{
	Destroy();
}

bool AProjectile::CheckMaxEffectDistance(APlayerController* p, FVector SpawnLocation)
{
	//return (!p.BeyondViewDistance(SpawnLocation, MaxEffectDistance));
	return false;    //FAKE   /EliZ
}

void AProjectile::HurtRadius(float DamageAmount, float aDamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation)
{
	AActor* Victims = nullptr;
	float damageScale = 0;
	float dist = 0;
	FVector Dir = FVector(0, 0, 0);
	/*
	if (bHurtEntry)
	{
		return;
	}
	bHurtEntry = true;
	ForEach VisibleCollidingActors(Class'Actor', Victims, DamageRadius, HitLocation)
	{
		if ((((Victims != Self) && (HurtWall != Victims)) && (Victims.Role == 4)) && (!Victims->IsA(AFluidSurfaceInfo::StaticClass())))
		{
			Dir = (Victims.Location - HitLocation);
			dist = FMax(1, VSize(Dir));
			Dir = (Dir / dist);
			damageScale = (1 - FMax(0, ((dist - Victims.CollisionRadius) / DamageRadius)));
			if ((Instigator == nullptr) || (Instigator.Controller == nullptr))
			{
				Victims.SetDelayedDamageInstigatorController(InstigatorController);
			}
			if (Victims == LastTouched)
			{
				LastTouched = nullptr;
			}
			Victims.TakeDamage(int((damageScale * DamageAmount)), Instigator, (Victims.Location - ((0.5 * (Victims.CollisionHeight + Victims.CollisionRadius)) * Dir)), ((damageScale * Momentum) * Dir), DamageType);
			if ((Cast<AVehicle>(Victims) != nullptr) && (Cast<AVehicle>(Victims).Health > 0))
			{
				Vehicle(Victims).DriverRadiusDamage(DamageAmount, DamageRadius, InstigatorController, DamageType, Momentum, HitLocation);
			}
		}
	}
	if ((((LastTouched != nullptr) && (LastTouched != Self)) && (LastTouched.Role == 4)) && (!LastTouched->IsA(AFluidSurfaceInfo::StaticClass())))
	{
		Victims = LastTouched;
		LastTouched = nullptr;
		Dir = (Victims.Location - HitLocation);
		dist = FMax(1, VSize(Dir));
		Dir = (Dir / dist);
		damageScale = FMax((Victims.CollisionRadius / (Victims.CollisionRadius + Victims.CollisionHeight)), (1 - FMax(0, ((dist - Victims.CollisionRadius) / DamageRadius))));
		if ((Instigator == nullptr) || (Instigator.Controller == nullptr))
		{
			Victims.SetDelayedDamageInstigatorController(InstigatorController);
		}
		Victims.TakeDamage(int((damageScale * DamageAmount)), Instigator, (Victims.Location - ((0.5 * (Victims.CollisionHeight + Victims.CollisionRadius)) * Dir)), ((damageScale * Momentum) * Dir), DamageType);
		if ((Cast<AVehicle>(Victims) != nullptr) && (Cast<AVehicle>(Victims).Health > 0))
		{
			Vehicle(Victims).DriverRadiusDamage(DamageAmount, DamageRadius, InstigatorController, DamageType, Momentum, HitLocation);
		}
	}
	bHurtEntry = false;
	*/
}

void AProjectile::DelayedHurtRadius(float DamageAmount, float aDamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation)
{
	HurtRadius(DamageAmount, DamageRadius, DamageType, Momentum, HitLocation);
}

bool AProjectile::EncroachingOn(AActor* Other)
{
	/*
	if ((Other->Brush != nullptr) || (Cast<ABrush>(Other) != nullptr))
	{
		return true;
	}
	*/
	return false;
}

void AProjectile::Touch(AActor* Other)
{
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	/*
	if (((Other == nullptr) || bDeleteMe) || Other.bDeleteMe)
	{
		return;
	}
	if (Other.bProjTarget || Other.bBlockActors)
	{
		LastTouched = Other;
		if ((Velocity == FVector(0, 0, 0)) || Other->IsA(AMover::StaticClass()))
		{
			ProcessTouch(Other, Location);
			LastTouched = nullptr;
			return;
		}
		if (Other.TraceThisActor(HitLocation, HitNormal, Location, (Location - (2 * Velocity)), GetCollisionExtent()))
		{
			HitLocation = Location;
		}
		ProcessTouch(Other, HitLocation);
		LastTouched = nullptr;
		if (((Role < 4) && (Other.Role == 4)) && (Cast<APawn>(Other) != nullptr))
		{
			ClientSideTouch(Other, HitLocation);
		}
	}
	*/
}

void AProjectile::ClientSideTouch(AActor* Other, FVector HitLocation)
{
	//Other.TakeDamage(int(Damage), Instigator, Location, (MomentumTransfer * Normal(Velocity)), MyDamageType);
}

void AProjectile::ProcessTouch(AActor* Other, FVector HitLocation)
{
	if (Other != GetInstigator())
	{
		//Explode(HitLocation, Normal((HitLocation - Other.Location)));
	}
}

void AProjectile::HitWall(FVector HitNormal, AActor* Wall)
{
	/*
	APlayerController* PC = nullptr;
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		if ((!Wall.bStatic) && (!Wall.bWorldGeometry))
		{
			if ((Instigator == nullptr) || (Instigator.Controller == nullptr))
			{
				Wall.SetDelayedDamageInstigatorController(InstigatorController);
			}
			Wall.TakeDamage(int(Damage), Instigator, Location, (MomentumTransfer * Normal(Velocity)), MyDamageType);
			if (((DamageRadius > 0) && (Cast<AVehicle>(Wall) != nullptr)) && (Cast<AVehicle>(Wall).Health > 0))
			{
				Vehicle(Wall).DriverRadiusDamage(Damage, DamageRadius, InstigatorController, MyDamageType, MomentumTransfer, Location);
			}
			HurtWall = Wall;
		}
		MakeNoise(1);
	}
	Explode((Location + (ExploWallOut * HitNormal)), HitNormal);
	if ((ExplosionDecal != nullptr) && (GetNetMode() != ENetMode::NM_DedicatedServer))
	{
		if (ExplosionDecal.Default.CullDistance != 0)
		{
			PC = Level.GetLocalPlayerController();
			if (!PC.BeyondViewDistance(Location, ExplosionDecal.Default.CullDistance))
			{
				Spawn(ExplosionDecal, this, , Location, rotator((-HitNormal)));
			}
			else
			{
				if (((Instigator != nullptr) && (PC == Instigator.Controller)) && (!PC.BeyondViewDistance(Location, (2 * ExplosionDecal.Default.CullDistance))))
				{
					Spawn(ExplosionDecal, this, , Location, rotator((-HitNormal)));
				}
			}
		}
		else
		{
			Spawn(ExplosionDecal, this, , Location, rotator((-HitNormal)));
		}
	}
	HurtWall = nullptr;
	*/
}

void AProjectile::BlowUp(FVector HitLocation)
{
	/*
	HurtRadius(Damage, DamageRadius, MyDamageType, MomentumTransfer, HitLocation);
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		MakeNoise(1);
	}
	*/
}

void AProjectile::Explode(FVector HitLocation, FVector HitNormal)
{
	Destroy();
}

void AProjectile::RandSpin(float spinRate)
{
	/*
	DesiredRotation = RotRand();
	RotationRate.Yaw = int((((spinRate * 2) * FMath::FRand()) - spinRate));
	RotationRate.Pitch = int((((spinRate * 2) * FMath::FRand()) - spinRate));
	RotationRate.Roll = int((((spinRate * 2) * FMath::FRand()) - spinRate));
	*/
}

float AProjectile::GetRange()
{
	if (GetDefault<AProjectile>()->LifeSpan == 0)
	{
		return 15000;
	}
	else
	{
		return (GetDefault<AProjectile>()->MaxSpeed * GetDefault<AProjectile>()->LifeSpan);
	}
}

bool AProjectile::IsStationary()
{
	return false;
}

void AProjectile::PostRender2D(UCanvas* C, float ScreenLocX, float ScreenLocY)
{
}

void AProjectile::MatchEnding()
{
	Destroy();
}
