// All the original content belonged to the US Army


#include "AttachW_M2_HMG.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/FixedWeapon/Weapon_M2_HMG/Weapon_M2_HMG.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash/AK47MuzzleFlash.h"


AAttachW_M2_HMG::AAttachW_M2_HMG()
{
	FixedWeaponClass		= AWeapon_M2_HMG::StaticClass();
	_cMuzzleFlashClass		= AAK47MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset	= FVector(0, 0, 0);
	_MuzzleOffset.ROffset	= FRotator(0, -90, 0);
	_MuzzleOffset.nBone		= "Muzzle";
	//bOnlyDrawIfAttached		= false;
	DrawType				= EDrawType::DT_Mesh;
	//bNoDelete				= true;
	sRotateStart			= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_TurretStart.WeaponsUS_Stryker_TurretStart"), NULL, LOAD_None, NULL);
	sRotateLoop				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_TurretLoop.WeaponsUS_Stryker_TurretLoop"), NULL, LOAD_None, NULL);
	sRotateStop				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_TurretStop.WeaponsUS_Stryker_TurretStop"), NULL, LOAD_None, NULL);
	Mesh					= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Objects/M2_Automated.M2_Automated"), NULL, LOAD_None, NULL);
}