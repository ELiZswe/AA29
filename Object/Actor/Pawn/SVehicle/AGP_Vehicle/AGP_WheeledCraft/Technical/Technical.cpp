// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/Technical/Technical.h"

ATechnical::ATechnical()
{
	WheelSoftness = 0.02;
	WheelPenScale = 1.7;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.1;
	WheelInertia = 0.1;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.0001;
	//	\\WheelLatSlipFunc = ;
	WheelLongFrictionScale = 0.7;
	WheelLatFrictionScale = 1.15;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 25;
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 3;
	FTScale = 0.03;
	ChassisTorqueScale = 0.2;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	
	GearRatios = { -0.78, 0.27, 0.58, 0.97, 1.4, 1.95 };
	NumForwardGears = 5;
	TransRatio = 0.2;
	ChangeUpPoint = 3700;
	ChangeDownPoint = 1400;
	LSDFactor = 1;
	EngineBrakeFactor = 5E-05;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 40;
	StopThreshold = 50;
	HandbrakeThresh = 200;
	EngineInertia = 0.05;
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
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//DamagePct = Sound'S_AA2_Vehicles.Technical.ToyotaTech_Idle_Lp_1';
	//StartUpSound = Sound'S_AA2_Vehicles.Technical.ToyotaTech_Start_1';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.tacoma.Tacoma_Static_Damage';
	//DestroyedModelClass = class'AGP_Vehicles.TacomaTechnical_DestroyedBody';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//	\\VisualEffect = ;
	//	\\VisualEffect = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	ImpactDamageRadius = 150;
	//	\\Wheels = ;
	//DamageBones = 3.5;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawDriverInTP = true;
	//bDrawMeshInFP = true;
	//bDesiredBehindView = false;
	//Team = 255;
	//DriverBone = "seat_driver_bone";
	//DriveAnim = "SF_Humvee_Driver_turn_Idle";
	//DriverPosOffset = FVector(0, 0, -10);
	//DriverRotOffset = (Pitch = 2000, Yaw = 0, Roll = 0);
	//ExitPositions[0] = FVector(0, -165, 100);
	//ExitPositions[1] = FVector(0, 165, 100);
	//ExitPositions[2] = FVector(0, -165, -100);
	//ExitPositions[3] = FVector(0, 165, -100);
	//FPCamPos = FVector(38, -255, 47);
	//TPCamDistance = 375;
	//TPCamLookat = FVector(0, 0, 0);
	//TPCamWorldOffset = FVector(0, 0, 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a Technical";
	//VehicleNameString = "Technical";
	//ObjectiveGetOutDist = 1500;
	//GroundSpeed = 600;
	//HealthMax = 1000;
	//Health = 1000;
	//Bob = 0.016;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.Technical';
	//CollisionRadius = 175;
	//CollisionHeight = 120;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.Technical.KParams0';
}



/*
void ATechnical::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'tacoma-tire1');
	L.AddPrecacheMaterial(Texture'tacoma-inside');
	L.AddPrecacheMaterial(Texture'tacoma-main1grey');
	L.AddPrecacheMaterial(Shader'window_final');
	L.AddPrecacheMaterial(Texture'tacoma-bar1');
	L.AddPrecacheMaterial(Shader'DS1_Final_Tacoma');
	L.AddPrecacheMaterial(Shader'DS1_Bar_Tacoma');
	L.AddPrecacheMaterial(Shader'DS1_Window_Final');
	L.AddPrecacheMaterial(Shader'DS2_Final_Tacoma');
	L.AddPrecacheMaterial(Shader'DS2_Final_Inside_Tacoma');
	L.AddPrecacheMaterial(Shader'DS2_Bar_Tacoma');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	L.AddPrecacheStaticMesh(StaticMesh'Tacoma_Static_Damage');
	StaticPrecache(L);
}
*/
void ATechnical::UpdatePrecacheStaticMeshes()
{
	//Level.AddPrecacheStaticMesh(StaticMesh'Tacoma_Static_Damage');
	//UpdatePrecacheStaticMeshes();
}
void ATechnical::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'tacoma-tire1');
	Level.AddPrecacheMaterial(Texture'tacoma-inside');
	Level.AddPrecacheMaterial(Texture'tacoma-main1grey');
	Level.AddPrecacheMaterial(Shader'window_final');
	Level.AddPrecacheMaterial(Texture'tacoma-bar1');
	Level.AddPrecacheMaterial(Shader'DS1_Final_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS1_Bar_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS1_Window_Final');
	Level.AddPrecacheMaterial(Shader'DS2_Final_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS2_Final_Inside_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS2_Bar_Tacoma');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	UpdatePrecacheMaterials();
	*/
}