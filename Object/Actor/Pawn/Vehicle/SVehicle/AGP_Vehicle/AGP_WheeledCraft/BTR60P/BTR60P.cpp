// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/BTR60P/BTR60P.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

ABTR60P::ABTR60P()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 6;
	KParams0->KInertiaTensor[3] = 14;
	KParams0->KInertiaTensor[5] = 18;
	KParams0->KCOMOffset = FVector(-0.3, 0, 0);
	KParams0->KLinearDamping = 0.08;
	KParams0->KAngularDamping = 0.05;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 2400;
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
	UVehicleEntryPoint* RightSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	RightSideEntry->EntryBone = "Entry_Passenger_1_bone";
	RightSideEntry->PositionIndex = { 0,1,2,3,4,5,6 };
	UVehicleDamageZone* Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left->ArmorThreshold = 5;
	Front_Left->MaxHitPoints = 1000;
	//Front_Left->DamageStates(0) = ({ "body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Left->DamageStates(1) = ({ "DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right->ArmorThreshold = 5;
	Front_Right->MaxHitPoints = 1000;
	//Front_Right->DamageStates(0) = ({ "body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Right->DamageStates(1) = ({ "DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Middle_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Right->ArmorThreshold = 5;
	Middle_Right->MaxHitPoints = 1000;
	//Middle_Right->DamageStates(0) = ({ "body_right_2_bone","hatch_right_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Middle_Right->DamageStates(1) = ({ "DS1_body_right_2_bone","DS1_hatch_right_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Middle_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Left->ArmorThreshold = 5;
	Middle_Left->MaxHitPoints = 1000;
	//Middle_Left->DamageStates(0) = ({ "body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Middle_Left->DamageStates(1) = ({ "DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right->ArmorThreshold = 5;
	Rear_Right->MaxHitPoints = 1000;
	//Rear_Right->DamageStates(0) = ({ "body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Right->DamageStates(1) = ({ "DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left->ArmorThreshold = 5;
	Rear_Left->MaxHitPoints = 1000;
	//Rear_Left->DamageStates(0) = ({ "body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Left->DamageStates(1) = ({ "DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 2;
	Wheel_Left_1->DamageModifier = 10;
	Wheel_Left_1->MaxHitPoints = 1000;
	Wheel_Left_1->bWheelZone = true;
	Wheel_Left_1->WheelNum = 4;
	//Wheel_Left_1->DamageStates(0) = ({ "wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_1->DamageStates(1) = ({ "ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_1->DamageStates(2) = ({ "ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 2;
	Wheel_Right_1->DamageModifier = 10;
	Wheel_Right_1->MaxHitPoints = 1000;
	Wheel_Right_1->bWheelZone = true;
	//Wheel_Right_1->DamageStates(0) = ({ "wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_1->DamageStates(1) = ({ "ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_1->DamageStates(2) = ({ "ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 2;
	Wheel_Left_2->DamageModifier = 10;
	Wheel_Left_2->MaxHitPoints = 1000;
	Wheel_Left_2->bWheelZone = true;
	Wheel_Left_2->WheelNum = 5;
	//Wheel_Left_2->DamageStates(0) = ({ "wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_2->DamageStates(1) = ({ "ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_2->DamageStates(2) = ({ "ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_2->bNoPassDamageToVehicle = true;
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
	UVehicleDamageZone* Wheel_Left_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_3->ArmorThreshold = 2;
	Wheel_Left_3->DamageModifier = 10;
	Wheel_Left_3->MaxHitPoints = 1000;
	Wheel_Left_3->bWheelZone = true;
	Wheel_Left_3->WheelNum = 6;
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
	UVehicleDamageZone* Wheel_Left_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_4->ArmorThreshold = 2;
	Wheel_Left_4->DamageModifier = 10;
	Wheel_Left_4->MaxHitPoints = 1000;
	Wheel_Left_4->bWheelZone = true;
	Wheel_Left_4->WheelNum = 7;
	//Wheel_Left_4->DamageStates(0) = ({ "Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_4->DamageStates(1) = ({ "DS1_Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_4->DamageStates(2) = ({ "DS2_Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_4->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_4->ArmorThreshold = 2;
	Wheel_Right_4->DamageModifier = 10;
	Wheel_Right_4->MaxHitPoints = 1000;
	Wheel_Right_4->bWheelZone = true;
	Wheel_Right_4->WheelNum = 3;
	//Wheel_Right_4->DamageStates(0) = ({ "Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_4->DamageStates(1) = ({ "DS1_Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_4->DamageStates(2) = ({ "DS2_Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_4->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 5;
	Turret->DamageModifier = 0.8;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0) = ({ "Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Turret->DamageStates(1) = ({ "DS1_yaw_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	Turret->bControlsExternalMesh = true;
	Turret->MeshOwnerType = EMeshOwnerType::MO_VehiclePositionWeapon;
	USVehicleWheel* RWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel1->bPoweredWheel = true;
	RWheel1->SteerType = EVehicleSteerType::VST_Steered;
	RWheel1->BoneName = "wheel_right_1_bone";
	RWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel1->WheelBoneOffset = FVector(-10, 0, 0);
	RWheel1->WheelRadius = 25;
	USVehicleWheel* RWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel2->bPoweredWheel = true;
	RWheel2->SteerType = EVehicleSteerType::VST_Steered;
	RWheel2->BoneName = "wheel_right_2_bone";
	RWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel2->WheelBoneOffset = FVector(10, 0, 0);
	RWheel2->WheelRadius = 25;
	USVehicleWheel* RWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel3->bPoweredWheel = true;
	RWheel3->BoneName = "Wheel_Right_3_Bone";
	RWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel3->WheelBoneOffset = FVector(-10, 0, 0);
	RWheel3->WheelRadius = 25;
	USVehicleWheel* RWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel4->bPoweredWheel = true;
	RWheel4->BoneName = "Wheel_Right_4_Bone";
	RWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel4->WheelBoneOffset = FVector(10, 0, 0);
	RWheel4->WheelRadius = 25;
	USVehicleWheel* LWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel1->bPoweredWheel = true;
	LWheel1->SteerType = EVehicleSteerType::VST_Steered;
	LWheel1->BoneName = "wheel_left_1_bone";
	LWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel1->WheelBoneOffset = FVector(-10, 0, 0);
	LWheel1->WheelRadius = 25;
	USVehicleWheel* LWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel2->bPoweredWheel = true;
	LWheel2->SteerType = EVehicleSteerType::VST_Steered;
	LWheel2->BoneName = "wheel_left_2_bone";
	LWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel2->WheelBoneOffset = FVector(10, 0, 0);
	LWheel2->WheelRadius = 25;
	USVehicleWheel* LWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel3->bPoweredWheel = true;
	LWheel3->BoneName = "Wheel_Left_3_Bone";
	LWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel3->WheelBoneOffset = FVector(-10, 0, 0);
	LWheel3->WheelRadius = 25;
	USVehicleWheel* LWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel4->bPoweredWheel = true;
	LWheel4->BoneName = "Wheel_Left_4_Bone";
	LWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel4->WheelBoneOffset = FVector(10, 0, 0);
	LWheel4->WheelRadius = 25;
	WheelSoftness = 0.02;
	WheelPenScale = 2.1;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.121;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 1;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 25;
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 10;
	FTScale = 0.04;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.38,0.32,0.53,0.87,1.35 };
	TransRatio = 0.21;
	ChangeUpPoint = 5000;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-05;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 40;
	SteerSpeed = 30;
	TurnDamping = 100;
	StopThreshold = 80;
	HandbrakeThresh = 200;
	EngineInertia = 0.03;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//PositionTypes(0) = ({ class'AGP_Vehicles.BTR60_Gunner',"Weapon_1_Bone","seat_driver_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) })
	//PositionTypes(1) = ({ class'AGP_Vehicles.PassengerPosition',"None","seat_driver_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) })
	//PositionTypes(2) = ({ class'AGP_Vehicles.PassengerPosition',"None","seat_driver_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) })
	//PositionTypes(3) = ({ class'AGP_Vehicles.PassengerPosition',"None","seat_driver_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) })
	//PositionTypes(4) = ({ class'AGP_Vehicles.PassengerPosition',"None","seat_driver_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) })
	//PositionTypes(5) = ({ class'AGP_Vehicles.PassengerPosition',"None","seat_driver_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) })
	//PositionTypes(6) = ({ class'AGP_Vehicles.PassengerPosition',"None","seat_driver_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) });
	EntryPoints = { LeftSideEntry,RightSideEntry };
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/btr60/BTR60_Static_damage.BTR60_Static_damage'"), NULL, LOAD_None, NULL);
	//DestroyedModelClass = class'AGP_Vehicles.BTR60_DestroyedBody';
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({100, 150 });
	DefaultDamageZones = { Front_Left,Front_Right,Middle_Right,Middle_Left,Rear_Right,Rear_Left,Wheel_Left_1,Wheel_Right_1,Wheel_Left_2,Wheel_Right_2,Wheel_Left_3,Wheel_Right_3,Wheel_Left_4,Wheel_Right_4,Turret };
	Health_Front_Left = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	//NewDamageInfo(0) = ({ Class'AGP_Inventory.RocketRPGDamage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',0.34,0.34,0.34,0.51,0,0,0,0,0,0,0,0.5 })
	//NewDamageInfo(1) = ({ Class'AGP_Inventory.RocketAT4Damage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',0.51,0.51,0.51,0.51,0,0,0,0,0,0,0,0.5 })
	//NewDamageInfo(2) = ({ Class'AGP_Gameplay.RocketJavelinDamage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',1,1,1,1,0,0,0,0,0,0,0,0.5 })
	//NewDamageInfo(3) = ({ Class'AGP_Gameplay.JavelinImpactDamage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',1,1,1,1,0,0,0,0,0,0,0,1 });
	TestDamageZones = {
		FTestDamageZoneInfo({ "Front_Left",0,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Front_Right",1,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Middle_Right",2,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Middle_Left",3,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Rear_Right",4,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Rear_Left",5,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_1",6,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_1",7,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_2",8,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_2",9,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_3",10,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_3",11,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_4",12,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_4",13,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Turret",14,5,1000,0,0,0.8,0,0 })
	};
	ParticleInfo = {
		FIniParticleInfo({ "Front_Left","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Front_Right","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Middle_Right","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Middle_Left","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Rear_Right","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Rear_Left","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Wheel_Left_1","None","None" }),
		FIniParticleInfo({ "Wheel_Right_1","None","None" }),
		FIniParticleInfo({ "Wheel_Left_2","None","None" }),
		FIniParticleInfo({ "Wheel_Right_2","None","None" }),
		FIniParticleInfo({ "Wheel_Left_3","None","None" }),
		FIniParticleInfo({ "Wheel_Right_3","None","None" }),
		FIniParticleInfo({ "Wheel_Left_4","None","None" }),
		FIniParticleInfo({ "Wheel_Right_4","None","None" }),
		FIniParticleInfo({ "Turret","AGP_Effects.VehicleFireHeavySmokeLarge","" })
	};
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	Wheels = { RWheel1,RWheel2,RWheel3,RWheel4,LWheel1,LWheel2,LWheel3,LWheel4 };
	VehicleMass = 8;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawMeshInFP = true;
	Team = 255;
	DriverBone = "seat_driver_bone";
	DriveAnim = "CrhNo";
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100),FVector(0, -165, -100),FVector(0, 165, -100) };
	FPCamPos = FVector(20, -35, 102);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a BTR-60";
	VehicleNameString = "BTR-60";
	ObjectiveGetOutDist = 1500;
	GroundSpeed = 350;
	HealthMax = 1000;
	Health = 1000;
	//AmbientSoundScaling = 2;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/btr60.btr60'"), NULL, LOAD_None, NULL);
	//SoundVolume = 180;
	//CollisionRadius = 175;
	ValidJavelinTarget = 2;
	KParams = KParams0;
}


/*
void ABTR60P::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'BTR-60_Turrett');
	L.AddPrecacheMaterial(Texture'BTR-60_Turrett_Darken');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/
void ABTR60P::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}
void ABTR60P::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'BTR-60_Turrett');
	Level.AddPrecacheMaterial(Texture'BTR-60_Turrett_Darken');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}