// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Harris_Bipod/AttachMod_Harris_Bipod.h"

AAttachMod_Harris_Bipod::AAttachMod_Harris_Bipod()
{
	SpinnyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/mods_display/wpn3_mods_display_harris_bipod.wpn3_mods_display_harris_bipod'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/harris_bipod_3p.harris_bipod_3p'"), NULL, LOAD_None, NULL);
}

void AAttachMod_Harris_Bipod::NotifyAttachmentAnimation(uint8 AnimState)
{
	bool bNewSupported = false;
	bNewSupported = ((AnimState & 2) == 2);
	if (bNewSupported != bSupported)
	{
		bSupported = bNewSupported;
		if (bSupported)
		{
			//PlayAnim('Supported', 1, 0.05);
		}
		else
		{
			//PlayAnim('Unsupported', 1, 0.05);
		}
	}
}
