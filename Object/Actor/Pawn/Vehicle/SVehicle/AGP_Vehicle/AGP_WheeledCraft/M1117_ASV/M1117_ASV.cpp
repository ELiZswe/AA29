// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1117_ASV/M1117_ASV.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

AM1117_ASV::AM1117_ASV()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 7;
	KParams0->KInertiaTensor[3] = 16;
	KParams0->KInertiaTensor[5] = 20;
	KParams0->KCOMOffset = FVector(0, 0, -0.8);
	KParams0->KLinearDamping = 0.015;
	KParams0->KAngularDamping = 0.005;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 2400;
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
	PassengerSideEntry->EntryBone = "Entry_Passenger_1_bone";
	PassengerSideEntry->PositionIndex = { 0 };
	UVehicleEntryPoint* RearEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	RearEntry->EntryBone = "entry_gunner_1_bone";
	RearEntry->PositionIndex = { 1 };
	UVehicleDamageZone* Body_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Right_1->ArmorThreshold = 5;
	Body_Right_1->MaxHitPoints = 1000;
	//Body_Right_1->DamageStates(0)=({"body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Body_Right_1->DamageStates(1)=({"DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Body_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Left_1->ArmorThreshold = 5;
	Body_Left_1->MaxHitPoints = 1000;
	//Body_Left_1->DamageStates(0)=({"body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Body_Left_1->DamageStates(1)=({"DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Body_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Right_2->ArmorThreshold = 5;
	Body_Right_2->MaxHitPoints = 1000;
	//Body_Right_2->DamageStates(0)=({"body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Body_Right_2->DamageStates(1)=({"DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Body_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Left_2->ArmorThreshold = 5;
	Body_Left_2->MaxHitPoints = 1000;
	//Body_Left_2->DamageStates(0)=({"body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Body_Left_2->DamageStates(1)=({"DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Body_Right_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Right_3->ArmorThreshold = 5;
	Body_Right_3->MaxHitPoints = 1000;
	//Body_Right_3->DamageStates(0)=({"body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Body_Right_3->DamageStates(1)=({"DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Body_Left_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Left_3->ArmorThreshold = 5;
	Body_Left_3->MaxHitPoints = 1000;
	//Body_Left_3->DamageStates(0)=({"body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Body_Left_3->DamageStates(1)=({"DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 6;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0)=({"Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Turret->DamageStates(1)=({"DS1_yaw_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	Turret->bControlsExternalMesh = true;
	Turret->VehiclePositionOwnerIndex = 1;
	Turret->MeshOwnerType = EMeshOwnerType::MO_VehiclePositionWeapon;
	UVehicleDamageZone* Door_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Door_Left_1->ArmorThreshold = 5;
	Door_Left_1->MaxHitPoints = 1000;
	//Door_Left_1->DamageStates(0)=({"door_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Door_Left_1->DamageStates(1)=({"DS1_door_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 2;
	Wheel_Left_1->DamageModifier = 10;
	Wheel_Left_1->MaxHitPoints = 1000;
	Wheel_Left_1->bWheelZone = true;
	Wheel_Left_1->WheelNum = 1;
	//Wheel_Left_1->DamageStates(0)=({"wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Wheel_Left_1->DamageStates(1)=({"ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Left_1->DamageStates(2)=({"ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Left_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 2;
	Wheel_Left_2->DamageModifier = 10;
	Wheel_Left_2->MaxHitPoints = 1000;
	Wheel_Left_2->bWheelZone = true;
	Wheel_Left_2->WheelNum = 3;
	//Wheel_Left_2->DamageStates(0)=({"wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Wheel_Left_2->DamageStates(1)=({"ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Left_2->DamageStates(2)=({"ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Left_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Door_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Door_Right_1->ArmorThreshold = 5;
	Door_Right_1->MaxHitPoints = 1000;
	//Door_Right_1->DamageStates(0)=({"door_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Door_Right_1->DamageStates(1)=({"DS1_door_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 2;
	Wheel_Right_2->DamageModifier = 10;
	Wheel_Right_2->MaxHitPoints = 1000;
	Wheel_Right_2->bWheelZone = true;
	Wheel_Right_2->WheelNum = 2;
	//Wheel_Right_2->DamageStates(0)=({"wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Wheel_Right_2->DamageStates(1)=({"ds1_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Right_2->DamageStates(2)=({"ds2_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Right_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 2;
	Wheel_Right_1->DamageModifier = 10;
	Wheel_Right_1->MaxHitPoints = 1000;
	Wheel_Right_1->bWheelZone = true;
	//Wheel_Right_1->DamageStates(0)=({"wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Wheel_Right_1->DamageStates(1)=({"ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Right_1->DamageStates(2)=({"ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,nullptr,nullptr,class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Right_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Windshield_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Windshield_Right_1->ArmorThreshold = 2;
	Windshield_Right_1->MaxHitPoints = 1000;
	//Windshield_Right_1->DamageStates(0)=({"windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Windshield_Right_1->DamageStates(1)=({"ds1_windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',nullptr,nullptr});
	Windshield_Right_1->bNoPassDamageToVehicle = true;
	Windshield_Right_1->PenetrationPercent = 1;
	UVehicleDamageZone* Windshield_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Windshield_Left_1->ArmorThreshold = 2;
	Windshield_Left_1->MaxHitPoints = 1000;
	//Windshield_Left_1->DamageStates(0)=({"windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Windshield_Left_1->DamageStates(1)=({"ds1_windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',nullptr,nullptr});
	Windshield_Left_1->bNoPassDamageToVehicle = true;
	Windshield_Left_1->PenetrationPercent = 1;
	UVehicleDamageZone* Door_Rear = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Door_Rear->ArmorThreshold = 5;
	Door_Rear->MaxHitPoints = 1000;
	//Door_Rear->DamageStates(0)=({"Door_rear_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Door_Rear->DamageStates(1)=({"DS1_Door_rear_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeLarge',nullptr,nullptr});
	UVehicleDamageZone* Window_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Window_Right_1->ArmorThreshold = 2;
	Window_Right_1->MaxHitPoints = 1000;
	//Window_Right_1->DamageStates(0)=({"window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Window_Right_1->DamageStates(1)=({"DS1_window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',nullptr,nullptr});
	Window_Right_1->bNoPassDamageToVehicle = true;
	Window_Right_1->PenetrationPercent = 1;
	UVehicleDamageZone* Window_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Window_Left_1->ArmorThreshold = 2;
	Window_Left_1->MaxHitPoints = 1000;
	//Window_Left_1->DamageStates(0)=({"window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,nullptr,nullptr,nullptr});
	//Window_Left_1->DamageStates(1)=({"DS1_window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',nullptr,nullptr});
	Window_Left_1->bNoPassDamageToVehicle = true;
	Window_Left_1->PenetrationPercent = 1;
	USVehicleWheel* RRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRWheel->bPoweredWheel = true;
	RRWheel->SteerType = EVehicleSteerType::VST_Steered;
	RRWheel->BoneName = "wheel_right_1_bone";
	RRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RRWheel->WheelBoneOffset = FVector(0, 15, 0);
	RRWheel->WheelRadius = 34;
	RRWheel->FlatWheelRadius = 28;
	RRWheel->RimWheelRadius = 24;
	USVehicleWheel* LRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRWheel->bPoweredWheel = true;
	LRWheel->SteerType = EVehicleSteerType::VST_Steered;
	LRWheel->BoneName = "wheel_left_1_bone";
	LRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LRWheel->WheelBoneOffset = FVector(0, -15, 0);
	LRWheel->WheelRadius = 34;
	LRWheel->FlatWheelRadius = 28;
	LRWheel->RimWheelRadius = 24;
	USVehicleWheel* RFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RFWheel->bPoweredWheel = true;
	RFWheel->BoneName = "wheel_right_2_bone";
	RFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RFWheel->WheelBoneOffset = FVector(0, 15, 0);
	RFWheel->WheelRadius = 34;
	RFWheel->FlatWheelRadius = 28;
	RFWheel->RimWheelRadius = 24;
	USVehicleWheel* LFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LFWheel->bPoweredWheel = true;
	LFWheel->BoneName = "wheel_left_2_bone";
	LFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LFWheel->WheelBoneOffset = FVector(0, -15, 0);
	LFWheel->WheelRadius = 34;
	LFWheel->FlatWheelRadius = 28;
	LFWheel->RimWheelRadius = 24;
	WheelSoftness = 0.01;
	WheelPenScale = 1.4;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.1;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 1.5;
	WheelLatFrictionScale = 1;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 25;
	WheelSuspensionOffset = -5;
	WheelSuspensionMaxRenderTravel = 6;
	FTScale = 0.03;
	ChassisTorqueScale = 0.05;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.38,0.25,0.38,0.56,0.78,1.22,1.85 };
	NumForwardGears = 6;
	TransRatio = 0.2;
	ChangeUpPoint = 2600;
	ChangeDownPoint = 1000;
	LSDFactor = 1;
	EngineBrakeFactor = 8E-05;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 100;
	HandbrakeThresh = 200;
	EngineInertia = 0.11;
	IdleRPM = 500;
	EngineRPMSoundRange = 6000;
	SteerBoneName = "steering_wheel_1_bone";
	SteerBoneMaxAngle = 120;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//PositionTypes(0) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_1_Bone",FVector(95, 20, 32),FVector(3, 0, -10),FRotator(3000,0,0) })
	//PositionTypes(1) = ({ class'AGP_Vehicles.M1117_ASV_Gunner',"Weapon_1_Bone","player_attach_bone",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) });
	EntryPoints = { DriverSideEntry,PassengerSideEntry,RearEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/stryker/STRYKER_Idle_Lp_3_Cue.STRYKER_Idle_Lp_3_Cue'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/stryker/STRYKER_Start_3_Cue.STRYKER_Start_3_Cue'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/ASV/M1117_ASV_static.M1117_ASV_static'"), NULL, LOAD_None, NULL);
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 150 });
	DefaultDamageZones = {
		Body_Right_1,
		Body_Left_1,
		Body_Right_2,
		Body_Left_2,
		Body_Right_3,
		Body_Left_3,
		Turret,
		Door_Left_1,
		Wheel_Left_1,
		Wheel_Left_2,
		Door_Right_1,
		Wheel_Right_2,
		Wheel_Right_1,
		Windshield_Right_1,
		Windshield_Left_1,
		Door_Rear,
		Window_Right_1,
		Window_Left_1,
	};
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	Wheels = { RRWheel,LRWheel,RFWheel,LFWheel };
	VehicleMass = 10;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawDriverInTP = true;
	bDrawMeshInFP = true;
	Team = 255;
	DriverBone = "seat_driver_bone";
	DriveAnim = "SF_Humvee_Driver_turn_Idle";
	DriverPosOffset = FVector(3, 0, -10);
	DriverRotOffset = FRotator(3000, 0, 0);
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100),FVector(0, -165, -100),FVector(0, 165, -100) };
	FPCamPos = FVector(95, -20, 32);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a M1117 ASV";
	VehicleNameString = "M1117 ASV";
	ObjectiveGetOutDist = 1500;
	FlagBone = "Dummy01";
	FlagRotation = FRotator(0, 32768, 0);
	GroundSpeed = 1290;
	HealthMax = 1000;
	Health = 1000;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1117_ASV.M1117_ASV'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 220;
	//CollisionHeight = 120;
	KParams = KParams0;
}
/*
void AM1117_ASV::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L->AddPrecacheMaterial(Texture'ASV_body_small');
	L->AddPrecacheMaterial(Shader'FMTV_Window');
	L->AddPrecacheMaterial(Texture'ASV_turret_small');
	L->AddPrecacheMaterial(Shader'DS1_FMTV_Window');
	L->AddPrecacheMaterial(Combiner'ds1_turret');
	L->AddPrecacheMaterial(Combiner'ds2_body');
	L->AddPrecacheMaterial(Combiner'ds2_turret');
	L->AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L->AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L->AddPrecacheMaterial(Texture'fx_part_explosion01');
	L->AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AM1117_ASV::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1117_ASV::UpdatePrecacheMaterials()
{
	/*
	LeveL->AddPrecacheMaterial(Texture'ASV_body_small');
	LeveL->AddPrecacheMaterial(Shader'FMTV_Window');
	LeveL->AddPrecacheMaterial(Texture'ASV_turret_small');
	LeveL->AddPrecacheMaterial(Shader'DS1_FMTV_Window');
	LeveL->AddPrecacheMaterial(Combiner'ds1_turret');
	LeveL->AddPrecacheMaterial(Combiner'ds2_body');
	LeveL->AddPrecacheMaterial(Combiner'ds2_turret');
	LeveL->AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	LeveL->AddPrecacheMaterial(Texture'fx_part_glasschunk');
	LeveL->AddPrecacheMaterial(Texture'fx_part_explosion01');
	LeveL->AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}