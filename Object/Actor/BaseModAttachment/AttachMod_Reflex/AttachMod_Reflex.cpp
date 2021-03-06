// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Reflex/AttachMod_Reflex.h"

AAttachMod_Reflex::AAttachMod_Reflex()
{
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_acog_reflex.wpn3_mods_display_acog_reflex'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/AcogReflex_3p.AcogReflex_3p'"), NULL, LOAD_None, NULL);
}
