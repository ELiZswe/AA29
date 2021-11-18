// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M978_HEMTT/M978_HEMTT.h"

AM978_HEMTT::AM978_HEMTT()
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
	WheelLatFrictionScale = 1;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 15;
	WheelSuspensionOffset = -9;
	WheelSuspensionMaxRenderTravel = 10;
	ExhaustBone = "Exhaust_1_Bone";
	bHasExhaust = true;
	FTScale = 0.03;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 5;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = { -0.48, 0.4, 0.65, 1, 1.8 };
	TransRatio = 0.17;
	ChangeUpPoint = 2200;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 0.001;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 30;
	TurnDamping = 95;
	StopThreshold = 150;
	HandbrakeThresh = 200;
	EngineInertia = 0.14;
	IdleRPM = 500;
	EngineRPMSoundRange = 5500;
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
	//DamagePct = Sound'S_AA2_Vehicles.HEMTT.HEMMT_Idle_Lp_4';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.HEMTT.HEMTT_Fuel_Static';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	ImpactDamageRadius = 350;
	//	\\Wheels = ;
	//DamageBones = 18;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawDriverInTP = true;
	//bDrawMeshInFP = true;
	//Team = 255;
	//DriverBone = "seat_driver_bone";
	//DriveAnim = "SF_Humvee_Driver_turn_Idle";
	//DriverPosOffset = (X = 0, Y = 0, Z = -3);
	//DriverRotOffset = (Pitch = -1000, Yaw = 0, Roll = 0);
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//FPCamPos = (X = 290, Y = -60, Z = 85);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a M978 HEMTT";
	//VehicleNameString = "M978 HEMTT";
	//ObjectiveGetOutDist = 1500;
	//FlagBone = "Dummy01";
	//FlagRotation = (Pitch = 0, Yaw = 32768, Roll = 0);
	//GroundSpeed = 1290;
	//HealthMax = 1000;
	//Health = 1000;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.M978_Fuel_HEMTT';
	//CollisionRadius = 380;
	//CollisionHeight = 120;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.M978_HEMTT.KParams0';


}
/*
void AM978_HEMTT::StaticPrecache(LevelInfo L)
{
	Super::StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'skn_veh_hemmt');
	L.AddPrecacheMaterial(Shader'Hemtt_window');
	L.AddPrecacheMaterial(Texture'skn_veh_hemmt_fuel');
	L.AddPrecacheMaterial(Texture'skn_veh_hemmt_tire_mud');
	L.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt');
	L.AddPrecacheMaterial(Shader'ds1_hemtt_window');
	L.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_fuel');
	L.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_tire_mud');
	L.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt');
	L.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_fuel');
	L.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_tire_mud');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AM978_HEMTT::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM978_HEMTT::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'skn_veh_hemmt');
	Level.AddPrecacheMaterial(Shader'Hemtt_window');
	Level.AddPrecacheMaterial(Texture'skn_veh_hemmt_fuel');
	Level.AddPrecacheMaterial(Texture'skn_veh_hemmt_tire_mud');
	Level.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt');
	Level.AddPrecacheMaterial(Shader'ds1_hemtt_window');
	Level.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_fuel');
	Level.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_tire_mud');
	Level.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt');
	Level.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_fuel');
	Level.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_tire_mud');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}