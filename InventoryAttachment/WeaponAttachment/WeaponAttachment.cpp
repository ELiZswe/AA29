// All the original content belonged to the US Army


#include "WeaponAttachment.h"
#include "AA29/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"


AWeaponAttachment::AWeaponAttachment()
{
	FiringSpeed = 1;
	BeaconColor = FColor(0, 255, 0, 255);

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
		if (Instigator != None)
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
		if (! Level.bDropDetail && Level.DetailMode != 0 && SplashEffect != None && ! Instigator.PhysicsVolume.bWaterVolume)
		{
			bTraceWater=True;
			HitActor=Trace(HitLocation,HitNormal,mHitLocation,Instigator.Location,True);
			bTraceWater=False;
			if (FluidSurfaceInfo(HitActor) != None || PhysicsVolume(HitActor) != None && PhysicsVolume(HitActor).bWaterVolume)
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
void AWeaponAttachment::GetAttachBoneFor(AInventory* Inv)
{
	/*
		if (Inv.Instigator.Weapon == Inv)
		{
			Return Inv.Instigator.GetWeaponBoneFor(Inv);
		}
		else
		{
			Return 'RSlungWeapon';
		}
	*/
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