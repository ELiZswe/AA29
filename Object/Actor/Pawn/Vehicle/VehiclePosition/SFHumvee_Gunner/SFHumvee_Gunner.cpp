// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/SFHumvee_Gunner/SFHumvee_Gunner.h"
#include "AA29/Object/Actor/VehicleWeapon/SFHumvee_50Cal/SFHumvee_50Cal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeaponFPOverlay/SFHumvee_50Cal_FP/SFHumvee_50Cal_FP.h"

ASFHumvee_Gunner::ASFHumvee_Gunner()
{
	//GunClass = ASFHumvee_50Cal::StaticClass();
	//GunOverlayClass = ASFHumvee_50Cal_FP::StaticClass();
	CameraBone = "Camera_Attach_Bone";
	DriveAnim = "SF_Humvee_50Cal_Down_Up";
	BaseEyeHeight = 150;
}
