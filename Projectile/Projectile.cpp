// All the original content belonged to the US Army


#include "Projectile.h"
#include "AA29/DecoMesh/DecoMesh.h"



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

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	if (!HasAnyFlags(RF_ClassDefaultObject | RF_ArchetypeObject))
	{
		OnActorHit.AddDynamic(this, &AProjectile::OnMyHit);
	}
}

// Called every frame
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