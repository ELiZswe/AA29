// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/M1117_ASV_Gunner/M1117_ASV_Gunner.h"
#include "AA29/Object/Actor/VehicleWeapon/M1117_ASV_Turret/M1117_ASV_Turret.h"

AM1117_ASV_Gunner::AM1117_ASV_Gunner()
{
	//GunClass = AM1117_ASV_Turret::StaticClass();
	CameraBone = "Camera_Attach_Bone";
	bDrawDriverInTP = false;
}
