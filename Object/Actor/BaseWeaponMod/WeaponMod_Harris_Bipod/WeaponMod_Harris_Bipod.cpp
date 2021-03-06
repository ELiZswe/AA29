// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Harris_Bipod/WeaponMod_Harris_Bipod.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Virtual_Harris_Bipod/WeaponMod_Virtual_Harris_Bipod.h"

AWeaponMod_Harris_Bipod::AWeaponMod_Harris_Bipod()
{
	WeaponBone       = "Bipod";
	bSupportMod      = true;
	ModImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_bipod_black_Mat.mod_bipod_black_Mat'"), NULL, LOAD_None, NULL);
	ModImageOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_bipod_Mat.m4mod_bipod_Mat'"), NULL, LOAD_None, NULL);
	//ValidSlot(4) = 1
	EnemyModClass    = AWeaponMod_Virtual_Harris_Bipod::StaticClass();
	modname          = "Harris Bipod";
	DrawType         = EDrawType::DT_Mesh;
	Mesh             = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/harris_bipod.harris_bipod"), NULL, LOAD_None, NULL);
}
