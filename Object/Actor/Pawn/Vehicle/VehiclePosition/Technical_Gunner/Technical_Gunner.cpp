// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/Technical_Gunner/Technical_Gunner.h"
#include "AA29/Object/Actor/VehicleWeapon/Technical_PK/Technical_PK.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeaponFPOverlay/Technical_PK_FP/Technical_PK_FP.h"

ATechnical_Gunner::ATechnical_Gunner()
{
	//GunClass = ATechnical_PK::StaticClass();
	//GunOverlayClass = ATechnical_PK_FP::StaticClass();
	CameraBone = "Camera_Attach_Bone";
	DriveAnim = "PKS_Down_2_UP_middle";
	BaseEyeHeight = 90;
}
