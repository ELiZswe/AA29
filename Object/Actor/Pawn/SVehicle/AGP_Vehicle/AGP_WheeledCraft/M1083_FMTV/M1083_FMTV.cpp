// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1083_FMTV/M1083_FMTV.h"

AM1083_FMTV::AM1083_FMTV()
{
	WheelSoftness = 0.01;
	WheelPenScale = 1.1;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.1;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.001;
	//	\\WheelLatSlipFunc = ;
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
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = { -0.2, 0.15, 0.25, 0.4, 0.6, 0.95, 1.35, 1.8 };
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
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//DamagePct = Sound'S_AA2_Vehicles.FMTV.FMTV_Idle_Lp_1';
	//StartUpSound = Sound'S_AA2_Vehicles.FMTV.FMTV_Start_1';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.FMTV.M1083_FMTV_Static';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//	\\Core = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	ImpactDamageRadius = 250;
	//	\\Wheels = ;
	//DamageBones = 10;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawDriverInTP = true;
	//bDrawMeshInFP = true;
	//Team = 255;
	//DriverBone = "seat_driver_bone";
	//DriveAnim = "SF_Humvee_Driver_turn_Idle";
	//DriverPosOffset = (X = 0, Y = 15, Z = -4);
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//FPCamPos = (X = 185, Y = -45, Z = 88);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a M1083 MTV";
	//VehicleNameString = "M1083 MTV";
	//ObjectiveGetOutDist = 1500;
	//FlagBone = "Dummy01";
	//FlagRotation = (Pitch = 0, Yaw = 32768, Roll = 0);
	//GroundSpeed = 900;
	//HealthMax = 1000;
	//Health = 1000;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.M1083_MTV';
	//CollisionRadius = 280;
	//CollisionHeight = 130;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.M1083_FMTV.KParams0';
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