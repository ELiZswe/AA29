// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/Packbot/Packbot.h"

APackbot::APackbot()
{
	//sndTreadSound = Sound'S_AAO_Vehicles.TankSounds.Tread_Loop2';
	SteerThrottleScale = 3;
	//	\\SteerSpeedCurve = ;
	TreadVelocityScale = 150;
	WheelVelocityScale = 85000;
	LeftTreadWheels = { "LMidWheel", "LRearWheel" };
	RightTreadWheels = { "RMidWheel", "RRearWheel" };
	//TreadPannerRotation = (Pitch = 0, Yaw = 0, Roll = 16384);
	LeftTreadSkinNum = 1;
	RightTreadSkinNum = 1;
	LeftTreadBone = "LMidWheel";
	RightTreadBone = "RMidWheel";
	WheelSoftness = 1E-06;
	WheelPenScale = 1;
	WheelRestitution = 0.5;
	WheelInertia = 0.1;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.001;
	//	\\WheelLatSlipFunc = ;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 5;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	FTScale = 0.03;
	ChassisTorqueScale = 1.5;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = { -0.1, 0.05, 0.12 };
	NumForwardGears = 2;
	TransRatio = 0.21;
	ChangeUpPoint = 2000;
	ChangeDownPoint = 1000;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-05;
	EngineBrakeRPMScale = 0.01;
	MaxBrakeTorque = 100;
	SteerSpeed = 300;
	StopThreshold = 50;
	HandbrakeThresh = 200;
	EngineInertia = 0.1;
	//	\\EntryPoints = ;
	//BoneSlot = "TankStartUp";
	ShutDownForce = "TankShutDown";
	ViewShakeRadius = 600;
	ViewShakeOffsetMag = FVector(5, 0, 2);
	ViewShakeOffsetFreq = 7;
	DisintegrationHealth = -125;
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 300;
	Health_Front_Left = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	bEnableProximityViewShake = true;
	bDriverCannotLeaveVehicle = true;
	bBulletImpactSparks = true;
	//	\\TreadBones = ;
	//	\\Vector = ;
	//InVal = true;
	//	\\Wheels = ;
	//DamageBones = 14;
	//bTurnInPlace = true;
	//TurnInPlaceThreshold = 0.85;
	//bDrawMeshInFP = true;
	//bPCRelativeFPRotation = False;
	//bFPNoZFromCameraPitch = true;
	//DriverBone = "root";
	//ExitPositions(0) = (X = 0, Y = -200, Z = 100);
	//FPCamPos = (X = -70, Y = 0, Z = 130);
	//FPCamViewOffset = (X = 90, Y = 0, Z = 0);
	//TPCamLookat = (X = -50, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 250);
	//Predict_Collision_Distance = 50;
	//MomentumMult = 0.3;
	//DriverDamageMult = 0;
	//VehiclePositionString = "in a Packbot";
	//VehicleNameString = "Packbot";
	//MaxDesireability = 0.8;
	//RecoilImpulse = -101024;
	//bAIDriversOnly = true;
	//bCanStrafe = true;
	//GroundSpeed = 250;
	//HealthMax = 1000;
	//Health = 1000;
	//AmbientSoundScaling = 2;
	//bProp = true;
	//Mesh = SkeletalMesh'A_AA2_Packbot.vehi_PackbotVehi';
	//Skins(0) = Texture'T_AA2_Packbot.Robot.Packbot';
	//Skins(1) = Texture'T_AA2_Packbot.Treads.packbot_largetread';
	//SoundVolume = 200;
	//CollisionRadius = 25;
	//CollisionHeight = 1;
	//bBlockActors = False;
	//bBlockPlayers = False;
	//ValidJavelinTarget = 0;
	//bBlockZeroExtentTraces = False;
	//bBlockNonZeroExtentTraces = False;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.Packbot.KParams0';
}

/*
void APackbot::DisplayDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	
	DisplayDebug(Canvas, YL, YPos);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("TurnDamping: " $ TurnDamping $ " On Ground: " $ bVehicleOnGround);
	YPos += YL;
	
}
*/

/*
void APackbot::StaticPrecache(LevelInfo L)
{
	Super::StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void APackbot::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void APackbot::FindEntryVehicle(APawn* p)
{
	//Return None;
}

void APackbot::IdleSoundTimer()
{
	//AmbientSound = IdleSound;
}

void APackbot::KDriverEnter(APawn* p)
{
	/*
	local float StartupDelay;
	KDriverEnter(p);
	if (IdleSound != None)
	{
		if (StartUpSound != None)
		{
			StartupDelay = Abs(GetSoundDuration(StartUpSound) - 0.2);
			SetCustomTimer(StartupDelay, False, 'IdleSoundTimer');
		}
	}
	if (StartUpSound != None)
	{
		PlaySound(StartUpSound, 0, 1);
	}
	SetTimer(0.5, True);
	*/
}

void APackbot::KDriverLeave(bool bForceLeave)
{
	/*
	SetTimer(0, False);
	Return KDriverLeave(bForceLeave);
	*/
}

void APackbot::Timer()
{
	/*
	Timer();
	if (Driver == None || Health_Front_Right <= 0 || Health_Front_Left <= 0 || Health_Back_Left <= 0 || Health_Back_Right <= 0)
	{
		Return;
	}
	if (VSize(Velocity) > 3)
	{
		if (Driver.AmbientSound != sndTreadSound)
		{
			Driver.AmbientSound = sndTreadSound;
			Driver.SoundVolume = 128;
			Driver.bFullVolume = true;
			Driver.SoundRadius = 100;
			Driver.AmbientSoundScaling = 5;
		}
	}
	else
	{
		if (Driver.AmbientSound != None)
		{
			Driver.AmbientSoundScaling = 0;
			Driver.SoundVolume = 0;
			Driver.AmbientSound = None;
		}
	}
	*/
}

bool APackbot::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != None)
	{
		Return False;
	}
	else
	{
		Return TryToDrive(p);
	}
	*/

	return false;    //FAKE    /ELiZ
}

void APackbot::UpdatePrecacheMaterials()
{
	//Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	//Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	//Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	Super::UpdatePrecacheMaterials();
}
