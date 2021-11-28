// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1083_FMTV/M1083_FMTV.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"


AM1083_FMTV::AM1083_FMTV()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 10;
	KParams0->KInertiaTensor[3] = 20;
	KParams0->KInertiaTensor[5] = 25;
	KParams0->KCOMOffset = FVector(0.3, 0, -0.3);
	KParams0->KLinearDamping = 0.03;
	KParams0->KAngularDamping = 0.005;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 2250;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 1;
	KParams0->KRestitution = 0.2;
	KParams0->KImpactThreshold = 500;
	UVehicleEntryPoint* DriverSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	DriverSideEntry->bDriverEntry = true;
	DriverSideEntry->EntryBone = "Entry_Driver_bone";
	UVehicleEntryPoint* PassengerSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	PassengerSideEntry->EntryBone = "Entry_Passenger_2_bone";
	PassengerSideEntry->PositionIndex = { 0 };
	UVehicleDamageZone* Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right->ArmorThreshold = 3;
	Front_Right->MaxHitPoints = 1000;
	//Front_Right->DamageStates(0) = ({ "body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Right->DamageStates(1) = ({ "DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'AGP_Vehicles.VPE_EngineDamage' });
	//Front_Right->DamageStates(2) = ({ "DS2_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'AGP_Vehicles.VPE_EngineDestroyed' });
	UVehicleDamageZone* Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left->ArmorThreshold = 3;
	Front_Left->MaxHitPoints = 1000;
	//Front_Left->DamageStates(0) = ({ "body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Left->DamageStates(1) = ({ "DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'AGP_Vehicles.VPE_EngineDamage' });
	//Front_Left->DamageStates(2) = ({ "DS2_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'AGP_Vehicles.VPE_EngineDestroyed' });
	UVehicleDamageZone* Middle_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Right->ArmorThreshold = 3;
	Middle_Right->MaxHitPoints = 1000;
	//Middle_Right->DamageStates(0) = ({ "body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Middle_Right->DamageStates(1) = ({ "DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Middle_Right->DamageStates(2) = ({ "DS2_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Middle_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Left->ArmorThreshold = 3;
	Middle_Left->MaxHitPoints = 1000;
	//Middle_Left->DamageStates(0) = ({ "body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Middle_Left->DamageStates(1) = ({ "DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Middle_Left->DamageStates(2) = ({ "DS2_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right->ArmorThreshold = 3;
	Rear_Right->MaxHitPoints = 1000;
	//Rear_Right->DamageStates(0) = ({ "body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Right->DamageStates(1) = ({ "DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Rear_Right->DamageStates(2) = ({ "DS2_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left->ArmorThreshold = 3;
	Rear_Left->MaxHitPoints = 1000;
	//Rear_Left->DamageStates(0) = ({ "body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Left->DamageStates(1) = ({ "DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Rear_Left->DamageStates(2) = ({ "DS2_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 2;
	Wheel_Left_1->DamageModifier = 10;
	Wheel_Left_1->MaxHitPoints = 1000;
	Wheel_Left_1->bWheelZone = true;
	Wheel_Left_1->WheelNum = 3;
	//Wheel_Left_1->DamageStates(0) = ({ "wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_1->DamageStates(1) = ({ "ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_1->DamageStates(2) = ({ "ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 2;
	Wheel_Left_2->DamageModifier = 10;
	Wheel_Left_2->MaxHitPoints = 1000;
	Wheel_Left_2->bWheelZone = true;
	Wheel_Left_2->WheelNum = 4;
	//Wheel_Left_2->DamageStates(0) = ({ "wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_2->DamageStates(1) = ({ "ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_2->DamageStates(2) = ({ "ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_3->ArmorThreshold = 2;
	Wheel_Left_3->DamageModifier = 10;
	Wheel_Left_3->MaxHitPoints = 1000;
	Wheel_Left_3->bWheelZone = true;
	Wheel_Left_3->WheelNum = 5;
	//Wheel_Left_3->DamageStates(0) = ({ "Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_3->DamageStates(1) = ({ "DS1_Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_3->DamageStates(2) = ({ "DS2_Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_3->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_3->ArmorThreshold = 2;
	Wheel_Right_3->DamageModifier = 10;
	Wheel_Right_3->MaxHitPoints = 1000;
	Wheel_Right_3->bWheelZone = true;
	Wheel_Right_3->WheelNum = 2;
	//Wheel_Right_3->DamageStates(0) = ({ "Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_3->DamageStates(1) = ({ "DS1_Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_3->DamageStates(2) = ({ "DS2_Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_3->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 2;
	Wheel_Right_2->DamageModifier = 10;
	Wheel_Right_2->MaxHitPoints = 1000;
	Wheel_Right_2->bWheelZone = true;
	Wheel_Right_2->WheelNum = 1;
	//Wheel_Right_2->DamageStates(0) = ({ "wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_2->DamageStates(1) = ({ "ds1_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_2->DamageStates(2) = ({ "ds2_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 2;
	Wheel_Right_1->DamageModifier = 10;
	Wheel_Right_1->MaxHitPoints = 1000;
	Wheel_Right_1->bWheelZone = true;
	//Wheel_Right_1->DamageStates(0) = ({ "wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_1->DamageStates(1) = ({ "ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_1->DamageStates(2) = ({ "ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Right_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Right_Windshield->MaxHitPoints = 1000;
	//Right_Windshield->DamageStates(0) = ({ "windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Right_Windshield->DamageStates(1) = ({ "ds1_windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Right_Windshield->bNoPassDamageToVehicle = true;
	Right_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Left_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Left_Windshield->MaxHitPoints = 1000;
	//Left_Windshield->DamageStates(0) = ({ "windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Left_Windshield->DamageStates(1) = ({ "ds1_windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Left_Windshield->bNoPassDamageToVehicle = true;
	Left_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Left_Window->MaxHitPoints = 1000;
	//Left_Window->DamageStates(0) = ({ "window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Left_Window->DamageStates(1) = ({ "DS1_window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Left_Window->bNoPassDamageToVehicle = true;
	Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Right_Window->MaxHitPoints = 1000;
	//Right_Window->DamageStates(0) = ({ "window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Right_Window->DamageStates(1) = ({ "DS1_window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Right_Window->bNoPassDamageToVehicle = true;
	Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 3;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0) = ({ "Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Turret->DamageStates(1) = ({ "DS2_Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	Turret->bControlsExternalMesh = true;
	Turret->MeshOwnerType = EMeshOwnerType::MO_AttachedActor;
	USVehicleWheel* FRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	FRWheel->bPoweredWheel = true;
	FRWheel->SteerType = EVehicleSteerType::VST_Steered;
	FRWheel->BoneName = "wheel_right_1_bone";
	FRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	FRWheel->WheelBoneOffset = FVector(0, 30, 0);
	FRWheel->WheelRadius = 36;
	FRWheel->FlatWheelRadius = 32;
	FRWheel->RimWheelRadius = 26;
	USVehicleWheel* MRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	MRWheel->bPoweredWheel = true;
	MRWheel->BoneName = "wheel_right_2_bone";
	MRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	MRWheel->WheelBoneOffset = FVector(0, 30, 0);
	MRWheel->WheelRadius = 36;
	MRWheel->FlatWheelRadius = 32;
	MRWheel->RimWheelRadius = 26;
	USVehicleWheel* RRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRWheel->bPoweredWheel = true;
	RRWheel->BoneName = "Wheel_Right_3_Bone";
	RRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RRWheel->WheelBoneOffset = FVector(0, 30, 0);
	RRWheel->WheelRadius = 36;
	RRWheel->FlatWheelRadius = 32;
	RRWheel->RimWheelRadius = 26;
	USVehicleWheel* FLWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	FLWheel->bPoweredWheel = true;
	FLWheel->SteerType = EVehicleSteerType::VST_Steered;
	FLWheel->BoneName = "wheel_left_1_bone";
	FLWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	FLWheel->WheelBoneOffset = FVector(0, -30, 0);
	FLWheel->WheelRadius = 36;
	FLWheel->FlatWheelRadius = 32;
	FLWheel->RimWheelRadius = 26;
	USVehicleWheel* MLWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	MLWheel->bPoweredWheel = true;
	MLWheel->BoneName = "wheel_left_2_bone";
	MLWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	MLWheel->WheelBoneOffset = FVector(0, -30, 0);
	MLWheel->WheelRadius = 36;
	MLWheel->FlatWheelRadius = 32;
	MLWheel->RimWheelRadius = 26;
	USVehicleWheel* RLWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RLWheel->bPoweredWheel = true;
	RLWheel->BoneName = "Wheel_Left_3_Bone";
	RLWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RLWheel->WheelBoneOffset = FVector(0, -30, 0);
	RLWheel->WheelRadius = 36;
	RLWheel->FlatWheelRadius = 32;
	RLWheel->RimWheelRadius = 26;
	WheelSoftness = 0.01;
	WheelPenScale = 1.1;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.1;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 1.5;
	WheelLatFrictionScale = 0.9;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 25;
	WheelSuspensionOffset = -5;
	WheelSuspensionMaxRenderTravel = 6;
	ExhaustBone = "Exhaust_1_Bone";
	bHasExhaust = true;
	FTScale = 0.03;
	ChassisTorqueScale = 0.05;
	MinBrakeFriction = 5;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.2,0.15,0.25,0.4,0.6,0.95,1.35,1.8 };
	NumForwardGears = 7;
	TransRatio = 0.21;
	ChangeUpPoint = 2100;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 0.0001;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 100;
	HandbrakeThresh = 200;
	EngineInertia = 0.15;
	IdleRPM = 500;
	EngineRPMSoundRange = 5000;
	SteerBoneName = "steering_wheel_1_bone";
	SteerBoneMaxAngle = 120;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//PositionTypes(0) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_2_bone",FVector(185, 45, 88),FVector(0, -20, -4),FRotator(0,0,0) });
	EntryPoints = { DriverSideEntry,PassengerSideEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/FMTV/FMTV_Idle_Lp_1_Que.FMTV_Idle_Lp_1_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/FMTV/FMTV_Start_1_Que.FMTV_Start_1_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/FMTV/M1083_FMTV_Static.M1083_FMTV_Static'"), NULL, LOAD_None, NULL);
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 150 });
	DefaultDamageZones = {
		Front_Right,
		Front_Left,
		Middle_Right,
		Middle_Left,
		Rear_Right,
		Rear_Left,
		Wheel_Left_1,
		Wheel_Left_2,
		Wheel_Left_3,
		Wheel_Right_3,
		Wheel_Right_2,
		Wheel_Right_1,
		Right_Windshield,
		Left_Windshield,
		Left_Window,
		Right_Window,
		Turret
	};
	//AttachedActorTypes(0) = ({ class'AGP_Vehicles.M1083_FMTVCover',"Seat_Passenger_1_Bone" });
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	ImpactDamageRadius = 250;
	Wheels = { FRWheel,MRWheel,RRWheel,FLWheel,MLWheel,RLWheel };
	VehicleMass = 10;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawDriverInTP = true;
	bDrawMeshInFP = true;
	Team = 255;
	DriverBone = "seat_driver_bone";
	DriveAnim = "SF_Humvee_Driver_turn_Idle";
	DriverPosOffset = FVector(0, 15, -4);
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100), FVector(0, -165, -100), FVector(0, 165, -100) };
	FPCamPos = FVector(185, -45, 88);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a M1083 MTV";
	VehicleNameString = "M1083 MTV";
	ObjectiveGetOutDist = 1500;
	FlagBone = "Dummy01";
	FlagRotation = FRotator(0, 32768, 0);
	GroundSpeed = 900;
	HealthMax = 1000;
	Health = 1000;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1083_MTV.M1083_MTV'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 280;
	//CollisionHeight = 130;
	KParams = KParams0;

}

/*
void AM1083_FMTV::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'FMTV_Cargo_Main');
	L.AddPrecacheMaterial(Texture'FMTV_Tire');
	L.AddPrecacheMaterial(Texture's-lights');
	L.AddPrecacheMaterial(Shader'FMTV_Window');
	L.AddPrecacheMaterial(Texture'skn_veh_hummer1114_lightoff');
	L.AddPrecacheMaterial(Combiner'ds1_FMTV_Cargo_Main');
	L.AddPrecacheMaterial(Combiner'ds1_FMTV_Tire');
	L.AddPrecacheMaterial(Shader'DS1_FMTV_Window');
	L.AddPrecacheMaterial(Texture'humvee_light_broken');
	L.AddPrecacheMaterial(Combiner'ds2_FMTV_Tire');
	L.AddPrecacheMaterial(Combiner'ds2_FMTV_Cargo_Main');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AM1083_FMTV::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1083_FMTV::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'FMTV_Cargo_Main');
	Level.AddPrecacheMaterial(Texture'FMTV_Tire');
	Level.AddPrecacheMaterial(Texture's-lights');
	Level.AddPrecacheMaterial(Shader'FMTV_Window');
	Level.AddPrecacheMaterial(Texture'skn_veh_hummer1114_lightoff');
	Level.AddPrecacheMaterial(Combiner'ds1_FMTV_Cargo_Main');
	Level.AddPrecacheMaterial(Combiner'ds1_FMTV_Tire');
	Level.AddPrecacheMaterial(Shader'DS1_FMTV_Window');
	Level.AddPrecacheMaterial(Texture'humvee_light_broken');
	Level.AddPrecacheMaterial(Combiner'ds2_FMTV_Tire');
	Level.AddPrecacheMaterial(Combiner'ds2_FMTV_Cargo_Main');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}