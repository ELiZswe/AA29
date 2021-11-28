// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/stryker/stryker.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

Astryker::Astryker()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 7;
	KParams0->KInertiaTensor[3] = 15;
	KParams0->KInertiaTensor[5] = 18;
	KParams0->KCOMOffset = FVector(-0.452, 0, 0);
	KParams0->KLinearDamping = 0.065;
	KParams0->KAngularDamping = 0.06;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 1;
	KParams0->KImpactThreshold = 500;
	UVehicleEntryPoint* LeftSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	LeftSideEntry->bDriverEntry = true;
	LeftSideEntry->EntryBone = "Entry_Driver_bone";
	UVehicleEntryPoint* RearPassengerEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	RearPassengerEntry->EntryBone = "entry_rear_bone";
	RearPassengerEntry->PositionIndex = { 1, 2,3,4,5,6,6 };
	UVehicleEntryPoint* GunnerEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	GunnerEntry->EntryBone = "entry_gunner_1_bone";
	GunnerEntry->PositionIndex = { 0 };
	UVehicleDamageZone* Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left->ArmorThreshold = 5;
	Front_Left->MaxHitPoints = 1000;
	//Front_Left->DamageStates(0) = FDamageStateStruct({ "body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Front_Left->DamageStates(1) = FDamageStateStruct({ "DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',nullptr,nullptr });
	//Front_Left->DamageStates(2) = FDamageStateStruct({ "DS2_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',nullptr,nullptr });
	UVehicleDamageZone* Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right->ArmorThreshold = 5;
	Front_Right->MaxHitPoints = 1000;
	//Front_Right->DamageStates(0) = FDamageStateStruct({ "body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Front_Right->DamageStates(1) = FDamageStateStruct({ "DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',nullptr,nullptr });
	//Front_Right->DamageStates(2) = FDamageStateStruct({ "DS2_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',nullptr,nullptr });
	UVehicleDamageZone* Middle_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Left->ArmorThreshold = 5;
	Middle_Left->MaxHitPoints = 1000;
	//Middle_Left->DamageStates(0) = FDamageStateStruct({ "body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Middle_Left->DamageStates(1) = FDamageStateStruct({ "DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',nullptr,nullptr });
	//Middle_Left->DamageStates(2) = FDamageStateStruct({ "DS2_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',nullptr,nullptr });
	UVehicleDamageZone* Middle_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Right->ArmorThreshold = 5;
	Middle_Right->MaxHitPoints = 1000;
	//Middle_Right->DamageStates(0) = FDamageStateStruct({ "body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Middle_Right->DamageStates(1) = FDamageStateStruct({ "DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',nullptr,nullptr });
	//Middle_Right->DamageStates(2) = FDamageStateStruct({ "DS2_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',nullptr,nullptr });
	UVehicleDamageZone* Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left->ArmorThreshold = 5;
	Rear_Left->MaxHitPoints = 1000;
	//Rear_Left->DamageStates(0) = FDamageStateStruct({ "body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Rear_Left->DamageStates(1) = FDamageStateStruct({ "DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',nullptr,nullptr });
	//Rear_Left->DamageStates(2) = FDamageStateStruct({ "DS2_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',nullptr,nullptr });
	UVehicleDamageZone* Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right->ArmorThreshold = 5;
	Rear_Right->MaxHitPoints = 1000;
	//Rear_Right->DamageStates(0) = FDamageStateStruct({ "body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Rear_Right->DamageStates(1) = FDamageStateStruct({ "DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',nullptr,nullptr });
	//Rear_Right->DamageStates(2) = FDamageStateStruct({ "DS2_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',nullptr,nullptr });
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 2;
	Wheel_Left_1->DamageModifier = 10;
	Wheel_Left_1->MaxHitPoints = 1000;
	Wheel_Left_1->bWheelZone = true;
	Wheel_Left_1->WheelNum = 4;
	//Wheel_Left_1->DamageStates(0) = FDamageStateStruct({ "wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Left_1->DamageStates(1) = FDamageStateStruct({ "ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_1->DamageStates(2) = FDamageStateStruct({ "ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 2;
	Wheel_Right_1->DamageModifier = 10;
	Wheel_Right_1->MaxHitPoints = 1000;
	Wheel_Right_1->bWheelZone = true;
	//Wheel_Right_1->DamageStates(0) = FDamageStateStruct({ "wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Right_1->DamageStates(1) = FDamageStateStruct({ "ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_1->DamageStates(2) = FDamageStateStruct({ "ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 2;
	Wheel_Left_2->DamageModifier = 10;
	Wheel_Left_2->MaxHitPoints = 1000;
	Wheel_Left_2->bWheelZone = true;
	Wheel_Left_2->WheelNum = 5;
	//Wheel_Left_2->DamageStates(0) = FDamageStateStruct({ "wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Left_2->DamageStates(1) = FDamageStateStruct({ "ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_2->DamageStates(2) = FDamageStateStruct({ "ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 2;
	Wheel_Right_2->DamageModifier = 10;
	Wheel_Right_2->MaxHitPoints = 1000;
	Wheel_Right_2->bWheelZone = true;
	Wheel_Right_2->WheelNum = 1;
	//Wheel_Right_2->DamageStates(0) = FDamageStateStruct({ "wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Right_2->DamageStates(1) = FDamageStateStruct({ "ds1_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_2->DamageStates(2) = FDamageStateStruct({ "ds2_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_3->ArmorThreshold = 2;
	Wheel_Left_3->DamageModifier = 10;
	Wheel_Left_3->MaxHitPoints = 1000;
	Wheel_Left_3->bWheelZone = true;
	Wheel_Left_3->WheelNum = 6;
	//Wheel_Left_3->DamageStates(0) = FDamageStateStruct({ "Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Left_3->DamageStates(1) = FDamageStateStruct({ "DS1_Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_3->DamageStates(2) = FDamageStateStruct({ "DS2_Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_3->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_3->ArmorThreshold = 2;
	Wheel_Right_3->DamageModifier = 10;
	Wheel_Right_3->MaxHitPoints = 1000;
	Wheel_Right_3->bWheelZone = true;
	Wheel_Right_3->WheelNum = 2;
	//Wheel_Right_3->DamageStates(0) = FDamageStateStruct({ "Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Right_3->DamageStates(1) = FDamageStateStruct({ "DS1_Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_3->DamageStates(2) = FDamageStateStruct({ "DS2_Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_3->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_4->ArmorThreshold = 2;
	Wheel_Left_4->DamageModifier = 10;
	Wheel_Left_4->MaxHitPoints = 1000;
	Wheel_Left_4->bWheelZone = true;
	Wheel_Left_4->WheelNum = 7;
	//Wheel_Left_4->DamageStates(0) = FDamageStateStruct({ "Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Left_4->DamageStates(1) = FDamageStateStruct({ "DS1_Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_4->DamageStates(2) = FDamageStateStruct({ "DS2_Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_4->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_4->ArmorThreshold = 2;
	Wheel_Right_4->DamageModifier = 10;
	Wheel_Right_4->MaxHitPoints = 1000;
	Wheel_Right_4->bWheelZone = true;
	Wheel_Right_4->WheelNum = 3;
	//Wheel_Right_4->DamageStates(0) = FDamageStateStruct({ "Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Right_4->DamageStates(1) = FDamageStateStruct({ "DS1_Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_4->DamageStates(2) = FDamageStateStruct({ "DS2_Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_4->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 5;
	Turret->MaxHitPoints = 1000;
	/*
	Turret->DamageStates = {
		FDamageStateStruct({ "Yaw","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr }),
		FDamageStateStruct({ "Yaw","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr })
	};
	*/

	Turret->bControlsExternalMesh = true;
	Turret->VehiclePositionOwnerIndex = 1;
	Turret->MeshOwnerType = EMeshOwnerType::MO_VehiclePositionWeapon;
	USVehicleWheel* RWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel1->bPoweredWheel = true;
	RWheel1->SteerType = EVehicleSteerType::VST_Steered;
	RWheel1->BoneName = "wheel_right_1_bone";
	RWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel1->WheelRadius = 33;
	USVehicleWheel* RWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel2->bPoweredWheel = true;
	RWheel2->SteerType = EVehicleSteerType::VST_Steered;
	RWheel2->BoneName = "wheel_right_2_bone";
	RWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel2->WheelRadius = 33;
	USVehicleWheel* RWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel3->bPoweredWheel = true;
	RWheel3->BoneName = "Wheel_Right_3_Bone";
	RWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel3->WheelRadius = 33;
	USVehicleWheel* RWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel4->bPoweredWheel = true;
	RWheel4->BoneName = "Wheel_Right_4_Bone";
	RWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel4->WheelRadius = 33;
	USVehicleWheel* LWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel1->bPoweredWheel = true;
	LWheel1->SteerType = EVehicleSteerType::VST_Steered;
	LWheel1->BoneName = "wheel_left_1_bone";
	LWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel1->WheelRadius = 33;
	USVehicleWheel* LWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel2->bPoweredWheel = true;
	LWheel2->SteerType = EVehicleSteerType::VST_Steered;
	LWheel2->BoneName = "wheel_left_2_bone";
	LWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel2->WheelRadius = 33;
	USVehicleWheel* LWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel3->bPoweredWheel = true;
	LWheel3->BoneName = "Wheel_Left_3_Bone";
	LWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel3->WheelRadius = 33;
	USVehicleWheel* LWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel4->bPoweredWheel = true;
	LWheel4->BoneName = "Wheel_Left_4_Bone";
	LWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel4->WheelRadius = 33;

	WheelSoftness = 0.02;
	WheelPenScale = 2.1;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.5;
	WheelInertia = 0.121;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 1;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 15;
	WheelSuspensionMaxRenderTravel = 14;
	FTScale = 0.04;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.35,0.25,0.34,0.51,0.72,1.05,1.35 };
	NumForwardGears = 6;
	TransRatio = 0.16;
	ChangeUpPoint = 3000;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-06;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	StopThreshold = 120;
	HandbrakeThresh = 200;
	EngineInertia = 0.04;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	RevMeterScale = 4000;
	//PositionTypes(0) = ({ class'AGP_Vehicles.Stryker_MainGunner',"Mount_Weapon_Bone","None",FVector(0, 0, 0),FVector(0, 0, 0),(Pitch })
	//PositionTypes(1) = ({ class'AGP_Vehicles.PassengerPosition',"None","None",FVector(0, 0, 0),FVector(0, 0, 0),(Pitch })
	//PositionTypes(2) = ({ class'AGP_Vehicles.PassengerPosition',"None","None",FVector(0, 0, 0),FVector(0, 0, 0),(Pitch })
	//PositionTypes(3) = ({ class'AGP_Vehicles.PassengerPosition',"None","None",FVector(0, 0, 0),FVector(0, 0, 0),(Pitch })
	//PositionTypes(4) = ({ class'AGP_Vehicles.PassengerPosition',"None","None",FVector(0, 0, 0),FVector(0, 0, 0),(Pitch })
	//PositionTypes(5) = ({ class'AGP_Vehicles.PassengerPosition',"None","None",FVector(0, 0, 0),FVector(0, 0, 0),(Pitch })
	//PositionTypes(6) = ({ class'AGP_Vehicles.PassengerPosition',"None","None",FVector(0, 0, 0),FVector(0, 0, 0),(Pitch });
	EntryPoints = { LeftSideEntry,RearPassengerEntry,GunnerEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/stryker/STRYKER_Idle_Lp_3_Que.STRYKER_Idle_Lp_3_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/stryker/STRYKER_Start_3_Que.STRYKER_Start_3_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/stryker/Stryker_static.Stryker_static'"), NULL, LOAD_None, NULL);
	//DestroyedModelClass = class'AGP_Vehicles.Stryker_DestroyedBody';
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({100, 150});
	DefaultDamageZones = { Front_Left,Front_Right,Middle_Left,Middle_Right,Rear_Left,Rear_Right,Wheel_Left_1,Wheel_Right_1,Wheel_Left_2,Wheel_Right_2,Wheel_Left_3,Wheel_Right_3,Wheel_Left_4,Wheel_Right_4,Turret };
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	Wheels = { RWheel1,RWheel2,RWheel3,RWheel4,LWheel1,LWheel2,LWheel3,LWheel4 };
	VehicleMass = 9.4;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawMeshInFP = true;
	Team = 255;
	DriveAnim = "CrhNo";
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100),FVector(0, -165, -100),FVector(0, 165,  -100) };
	FPCamPos = FVector(20, -35, 102);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a Stryker";
	VehicleNameString = "Stryker";
	ObjectiveGetOutDist = 1500;
	GroundSpeed = 1290;
	HealthMax = 600;
	Health = 600;
	Bob = 0.016;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/stryker.stryker'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 200;
	//CollisionHeight = 120;
	KParams = KParams0;
}


/*
void Astryker::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'skn_veh_hummer1114_lightoff');
	L.AddPrecacheMaterial(Texture'gascan1');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_green01a');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_lights_g01a');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01a');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01b');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01c_t');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_tire01d');
	StaticPrecache(L);
}
*/

void Astryker::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void Astryker::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'skn_veh_hummer1114_lightoff');
	Level.AddPrecacheMaterial(Texture'gascan1');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_green01a');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_lights_g01a');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01a');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01b');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01c_t');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_tire01d');
	*/
	Super::UpdatePrecacheMaterials();
}