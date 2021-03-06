// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SUAVPlane/RavenUAV/RavenUAV.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/BaseSmokeEmitter.h"
#include "AA29/Object/Actor/Emitter/HelicopterDustCloudEffect/HelicopterDustCloudEffect.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_metal/em_bt_metal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_PG7Bexplosion/em_bt_PG7Bexplosion.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/M83SmokeEmitter/M83SmokeEmitter.h"
#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleHulkBurn/VehicleHulkBurn.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseHelicopterController/NPCBaseHelicopterController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseRavenController/NPCBaseRavenController.h"
#include "Particles/Emitter.h"

ARavenUAV::ARavenUAV()
{
	emitDust.SetNum(16);
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 1;
	KParams0->KInertiaTensor[3] = 3;
	KParams0->KInertiaTensor[5] = 3.5;
	KParams0->KLinearDamping = 0;
	KParams0->KAngularDamping = 0;
	KParams0->bKNonSphericalInertia = true;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bKStayUpright = true;
	KParams0->bKAllowRotate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 0.5;
	sndCruising = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Helicopter/blackhawk/BHRotorCruise_Cue.BHRotorCruise_Cue'"), NULL, LOAD_None, NULL);
	sndHover = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Helicopter/blackhawk/BHRotorHover_Cue.BHRotorHover_Cue'"), NULL, LOAD_None, NULL);
	KillHealth = 1000;
	fpOriginalMaxRotorSpeed = 250;
	SmokeGeneratorAttachmentBone = "MainRotor";
	UprightStiffness = 100;
	UprightDamping = 90;
	LongDamping = 0.1;
	LatDamping = 0.1;
	UpDamping = 0.1;
	TurnTorqueFactor = 350;
	TurnTorqueMax = 150;
	TurnDamping = 45;
	MaxYawRate = 2;
	PitchTorqueMax = 10;
	PitchDamping = 40;
	RollTorqueMax = 10;
	RollDamping = 50;
	RotorSpeedAccelRateMax = 160;
	RotorSpeedForceFactor = 1;
	RotorSpeedIdle = 20;
	RotorSpeedMax = 250;
	TailRotorBoneName = "TailRotor";
	RotorBoneName = "MainRotor";
	RotorBoneAxis = EAA2_Axis::AXIS_Y;
	RotorBoneSpeedScale = 1000;
	RotorBoneSpeedMax = 1000000;
	VehicleMass = 4;
	bDrawDriverInTP = true;
	bFPNoZFromCameraPitch = true;
	DriverBone = "Pilot";
	DrivePos = FVector(0, 0, -15);
	bPlayDrivingAnimations = false;
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100) };
	EntryPosition = FVector(0, -165, -80);
	EntryRadius = 180;
	FPCamPos = FVector(160, 0, 120);
	FPCamViewOffset = FVector(90, 0, 0);
	TPCamDistance = 1400;
	TPCamLookat = FVector(-50, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 250);
	bIsHelicopter = true;
	bIsUAV = true;
	bSusceptibleToSmallArms = true;
	//SightRadius = 27000;
	//bIgnoresFog = true;
	//AmbientSoundScaling = 2;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Helicopter/Raven.Raven'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 200;
	//CollisionHeight = 60;
	//bBlockProjectiles = true;
	KParams = KParams0;
}

void ARavenUAV::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	YL = 10;
	YPos += YL;
	YPos += YL;
	//Canvas->SetPos(4, YPos);
}

void ARavenUAV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetNetMode() != ENetMode::NM_Client)
	{
		fpRealAltitude = Cast<ANPCBaseRavenController>(Controller)->fpRealAltitude;
	}
}

void ARavenUAV::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	SetTimer(0.25, true);
	*/
}

void ARavenUAV::UAVTakeOff()
{
}

void ARavenUAV::UAVTurnLeft()
{
}

void ARavenUAV::UAVTurnRight()
{
}

void ARavenUAV::UAVSetThrottle(float fpThrottle)
{
}

void ARavenUAV::UAVSetAileron(float fpAngle)
{
}

void ARavenUAV::UAVMoveElevator(float fpDelta)
{
}

void ARavenUAV::UAVSetElevator(float fpAngle)
{
}

void ARavenUAV::UAVSetVerticalVelocity(float fpVelocity)
{
}

void ARavenUAV::UAVSetHorizontalVelocity(float fpVelocity)
{
}

void ARavenUAV::UAVMoveRudder(float fpRudderIncrement)
{
}

void ARavenUAV::UAVSetRudder(float fpRudderSetting)
{
}

void ARavenUAV::UAVGear(bool bGearUp)
{
}

void ARavenUAV::UAVLand()
{
}

void ARavenUAV::UAVEnableAutoPilot(bool bEnable)
{
}

float ARavenUAV::UAVGetRadioStrength()
{
	return 1;
}

void ARavenUAV::Destroyed()
{
	/*
	Log("Destroyed Raven in state " + FString::FromInt(GetStateName()));
	if (SmokeGenerator != nullptr)
	{
		SmokeGenerator.Destroy();
	}
	if ((Controller == nullptr) || (Cast<ANPCBaseHelicopterController>(Controller) == nullptr))
	{
		Super::Destroyed();
		return;
	}
	Cast<ANPCBaseHelicopterController>(Controller).CleanupCrew();
	Controller.Destroy();
	Controller = nullptr;
	Super::Destroyed();
	*/
}

void ARavenUAV::Timer()
{
	/*
	FVector vNoVertVel = FVector(0, 0, 0);
	float fpAltitude = 0;
	int32 iEmitter = 0;
	CheckSmokeGenerator();
	Super::Timer();
	vNoVertVel = Velocity;
	vNoVertVel.Z = 0;
	if (VSize(vNoVertVel) < float(10))
	{
		if (AmbientSound != sndHover)
		{
			AmbientSound = sndHover;
			bFullVolume = true;
			SoundRadius = 250;
			AmbientSoundScaling = 10;
		}
		SoundVolume = uint8((float(192) + (float(64) * ((fpHelicopterCollective + 1) / 2))));
	}
	else
	{
		if (AmbientSound != sndCruising)
		{
			AmbientSound = sndCruising;
			bFullVolume = true;
			SoundRadius = 250;
			AmbientSoundScaling = 10;
		}
		SoundVolume = uint8((float(192) + (float(64) * ((fpHelicopterCollective + 1) / 2))));
	}
	*/
}

bool ARavenUAV::UsedBy(APawn* User)
{
	//return Controller.UsedBy(User);
	return false;    //FAKE   /ELIZ

}

bool ARavenUAV::TryToDrive(APawn* p)
{
	return true;
}

void ARavenUAV::KDriverEnter(APawn* p)
{
}

bool ARavenUAV::KDriverLeave(bool bForceLeave)
{
	return true;
}
/*
void ARavenUAV::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  dtDamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	Log(string(this) + "." + FString::FromInt(Tag) + ".TakeDamage() Damage: " + FString::FromInt(Damage) + " Bone: " + Bone.Name);
	if (dtDamageType.Default.bBulletHit)
	{
		Spawn(Aem_bt_metal::StaticClass(), this, , HitLocation);
	}
	if ((Controller != nullptr) && Controller->IsA(AaAIController::StaticClass()))
	{
		Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, dtDamageType, Bone);
	}
	TriggerEvent(DamageEvent, this, instigatedBy);
	if ((KillHealth > 0) && ((Bone.Name ~= "MainRotor") || (Bone.Name == "Rotor")))
	{
		Controller.TakeDamage(Damage, instigatedBy, HitLocation, Momentum, dtDamageType, Bone, KillerController);
		Damage = FMath::Min(Damage, KillHealth);
		(KillHealth -= Damage);
		Health = KillHealth;
		if (DamageObjective != nullptr)
		{
			DamageObjective.NotifyLinkDamage(instigatedBy, Damage);
		}
		if (KillHealth <= 0)
		{
			TriggerEvent(KillEvent, this, instigatedBy);
			if (DamageObjective != nullptr)
			{
				DamageObjective.NotifyLinkKill(instigatedBy);
			}
			AmbientSound = nullptr;
			Log("UAV shot down");
			if ((Controller != nullptr) && Controller->IsA(AaAIController::StaticClass()))
			{
				Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, dtDamageType, Bone);
			}
		}
	}
}
*/

void ARavenUAV::HelicopterEngineSmoke(bool bEnable)
{
	/*
	bSmokeGeneratorOn = bEnable;
	if ((fpSmokeEndTime != 0) && (fpSmokeEndTime < GetWorld()->GetTimeSeconds()))
	{
		fpSmokeEndTime = (GetWorld()->GetTimeSeconds() + float(30));
	}
	*/
}

void ARavenUAV::HelicopterRotorSmoke(bool bEnable)
{
}

void ARavenUAV::HelicopterCockpitSmoke(bool bEnable)
{
}

void ARavenUAV::CheckSmokeGenerator()
{
	/*
	if (((((GetWorld()->GetNetMode() == NM_DedicatedServer) || (GetWorld()->GetNetMode() == NM_Standalone)) && bSmokeGeneratorOn) && (GetWorld()->GetTimeSeconds() > fpSmokeEndTime)) && (fpSmokeEndTime > 0))
	{
		bSmokeGeneratorOn = false;
		return;
	}
	if ((SmokeGenerator != nullptr) && (!bSmokeGeneratorOn))
	{
		SmokeGenerator.Kill();
		SmokeGenerator = nullptr;
		return;
	}
	if (bSmokeGeneratorOn && (SmokeGenerator == nullptr))
	{
		Log(string(this) + "CheckSmokeGenerator() Turning smoke on with  bSmokeGeneratorOn: " + FString::FromInt(bSmokeGeneratorOn) + "  SmokeGenerator: " + FString::FromInt(SmokeGenerator));
		SpawnSmokeGenerator(60);
	}
	*/
}

void ARavenUAV::SpawnSmokeGenerator(float fpSmokeLengthSeconds)
{
	/*
	SmokeGenerator = Spawn(AM83SmokeEmitter::StaticClass(), this, , Location, FRotator(16384, 0, 0));
	if (SmokeGenerator == nullptr)
	{
		bSmokeGeneratorOn = false;
		return;
	}
	Log("Created smoke generator: " + FString::FromInt(SmokeGenerator) + ", attaching to " + FString::FromInt(SmokeGeneratorAttachmentBone));
	SmokeGenerator.SetBase(this);
	AttachToBone(SmokeGenerator, SmokeGeneratorAttachmentBone);
	SmokeGenerator._EffectDuration = fpSmokeLengthSeconds;
	fpSmokeEndTime = (GetWorld()->GetTimeSeconds() + fpSmokeLengthSeconds);
	*/
}

void ARavenUAV::StartSmokeGenerator()
{
	//bSmokeGeneratorOn = true;
}

void ARavenUAV::SpawnDestructionEffects()
{
	AEmitter* DestructionEffect = nullptr;
	/*
	DestructionEffect = Spawn(AVehicleHulkBurn::StaticClass(), this);
	DestructionEffect.SetBase(this);
	DestructionEffect = Spawn(Aem_bt_PG7Bexplosion::StaticClass(), this);
	DestructionEffect.SetBase(this);
	*/
}

void ARavenUAV::Landed(FVector HitNormal)
{
	if (Controller != nullptr)
	{
		//Controller->Landed(HitNormal);
	}
}

void ARavenUAV::HelicopterForceRotorMaxToIdleSpeed()
{
	//RotorSpeedMax = RotorSpeedIdle;
}

void ARavenUAV::HelicopterRestoreRotorMaxSpeed()
{
	//RotorSpeedMax = fpOriginalMaxRotorSpeed;
}
