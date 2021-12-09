// All the original content belonged to the US Army


#include "WeaponMod_HeatShield.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Virtual_HeatShield/WeaponMod_Virtual_HeatShield.h"

AWeaponMod_HeatShield::AWeaponMod_HeatShield()
{
	ModImage           = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_heatshield_black.mod_heatshield_black"), NULL, LOAD_None, NULL);
	ModImageOverlay    = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_heatupper.m4mod_heatupper"), NULL, LOAD_None, NULL);
		//ValidSlot(1) = 1
		//ValidSlot(2) = 1
		//ValidSlot(3) = 1
		//ValidSlot(4) = 1
	EnemyModClass      = AWeaponMod_Virtual_HeatShield::StaticClass();
	modname            = "Heatshield";
	DrawType           = EDrawType::DT_Mesh;
	Mesh               = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/Heatshield.Heatshield"), NULL, LOAD_None, NULL);
}