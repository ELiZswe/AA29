// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/M1114_Gunner/M1114_Gunner.h"
#include "AA29/Object/Actor/VehicleWeapon/M1114_50Cal/M1114_50Cal.h"

AM1114_Gunner::AM1114_Gunner()
{
	//GunClass = AM1114_50Cal::StaticClass();
	CameraBone = "Camera_Attach_Bone";
	DriveAnim = "SF_Humvee_50Cal_Down_Up";
}
