// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1114_HMMWV/M1114_HMMWV_Desert/M1114_HMMWV_Desert.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

AM1114_HMMWV_Desert::AM1114_HMMWV_Desert()
{
	USVehicleWheel* RRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRWheel->bPoweredWheel = true;
	RRWheel->BoneName = "wheel_right_2_bone";
	RRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RRWheel->WheelBoneOffset = FVector(0, 6, 0);
	RRWheel->WheelRadius = 25;
	RRWheel->FlatWheelRadius = 22;
	RRWheel->RimWheelRadius = 18;
	RRWheel->SupportBoneName = "right_suspension_2_bone";
	RRWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* LRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRWheel->bPoweredWheel = true;
	LRWheel->BoneName = "wheel_left_2_bone";
	LRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LRWheel->WheelBoneOffset = FVector(0, -6, 0);
	LRWheel->WheelRadius = 25;
	LRWheel->FlatWheelRadius = 22;
	LRWheel->RimWheelRadius = 18;
	LRWheel->SupportBoneName = "left_suspension_2_bone";
	LRWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* RFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RFWheel->bPoweredWheel = true;
	RFWheel->SteerType = EVehicleSteerType::VST_Steered;
	RFWheel->BoneName = "wheel_right_1_bone";
	RFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RFWheel->WheelBoneOffset = FVector(0, 18, 0);
	RFWheel->WheelRadius = 25;
	RFWheel->FlatWheelRadius = 22;
	RFWheel->RimWheelRadius = 18;
	RFWheel->SupportBoneName = "right_suspension_1_bone";
	RFWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* LFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LFWheel->bPoweredWheel = true;
	LFWheel->SteerType = EVehicleSteerType::VST_Steered;
	LFWheel->BoneName = "wheel_left_1_bone";
	LFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LFWheel->WheelBoneOffset = FVector(0, -18, 0);
	LFWheel->WheelRadius = 25;
	LFWheel->FlatWheelRadius = 22;
	LFWheel->RimWheelRadius = 18;
	LFWheel->SupportBoneName = "left_suspension_1_bone";
	LFWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	Wheels = { RRWheel,LRWheel,RFWheel,LFWheel };
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1114_HMMWV_Desert.M1114_HMMWV_Desert'"), NULL, LOAD_None, NULL);
}
/*
void AM1114_HMMWV_Desert::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
}
*/
void AM1114_HMMWV_Desert::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1114_HMMWV_Desert::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}