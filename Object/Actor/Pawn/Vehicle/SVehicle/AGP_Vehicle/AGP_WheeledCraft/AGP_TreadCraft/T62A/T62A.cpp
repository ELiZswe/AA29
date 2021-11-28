// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/T62A/T62A.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

AT62A::AT62A()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 1;
	KParams0->KInertiaTensor[3] = 3;
	KParams0->KInertiaTensor[5] = 3;
	KParams0->KCOMOffset = FVector(-0.25, 0, -1.35);
	KParams0->KLinearDamping = 0.05;
	KParams0->KAngularDamping = 0.05;
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
	UVehicleEntryPoint* RightSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	RightSideEntry->EntryBone = "Entry_Passenger_1_bone";
	RightSideEntry->PositionIndex = { 0, 1, 2 };
	UVehicleDamageZone* Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left->ArmorThreshold = 7;
	Front_Left->MaxHitPoints = 1000;
	//Front_Left->DamageStates(0) = ({ "body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Left->DamageStates(1) = ({ "DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right->ArmorThreshold = 7;
	Front_Right->MaxHitPoints = 1000;
	//Front_Right->DamageStates(0) = ({ "body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Right->DamageStates(1) = ({ "DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Side_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Right->ArmorThreshold = 7;
	Side_Right->MaxHitPoints = 1000;
	//Side_Right->DamageStates(0) = ({ "body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Right->DamageStates(1) = ({ "DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Side_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Left->ArmorThreshold = 7;
	Side_Left->MaxHitPoints = 1000;
	//Side_Left->DamageStates(0) = ({ "body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Left->DamageStates(1) = ({ "DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right->ArmorThreshold = 7;
	Rear_Right->MaxHitPoints = 1000;
	//Rear_Right->DamageStates(0) = ({ "body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Right->DamageStates(1) = ({ "DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left->ArmorThreshold = 7;
	Rear_Left->MaxHitPoints = 1000;
	//Rear_Left->DamageStates(0) = ({ "body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Left->DamageStates(1) = ({ "DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 6;
	Wheel_Left_1->MaxHitPoints = 1000;
	//Wheel_Left_1->DamageStates(0) = ({ "wheel_left_1_bone","wheel_left_2_bone","Wheel_Left_3_Bone","Wheel_Left_4_Bone","Tread_Left_1_bone","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_1->DamageStates(1) = ({ "ds1_wheel_left_1_bone","ds1_wheel_left_2_bone","DS1_Wheel_Left_3_Bone","DS1_Wheel_Left_4_Bone","DS1_Tread_Left_1_bone","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	Wheel_Left_1->bAttachedToLeftTread = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 6;
	Wheel_Right_1->MaxHitPoints = 1000;
	//Wheel_Right_1->DamageStates(0) = ({ "wheel_right_1_bone","wheel_right_2_bone","Wheel_Right_3_Bone","Wheel_Right_4_Bone","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_1->DamageStates(1) = ({ "ds1_wheel_right_1_bone","ds1_wheel_right_2_bone","DS1_Wheel_Right_3_Bone","DS1_Wheel_Right_4_Bone","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	Wheel_Right_1->bAttachedToRightTread = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 6;
	Wheel_Left_2->MaxHitPoints = 1000;
	//Wheel_Left_2->DamageStates(0) = ({ "Wheel_Left_5_Bone","Wheel_Left_6_Bone","Wheel_Left_7_Bone","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_2->DamageStates(1) = ({ "DS1_Wheel_Left_5_Bone","DS1_Wheel_Left_6_Bone","DS1_Wheel_Left_7_Bone","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	Wheel_Left_2->bAttachedToLeftTread = true;
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 6;
	Wheel_Right_2->MaxHitPoints = 1000;
	//Wheel_Right_2->DamageStates(0) = ({ "Wheel_Right_5_Bone","Wheel_Right_6_Bone","Wheel_Right_7_Bone","Tread_Right_1_bone","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_2->DamageStates(1) = ({ "DS1_Wheel_Right_5_Bone","DS1_Wheel_Right_6_Bone","DS1_Wheel_Right_7_Bone","DS1_Tread_Right_1_bone","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	Wheel_Right_2->bAttachedToRightTread = true;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 7;
	Turret->DamageModifier = 0.8;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0) = ({ "Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Turret->DamageStates(1) = ({ "DS1_yaw_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',class'None',class'None' });
	Turret->bControlsExternalMesh = true;
	Turret->MeshOwnerType = EMeshOwnerType::MO_VehiclePositionWeapon;
	USVehicleWheel* RWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel1->bPoweredWheel = true;
	RWheel1->SteerType = EVehicleSteerType::VST_Steered;
	RWheel1->BoneName = "Physics_Right_1_Bone";
	RWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel1->WheelRadius = 33;
	USVehicleWheel* RWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel2->bPoweredWheel = true;
	RWheel2->SteerType = EVehicleSteerType::VST_Steered;
	RWheel2->BoneName = "Physics_Right_1_Bone1";
	RWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel2->WheelRadius = 33;
	USVehicleWheel* RWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel3->bPoweredWheel = true;
	RWheel3->SteerType = EVehicleSteerType::VST_Inverted;
	RWheel3->BoneName = "Physics_Right_1_Bone2";
	RWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel3->WheelRadius = 33;
	USVehicleWheel* RWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel4->bPoweredWheel = true;
	RWheel4->SteerType = EVehicleSteerType::VST_Inverted;
	RWheel4->BoneName = "Physics_Right_1_Bone3";
	RWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel4->WheelRadius = 33;
	USVehicleWheel* LWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel1->bPoweredWheel = true;
	LWheel1->SteerType = EVehicleSteerType::VST_Steered;
	LWheel1->BoneName = "Physics_Left_1_Bone";
	LWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel1->WheelRadius = 33;
	USVehicleWheel* LWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel2->bPoweredWheel = true;
	LWheel2->SteerType = EVehicleSteerType::VST_Steered;
	LWheel2->BoneName = "Physics_Left_2_Bone";
	LWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel2->WheelRadius = 33;
	USVehicleWheel* LWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel3->bPoweredWheel = true;
	LWheel3->SteerType = EVehicleSteerType::VST_Inverted;
	LWheel3->BoneName = "Physics_Left_3_Bone";
	LWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel3->WheelRadius = 33;
	USVehicleWheel* LWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel4->bPoweredWheel = true;
	LWheel4->SteerType = EVehicleSteerType::VST_Inverted;
	LWheel4->BoneName = "Physics_Left_4_Bone";
	LWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel4->WheelRadius = 33;
	sndTreadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/TankSounds/Tread_Loop2_Que.Tread_Loop2_Que'"), NULL, LOAD_None, NULL);
	//ZeroSizeSize;
	TreadVelocityScale = 450;
	WheelVelocityScale = 85000;
	LeftTreadWheels = {
		"wheel_left_1_bone",
		"wheel_left_2_bone",
		"Wheel_Left_3_Bone",
		"Wheel_Left_4_Bone",
		"Wheel_Left_5_Bone",
		"Wheel_Left_6_Bone",
		"Wheel_Left_7_Bone",
		"ds1_wheel_left_1_bone",
		"ds1_wheel_left_2_bone",
		"DS1_Wheel_Left_3_Bone",
		"DS1_Wheel_Left_4_Bone",
		"DS1_Wheel_Left_5_Bone",
		"DS1_Wheel_Left_6_Bone",
		"DS1_Wheel_Left_7_Bone"
	};
	RightTreadWheels = {
		"wheel_right_1_bone",
		"wheel_right_2_bone",
		"Wheel_Right_3_Bone",
		"Wheel_Right_4_Bone",
		"Wheel_Right_5_Bone",
		"Wheel_Right_6_Bone",
		"Wheel_Right_7_Bone",
		"ds1_wheel_right_1_bone",
		"ds1_wheel_right_2_bone",
		"DS1_Wheel_Right_3_Bone",
		"DS1_Wheel_Right_4_Bone",
		"DS1_Wheel_Right_5_Bone",
		"DS1_Wheel_Right_6_Bone",
		"DS1_Wheel_Right_7_Bone"
	};
	TreadPannerRotation = FRotator(0, 16384, 0);
	LeftTreadSkinNum = 1;
	RightTreadSkinNum = 2;
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
	EngineInertia = 0.1;
	//PositionTypes(0) = ({ class'AGP_Vehicles.T62_MainGunner',"Weapon_1_Bone","None",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) });
	EntryPoints = { LeftSideEntry,RightSideEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/BMP1/s_vehi_bmp1_treads_2_Que.s_vehi_bmp1_treads_2_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/T62Tank/s_vehi_t62_engine_2_Que.s_vehi_t62_engine_2_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "TankStartUp";
	ShutDownForce = "TankShutDown";
	ViewShakeRadius = 600;
	ViewShakeOffsetMag = FVector(0.5, 0, 2);
	ViewShakeOffsetFreq = 7;
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/T62/T_62_Static_damage.T_62_Static_damage'"), NULL, LOAD_None, NULL);
	//DestroyedModelClass = class'AGP_Vehicles.T62A_DestroyedBody';
	DisintegrationHealth = -125;
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 300 });
	DefaultDamageZones = { Front_Left,Front_Right,Side_Right,Side_Left,Rear_Right,Rear_Left,Wheel_Left_1,Wheel_Right_1,Wheel_Left_2,Wheel_Right_2,Turret };
	Health_Front_Left = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	bUseNewTreadDamage = true;
	//NewDamageInfo(0) = ({ Class'AGP_Inventory.RocketRPGDamage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',0.34,0.34,0.34,0.51,0.5,0.5,0.5,0.5,0.5,0,0,0.5 })
	//NewDamageInfo(1) = ({ Class'AGP_Inventory.RocketAT4Damage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',0.51,0.51,0.51,0.51,0.5,0.5,0.5,0.5,0.5,0,0,0.5 })
	//NewDamageInfo(2) = ({ Class'AGP_Gameplay.RocketJavelinDamage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',1,1,1,1,0.5,0.5,0.5,0.5,0.5,0,0,0.5 })
	//NewDamageInfo(3) = ({ Class'AGP_Gameplay.JavelinImpactDamage',Class'AGP_Effects.VehicleFireHeavySmokeLarge',1,1,1,1,0.5,0.5,0.5,0.5,0.5,0,0,1 });

	TestDamageZones = {
		FTestDamageZoneInfo({ "Front_Left",0,7,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Front_Right",1,7,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Right",2,7,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Left",3,7,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Rear_Right",4,7,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Rear_Left",5,7,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_1",6,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_1",7,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_2",8,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_2",9,6,1000,0,0,1,0,0 }),
		FTestDamageZoneInfo({ "Turret",10,7,1000,0,0,0.8,0,0 })
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
		FIniParticleInfo({ "Wheel_Left_2","None","" }),
		FIniParticleInfo({ "Wheel_Right_2","None","" }),
		FIniParticleInfo({ "Turret","AGP_Effects.VehicleFireHeavySmokeLarge","" })
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
		"wheel_right_1_bone",
		"wheel_right_2_bone",
		"Wheel_Right_3_Bone",
		"Wheel_Right_4_Bone",
		"Wheel_Right_5_Bone",
		"Wheel_Right_6_Bone",
		"Wheel_Right_7_Bone",
		"Physics_Left_1_Bone",
		"Physics_Left_2_Bone",
		"Physics_Left_3_Bone",
		"Physics_Left_4_Bone",
		"Physics_Right_1_Bone",
		"Physics_Right_1_Bone1",
		"Physics_Right_1_Bone2",
		"Physics_Right_1_Bone3"
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
	Predict_Collision_Distance = 1500;
	MomentumMult = 0.3;
	DriverDamageMult = 0;
	VehiclePositionString = "in a T-62A";
	VehicleNameString = "T-62A";
	MaxDesireability = 0.8;
	RecoilImpulse = -101024;
	bAIDriversOnly = true;
	bCanStrafe = true;
	GroundSpeed = 500;
	HealthMax = 1000;
	Health = 1000;
	//AmbientSoundScaling = 2;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/T62.T62'"), NULL, LOAD_None, NULL);
	/*
	Skins(0) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/T-62_Tread_Mat.T-62_Tread_Mat'"), NULL, LOAD_None, NULL)
	Skins(1) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/T-62_Tread_Mat.T-62_Tread_Mat'"), NULL, LOAD_None, NULL)
	Skins(2) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/T-62_Tread_Mat.T-62_Tread_Mat'"), NULL, LOAD_None, NULL)
	Skins(3) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/T-62_Main_Mat.T-62_Main_Mat'"), NULL, LOAD_None, NULL)
	Skins(4) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/DS1_Tread_Mat.DS1_Tread_Mat'"), NULL, LOAD_None, NULL)
	Skins(5) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/DS1_Tread_Mat.DS1_Tread_Mat'"), NULL, LOAD_None, NULL)
	Skins(6) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/DS1_Tread_Mat.DS1_Tread_Mat'"), NULL, LOAD_None, NULL)
	Skins(7) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/T-62/DS1_Final_Mat.DS1_Final_Mat'"), NULL, LOAD_None, NULL);
	*/

	//SoundRadius = 400;
	//CollisionRadius = 260;
	//CollisionHeight = 60;
	ValidJavelinTarget = 2;
	KParams = KParams0;
}




/*
void AT62A::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AT62A::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AT62A::FindEntryVehicle(APawn* p)
{
	//Return None;
}

void AT62A::IdleSoundTimer()
{
	//AmbientSound = IdleSound;
}

void AT62A::KDriverEnter(APawn* p)
{
	/*
	local float StartupDelay;
	KDriverEnter(p);
	if (IdleSound != None)
	{
		if (StartUpSound != None)
		{
			StartupDelay = Abs(GetSoundDuration(StartUpSound) - 0.2);
			SetCustomTimer(StartupDelay, False, 'IdleSoundTimer');
		}
	}
	if (StartUpSound != None)
	{
		PlaySound(StartUpSound, 0, 1);
	}
	SetTimer(0.5, True);
	*/
}

void AT62A::KDriverLeave(bool bForceLeave)
{
	/*
	SetTimer(0, False);
	Return KDriverLeave(bForceLeave);
	*/
}

void AT62A::Timer()
{
	Super::Timer();
	/*
	if (Driver == None || Health_Front_Right <= 0 || Health_Front_Left <= 0 || Health_Back_Left <= 0 || Health_Back_Right <= 0)
	{
		Return;
	}
	if (VSize(Velocity) > 3)
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
		if (Driver.AmbientSound != None)
		{
			Driver.AmbientSoundScaling = 0;
			Driver.SoundVolume = 0;
			Driver.AmbientSound = None;
		}
	}
	*/
}

bool AT62A::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != None)
	{
		Return False;
	}
	else
	{
		Return TryToDrive(p);
	}
	*/
	return false;   //FAKE    /ELiZ
}

void AT62A::UpdatePrecacheMaterials()
{
	//Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	//Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	//Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	Super::UpdatePrecacheMaterials();
}