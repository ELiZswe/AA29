// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/Proj_Mk19G.h"
#include "AA29/Object/DamageType/CROWS_Mk19Damage/CROWS_Mk19Damage.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_mk19grenexplosion/em_bt_mk19grenexplosion.h"
#include "AA29/Object/Actor/KActor/KActor.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"

AProj_Mk19G::AProj_Mk19G(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ArmingTimeRange = FObjectRange({ 0.16, 0.16 });
	ImpactDamage = 125;
	//ImpactDamageType = ACROWS_Mk19Damage::StaticClass();
	//ExplosionEmitter = Aem_bt_mk19grenexplosion::StaticClass();
	ExplosionSoundRadius = 4000;
	DamageClasses = {
		//ADecoMesh::StaticClass()
		//Class'Engine.Pawn'
		//ABaseProjectile::StaticClass()
		//AThrowWeaponPickup::StaticClass()
		//ATriggers::StaticClass()
		//AKActor::StaticClass()
		//ABodyPanel::StaticClass()
	};
	fKillRadius = 296;
	ExplosionSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/MK19/s_arm_mk19_impact_explosion_Cue.s_arm_mk19_impact_explosion_Cue'"), NULL, LOAD_None, NULL);
	//EnemyProjectileClass = AProj_Mk19G::StaticClass();
	Speed = 6000;
	Damage = 125;
	DamageRadius = 890;
	MomentumTransfer = 5000;
	//MyDamageType = ACROWS_Mk19Damage::StaticClass();
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203'"), NULL, LOAD_None, NULL);
	DrawScale = 1;
	CollisionRadius = 1;
	CollisionHeight = 1;
}

void AProj_Mk19G::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	FRotator Rot = FRotator(0, 0, 0);
	FVector HitLoc = FVector(0, 0, 0);
	FVector HitNorm = FVector(0, 0, 0);
	FVector ExplodeLoc = FVector(0, 0, 0);
	AGrenadeHelper* GH = nullptr;
	float HitDamage = 0;
	FVector HitRay = FVector(0, 0, 0);
	FBoneInfo HitBone = FBoneInfo({});
	FVector SavedCollisionLocation = FVector(0, 0, 0);
	FRotator SavedRotation = FRotator(0, 0, 0);
	UMaterialInstance* thisHitMaterial = nullptr;
	FVector ThisHitLocation = FVector(0, 0, 0);
	FVector ThisHitNormal = FVector(0, 0, 0);
	bool bOldUseCollisionStaticMesh = false;
	FinishedBallistics = true;
	bReachedCollision = true;
	/*
	if (IsInstigator(HitActor) && (ProjState != 2))
	{
		if (Level.debugGrenade)
		{
			DebugLog(DEBUG_Vehicle, "Skip collision - Hit instigator before dudding");
		}
		return;
	}
	if (((HitActor != nullptr) && (!IsZero(Velocity))) && (Physics != 1))
	{
		SavedCollisionLocation = HitLocation;
		SavedRotation = rotator(Velocity);
		HitRay = (SavedCollisionLocation + (Vector(SavedRotation) * float(100)));
		bOldUseCollisionStaticMesh = bUseCollisionStaticMesh;
		bUseCollisionStaticMesh = true;
		BoneTrace(ThisHitLocation, ThisHitNormal, HitRay, (SavedCollisionLocation + (Vector(SavedRotation) * float(-35))), thisHitMaterial, HitBone, false);
		bUseCollisionStaticMesh = bOldUseCollisionStaticMesh;
		DebugLog(DEBUG_Vehicle, "HitMaterial is " + FString::FromInt(HitMaterial) + " and thisHitMaterial is " + FString::FromInt(thisHitMaterial));
		if (HitBone.HitBone != 0)
		{
			HitDamage = Damage;
			DebugLog(DEBUG_Vehicle, " In ProjectileCollision, Un modified Hitdamage= " + FString::FromInt(HitDamage));
			if (HitBone.DamageModifier > 0)
			{
				(HitDamage *= HitBone.DamageModifier);
			}
		}
		HitActor.TakeDamage(int(Damage), Instigator, HitLocation, (Normal(HitRay) * MomentumTransfer), ImpactDamageType, , , this, thisHitMaterial);
		if (ShouldExplode() && (ProjState != 2))
		{
			HitActor.TakeProjectileImpactDamage(int(HitDamage), Instigator, HitLocation, (Normal(HitRay) * MomentumTransfer), ImpactDamageType, , , this, thisHitMaterial);
		}
	}
	Log("Project " + FString::FromInt(this) + " colliding with " + FString::FromInt(HitActor));
	if (!_bResolvedState)
	{
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (ProjState == 1)
			{
				_bResolvedState = true;
				Boom(HitLocation, HitNormal);
				HandleDestroyCall();
			}
			else
			{
				if (ProjState == 2)
				{
					_bResolvedState = true;
				}
				else
				{
					if (!bAlreadySaved)
					{
						SavedHitactor = HitActor;
						SavedHitLocation = HitLocation;
						SavedHitNormal = HitNormal;
						SavedHitMaterial = HitMaterial;
						SavedType = Type;
						SavedLocation = Location;
						SavedVelocity = Velocity;
					}
					SetTimer(0.1, false);
				}
			}
		}
		else
		{
			_bResolvedState = true;
			if (ShouldExplode())
			{
				ProjState = 1;
				Boom(HitLocation, HitNormal);
				ExplodeLoc = (Location + (HitNormal * CollisionHeight));
				GH = Level.GetGrenadeHelper();
				if (!HitActor->IsA(ADecoMesh::StaticClass()))
				{
					HitActor = this;
				}
				GH.GrenHurtRadius(HitActor, ExplodeLoc, DamageRadius, fKillRadius, Damage, MyDamageType, FragDamageType, MomentumTransfer, Default.DamageClasses, InstigatorController);
				GH.GrenadeEffects(HitActor, ExplodeLoc, DamageRadius, fKillRadius, _fEffectDuration, _fAudIntensity, 0);
				HandleDestroyCall();
			}
			else
			{
				ProjState = 2;
			}
		}
	}
	if (ProjState == 2)
	{
		LifeSpan = Default.LifeSpan;
		if ((VSize(Velocity) > float(200)) && (GetNetMode() != ENetMode::NM_DedicatedServer))
		{
			if (HitMaterial == nullptr)
			{
				Trace(HitLoc, HitNorm, (Location + (Velocity * float(1000))), Location, true, FVector(0, 0, 0), HitMaterial);
			}
			if (HitMaterial != nullptr)
			{
				PlayLandedSound(HitMaterial);
			}
			else
			{
				PlayOwnedSound(ImpactSound, 1, 1.5, , 150, 0.5, true);
			}
		}
		if (Type == 1)
		{
			if (VSize(Velocity) < float(400))
			{
				bBounce = false;
			}
			Velocity = (MirrorVectorByNormal(Velocity, HitNormal) * RandRange(0.15, 0.25));
		}
		else
		{
			if (Type == 2)
			{
				Velocity = FVector(0, 0, 0);
				SetPhysics(PHYS_None);
				Rot = Rotation;
				Rot.Pitch = int((float(-16384) * (FVector(0, 0, 1) Dot HitNormal)));
				SetActorRotation(Rot);
			}
			else
			{
				if (Type == 3)
				{
					Velocity = (MirrorVectorByNormal(Velocity, HitNormal) * RandRange(0.005, 0.1));
				}
			}
		}
	}
	*/
}

void AProj_Mk19G::Boom(FVector HitLocation, FVector HitNormal)
{
	AController* ctrlIterator = nullptr;
	/*
	Super::Boom(HitLocation, HitNormal);
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator->IsA(AaAIController::StaticClass()))
		{
		}
		if ((Cast<AAIController>(ctrlIterator).Pawn != nullptr) && (VSize((Cast<AAIController>(ctrlIterator).Pawn.Location - HitLocation)) < float(1650)))
		{
			if (ctrlIterator.Pawn.LineOfSightTo(this))
			{
				Cast<AaAIController>(ctrlIterator).NotifyBuzzedByBullet(GetOwner());
			}
		}
	}
	*/
}

void AProj_Mk19G::Tick(float DeltaTime)
{
	//DrawDebugSphere(GetActorLocation(), 128, 10, 255, 0, 0);
}
