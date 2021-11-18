// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/SFHumvee/SFHumvee.h"

ASFHumvee::ASFHumvee()
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
	FTScale = 0.03;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	
	GearRatios = { -0.49, 0.43, 0.74, 1.23, 2.05 };
	TransRatio = 0.15;
	ChangeUpPoint = 3600;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 0.0002;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 100;
	HandbrakeThresh = 200;
	EngineInertia = 0.1;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	SteerBoneName = "steering_wheel_1_bone";
	SteerBoneMaxAngle = 120;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	bAllowCOMAdjust = true;
	MaxCOMOffset = 0.3;
	COMAdjustScale = 0.00032;
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//DamagePct = Sound'S_AA2_Vehicles.HUMMWV.HUMMWV_Idle_Lp_3';
	//StartUpSound = Sound'S_AA2_Vehicles.HUMMWV.HUMMWV_Start_3';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.SF_Humvee.SF_Humvee_Static_Damage';
	//DestroyedModelClass = class'AGP_Vehicles.SFHumvee_DestroyedBody';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//	\\VisualEffect = ;
	//	\\VisualEffect = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	//	\\Wheels = ;
	//DamageBones = 5;
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
	//VehiclePositionString = "in a Humvee";
	//VehicleNameString = "SF Humvee";
	//ObjectiveGetOutDist = 1500;
	//FlagBone = "Dummy01";
	//FlagRotation = (Pitch = 0, Yaw = 32768, Roll = 0);
	//GroundSpeed = 900;
	//HealthMax = 1000;
	//Health = 1000;
	//Bob = 0.016;
	//bDemoRecSounds = false;
	//bDemoRecMuzzleFlash = false;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.SFHumvee';
	//SoundRadius = 255;
	//CollisionRadius = 190;
	//CollisionHeight = 120;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.SFHumvee.KParams0';
}



/*
void ASFHumvee::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
}
*/

void ASFHumvee::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ASFHumvee::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}
