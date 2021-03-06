// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_HeatShield/AttachMod_HeatShield.h"

AAttachMod_HeatShield::AAttachMod_HeatShield()
{
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_heatshield.wpn3_mods_display_heatshield'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/heatshield_3p.heatshield_3p'"), NULL, LOAD_None, NULL);
}
