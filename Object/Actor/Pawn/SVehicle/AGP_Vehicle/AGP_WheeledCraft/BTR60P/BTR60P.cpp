// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/BTR60P/BTR60P.h"

ABTR60P::ABTR60P()
{
	WheelSoftness = 0.02;
	WheelPenScale = 2.1;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.121;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.001;
	//	\\WheelLatSlipFunc = ;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 1;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 25;
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 10;
	FTScale = 0.04;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = {-0.38, 0.32, 0.53, 0.87, 1.35};
	TransRatio = 0.21;
	ChangeUpPoint = 5000;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-05;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 40;
	SteerSpeed = 30;
	TurnDamping = 100;
	StopThreshold = 80;
	HandbrakeThresh = 200;
	EngineInertia = 0.03;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//BoneSlot = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.btr60.BTR60_Static_damage';
	//DestroyedModelClass = class'AGP_Vehicles.BTR60_DestroyedBody';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//Vector = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	//	\\NewDamageInfo = ;
	//	\\VisualEffect = ;
	//	\\VisualEffect = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	//	\\Wheels = ;
	//DamageBones = 8;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawMeshInFP = true;
	//Team = 255;
	//DriverBone = "seat_driver_bone";
	//DriveAnim = "CrhNo";
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//FPCamPos = (X = 20, Y = -35, Z = 102);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a BTR-60";
	//VehicleNameString = "BTR-60";
	//ObjectiveGetOutDist = 1500;
	//GroundSpeed = 350;
	//HealthMax = 1000;
	//Health = 1000;
	//AmbientSoundScaling = 2;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.btr60';
	//SoundVolume = 180;
	//CollisionRadius = 175;
	//ValidJavelinTarget = 2;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.BTR60P.KParams0';
}


/*
void ABTR60P::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'BTR-60_Turrett');
	L.AddPrecacheMaterial(Texture'BTR-60_Turrett_Darken');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/
void ABTR60P::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}
void ABTR60P::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'BTR-60_Turrett');
	Level.AddPrecacheMaterial(Texture'BTR-60_Turrett_Darken');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}