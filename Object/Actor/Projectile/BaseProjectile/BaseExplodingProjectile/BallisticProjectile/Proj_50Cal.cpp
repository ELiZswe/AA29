// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/Proj_50Cal.h"
#include "AA29/Object/DamageType/CROWS_50CalDamage/CROWS_50CalDamage.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/Emitter/BaseTracerEmitter/BaseTracerEmitter.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/KActor/KActor.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_40Gren/Proj_40Gren.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/Proj_50Cal_MetalEffectEmitter/Proj_50Cal_MetalEffectEmitter.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AProj_50Cal::AProj_50Cal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//MetalImpactEmitter = AProj_50Cal_MetalEffectEmitter::StaticClass();
	//cTracerClass = ABaseTracerEmitter::StaticClass();
	DamageClasses = {
		//ADecoMesh::StaticClass()
		//Class'Engine.Pawn'
		//ABaseProjectile::StaticClass()
		//AThrowWeaponPickup::StaticClass()
		//ATriggers::StaticClass()
		//AKActor::StaticClass()
	};
	//EnemyProjectileClass = AProj_40Gren::StaticClass();
	Speed = 40000;
	Damage = 150;
	MomentumTransfer = 5000;
	//MyDamageType = ACROWS_50CalDamage::StaticClass();
	//DrawType = DT_None;
	DrawScale = 1;
	CollisionRadius = 1;
	CollisionHeight = 1;
}

void AProj_50Cal::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector HitRay = FVector(0, 0, 0);
	FBoneInfo HitBone;
	FVector SavedCollisionLocation = FVector(0, 0, 0);
	FRotator SavedRotation = FRotator(0, 0, 0);
	UMaterialInstance* thisHitMaterial = nullptr;
	FVector ThisHitLocation = FVector(0, 0, 0);
	FVector ThisHitNormal = FVector(0, 0, 0);
	/*
	EmitterEffects(HitLocation, HitNormal, HitMaterial, HitActor);
	GetAxes(Rotation, X, Y, Z);
	SavedCollisionLocation = HitLocation;
	SavedRotation = rotator(Velocity);
	if (InstigatorController != nullptr)
	{
		HitRay = Normal((HitLocation - InstigatorController.Pawn.Location));
	}
	else
	{
		HitRay = Normal((HitLocation - Instigator.Controller.Pawn.Location));
	}
	BoneTrace(ThisHitLocation, ThisHitNormal, HitRay, (SavedCollisionLocation + (Vector(SavedRotation) * float(-35))), thisHitMaterial, HitBone, false);
	if (Instigator != nullptr)
	{
		if (Cast<AAGP_Pawn>(HitActor) != nullptr)
		{
			HitActor.TakeDamage(int(Damage), Instigator, HitLocation, Normal(HitRay), MyDamageType, HitBone, InstigatorController, this, HitMaterial);
		}
		else
		{
			if (HitActor->IsA(AVehicle::StaticClass()))
			{
				HitActor.TakeDamage(int(Damage), Instigator, HitLocation, (MomentumTransfer * HitRay), MyDamageType, HitBone, InstigatorController, this, HitMaterial);
			}
			else
			{
				HitActor.TakeDamage(int(Damage), Instigator, HitLocation, (MomentumTransfer * HitRay), MyDamageType, HitBone, , this);
			}
		}
	}
	if ((HitMaterial != nullptr) && (GetNetMode() != ENetMode::NM_DedicatedServer))
	{
		HitMaterial.PlayBulletContactSound(this, HitLocation, HitNormal, 0);
		HitMaterial.PlayBulletContactProjector(this, HitLocation, HitNormal, 0);
		HitMaterial.PlayBulletContactEmitter(this, HitLocation, HitNormal, 0);
	}
	SetDrawType(DT_None);
	SetPhysics(PHYS_None);
	Velocity = FVector(0, 0, 0);
	if (TracerEmitter != nullptr)
	{
		TracerEmitter.Destroy();
	}
	*/
	Destroy();
}

void AProj_50Cal::EmitterEffects(FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, AActor* HitActor)
{
	bool bMetalImpact = false;
	/*
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		switch (HitMaterial.GetMaterialType())
		{
		case 21:
			bMetalImpact = true;
			break;
		case 22:
			bMetalImpact = true;
			break;
		case 23:
			bMetalImpact = true;
			break;
		case 4:
			bMetalImpact = true;
			break;
		case 6:
			bMetalImpact = false;
			break;
		case 10:
			bMetalImpact = true;
			break;
		case 17:
			bMetalImpact = true;
			break;
		default:
			break;
		}
		bMetalImpact = true;
		if ((MetalImpactEmitter != nullptr) && bMetalImpact)
		{
			Spawn(MetalImpactEmitter, , , HitLocation, rotator((-HitNormal)));
		}
	}
	*/
}
