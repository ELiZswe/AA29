// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AWeaponAttachment::AWeaponAttachment()
{
	FiringSpeed = 1;
	BeaconColor = FColor(0, 255, 0, 255);

	BulletImpact.SetNum(4);
	//CullDistance = 4000
	//bActorShadows = True
	//bReplicateInstigator = True
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
	/*
		local Actor HitActor;
		local FVector HitNormal;
		local FVector HitLocation;
		if (! Level.bDropDetail && Level.DetailMode != 0 && SplashEffect != nullptr && ! Instigator.PhysicsVolume.bWaterVolume)
		{
			bTraceWater=true;
			HitActor=Trace(HitLocation,HitNormal,mHitLocation,Instigator.Location,True);
			bTraceWater=False;
			if (FluidSurfaceInfo(HitActor) != nullptr || PhysicsVolume(HitActor) != nullptr && PhysicsVolume(HitActor).bWaterVolume)
			{
				Spawn(SplashEffect,,,HitLocation,rot(16384 0 0));
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
