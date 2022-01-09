// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/Proj_50Cal.h"
#include "AA29/Object/DamageType/CROWS_50CalDamage/CROWS_50CalDamage.h"

AProj_50Cal::AProj_50Cal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//MetalImpactEmitter = class'AGP_Vehicles.Proj_50Cal_MetalEffectEmitter';
	//cTracerClass = Class'AGP_Effects.BaseTracerEmitter';
	DamageClasses = {
		//Class'Engine.DecoMesh'
		//Class'Engine.Pawn'
		//Class'Engine.BaseProjectile'
		//Class'AGP.ThrowWeaponPickup'
		//Class'Engine.Triggers'
		//Class'Engine.KActor'
	};
	//EnemyProjectileClass = Class'AGP_Inventory.Proj_40Gren';
	Speed = 40000;
	Damage = 150;
	MomentumTransfer = 5000;
	//MyDamageType = class'AGP_Vehicles.CROWS_50CalDamage';
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
		if (AGP_Pawn(HitActor) != nullptr)
		{
			HitActor.TakeDamage(int(Damage), Instigator, HitLocation, Normal(HitRay), MyDamageType, HitBone, InstigatorController, this, HitMaterial);
		}
		else
		{
			if (HitActor.IsA("Vehicle"))
			{
				HitActor.TakeDamage(int(Damage), Instigator, HitLocation, (MomentumTransfer * HitRay), MyDamageType, HitBone, InstigatorController, this, HitMaterial);
			}
			else
			{
				HitActor.TakeDamage(int(Damage), Instigator, HitLocation, (MomentumTransfer * HitRay), MyDamageType, HitBone, , Self);
			}
		}
	}
	if ((HitMaterial != nullptr) && (Level.NetMode != NM_DedicatedServer))
	{
		HitMaterial.PlayBulletContactSound(Self, HitLocation, HitNormal, 0);
		HitMaterial.PlayBulletContactProjector(Self, HitLocation, HitNormal, 0);
		HitMaterial.PlayBulletContactEmitter(Self, HitLocation, HitNormal, 0);
	}
	SetDrawType(DT_None);
	SetPhysics(PHYS_None);
	Velocity = vect(0, 0, 0);
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
	if (Level.NetMode != NM_DedicatedServer)
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