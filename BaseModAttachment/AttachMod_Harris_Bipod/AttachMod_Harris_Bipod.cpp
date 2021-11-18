// All the original content belonged to the US Army


#include "AttachMod_Harris_Bipod.h"

AAttachMod_Harris_Bipod::AAttachMod_Harris_Bipod()
{
	//SpinnyMesh = StaticMesh'M_AA2_Weapons.mods_display.wpn3_mods_display_harris_bipod'
	//DrawType = 2
	//Mesh = SkeletalMesh'A_AA2_ModsUS.harris_bipod_3p'
}



void NotifyAttachmentAnimation(uint8 AnimState)
{
	/*
	local bool bNewSupported;
	bNewSupported = AnimState & 2 == 2;
	if (bNewSupported != bSupported)
	{
		bSupported = bNewSupported;
		if (bSupported)
		{
			PlayAnim('Supported', 1, 0.05);
		}
		else
		{
			PlayAnim('Unsupported', 1, 0.05);
		}
	}
	*/
}