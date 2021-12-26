// All the original content belonged to the US Army
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/Packbot/Packbot.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

APackbot::APackbot()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 3;
	KParams0->KInertiaTensor[3] = 9;
	KParams0->KInertiaTensor[5] = 1.5;
	KParams0->KCOMOffset = FVector(0.25, 0, -5);
	KParams0->KLinearDamping = 0.05;
	KParams0->KAngularDamping = 1;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 300;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bKStayUpright = true;
	KParams0->bKAllowRotate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 1;
	UVehicleEntryPoint* LeftSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	LeftSideEntry->bDriverEntry = true;
	LeftSideEntry->EntryBone = "root";
	USVehicleWheel* RMidWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RMidWheel->bPoweredWheel = true;
	RMidWheel->bTrackWheel = true;
	RMidWheel->SteerType = EVehicleSteerType::VST_Steered;
	RMidWheel->BoneName = "RMidWheel";
	RMidWheel->WheelBoneOffset = FVector(0, 0.25, 0);
	RMidWheel->WheelRadius = 6;
	USVehicleWheel* RRearWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRearWheel->bPoweredWheel = true;
	RRearWheel->bTrackWheel = true;
	RRearWheel->BoneName = "RRearWheel";
	RRearWheel->WheelBoneOffset = FVector(0, 0.25, 0);
	RRearWheel->WheelRadius = 6;
	USVehicleWheel* LMidWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LMidWheel->bPoweredWheel = true;
	LMidWheel->bTrackWheel = true;
	LMidWheel->SteerType = EVehicleSteerType::VST_Steered;
	LMidWheel->BoneName = "LMidWheel";
	LMidWheel->WheelBoneOffset = FVector(0, 0.25, 0);
	LMidWheel->WheelRadius = 6;
	USVehicleWheel* LRearWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRearWheel->bPoweredWheel = true;
	LRearWheel->bTrackWheel = true;
	LRearWheel->BoneName = "LRearWheel";
	LRearWheel->WheelBoneOffset = FVector(0, 0.25, 0);
	LRearWheel->WheelRadius = 6;
	sndTreadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/TankSounds/Tread_Loop2_Que.Tread_Loop2_Cue'"), NULL, LOAD_None, NULL);
	SteerThrottleScale = 3;
	//ZeroSizeSize;
	TreadVelocityScale = 150;
	WheelVelocityScale = 85000;
	LeftTreadWheels = { "LMidWheel","LRearWheel" };
	RightTreadWheels = { "RMidWheel","RRearWheel" };
	TreadPannerRotation = FRotator(0, 0, 16384);
	LeftTreadSkinNum = 1;
	RightTreadSkinNum = 1;
	LeftTreadBone = "LMidWheel";
	RightTreadBone = "RMidWheel";
	WheelSoftness = 1E-06;
	WheelPenScale = 1;
	WheelRestitution = 0.5;
	WheelInertia = 0.1;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 1.6;
	WheelLatFrictionScale = 5;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	FTScale = 0.03;
	ChassisTorqueScale = 1.5;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.1,0.05,0.12 };
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
	EntryPoints = { LeftSideEntry };
	StartUpForce = "TankStartUp";
	ShutDownForce = "TankShutDown";
	ViewShakeRadius = 600;
	ViewShakeOffsetMag = FVector(0.5, 0, 2);
	ViewShakeOffsetFreq = 7;
	DisintegrationHealth = -125;
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 300 });
	Health_Front_Left = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	bEnableProximityViewShake = true;
	bDriverCannotLeaveVehicle = true;
	bBulletImpactSparks = true;
	TreadBones = { "LFrontWheel","LTrackTilt","LRearWheel","RFrontWheel","RTrackTilt","RRearWheel" };
	UndercarriageBones = { "root","root" };
	bUseDotTestForAim = true;
	Wheels = { RMidWheel,RRearWheel,LMidWheel,LRearWheel };
	VehicleMass = 14;
	bTurnInPlace = true;
	TurnInPlaceThreshold = 0.85;
	bDrawMeshInFP = true;
	bPCRelativeFPRotation = false;
	bFPNoZFromCameraPitch = true;
	DriverBone = "root";
	ExitPositions = { FVector(0, -200, 100) };
	FPCamPos = FVector(-70, 0, 130);
	FPCamViewOffset = FVector(90, 0, 0);
	TPCamLookat = FVector(-50, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 250);
	Predict_Collision_Distance = 50;
	MomentumMult = 0.3;
	DriverDamageMult = 0;
	VehiclePositionString = "in a Packbot";
	VehicleNameString = "Packbot";
	MaxDesireability = 0.8;
	RecoilImpulse = -101024;
	bAIDriversOnly = true;
	bCanStrafe = true;
	GroundSpeed = 250;
	HealthMax = 1000;
	Health = 1000;
	//AmbientSoundScaling = 2;
	//bProp = true;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Packbot/vehi_PackbotVehi.vehi_PackbotVehi'"), NULL, LOAD_None, NULL);
	/*
	Skins = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Packbot/Robot/Packbot_Mat.Packbot_Mat'"), NULL, LOAD_None, NULL)
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Packbot/Treads/packbot_largetread_Mat.packbot_largetread_Mat'"), NULL, LOAD_None, NULL);
	};
	*/
	//SoundVolume = 200;
	//CollisionRadius = 25;
	//CollisionHeight = 1;
	//bBlockActors = false;
	//bBlockPlayers = false;
	ValidJavelinTarget = 0;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	KParams = KParams0;
}

void APackbot::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	DisplayDebug(Canvas, YL, YPos);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("TurnDamping: " $ TurnDamping $ " On Ground: " $ bVehicleOnGround);
	YPos += YL;
	*/
}

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
	return KDriverLeave(bForceLeave);
	*/
}

void APackbot::Timer()
{
	/*
	Timer();
	if (Driver == nullptr || Health_Front_Right <= 0 || Health_Front_Left <= 0 || Health_Back_Left <= 0 || Health_Back_Right <= 0)
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
			Driver.AmbientSound = nullptr;
		}
	}
	*/
}

bool APackbot::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != None)
	{
		return false;
	}
	else
	{
		return TryToDrive(p);
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
