// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Acog4x/AttachMod_Acog4x.h"

AAttachMod_Acog4x::AAttachMod_Acog4x()
{
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_acog_4x.wpn3_mods_display_acog_4x'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/acog4x_3p.acog4x_3p'"), NULL, LOAD_None, NULL);
}
