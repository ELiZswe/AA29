// All the original content belonged to the US Army


#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

USVehicleWheel::USVehicleWheel()
{
	BoneSteerAxis = EAA2_Axis::AXIS_Z;
	WheelRadius = 35;
	FlatWheelRadius = 25;
	RimWheelRadius = 5;
	Softness = 0.05;
	PenScale = 1;
	WheelInertia = 1;
	SuspensionTravel = 50;
	HandbrakeSlipFactor = 1;
	HandbrakeFrictionFactor = 1;
	SuspensionMaxRenderTravel = 50;
	SupportBoneAxis = EAA2_Axis::AXIS_Y;
}