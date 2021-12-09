// All the original content belonged to the US Army


#include "AttachW_BTR_HMG.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/Weapon_BTR_HMG/Weapon_BTR_HMG.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash/AK47MuzzleFlash.h"


AAttachW_BTR_HMG::AAttachW_BTR_HMG()
{
	FixedWeaponClass		= AWeapon_BTR_HMG::StaticClass();
	sRotateStart			= LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_TurretStart_Cue.WeaponsUS_Stryker_TurretStart_Cue'"), NULL, LOAD_None, NULL);
	sRotateLoop				= LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_TurretLoop_Cue.WeaponsUS_Stryker_TurretLoop_Cue'"), NULL, LOAD_None, NULL);
	sRotateStop				= LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_TurretStop_Cue.WeaponsUS_Stryker_TurretStop_Cue'"), NULL, LOAD_None, NULL);
	_cMuzzleFlashClass		= AAK47MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset	= FVector(0, 0, 0);
	_MuzzleOffset.ROffset	= FRotator(0, -90, 0);
	_MuzzleOffset.nBone		= "Muzzle";
	DrawType				= EDrawType::DT_Mesh;
	//bNoDelete				= true;
	//bOnlyDrawIfAttached		= false;
	Mesh					= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Objects/BTR_Turret.BTR_Turret"), NULL, LOAD_None, NULL);
}