// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/FA_Ammo_556_30_Mag_Blanks/FA_Ammo_556_30_Mag_Blanks.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/FSTS_Shot_Detection_Volume/FSTS_Shot_Detection_Volume.h"

AFA_Ammo_556_30_Mag_Blanks::AFA_Ammo_556_30_Mag_Blanks()
{

}

void AFA_Ammo_556_30_Mag_Blanks::ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength)
{
	/*
	if (Cast<AFSTS_Shot_Detection_Volume>(HitActor) != nullptr)
	{
		HitActor.TakeDamage(0, W.Instigator, HitLocation, (MomentumTransfer * X), MyDamageType, HitBone, , W, HitMaterial);
	}
	Super::ProcessTraceHit(W, StartTrace, Direction, HitActor, HitBone, HitLocation, HitNormal, HitMaterial, X, Y, Z, fStrength);
	*/
}
