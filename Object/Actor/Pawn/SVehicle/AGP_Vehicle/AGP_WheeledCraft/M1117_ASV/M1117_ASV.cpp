// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1117_ASV/M1117_ASV.h"

AM1117_ASV::AM1117_ASV()
{
	WheelSoftness = 0.01;
	WheelPenScale = 1.4;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.1;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.001;
	//	\\WheelLatSlipFunc = ;
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
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	
	GearRatios = { -0.38, 0.25, 0.38, 0.56, 0.78, 1.22, 1.85 };
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
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//DamagePct = Sound'S_AA2_Vehicles.stryker.STRYKER_Idle_Lp_3';
	//StartUpSound = Sound'S_AA2_Vehicles.stryker.STRYKER_Start_3';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.ASV.M1117_ASV_static';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	//	\\Wheels = ;
	//DamageBones = 10;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawDriverInTP = true;
	//bDrawMeshInFP = true;
	//Team = 255;
	//DriverBone = "seat_driver_bone";
	//DriveAnim = "SF_Humvee_Driver_turn_Idle";
	//DriverPosOffset = (X = 3, Y = 0, Z = -10);
	//DriverRotOffset = (Pitch = 3000, Yaw = 0, Roll = 0);
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//FPCamPos = (X = 95, Y = -20, Z = 32);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a M1117 ASV";
	//VehicleNameString = "M1117 ASV";
	//ObjectiveGetOutDist = 1500;
	//FlagBone = "Dummy01";
	//FlagRotation = (Pitch = 0, Yaw = 32768, Roll = 0);
	//GroundSpeed = 1290;
	//HealthMax = 1000;
	//Health = 1000;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.M1117_ASV';
	//CollisionRadius = 220;
	//CollisionHeight = 120;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.M1117_ASV.KParams0';
}
/*
void AM1117_ASV::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'ASV_body_small');
	L.AddPrecacheMaterial(Shader'FMTV_Window');
	L.AddPrecacheMaterial(Texture'ASV_turret_small');
	L.AddPrecacheMaterial(Shader'DS1_FMTV_Window');
	L.AddPrecacheMaterial(Combiner'ds1_turret');
	L.AddPrecacheMaterial(Combiner'ds2_body');
	L.AddPrecacheMaterial(Combiner'ds2_turret');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AM1117_ASV::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1117_ASV::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'ASV_body_small');
	Level.AddPrecacheMaterial(Shader'FMTV_Window');
	Level.AddPrecacheMaterial(Texture'ASV_turret_small');
	Level.AddPrecacheMaterial(Shader'DS1_FMTV_Window');
	Level.AddPrecacheMaterial(Combiner'ds1_turret');
	Level.AddPrecacheMaterial(Combiner'ds2_body');
	Level.AddPrecacheMaterial(Combiner'ds2_turret');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}