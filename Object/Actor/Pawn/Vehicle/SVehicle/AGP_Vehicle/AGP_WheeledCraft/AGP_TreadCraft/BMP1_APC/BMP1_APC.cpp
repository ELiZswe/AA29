// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/BMP1_APC/BMP1_APC.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BMP1_Gunner/BMP1_Gunner.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/BMP1_DestroyedBody/BMP1_DestroyedBody.h"
#include "AA29/Object/DamageType/CROWS_Mk19Damage/CROWS_Mk19Damage.h"
#include "AA29/Object/Actor/Emitter/fx_exp_smallfire/fx_exp_smallfire.h"
#include "AA29/Object/DamageType/AGP_DamageType/RocketImpact/JavelinImpactDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/RocketImpact/Mortar_120mm_ImpactDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/DamageType/RocketAT4Damage/RocketAT4Damage.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/RocketExplosionDamage/RocketJavelinDamage/RocketJavelinDamage.h"
#include "AA29/Object/DamageType/RocketRPGDamage/RocketRPGDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/GrenadeImpact/SpecialGrenadeImpact.h"
#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleFireHeavySmokeLarge/VehicleFireHeavySmokeLarge.h"
#include "AA29/Object/VehiclePhysicalEffect/VPE_TireFlat/VPE_TireFlat.h"

ABMP1_APC::ABMP1_APC()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 1;
	KParams0->KInertiaTensor[3] = 3;
	KParams0->KInertiaTensor[5] = 3;
	KParams0->KCOMOffset = FVector(0, 0, 0.2);
	KParams0->KLinearDamping = 0.05;
	KParams0->KAngularDamping = 0.04;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 1600;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 1;
	UVehicleEntryPoint* LeftSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	LeftSideEntry->bDriverEntry = true;
	LeftSideEntry->EntryBone = "Entry_Driver_bone";
	UVehicleEntryPoint* RearEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	RearEntry->EntryBone = "Entry_Passenger_1_bone";
	RearEntry->PositionIndex = { 1,2,3,4,5,6,7 };
	UVehicleEntryPoint* GunnerEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	GunnerEntry->EntryBone = "entry_gunner_1_bone";
	GunnerEntry->PositionIndex = { 0 };
	UVehicleDamageZone* Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left->ArmorThreshold = 6;
	Front_Left->MaxHitPoints = 1000;
	//Front_Left->DamageStates(0) = ({ "body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Front_Left->DamageStates(1) = ({ "DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,AVehicleFireHeavySmokeLarge::StaticClass(),nullptr,nullptr });
	UVehicleDamageZone* Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right->ArmorThreshold = 6;
	Front_Right->MaxHitPoints = 1000;
	//Front_Right->DamageStates(0) = ({ "body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Front_Right->DamageStates(1) = ({ "DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,AVehicleFireHeavySmokeLarge::StaticClass(),nullptr,nullptr });
	UVehicleDamageZone* Side_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Right->ArmorThreshold = 6;
	Side_Right->MaxHitPoints = 1000;
	//Side_Right->DamageStates(0) = ({ "body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Side_Right->DamageStates(1) = ({ "DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,AVehicleFireHeavySmokeLarge::StaticClass(),nullptr,nullptr });
	UVehicleDamageZone* Side_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Left->ArmorThreshold = 6;
	Side_Left->MaxHitPoints = 1000;
	//Side_Left->DamageStates(0) = ({ "body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Side_Left->DamageStates(1) = ({ "DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,AVehicleFireHeavySmokeLarge::StaticClass(),nullptr,nullptr });
	UVehicleDamageZone* Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right->ArmorThreshold = 6;
	Rear_Right->MaxHitPoints = 1000;
	//Rear_Right->DamageStates(0) = ({ "body_right_3_bone","door_right_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Rear_Right->DamageStates(1) = ({ "DS1_body_right_3_bone","DS1_door_right_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,AVehicleFireHeavySmokeLarge::StaticClass(),nullptr,nullptr });
	UVehicleDamageZone* Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left->ArmorThreshold = 6;
	Rear_Left->MaxHitPoints = 1000;
	//Rear_Left->DamageStates(0) = ({ "body_left_3_bone","door_left_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Rear_Left->DamageStates(1) = ({ "DS1_body_left_3_bone","DS1_door_left_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,AVehicleFireHeavySmokeLarge::StaticClass(),nullptr,nullptr });
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 5;
	Wheel_Left_1->MaxHitPoints = 1000;
	//Wheel_Left_1->DamageStates(0) = ({ "wheel_left_1_bone","wheel_left_2_bone","Wheel_Left_3_Bone","Wheel_Left_4_Bone","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Left_1->DamageStates(1) = ({ "ds1_wheel_left_1_bone","ds1_wheel_left_2_bone","DS1_Wheel_Left_3_Bone","DS1_Wheel_Left_4_Bone","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,UVPE_TireFlat::StaticClass() });
	Wheel_Left_1->bAttachedToLeftTread = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 5;
	Wheel_Right_1->MaxHitPoints = 1000;
	//Wheel_Right_1->DamageStates(0) = ({ "wheel_right_1_bone","wheel_right_2_bone","Wheel_Right_3_Bone","Wheel_Right_4_Bone","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Right_1->DamageStates(1) = ({ "ds1_wheel_right_1_bone","ds1_wheel_right_2_bone","DS1_Wheel_Right_3_Bone","DS1_Wheel_Right_4_Bone","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,UVPE_TireFlat::StaticClass() });
	Wheel_Right_1->bAttachedToRightTread = true;
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 5;
	Wheel_Right_2->MaxHitPoints = 1000;
	//Wheel_Right_2->DamageStates(0) = ({ "Wheel_Right_5_Bone","Wheel_Right_6_Bone","Wheel_Right_7_Bone","Wheel_Right_8_Bone","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Right_2->DamageStates(1) = ({ "DS1_Wheel_Right_5_Bone","DS1_Wheel_Right_6_Bone","DS1_Wheel_Right_7_Bone","DS1_Wheel_Right_8_Bone","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,UVPE_TireFlat::StaticClass() });
	Wheel_Right_2->bAttachedToRightTread = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 5;
	Wheel_Left_2->MaxHitPoints = 1000;
	//Wheel_Left_2->DamageStates(0) = ({ "Wheel_Left_5_Bone","Wheel_Left_6_Bone","Wheel_Left_7_Bone","Wheel_Left_8_Bone","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Wheel_Left_2->DamageStates(1) = ({ "DS1_Wheel_Left_5_Bone","DS1_Wheel_Left_6_Bone","DS1_Wheel_Left_7_Bone","DS1_Wheel_Left_8_Bone","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,UVPE_TireFlat::StaticClass() });
	Wheel_Left_2->bAttachedToLeftTread = true;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 5;
	Turret->DamageModifier = 0.8;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0) = ({ "Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr });
	//Turret->DamageStates(1) = ({ "DS1_yaw_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Afx_exp_smallfire::StaticClass(),nullptr,nullptr });
	Turret->bControlsExternalMesh = true;
	Turret->MeshOwnerType = EMeshOwnerType::MO_VehiclePositionWeapon;
	USVehicleWheel* RWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel1->bPoweredWheel = true;
	RWheel1->SteerType = EVehicleSteerType::VST_Steered;
	RWheel1->BoneName = "Physics_Right_1_Bone";
	RWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel1->WheelRadius = 30;
	USVehicleWheel* RWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel2->bPoweredWheel = true;
	RWheel2->SteerType = EVehicleSteerType::VST_Steered;
	RWheel2->BoneName = "Physics_Right_2_Bone";
	RWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel2->WheelRadius = 30;
	USVehicleWheel* RWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel3->bPoweredWheel = true;
	RWheel3->SteerType = EVehicleSteerType::VST_Inverted;
	RWheel3->BoneName = "Physics_Right_3_Bone";
	RWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel3->WheelRadius = 30;
	USVehicleWheel* RWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel4->bPoweredWheel = true;
	RWheel4->SteerType = EVehicleSteerType::VST_Inverted;
	RWheel4->BoneName = "Physics_Right_4_Bone";
	RWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel4->WheelRadius = 30;
	USVehicleWheel* LWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel1->bPoweredWheel = true;
	LWheel1->SteerType = EVehicleSteerType::VST_Steered;
	LWheel1->BoneName = "Physics_Left_1_Bone";
	LWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel1->WheelRadius = 30;
	USVehicleWheel* LWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel2->bPoweredWheel = true;
	LWheel2->SteerType = EVehicleSteerType::VST_Steered;
	LWheel2->BoneName = "Physics_Left_2_Bone";
	LWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel2->WheelRadius = 30;
	USVehicleWheel* LWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel3->bPoweredWheel = true;
	LWheel3->SteerType = EVehicleSteerType::VST_Inverted;
	LWheel3->BoneName = "Physics_Left_3_Bone";
	LWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel3->WheelRadius = 30;
	USVehicleWheel* LWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel4->bPoweredWheel = true;
	LWheel4->SteerType = EVehicleSteerType::VST_Inverted;
	LWheel4->BoneName = "Physics_Left_4_Bone";
	LWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel4->WheelRadius = 30;
	sndTreadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/TankSounds/Tread_Loop2_Cue.Tread_Loop2_Cue'"), NULL, LOAD_None, NULL);
	//ZeroSizeSize;
	TreadVelocityScale = 450;
	WheelVelocityScale = 85000;
	LeftTreadWheels = {
		"wheel_left_1_bone"
		"wheel_left_2_bone"
		"Wheel_Left_3_Bone"
		"Wheel_Left_4_Bone"
		"Wheel_Left_5_Bone"
		"Wheel_Left_6_Bone"
		"Wheel_Left_7_Bone"
		"Wheel_Left_8_Bone"
		"ds1_wheel_left_1_bone"
		"ds1_wheel_left_2_bone"
		"DS1_Wheel_Left_3_Bone"
		"DS1_Wheel_Left_4_Bone"
		"DS1_Wheel_Left_5_Bone"
		"DS1_Wheel_Left_6_Bone"
		"DS1_Wheel_Left_7_Bone"
		"DS1_Wheel_Left_8_Bone"
	};
	RightTreadWheels = {
		"wheel_right_1_bone",
		"wheel_right_2_bone",
		"Wheel_Right_3_Bone",
		"Wheel_Right_4_Bone",
		"Wheel_Right_5_Bone",
		"Wheel_Right_6_Bone",
		"Wheel_Right_7_Bone",
		"Wheel_Right_8_Bone",
		"ds1_wheel_right_1_bone",
		"ds1_wheel_right_2_bone",
		"DS1_Wheel_Right_3_Bone",
		"DS1_Wheel_Right_4_Bone",
		"DS1_Wheel_Right_5_Bone",
		"DS1_Wheel_Right_6_Bone",
		"DS1_Wheel_Right_7_Bone",
		"DS1_Wheel_Right_8_Bone"
	};
	TreadPannerRotation = FRotator(0, -16384, 0);
	LeftTreadSkinNum = 2;
	RightTreadSkinNum = 3;
	LeftTreadBone = "Tread_Left_1_bone";
	LeftTreadDamageBone = "DS1_Tread_Left_1_bone";
	RightTreadBone = "Tread_Right_1_bone";
	RightTreadDamageBone = "DS1_Tread_Right_1_bone";
	WheelSoftness = 0.02;
	WheelPenScale = 1;
	WheelPenOffset = 0.001;
	WheelRestitution = 0.5;
	WheelInertia = 0.1;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 0.9;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 45;
	WheelSuspensionOffset = -12;
	WheelSuspensionMaxRenderTravel = 45;
	FTScale = 0.03;
	ChassisTorqueScale = 0.01;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.42,0.28,0.62,1.25 };
	NumForwardGears = 3;
	TransRatio = 0.03;
	ChangeUpPoint = 2000;
	ChangeDownPoint = 1000;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-05;
	EngineBrakeRPMScale = 0.01;
	MaxBrakeTorque = 40;
	SteerSpeed = 150;
	StopThreshold = 50;
	HandbrakeThresh = 200;
	PositionTypes = { FVehiclePositionStruct({ABMP1_Gunner::StaticClass(),"Weapon_1_Bone","None",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0)}) };
	EntryPoints = { LeftSideEntry,RearEntry,GunnerEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/BMP1/s_vehi_bmp1_treads_2_Cue.s_vehi_bmp1_treads_2_Cue'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/stryker/STRYKER_Start_3_Cue.STRYKER_Start_3_Cue'"), NULL, LOAD_None, NULL);
	StartUpForce = "TankStartUp";
	ShutDownForce = "TankShutDown";
	ViewShakeRadius = 600;
	ViewShakeOffsetMag = FVector(0.5, 0, 2);
	ViewShakeOffsetFreq = 7;
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/BMP-1/BMP-1_static.BMP-1_static'"), NULL, LOAD_None, NULL);
	//DestroyedModelClass = ABMP1_DestroyedBody::StaticClass();
	DisintegrationHealth = -125;
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 300 });
	DefaultDamageZones = { Front_Left,Front_Right,Side_Right,Side_Left,Rear_Right,Rear_Left,Wheel_Left_1,Wheel_Right_1,Wheel_Right_2,Wheel_Left_2,Turret };
	Health_Front_Left = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	bUseNewTreadDamage = true;
	/*
	NewDamageInfo(0) = ({ ARocketRPGDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.3,0.3,0.3,0.45,0.4,0.4,0.4,0.4,0.4,0,0,0.5 })
		NewDamageInfo(1) = ({ ARocketAT4Damage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.5,0.5,0.7,0.7,0.3,0.3,0.3,0.3,0.3,0,0,1 })
		NewDamageInfo(2) = ({ ARocketJavelinDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.65,0.65,0.65,0.65,0.5,0.5,0.65,0.5,0.5,0,0,0.5 })
		NewDamageInfo(3) = ({ AJavelinImpactDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),1,1,1,1,0.5,0.5,0.5,0.5,0.5,0,0,1 })
		NewDamageInfo(4) = ({ ACROWS_Mk19Damage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.6,0.4,0.4,0.4,0.4,0.4,0.4,0.4,0.4,0,0,1 })
		NewDamageInfo(5) = ({ AProjectileDamageLargeArms::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),1.5,1.5,1.5,1.5,0.75,1,2,2,2,0,0,2 })
		NewDamageInfo(6) = ({ ASpecialGrenadeImpact::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.65,0.45,0.45,0.45,0.45,0.45,0.5,0.5,0.5,0,0,1 })
		NewDamageInfo(7) = ({ AMortar_120mm_ImpactDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.65,0.45,0.45,0.45,0.45,0.45,0.5,0.5,0.5,0,0,1 });
	*/
	TestDamageZones = {
		FTestDamageZoneInfo({ "Front_Left",0,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Front_Right",1,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Right",2,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Left",3,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Rear_Right",4,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Rear_Left",5,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_1",6,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_1",7,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_2",8,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_2",9,5,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Turret",10,5,1000,0,0,0.8,0,0 })
	};
	ParticleInfo = {
		FIniParticleInfo({ "Front_Left","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Front_Right","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Side_Right","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Side_Left","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Rear_Right","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Rear_Left","AGP_Effects.VehicleFireHeavySmokeLarge","" }),
		FIniParticleInfo({ "Wheel_Left_1","None","" }),
		FIniParticleInfo({ "Wheel_Right_1","None","" }),
		FIniParticleInfo({ "Wheel_Right_2","None","" }),
		FIniParticleInfo({ "Wheel_Left_2","None","" }),
		FIniParticleInfo({ "Turret","AGP_Effects.fx_exp_smallfire","" })
	};
	bEnableProximityViewShake = true;
	bDriverCannotLeaveVehicle = true;
	bBulletImpactSparks = true;
	SmokeGeneratorAttachmentBone = "Exhaust_1_Bone";
	TreadBones = {
		"Tread_Right_1_bone",
		"Tread_Left_1_bone",
		"Tread_Right_3_Bone",
		"wheel_left_1_bone",
		"wheel_left_2_bone",
		"Wheel_Left_3_Bone",
		"Wheel_Left_4_Bone",
		"Wheel_Left_5_Bone",
		"Wheel_Left_6_Bone",
		"Wheel_Left_7_Bone",
		"Wheel_Left_8_Bone",
		"wheel_right_1_bone",
		"wheel_right_2_bone",
		"Wheel_Right_3_Bone",
		"Wheel_Right_4_Bone",
		"Wheel_Right_5_Bone",
		"Wheel_Right_6_Bone",
		"Wheel_Right_7_Bone",
		"Wheel_Right_8_Bone",
		"Physics_Left_1_Bone",
		"Physics_Left_2_Bone",
		"Physics_Left_3_Bone",
		"Physics_Left_4_Bone",
		"Physics_Right_1_Bone",
		"Physics_Right_2_Bone",
		"Physics_Right_3_Bone",
		"Physics_Right_4_Bone"
	};
	UndercarriageBones = { "body_root","seat_driver_bone" };
	bUseDotTestForAim = true;
	Wheels = { RWheel1,RWheel2,RWheel3,RWheel4,LWheel1,LWheel2,LWheel3,LWheel4 };
	VehicleMass = 8;
	bTurnInPlace = true;
	TurnInPlaceThreshold = 0.3;
	bNPCDriverCanUseSmoke = true;
	bDrawMeshInFP = true;
	bPCRelativeFPRotation = false;
	bFPNoZFromCameraPitch = true;
	DriverBone = "seat_driver_bone";
	ExitPositions = { FVector(0, -200, 100),FVector(0, 200, 100) };
	FPCamPos = FVector(-70, 0, 130);
	FPCamViewOffset = FVector(90, 0, 0);
	TPCamLookat = FVector(-50, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 250);
	bPredict_Collision_MoveToward = true;
	Predict_Collision_Distance = 1300;
	MomentumMult = 0.3;
	DriverDamageMult = 0;
	VehiclePositionString = "in a BMP-1";
	VehicleNameString = "BMP-1";
	MaxDesireability = 0.8;
	bAIDriversOnly = true;
	//bCanStrafe = true;
	GroundSpeed = 520;
	HealthMax = 1000;
	Health = 1000;
	//AmbientSoundScaling = 2;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/BMP1.BMP1'"), NULL, LOAD_None, NULL);
	/*
	Skins = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/BMP-1_Main_Mat.BMP-1_Main_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/BMP-1_Tread_Mat.BMP-1_Tread_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/BMP-1_Tread_Mat.BMP-1_Tread_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/BMP-1_Tread_Mat.BMP-1_Tread_Mat'"), NULL, LOAD_None, NULL)
	};
	*/
	//SoundRadius = 400;
	//CollisionRadius = 260;
	//CollisionHeight = 60;
	ValidJavelinTarget = 2;
	KParams = KParams0;
}

void ABMP1_APC::StaticPrecache(ALevelInfo* L)
{
	Super::StaticPrecache(L);
	L->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/BMP-1_Main_Mat.BMP-1_Main_Mat'"), NULL, LOAD_None, NULL));
	L->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/BMP-1_Tread_Mat.BMP-1_Tread_Mat'"), NULL, LOAD_None, NULL));
	L->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/DS1_Darkener_Mat.DS1_Darkener_Mat'"), NULL, LOAD_None, NULL));
	L->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/BMP-1/DS2_BMP-1_Main_Mat.DS2_BMP-1_Main_Mat'"), NULL, LOAD_None, NULL));
	L->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL));
	L->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL));
	L->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/FX2_misc_explosionA_Mat.FX2_misc_explosionA_Mat'"), NULL, LOAD_None, NULL));
}

AVehicle* ABMP1_APC::FindEntryVehicle(APawn* p)
{
	return nullptr;
}

bool ABMP1_APC::TryToDrive(APawn* p)
{
	/*
	if (Cast<AHumanController>(p->Controller) != nullptr)
	{
		return false;
	}
	else
	{
		return Super::TryToDrive(p);
	}
	*/
	return false;    //FAKE   /ELiZ
}

void ABMP1_APC::InitializeDamageZones()
{
	/*
	InitializeDamageZones();
	SetBoneScale(GetNextScalerSlot(), 0, 'ds1_light_1_bone');
	SetBoneScale(GetNextScalerSlot(), 0, 'ds1_hatch_front_1_bone');
	*/
}

void ABMP1_APC::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ABMP1_APC::UpdatePrecacheMaterials()
{
	/*
	LeveL->AddPrecacheMaterial(Texture'BMP-1_Main');
	LeveL->AddPrecacheMaterial(Texture'BMP-1_Tread');
	LeveL->AddPrecacheMaterial(Texture'DS1_Darkener');
	LeveL->AddPrecacheMaterial(Texture'DS2_BMP-1_Main');
	LeveL->AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	LeveL->AddPrecacheMaterial(Texture'fx_part_explosion01');
	LeveL->AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}

void ABMP1_APC::AttachDriver(APawn* p)
{
	/*
	p.bHidden = true;
	AttachDriver(p);
	return;
	*/
}

void ABMP1_APC::IdleSoundTimer()
{
	//AmbientSound = IdleSound;
}

void ABMP1_APC::KDriverEnter(APawn* p)
{
	float StartupDelay = 0;
	Super::KDriverEnter(p);
	/*
	if (IdleSound != nullptr)
	{
		if (StartUpSound != nullptr)
		{
			StartupDelay = Abs(GetSoundDuration(StartUpSound) - 0.2);
			SetCustomTimer(StartupDelay, false, 'IdleSoundTimer');
		}
	}
	if (StartUpSound != nullptr)
	{
		PlaySound(StartUpSound, 0, 1);
	}
	SetTimer(0.5, true);
	*/
}

bool ABMP1_APC::KDriverLeave(bool bForceLeave)
{
	//SetTimer(0, false);
	return Super::KDriverLeave(bForceLeave);
}

void ABMP1_APC::Timer()
{
	Super::Timer();
	/*
	if (Driver == nullptr || Health_Front_Right <= 0 || Health_Front_Left <= 0 || Health_Back_Left <= 0 || Health_Back_Right <= 0)
	{
		return;
	}
	if (VSize(Velocity) >= 3)
	{
		if (Driver.AmbientSound != sndTreadSound)
		{
			Driver.AmbientSound = sndTreadSound;
			Driver.SoundVolume = 255;
			Driver.bFullVolume = true;
			Driver.SoundRadius = 500;
			Driver.AmbientSoundScaling = 10;
		}
	}
	else
	{
		if (Driver.AmbientSound != nullptr)
		{
			Driver.AmbientSoundScaling = 0;
			Driver.SoundVolume = 0;
			Driver.AmbientSound = nullptr;
		}
	}
	*/
}

/*
void ABMP1_APC::TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  InDamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (InDamageType == ASpecialGrenadeImpact::StaticClass())
	{
		Damage = 125;
	}
	TakeDamage(Damage, instigatedBy, HitLocation, Momentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
}
*/
