// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_M4qd_Suppressor/AttachMod_M4qd_Suppressor.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash/SuppressorMuzzleFlash.h"

AAttachMod_M4qd_Suppressor::AAttachMod_M4qd_Suppressor()
{
	//cSuppressorMuzzleFlash = ASuppressorMuzzleFlash::StaticClass();
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_m4qd_suppressor.wpn3_mods_display_m4qd_suppressor'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/m4qd_suppressor_3p.m4qd_suppressor_3p'"), NULL, LOAD_None, NULL);
}
