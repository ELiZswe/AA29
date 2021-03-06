// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_M203_Gren/AttachMod_M203_Gren.h"

AAttachMod_M203_Gren::AAttachMod_M203_Gren()
{
	SpinnyWeaponMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Weapons3P/m4a1_m203_spinny_3P.m4a1_m203_spinny_3P'"), NULL, LOAD_None, NULL);
	WeaponMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Weapons3P/m4a1_m203_3P.m4a1_m203_3P'"), NULL, LOAD_None, NULL);
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_m203a1_grenade_launcher.wpn3_mods_display_m203a1_grenade_launcher'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_None;
}
