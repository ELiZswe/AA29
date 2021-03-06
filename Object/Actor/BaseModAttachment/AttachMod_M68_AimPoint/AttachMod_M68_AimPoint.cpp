// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_M68_AimPoint/AttachMod_M68_AimPoint.h"

AAttachMod_M68_AimPoint::AAttachMod_M68_AimPoint()
{
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_m68_aimpoint.wpn3_mods_display_m68_aimpoint'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/m68_aimpoint_3p.m68_aimpoint_3p'"), NULL, LOAD_None, NULL);
}
