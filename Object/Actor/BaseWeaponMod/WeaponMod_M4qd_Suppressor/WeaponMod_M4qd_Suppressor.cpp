// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_M4qd_Suppressor/WeaponMod_M4qd_Suppressor.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_PBS4_Suppressor/WeaponMod_PBS4_Suppressor.h"

AWeaponMod_M4qd_Suppressor::AWeaponMod_M4qd_Suppressor()
{
	ModImage		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_suppressor_black_Mat.mod_suppressor_black_Mat'"), NULL, LOAD_None, NULL);
	ModImageOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_suppressor_Mat.m4mod_suppressor_Mat'"), NULL, LOAD_None, NULL);
	bSuppressorMod   = true;
	//ValidSlot(5) = 1
	EnemyModClass    = AWeaponMod_PBS4_Suppressor::StaticClass();
	modname          = "M4QD Suppressor";
	DrawType         = EDrawType::DT_Mesh;
	Mesh             = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/m4qd_suppressor.m4qd_suppressor"), NULL, LOAD_None, NULL);
}
