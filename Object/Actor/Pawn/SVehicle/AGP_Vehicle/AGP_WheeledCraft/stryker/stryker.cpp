// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/stryker/stryker.h"

Astryker::Astryker()
{
	WheelSoftness = 0.02;
	WheelPenScale = 2.1;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.5;
	WheelInertia = 0.121;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.001;
	//	\\WheelLatSlipFunc = ;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 1;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 15;
	WheelSuspensionMaxRenderTravel = 14;
	FTScale = 0.04;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = { -0.35, 0.25, 0.34, 0.51, 0.72, 1.05, 1.35 };
	NumForwardGears = 6;
	TransRatio = 0.16;
	ChangeUpPoint = 3000;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-06;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	StopThreshold = 120;
	HandbrakeThresh = 200;
	EngineInertia = 0.04;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	RevMeterScale = 4000;
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//DamagePct = Sound'S_AA2_Vehicles.stryker.STRYKER_Idle_Lp_3';
	//StartUpSound = Sound'S_AA2_Vehicles.stryker.STRYKER_Start_3';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.stryker.Stryker_static';
	//DestroyedModelClass = class'AGP_Vehicles.Stryker_DestroyedBody';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	//	\\DefaultDamageZones = ;
	//DamagePct = false;
	ImpactDamageMult = 0.001;
	//	\\Wheels = ;
	//DamageBones = 9.4;
	FlipTorque = 2000;
	FlipTime = 5;
	//bDrawMeshInFP = true;
	//Team = 255;
	//DriveAnim = "CrhNo";
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//FPCamPos = FVector(20, -35, 102);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a Stryker";
	//VehicleNameString = "Stryker";
	//ObjectiveGetOutDist = 1500;
	//GroundSpeed = 1290;
	//HealthMax = 600;
	//Health = 600;
	//Bob = 0.016;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.stryker';
	//CollisionRadius = 200;
	//CollisionHeight = 120;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.stryker.KParams0';
}


/*
void Astryker::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'skn_veh_hummer1114_lightoff');
	L.AddPrecacheMaterial(Texture'gascan1');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_green01a');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_lights_g01a');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01a');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01b');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01c_t');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_tire01d');
	StaticPrecache(L);
}
*/

void Astryker::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void Astryker::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'skn_veh_hummer1114_lightoff');
	Level.AddPrecacheMaterial(Texture'gascan1');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_green01a');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_lights_g01a');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01a');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01b');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_inside01c_t');
	Level.AddPrecacheMaterial(Texture'skin_veh_stryker_tire01d');
	*/
	Super::UpdatePrecacheMaterials();
}