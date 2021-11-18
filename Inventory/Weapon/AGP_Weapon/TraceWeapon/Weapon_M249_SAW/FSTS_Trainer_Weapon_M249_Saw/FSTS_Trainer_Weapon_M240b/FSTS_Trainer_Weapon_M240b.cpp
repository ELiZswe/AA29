// All the original content belonged to the US Army


#include "FSTS_Trainer_Weapon_M240b.h"
#include "AA29/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_M240b/PickupW_FSTS_Trainer_M240b.h"

AFSTS_Trainer_Weapon_M240b::AFSTS_Trainer_Weapon_M240b()
{
	FireAnimsLowAmmo				= { "Fire", "FireB", "FireC", "Fire", "FireB", "FireC", "Fire", "FireB", "FireC", "Fire"};
	StillLowAmmo					= { "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle" };
	SupportedFireAnimsLowAmmo		= { "None", "Fire", "Fire", "Fire", "Fire", "Fire", "Fire", "Fire", "Fire", "Fire" };
	SupportedStillLowAmmo			= { "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle", "Idle" };
	ReloadEmptyAnim					= FName("ReloadFull");
	ReloadFullAnim					= FName("ReloadFull");
	ProneReloadEmptyAnim			= FName("ReloadFull");
	ProneReloadFullAnim				= FName("ReloadFull");
	_FPMuzzleFlashOffset.VOffset	= FVector(0, 0, 0);
	_FPMuzzleFlashOffset.ROffset	= FRotator(0, 179.901123046875, 0);
	_FPMuzzleFlashOffset.nBone		= "Muzzle";
	DisplayFOV						= 7;
	PickupClass						= APickupW_FSTS_Trainer_M240b::StaticClass();
	PlayerViewOffset				= FVector(0, 0, 0);
	Mesh							= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M240b_1P.M240b_1P"), NULL, LOAD_None, NULL);
}


void AFSTS_Trainer_Weapon_M240b::GiveTo(APawn* Other, APickup* Pickup)
{
	
	//GiveTo(Other, Pickup);
	_bActive = true;
	//GotoState('Idle');
	bInZoom = true;
	bZoomDir = true;
	//Instigator.SetZoomed(bInZoom);
	
}
void AFSTS_Trainer_Weapon_M240b::PlayReloading()
{
	Super::PlayReloading();
}
void AFSTS_Trainer_Weapon_M240b::PlayIdleAnim()
{
	if (_bActive)
	{
		//RunAnimation('Idle', 1, 0.05, true);
	}
}
void AFSTS_Trainer_Weapon_M240b::Reload()
{
	//GotoState('BusyReloadingZoom', 'ZoomOut');
}
