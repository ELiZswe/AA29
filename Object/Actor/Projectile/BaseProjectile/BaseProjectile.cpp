// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"

ABaseProjectile::ABaseProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	fWindFactor    = 1;
	fAtmoFactor    = 1;
	idTeamOwner    = 255;
	Speed          = 7000;
	MaxSpeed       = 100000;
	DrawType       = EDrawType::DT_None;
	LifeSpan       = 10;
	//bUseCollisionStaticMesh = true;
}

/*
auto State Flying
{
	simulated Function PhysicsVolumeChange(APhysicsVolume* NewVolume)
	{
		if (! NewVolume.bWaterVolume)
		{
			return;
		}
		Velocity=(0.6 * Velocity);
	}
	simulated Function HitWall(Vector HitNormal, AActor* Wall)
	{
		ADecoMesh* DM = nullptr;
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			if (Cast<AMover>(Wall) != nullptr)
			{
				Wall.TakeDamage(int(Damage),Instigator,Location,(MomentumTransfer * Normal(Velocity)),MyDamageType,,,Self);
			}
			MakeNoise(1);
		}
		if ((Wall != nullptr) && Wall->IsA(ADecoMesh::StaticClass()))
		{
			DM=DecoMesh(Wall);
			if (DM.bInstantGrenBreak && (DM.DamageHealth > 0))
			{
				DM.TakeDamage((DM.InitialDamageHealth * 1000),Instigator,DM->GetActorLocation(),FVector(0,0,0),nullptr,,,Self);
				return;
			}
		}
		FindCollide(Wall,1);
	}
	simulated Function Landed(Vector HitNormal)
	{
		FindCollide(nullptr,2);
	}
	simulated Function FindCollide(AActor* CAct, ECollisionType CType)
	{
		FVector HitLoc = FVector(0,0,0);
		FVector HitNorm = FVector(0,0,0);
		UMaterialInstance* HitMaterial = nullptr;
		int32 PolyFlags = 0;
		StopTrail();
		Trace(HitLoc,HitNorm,(Location + (Velocity * float(1000))),Location,true,FVector(0,0,0),HitMaterial,PolyFlags);
		if (PFlag_DeleteProjectiles(PolyFlags))
		{
			Destroy();
		}
		else
		{
			Collision(CAct,HitLoc,HitNorm,HitMaterial,CType);
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
		StopTrail();
		Collision(Other,HitLocation,HitNormal,Other.Texture,3);
	}
}
*/

/*
replication
{
	reliable if (((Role == ROLE_Authority) && bNetInitial))
		idTeamOwner;
}
*/

void ABaseProjectile::PreBeginPlay()
{
	//idTeamOwner = Level.Game.GetPlayerTeamIndex(Instigator.Controller);
}

bool ABaseProjectile::IsEnemyProjectile()
{
	//return ((idTeamOwner != 255) && (idTeamOwner != Level.GetClientController().PlayerReplicationInfo.Team.TeamIndex));
	return false;    //FAKE   /ELiZ
}

void ABaseProjectile::MaybeSetStaticMesh()
{
	/*
	if (EnemyProjectileClass != nullptr)
	{
		if (Instigator != nullptr)
		{
			DebugLog(DEBUG_Inv, "BaseProjectile::MaybeSetStaticMesh()	" + FString::FromInt(this) @ FString::FromInt(Instigator) @ FString::FromInt(Instigator.bClientFriend));
		}
		if (IsEnemyProjectile())
		{
			SetStaticMesh(EnemyProjectileClass.Default.StaticMesh);
			cTrailEmitterClass = EnemyProjectileClass.Default.cTrailEmitterClass;
		}
	}
	*/
}

void ABaseProjectile::BeginPlay()
{
	/*
	Super::BeginPlay();
	fWindFactor =FMath::Clamp(fWindFactor, 0, 1);
	fAtmoFactor =FMath::Clamp(fAtmoFactor, 0, 1);
	(Speed += (Level.GetProjectileMod() * fAtmoFactor));
	if (Instigator != nullptr)
	{
		InstigatorController = Instigator.Controller;
	}
	*/
}

void ABaseProjectile::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	Velocity = (Speed * Vector(Rotation));
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		SetupProjectile();
	}
	if ((Instigator != nullptr) && (Instigator.EventLab != nullptr))
	{
		SetEventLab(Instigator.EventLab);
	}
	*/
}

void ABaseProjectile::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		SetupProjectile();
	}
	*/
}

void ABaseProjectile::SetupProjectile()
{
	MaybeSetStaticMesh();
	if (cTrailEmitterClass != nullptr)
	{
		//TrailEmitter = Spawn(cTrailEmitterClass, this, , Location, Rotation);
		//TrailEmitter.SetBase(this);
	}
}

void ABaseProjectile::Destroyed()
{
	Super::Destroyed();
	StopTrail();
}

void ABaseProjectile::StopTrail()
{
	if (TrailEmitter != nullptr)
	{
		//TrailEmitter->Destroy();
		TrailEmitter = nullptr;
	}
}

void ABaseProjectile::Collision(AActor* Other, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	GetAxes(Rotation, X, Y, Z);
	if (Instigator != nullptr)
	{
		if (DamageRadius > 0)
		{
			Instigator.HurtRadius(Damage, DamageRadius, MyDamageType, MomentumTransfer, HitLocation);
		}
		else
		{
			if (Other != nullptr)
			{
				Other.TakeDamage(int(Damage), Instigator, HitLocation, (MomentumTransfer * X), MyDamageType, , , this);
			}
		}
	}
	if (Cast<APawn>(Other) != nullptr)
	{
		HitMaterial = Other.Skins[0];
	}
	if ((HitMaterial != nullptr) && (GetNetMode() != ENetMode::NM_DedicatedServer))
	{
		HitMaterial.PlayBulletContactSound(this, HitLocation, HitNormal, 0);
		HitMaterial.PlayBulletContactProjector(this, HitLocation, HitNormal, 0);
		HitMaterial.PlayBulletContactEmitter(this, HitLocation, HitNormal, 0);
	}
	Destroy();
	*/
}
