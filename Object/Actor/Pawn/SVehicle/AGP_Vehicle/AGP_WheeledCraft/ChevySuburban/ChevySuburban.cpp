// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/ChevySuburban/ChevySuburban.h"

AChevySuburban::AChevySuburban()
{
	WheelSoftness = 0.025;
	WheelPenScale = 1.6;
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
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 5;
	FTScale = 0.04;
	ChassisTorqueScale = 0.2;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = { -0.86, 0.43, 0.74, 1.23, 1.85 };
	TransRatio = 0.15;
	ChangeUpPoint = 3500;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 8E-05;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 50;
	HandbrakeThresh = 200;
	EngineInertia = 0.025;
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
	//DamagePct = Sound'S_AA2_Vehicles.ChevySuburban.SUV_Idle_Lp_1';
	//StartUpSound = Sound'S_AA2_Vehicles.ChevySuburban.SUV_Start_1';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.suburban.Suburban_Static';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	//	\\Wheels = ;
	//DamageBones = 4;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawDriverInTP = true;
	//bDrawMeshInFP = true;
	//Team = 255;
	//DriverBone = "seat_driver_bone";
	//DriveAnim = "SF_Humvee_Driver_turn_Idle";
	//DriverPosOffset = (X = 4, Y = 0, Z = 0);
	//DriverRotOffset = (Pitch = 1600, Yaw = 0, Roll = 0);
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//FPCamPos = (X = 35, Y = -25, Z = 60);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a Chevy Suburban";
	//VehicleNameString = "Chevy Suburban";
	//ObjectiveGetOutDist = 1500;
	//FlagBone = "Dummy01";
	//FlagRotation = (Pitch = 0, Yaw = 32768, Roll = 0);
	//GroundSpeed = 1290;
	//HealthMax = 1000;
	//Health = 1000;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.suburban';
	//CollisionRadius = 175;
	//CollisionHeight = 100;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.ChevySuburban.KParams0';
}


/*
void AChevySuburban::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'chevy_suburban_tire');
	L.AddPrecacheMaterial(Texture'chevy_suburban_b');
	L.AddPrecacheMaterial(Texture'chevy_suburban_a');
	L.AddPrecacheMaterial(Shader'suburban_window_final');
	L.AddPrecacheMaterial(Combiner'ds1_combiner_tire');
	L.AddPrecacheMaterial(Shader'ds1_final_body');
	L.AddPrecacheMaterial(Shader'ds1_final_interior');
	L.AddPrecacheMaterial(Shader'suburban_window_final_ds1');
	L.AddPrecacheMaterial(Combiner'ds2_combiner_tire');
	L.AddPrecacheMaterial(Shader'ds2_final_body');
	L.AddPrecacheMaterial(Shader'ds2_final_interior');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AChevySuburban::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AChevySuburban::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'chevy_suburban_tire');
	Level.AddPrecacheMaterial(Texture'chevy_suburban_b');
	Level.AddPrecacheMaterial(Texture'chevy_suburban_a');
	Level.AddPrecacheMaterial(Shader'suburban_window_final');
	Level.AddPrecacheMaterial(Combiner'ds1_combiner_tire');
	Level.AddPrecacheMaterial(Shader'ds1_final_body');
	Level.AddPrecacheMaterial(Shader'ds1_final_interior');
	Level.AddPrecacheMaterial(Shader'suburban_window_final_ds1');
	Level.AddPrecacheMaterial(Combiner'ds2_combiner_tire');
	Level.AddPrecacheMaterial(Shader'ds2_final_body');
	Level.AddPrecacheMaterial(Shader'ds2_final_interior');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	UpdatePrecacheMaterials();
	*/
}