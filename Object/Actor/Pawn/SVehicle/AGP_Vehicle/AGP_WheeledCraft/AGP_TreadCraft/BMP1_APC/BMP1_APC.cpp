// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/BMP1_APC/BMP1_APC.h"

ABMP1_APC::ABMP1_APC()
{
	//sndTreadSound = Sound'S_AAO_Vehicles.TankSounds.Tread_Loop2';
	//	\\SteerSpeedCurve = ;
	TreadVelocityScale = 450;
	WheelVelocityScale = 85000;
	LeftTreadWheels = {"wheel_left_1_bone", "wheel_left_2_bone", "Wheel_Left_3_Bone", "Wheel_Left_4_Bone", "Wheel_Left_5_Bone", "Wheel_Left_6_Bone", "Wheel_Left_7_Bone", "Wheel_Left_8_Bone", "ds1_wheel_left_1_bone", "ds1_wheel_left_2_bone", "DS1_Wheel_Left_3_Bone", "DS1_Wheel_Left_4_Bone", "DS1_Wheel_Left_5_Bone", "DS1_Wheel_Left_6_Bone", "DS1_Wheel_Left_7_Bone", "DS1_Wheel_Left_8_Bone" };
	RightTreadWheels = {"wheel_right_1_bone", "wheel_right_2_bone", "Wheel_Right_3_Bone", "Wheel_Right_4_Bone", "Wheel_Right_5_Bone", "Wheel_Right_6_Bone", "Wheel_Right_7_Bone", "Wheel_Right_8_Bone", "ds1_wheel_right_1_bone", "ds1_wheel_right_2_bone", "DS1_Wheel_Right_3_Bone", "DS1_Wheel_Right_4_Bone", "DS1_Wheel_Right_5_Bone", "DS1_Wheel_Right_6_Bone",  "DS1_Wheel_Right_7_Bone", "DS1_Wheel_Right_8_Bone"};
		
	//TreadPannerRotation = (Pitch = 0, Yaw = -16384, Roll = 0);
	LeftTreadSkinNum = 2;
	RightTreadSkinNum = 3;
	LeftTreadBone = "Tread_Left_1_bone";
	LeftTreadDamageBone = "DS1_Tread_Left_1_bone";
	RightTreadBone = "Tread_Right_1_bone";
	RightTreadDamageBone = "DS1_Tread_Right_1_bone";
	WheelSoftness = 0.02;
	WheelPenScale = 1;
	WheelPenOffset = 0.001;
	WheelRestitution = 0.5;
	WheelInertia = 0.1;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.001;
	//	\\WheelLatSlipFunc = ;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 0.9;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 45;
	WheelSuspensionOffset = -12;
	WheelSuspensionMaxRenderTravel = 45;
	FTScale = 0.03;
	ChassisTorqueScale = 0.01;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;
	GearRatios = { -0.42, 0.28, 0.62, 1.25 };
	NumForwardGears = 3;
	TransRatio = 0.03;
	ChangeUpPoint = 2000;
	ChangeDownPoint = 1000;
	LSDFactor = 1;
	EngineBrakeFactor = 1E-05;
	EngineBrakeRPMScale = 0.01;
	MaxBrakeTorque = 40;
	SteerSpeed = 150;
	StopThreshold = 50;
	HandbrakeThresh = 200;
	//	\\PositionTypes = ;
	//	\\DamagePct = ;
	//DamagePct = Sound'S_AAO_Vehicles.BMP1.s_vehi_bmp1_treads_2';
	//StartUpSound = Sound'S_AA2_Vehicles.stryker.STRYKER_Start_3';
	StartUpForce = "TankStartUp";
	ShutDownForce = "TankShutDown";
	ViewShakeRadius = 600;
	ViewShakeOffsetMag = FVector(5, 0, 2);
	ViewShakeOffsetFreq = 7;
	//DestroyedVehicleMesh = StaticMesh'M_AA2_Vehicles.BMP-1.BMP-1_static';
	//DestroyedModelClass = class'AGP_Vehicles.BMP1_DestroyedBody';
	DisintegrationHealth = -125;
	//DestructionLinearMomentum = Min = Min = 250000 Max = Max = 400000;
	//DestructionAngularMomentum = Min = Min = 100 Max = Max = 300;
	//	\\DefaultDamageZones = ;
	//Vector = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	bUseNewTreadDamage = true;
	//	\\NewDamageInfo = ;
	//	\\VisualEffect = ;
	//	\\VisualEffect = ;
	//InVal = true;
	bDriverCannotLeaveVehicle = true;
	bBulletImpactSparks = true;
	SmokeGeneratorAttachmentBone = "Exhaust_1_Bone";
	//	\\TreadBones = ;
	//	\\Vector = ;
	//InVal = true;
	//	\\Wheels = ;
	//DamageBones = 8;
	//bTurnInPlace = true;
	//TurnInPlaceThreshold = 0.3;
	//bNPCDriverCanUseSmoke = true;
	//bDrawMeshInFP = true;
	//bPCRelativeFPRotation = False;
	//bFPNoZFromCameraPitch = true;
	//DriverBone = "seat_driver_bone";
	//ExitPositions(0) = (X = 0, Y = -200, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 200, Z = 100);
	//FPCamPos = (X = -70, Y = 0, Z = 130);
	//FPCamViewOffset = (X = 90, Y = 0, Z = 0);
	//TPCamLookat = (X = -50, Y = 0, Z = 0);
	//TPCamWorldOffset = (X = 0, Y = 0, Z = 250);
	//bPredict_Collision_MoveToward = true;
	//Predict_Collision_Distance = 1300;
	//MomentumMult = 0.3;
	//DriverDamageMult = 0;
	//VehiclePositionString = "in a BMP-1";
	//VehicleNameString = "BMP-1";
	//MaxDesireability = 0.8;
	//bAIDriversOnly = true;
	//bCanStrafe = true;
	//GroundSpeed = 520;
	//HealthMax = 1000;
	//Health = 1000;
	//AmbientSoundScaling = 2;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.BMP1';
	//Skins(0) = Texture'T_AAO_Vehicles.BMP-1.BMP-1_Main';
	//Skins(1) = Texture'T_AAO_Vehicles.BMP-1.BMP-1_Tread';
	//Skins(2) = Texture'T_AAO_Vehicles.BMP-1.BMP-1_Tread';
	//Skins(3) = Texture'T_AAO_Vehicles.BMP-1.BMP-1_Tread';
	//SoundRadius = 400;
	//CollisionRadius = 260;
	//CollisionHeight = 60;
	//ValidJavelinTarget = 2;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.BMP1_APC.KParams0';
}

/*
void ABMP1_APC::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'BMP-1_Main');
	L.AddPrecacheMaterial(Texture'BMP-1_Tread');
	L.AddPrecacheMaterial(Texture'DS1_Darkener');
	L.AddPrecacheMaterial(Texture'DS2_BMP-1_Main');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void ABMP1_APC::FindEntryVehicle(APawn* p)
{
	//Return None;
}

bool ABMP1_APC::TryToDrive(APawn* p)
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
	return false;    //FAKE   /ELiZ
}

void ABMP1_APC::InitializeDamageZones()
{
	/*
	InitializeDamageZones();
	SetBoneScale(GetNextScalerSlot(), 0, 'ds1_light_1_bone');
	SetBoneScale(GetNextScalerSlot(), 0, 'ds1_hatch_front_1_bone');
	*/
}

void ABMP1_APC::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ABMP1_APC::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'BMP-1_Main');
	Level.AddPrecacheMaterial(Texture'BMP-1_Tread');
	Level.AddPrecacheMaterial(Texture'DS1_Darkener');
	Level.AddPrecacheMaterial(Texture'DS2_BMP-1_Main');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}

void ABMP1_APC::AttachDriver(APawn* p)
{
	/*
	p.bHidden = true;
	AttachDriver(p);
	Return;
	*/
}

void ABMP1_APC::IdleSoundTimer()
{
	//AmbientSound = IdleSound;
}

void ABMP1_APC::KDriverEnter(APawn* p)
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

void ABMP1_APC::KDriverLeave(bool bForceLeave)
{
	/*
	SetTimer(0, False);
	Return KDriverLeave(bForceLeave);
	*/
}

void ABMP1_APC::Timer()
{
	Super::Timer();
	/*
	if (Driver == None || Health_Front_Right <= 0 || Health_Front_Left <= 0 || Health_Back_Left <= 0 || Health_Back_Right <= 0)
	{
		Return;
	}
	if (VSize(Velocity) >= 3)
	{
		if (Driver.AmbientSound != sndTreadSound)
		{
			Driver.AmbientSound = sndTreadSound;
			Driver.SoundVolume = 255;
			Driver.bFullVolume = true;
			Driver.SoundRadius = 500;
			Driver.AmbientSoundScaling = 10;
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

/*
void ABMP1_APC::TakeDamage(int Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  InDamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (InDamageType == Class'SpecialGrenadeImpact')
	{
		Damage = 125;
	}
	TakeDamage(Damage, instigatedBy, HitLocation, Momentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
}
*/