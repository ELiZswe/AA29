// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Info/FluidSurfaceInfo/FluidSurfaceInfo.h"

AWeaponAttachment::AWeaponAttachment()
{
	BulletTrace.SetNum(5);
	FiringSpeed = 1;
	BeaconColor = FColor(0, 255, 0, 255);

	BulletImpact.SetNum(4);
	//CullDistance = 4000
	//bActorShadows = true
	//bReplicateInstigator = true
	//NetUpdateFrequency = 8
}

void AWeaponAttachment::DestroyAR3P()
{
}
void AWeaponAttachment::SpawnAndAttachAR3P()
{
}
void AWeaponAttachment::ThirdPersonEffects()
{
	/*
	if (Instigator != nullptr)
	{
		Instigator.PlayFiring(1,FiringMode);
	}
	*/
}

void AWeaponAttachment::CheckForSplash()
{
	AActor* HitActor = nullptr;
	FVector HitNormal = FVector(0,0,0);
	FVector HitLocation = FVector(0,0,0);
	/*
	if (! Level.bDropDetail && Level.DetailMode != 0 && SplashEffect != nullptr && ! Instigator.PhysicsVolume.bWaterVolume)
	{
		bTraceWater=true;
		HitActor=Trace(HitLocation,HitNormal,mHitLocation,Instigator->GetActorLocation(),true);
		bTraceWater=false;
		if (Cast<AFluidSurfaceInfo>(HitActor) != nullptr || PhysicsVolume(HitActor) != nullptr && PhysicsVolume(HitActor).bWaterVolume)
		{
			Spawn(SplashEffect,,,HitLocation,FRotator(16384 0 0));
		}
	}
	*/
}

void AWeaponAttachment::UpdateHit(AActor* HitActor, FVector HitLocation, FVector HitNormal)
{
}

void AWeaponAttachment::moveTurret()
{
}

void AWeaponAttachment::VerifyMesh()
{
}

void AWeaponAttachment::SetLaser()
{
}

int32 AWeaponAttachment::GetMaxBulletTraces()
{
	return 4;
}

FName AWeaponAttachment::GetAttachBoneFor(AInventory* Inv)
{
	/*
	if (Inv.Instigator.Weapon == Inv)
	{
		return Inv.Instigator.GetWeaponBoneFor(Inv);
	}
	else
	{
		return 'RSlungWeapon';
	}
	*/
	return "FAKE";    //FAKE ELiZ
}

void AWeaponAttachment::AdjustAttachmentFor(AInventory* Inv)
{
}

void AWeaponAttachment::AttachmentAnimation()
{
}

void AWeaponAttachment::ThirdPersonTrace()
{
}
