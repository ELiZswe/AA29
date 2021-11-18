// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/BTR80APC/BTR80APC.h"

ABTR80APC::ABTR80APC()
{
	WeaponBoneHack = true;
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
	GearRatios = { -0.38, 0.32, 0.53, 0.87,  1.35 };
	TransRatio = 0.21;
	ChangeUpPoint = 2000;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-05;
	EngineBrakeRPMScale = 0.01;
	MaxBrakeTorque = 40;
	SteerSpeed = 30;
	TurnDamping = 100;
	StopThreshold = 80;
	HandbrakeThresh = 200;
	EngineInertia = 0.1;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//	\\PositionTypes = ;
	//DamagePct = Sound'S_AA2_Vehicles.stryker.STRYKER_Idle_Lp_3';
	//StartUpSound = Sound'S_AA2_Vehicles.stryker.STRYKER_Start_3';
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.btr60.BTR60_Static_damage';
	//DestroyedModelClass = class'AGP_Vehicles.BTR60_DestroyedBody';
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 150;
	Health_Front_Left = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	bUseNewWheelDamage = true;
	//	\\NewDamageInfo = ;
	//DamagePct = false;
	bDriverCannotLeaveVehicle = true;
	ImpactDamageMult = 0.001;
	bBulletImpactSparks = true;
	SmokeGeneratorAttachmentBone = "Exhaust_L_bone";
	//	\\WheelBones = ;
	//	\\Vector = ;
	//	\\BoneSlot = ;
	//DamageBones = 8;
	//bNPCDriverCanUseSmoke = true;
	//bDrawMeshInFP = true;
	//bCanFlip = false;
	//Team = 255;
	//DriverBone = "BTR80_root";
	//DriveAnim = "CrhNo";
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//FPCamPos = (X = 20, Y = -35, Z = 102);
	//TPCamDistance = 375;
	//TPCamLookat = (X = 0, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 100);
	//bPredict_Collision_MoveToward = true;
	//Predict_Collision_Distance = 1150;
	//MomentumMult = 2;
	//DriverDamageMult = 0.4;
	//VehiclePositionString = "in a BTR-80";
	//VehicleNameString = "BTR-80";
	//ObjectiveGetOutDist = 1500;
	//bAIDriversOnly = true;
	//GroundSpeed = 350;
	//HealthMax = 1000;
	//Health = 1000;
	//Mesh = SkeletalMesh'A_AAO_Vehicles.BTR80';
	//SoundRadius = 500;
	//CollisionRadius = 300;
	//CollisionHeight = 75;
	//ValidJavelinTarget = 2;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.BTR80APC.KParams0';
}




void ABTR80APC::PostBeginPlay()
{
	/*
	local Object.Rotator newRot;
	if (WeaponBoneHack)
	{
		newRot = GetBoneRotation('Weapon_1_Bone');
		newRot.Yaw = 32768;
		newRot.Pitch -= 32768;
		newRot.Roll += 32768;
		SetBoneRotation('Weapon_1_Bone', newRot);
	}
	Super::PostBeginPlay();
	*/
}

void ABTR80APC::FindEntryVehicle(APawn* p)
{
	//Return None;
}

void ABTR80APC::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != None)
	{
		return false;
	}
	else
	{
		Return TryToDrive(p);
	}
	*/
}

void ABTR80APC::KDriverEnter(APawn* p)
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
	*/
}

void ABTR80APC::IdleSoundTimer()
{
	//AmbientSound = IdleSound;
}
/*
void ABTR80APC::TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, UaDamageType* InDamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (InDamageType == Class'SpecialGrenadeImpact')
	{
		Damage = 125;
	}
	TakeDamage(Damage, instigatedBy, HitLocation, Momentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
}*/