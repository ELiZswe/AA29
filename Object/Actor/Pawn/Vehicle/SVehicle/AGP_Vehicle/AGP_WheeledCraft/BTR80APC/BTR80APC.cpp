// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/BTR80APC/BTR80APC.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/DamageType/RocketRPGDamage/RocketRPGDamage.h"
#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleFireHeavySmokeLarge/VehicleFireHeavySmokeLarge.h"
#include "AA29/Object/DamageType/RocketAT4Damage/RocketAT4Damage.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/RocketExplosionDamage/RocketJavelinDamage/RocketJavelinDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/RocketImpact/JavelinImpactDamage.h"
#include "AA29/Object/DamageType/CROWS_Mk19Damage/CROWS_Mk19Damage.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/DamageType/AGP_DamageType/GrenadeImpact/SpecialGrenadeImpact.h"
#include "AA29/Object/DamageType/AGP_DamageType/RocketImpact/Mortar_120mm_ImpactDamage.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/BTR60_DestroyedBody/BTR60_DestroyedBody.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BTR80_Gunner/BTR80_Gunner.h"

ABTR80APC::ABTR80APC()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 1;
	KParams0->KInertiaTensor[3] = 3;
	KParams0->KInertiaTensor[5] = 3;
	KParams0->KCOMOffset = FVector(-0.3, 0, 0);
	KParams0->KLinearDamping = 0.08;
	KParams0->KAngularDamping = 0.05;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 2400;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 1;
	KParams0->KImpactThreshold = 500;
	USVehicleWheel* RWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel1->bPoweredWheel = true;
	RWheel1->SteerType = EVehicleSteerType::VST_Steered;
	RWheel1->BoneName = "Wheel_R_01_bone";
	RWheel1->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	RWheel1->WheelBoneOffset = FVector(-10, 0, 0);
	RWheel1->WheelRadius = 37;
	USVehicleWheel* RWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel2->bPoweredWheel = true;
	RWheel2->SteerType = EVehicleSteerType::VST_Steered;
	RWheel2->BoneName = "Wheel_R_02_bone";
	RWheel2->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	RWheel2->WheelBoneOffset = FVector(10, 0, 0);
	RWheel2->WheelRadius = 37;
	USVehicleWheel* RWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel3->bPoweredWheel = true;
	RWheel3->BoneName = "Wheel_R_03_bone";
	RWheel3->WheelBoneOffset = FVector(-10, 0, 0);
	RWheel3->WheelRadius = 37;
	USVehicleWheel* RWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel4->bPoweredWheel = true;
	RWheel4->BoneName = "Wheel_R_04_bone";
	RWheel4->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	RWheel4->WheelBoneOffset = FVector(10, 0, 0);
	RWheel4->WheelRadius = 37;
	USVehicleWheel* LWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel1->bPoweredWheel = true;
	LWheel1->SteerType = EVehicleSteerType::VST_Steered;
	LWheel1->BoneName = "Wheel_L_01_bone";
	LWheel1->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	LWheel1->WheelBoneOffset = FVector(-10, 0, 0);
	LWheel1->WheelRadius = 37;
	USVehicleWheel* LWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel2->bPoweredWheel = true;
	LWheel2->SteerType = EVehicleSteerType::VST_Steered;
	LWheel2->BoneName = "Wheel_L_02_bone";
	LWheel2->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	LWheel2->WheelBoneOffset = FVector(10, 0, 0);
	LWheel2->WheelRadius = 37;
	USVehicleWheel* LWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel3->bPoweredWheel = true;
	LWheel3->BoneName = "Wheel_L_03_bone";
	LWheel3->WheelBoneOffset = FVector(-10, 0, 0);
	LWheel3->WheelRadius = 37;
	USVehicleWheel* LWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel4->bPoweredWheel = true;
	LWheel4->BoneName = "Wheel_L_04_bone";
	LWheel4->WheelBoneOffset = FVector(10, 0, 0);
	LWheel4->WheelRadius = 37;
	WeaponBoneHack = true;
	WheelSoftness = 0.02;
	WheelPenScale = 2.1;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.121;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
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
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.38,0.32,0.53,0.87,1.35 };
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
	//PositionTypes(0) = ({ ABTR80_Gunner::StaticClass(),"Weapon_1_Bone","BTR80_root",FVector(0, 0, 0),FVector(0, 0, 0),FRotator(0,0,0) });
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/stryker/STRYKER_Idle_Lp_3_Cue.STRYKER_Idle_Lp_3_Cue'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/stryker/STRYKER_Start_3_Cue.STRYKER_Start_3_Cue'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/btr60/BTR60_Static_damage.BTR60_Static_damage'"), NULL, LOAD_None, NULL);
	//DestroyedModelClass = ABTR60_DestroyedBody::StaticClass();
	DestructionLinearMomentum = FRange({ 250000, 400000});
	DestructionAngularMomentum = FRange({ 100, 150 });
	Health_Front_Left = 100;
	Health_Front_Right = 100;
	Health_Back_Left = 100;
	Health_Back_Right = 100;
	bUseNewWheelDamage = true;
	NewDamageInfo = {
		FsDamageInfo({ URocketRPGDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.34,0.34,0.34,0.51,0,0,0,0,0,0,0,0.5}),
		FsDamageInfo({ URocketAT4Damage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.7,0.7,1,1,0.5,0.5,0.5,0.5,0.5,0,0,1 }),
		FsDamageInfo({ URocketJavelinDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),1,1,1,1,0,0,0,0,0,0,0,0.5 }),
		FsDamageInfo({ UJavelinImpactDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),1,1,1,1,0,0,0,0,0,0,0,1 }),
		FsDamageInfo({ UCROWS_Mk19Damage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.75,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0,0,1 }),
		FsDamageInfo({ UProjectileDamageLargeArms::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),2,2,2,2,2,2,2,2,2,0,0,2 }),
		FsDamageInfo({ USpecialGrenadeImpact::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.75,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0,0,1 }),
		FsDamageInfo({ UMortar_120mm_ImpactDamage::StaticClass(),AVehicleFireHeavySmokeLarge::StaticClass(),0.65,0.45,0.45,0.45,0.45,0.45,0.5,0.5,0.5,0,0,1 })
	};
	bEjectPassengersWhenFlipped = false;
	bDriverCannotLeaveVehicle = true;
	ImpactDamageMult = 0.001;
	bBulletImpactSparks = true;
	SmokeGeneratorAttachmentBone = "Exhaust_L_bone";
	WheelBones = { "Wheel_L_01_bone","Wheel_L_02_bone","Wheel_L_03_bone","Wheel_L_04_bone","Wheel_R_01_bone","Wheel_R_02_bone","Wheel_R_03_bone","Wheel_R_04_bone" };
	UndercarriageBones = { "body_root","seat_driver_bone" };
	Wheels = { RWheel1,RWheel2,RWheel3,RWheel4,LWheel1,LWheel2,LWheel3,LWheel4 };
	VehicleMass = 8;
	bNPCDriverCanUseSmoke = true;
	bDrawMeshInFP = true;
	bCanFlip = false;
	Team = 255;
	DriverBone = "BTR80_root";
	DriveAnim = "CrhNo";
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100),FVector(0, -165, -100),FVector(0, 165, -100) };
	FPCamPos = FVector(20, -35, 102);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	bPredict_Collision_MoveToward = true;
	Predict_Collision_Distance = 1150;
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a BTR-80";
	VehicleNameString = "BTR-80";
	ObjectiveGetOutDist = 1500;
	bAIDriversOnly = true;
	GroundSpeed = 350;
	HealthMax = 1000;
	Health = 1000;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AAO_Vehicles/BTR80.BTR80'"), NULL, LOAD_None, NULL);
	//SoundRadius = 500;
	//CollisionRadius = 300;
	//CollisionHeight = 75;
	ValidJavelinTarget = 2;
	KParams = KParams0;
}

void ABTR80APC::PostBeginPlay()
{
	FRotator newRot = FRotator(0,0,0);
	if (WeaponBoneHack)
	{
		//newRot = GetBoneRotation('Weapon_1_Bone');
		//newRot.Yaw = 32768;
		//newRot.Pitch -= 32768;
		//newRot.Roll += 32768;
		//SetBoneRotation('Weapon_1_Bone', newRot);
	}
	Super::PostBeginPlay();
}

AVehicle* ABTR80APC::FindEntryVehicle(APawn* p)
{
	return nullptr;
}

bool ABTR80APC::TryToDrive(APawn* p)
{
	if (Cast<AHumanController>(p->Controller) != nullptr)
	{
		return false;
	}
	else
	{
		return Super::TryToDrive(p);
	}
	return false;    //FAKE   /ELiZ
}

void ABTR80APC::KDriverEnter(APawn* p)
{
	float StartupDelay = 0;
	Super::KDriverEnter(p);
	if (IdleSound != nullptr)
	{
		if (StartUpSound != nullptr)
		{
			//StartupDelay = Abs(GetSoundDuration(StartUpSound) - 0.2);
			//SetCustomTimer(StartupDelay, false, 'IdleSoundTimer');
		}
	}
	if (StartUpSound != nullptr)
	{
		//PlaySound(StartUpSound, 0, 1);
	}
}

void ABTR80APC::IdleSoundTimer()
{
	//AmbientSound = IdleSound;
}

/*
void ABTR80APC::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	if (InDamageType == ASpecialGrenadeImpact::StaticClass())
	{
		Damage = 125;
	}
	TakeDamage(Damage, instigatedBy, HitLocation, Momentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
}*/
