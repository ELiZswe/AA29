// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1114_HMMWV/M1114_HMMWV.h"

AM1114_HMMWV::AM1114_HMMWV()
{
	WheelSoftness = 0.02;
	WheelPenScale = 2.1;
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
	FTScale = 0.04;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = { -0.49, 0.43, 0.74, 1.23, 2.05 };
	TransRatio = 0.15;
	ChangeUpPoint = 3600;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 0.0003;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 100;
	HandbrakeThresh = 200;
	EngineInertia = 0.1;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	SteerBoneName = "steering_wheel_bone";
	SteerBoneMaxAngle = 120;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//DamagePct = Sound'S_AA2_Vehicles.HUMMWV.HUMMWV_Idle_Lp_3';
	//StartUpSound = Sound'S_AA2_Vehicles.HUMMWV.HUMMWV_Start_3';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.HMMWV.M1114_HMMWV_Static';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	//	\\Wheels = ;
	//DamageBones = 4.8;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawDriverInTP = true;
	//bDrawMeshInFP = true;
	//Team = 255;
	//DriverBone = "seat_driver_bone";
	//DriveAnim = "SF_Humvee_Driver_turn_Idle";
	//DriverPosOffset = (X = 1, Y = 0, Z = -21);
	//DriverRotOffset = (Pitch = 1600, Yaw = 0, Roll = 0);
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//FPCamPos = (X = 15, Y = -35, Z = 65);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a M1114 HMMWV";
	//VehicleNameString = "M1114 HMMWV";
	//ObjectiveGetOutDist = 1500;
	//FlagBone = "Dummy01";
	//FlagRotation = (Pitch = 0, Yaw = 32768, Roll = 0);
	//GroundSpeed = 1290;
	//HealthMax = 1000;
	//Health = 1000;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.M1114_HMMWV';
	//CollisionRadius = 170;
	//CollisionHeight = 110;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.M1114_HMMWV.KParams0';
}



/*
void AM1114_HMMWV::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
}
*/

void AM1114_HMMWV::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1114_HMMWV::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}
