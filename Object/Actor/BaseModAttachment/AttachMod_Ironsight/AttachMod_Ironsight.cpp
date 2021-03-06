// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Ironsight/AttachMod_Ironsight.h"

AAttachMod_Ironsight::AAttachMod_Ironsight()
{
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_carryinghandle.wpn3_mods_display_carryinghandle'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/carryinghandle_3p.carryinghandle_3p'"), NULL, LOAD_None, NULL);
}
