// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_HeatShield/WeaponMod_HeatShield.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Virtual_HeatShield/WeaponMod_Virtual_HeatShield.h"

AWeaponMod_HeatShield::AWeaponMod_HeatShield()
{
	ModImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_heatshield_black_Mat.mod_heatshield_black_Mat'"), NULL, LOAD_None, NULL);
	ModImageOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_heatupper_Mat.m4mod_heatupper_Mat'"), NULL, LOAD_None, NULL);
	//ValidSlot(1) = 1
		//ValidSlot(2) = 1
		//ValidSlot(3) = 1
		//ValidSlot(4) = 1
	EnemyModClass      = AWeaponMod_Virtual_HeatShield::StaticClass();
	modname            = "Heatshield";
	DrawType           = EDrawType::DT_Mesh;
	Mesh               = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/Heatshield.Heatshield"), NULL, LOAD_None, NULL);
}
