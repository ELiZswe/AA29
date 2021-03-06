// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/Info/AnnouncerVoice/AnnouncerVoice.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/BaseSmokeEmitter.h"
#include "AA29/Object/Actor/Projector/HeadlightProjector/HeadlightProjector.h"
#include "AA29/Object/Actor/Light/HeadlightCorona/HeadlightCorona.h"
#include "AA29/Object/Actor/Emitter/ImpactSparks/ImpactSparks.h"
#include "AA29/Object/Actor/Emitter/DamagedEffect/DamagedEffect.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/AGP_DestroyedVehicleModels.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParams.h"
#include "AA29/AA29.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/AGP_VehicleReplicationInfo/AGP_VehicleReplicationInfo.h"
#include "AA29/Object/DamageType/DamRanOver/DamRanOver.h"
#include "AA29/Object/DamageType/AGP_DamageType/DamTypeVehicle/DamTypeVehicle.h"
#include "AA29/Object/DamageType/Drowned/Drowned.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_metal/em_bt_metal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_PG7Bexplosion/em_bt_PG7Bexplosion.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/M83SmokeEmitter/M83SmokeEmitter.h"
#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleHulkBurn/VehicleHulkBurn.h"
#include "Engine/Canvas.h"
#include "Particles/Emitter.h"

AAGP_Vehicle::AAGP_Vehicle()
{
	LastDamageZoneStates.SetNum(22);
	DamageZoneStates.SetNum(22);
	bEnableChangePosition = true;
	DriverRoot = "Pelvis";
	bHasAltFire = true;
	EngineIdleVolume = 0.3;
	EngineIdlePitch = 1;
	ViewShakeRadius = 100;
	DisintegrationHealth = -50;
	//DestructionAngularMomentum = Min = Min = 50 Max = Max = 50;
	TimeBetweenImpactExplosions = 0.1;
	ExplosionDamage = 100;
	ExplosionRadius = 300;
	ExplosionMomentum = 60000;
	//ExplosionDamageType = ADamTypeVehicle::StaticClass();
	//DamagedEffectClass = ADamagedEffect::StaticClass();
	bOnlyViewShakeIfDriven = true;
	bEjectPassengersWhenFlipped = true;
	ShakeRotMag = FVector(0, 0, 250);
	ShakeRotRate = FVector(0, 0, 2500);
	ShakeRotTime = 6;
	ShakeOffsetMag = FVector(0, 0, 10);
	ShakeOffsetRate = FVector(0, 0, 00);
	ShakeOffsetTime = 10;
	ImpactDamageTicks = 10;
	ImpactDamageThreshold = 5000;
	ImpactDamageMult = 0.00015;
	ImpactDamageRadius = 175;
	//SparkEffectClass = AImpactSparks::StaticClass();
	SparkAdvanceFactor = 1.5;
	MinRunOverWarningAim = 0.88;
	DamageStateParticleTimeScaler = 1;
	CurrentZoneTimeToKill = 9999999;
	//bZeroPCRotOnEntry = false;
	//bEnterringUnlocks = true;
	//Team = 0;
	//DriveAnim = "None";
	//WaterDamage = 150;
	//VehicleDrowningDamType = ADrowned::StaticClass();
	//VehicleReplicationInfoClass = AAGP_VehicleReplicationInfo::StaticClass();
	//bSpecialHUD = true;
	//bSetPCRotOnPossess = false;
	//bCanTeleport = false;
	//SoundRadius = 200;
	//TransientSoundRadius = 600;
	//bBulletRicochet = true;
}

/*
State VehicleDestroyed
{
	Function CallDestroy()
	{
		DebugLog(DEBUG_Vehicle,"VehicleDestroyed::CallDestroy() called: Destroy_Track");
	}
	Function Died(AController* Killer, class<DamageType>  DamageType, Vector HitLocation, Vector HitDir, FBoneInfo Bone)
	{
	}
Begin:
	DebugLog(DEBUG_Vehicle,"VehicleDestroyed state: vehicle_damage");
	DestroyAppearance();
}
*/

/*
State VehicleDisintegrated
{
	Function CallDestroy()
	{
		DebugLog(DEBUG_Vehicle,"VehicleDisintegrated::CallDestroy() called, Destroy_Track ");
	}
	Function Died(AController* Killer, class<DamageType>  DamageType, Vector HitLocation, Vector HitDir, FBoneInfo Bone)
	{
	}
Begin:
	DebugLog(DEBUG_Vehicle,"VehicleDisintegrated state: vehicle_damage");
	if (! bDestroyAppearance)
	{
		DestroyAppearance();
	}
}
*/

/*
replication
{
	reliable if(((bNetOwner && bNetDirty) && (Role == ROLE_Authority)))
		ActiveWeapon;
	reliable if((bNetDirty && (Role == ROLE_Authority)))
		ExplosionCount, DamageZoneStates, bDestroyAppearance, bDisintegrateVehicle, bSmokeGeneratorOn, OutOfBounds;
	reliable if((Role == ROLE_Authority))
		KillControllerOutOfBounds, AlertClientReturnedToCombat, NotifyControllerOutOfBounds, ClientRegisterVehicleWeapon, bPlayedStartup;
	reliable if((Role < ROLE_Authority))
		ServerChangePosition, ServerVerifyVehicleWeapon;
}
*/


//native void SetVehicleZeroExtentCollision(bool bSet);
void AAGP_Vehicle::SetVehicleZeroExtentCollision(bool bSet)
{

}

//native void DamageOccupants(int32 Damage, Actor Instigator, FVector StartLoc, FRotator TestAngle, UaDamageType* DamageType);
void AAGP_Vehicle::DamageOccupants(int32 Damage, AActor* aInstigator, FVector StartLoc, FRotator TestAngle, UaDamageType* DamageType)
{

}

//native void WeaponSeePawn(AActor* TargetActor);
bool AAGP_Vehicle::WeaponSeePawn(AActor* TargetActor)
{
	return false;    //FAKE   /ELiZ
}

//native void PlayIdleSound();
void AAGP_Vehicle::PlayIdleSound()
{

}

void AAGP_Vehicle::Trigger(AActor* Other, APawn* EventInstigator)
{
	ANPCBasePreCrewedVehicleControlle* NPCController = nullptr;
	NPCController = Cast<ANPCBasePreCrewedVehicleControlle>(Controller);
	/*
	if (NPCController != nullptr)
	{
		NPCController.NotifyTrigger(Other, EventInstigator);
	}
	Trigger(Other, EventInstigator);
	*/
}

void AAGP_Vehicle::PostBeginPlay()
{
	int32 i = 0;
	if (GetNetMode() !=  ENetMode::NM_DedicatedServer)
	{
		for (i = 0; i < AttachedActorTypes.Num(); i++)
		{
			/*
			AttachedActors[i] = Spawn(AttachedActorTypes[i].attachClass, this, , Location);
			AttachToBone(AttachedActors[i], AttachedActorTypes[i].AttachBone);
			*/
		}
	}
	Super::PostBeginPlay();
	//SetTimer(1, true);
}

void AAGP_Vehicle::NotifyEnemyLockedOn()
{
	int32 i = 0;
	Super::NotifyEnemyLockedOn();
	if (LockedOnSound != nullptr)
	{
		//PlaySound(LockedOnSound);
	}
	for (i = 0; i < Positions.Num(); i++)
	{
		Positions[i]->NotifyEnemyLockedOn();
	}
}

void AAGP_Vehicle::NotifyEnemyLostLock()
{
	int32 i = 0;
	Super::NotifyEnemyLostLock();
	for (i = 0; i < Positions.Num(); i++)
	{
		Positions[i]->NotifyEnemyLostLock();
	}
}

bool AAGP_Vehicle::HasWeapon()
{
	return (ActiveWeapon < VehicleWeapons.Num());
}

UMaterialInstance* AAGP_Vehicle::LookupCollisionMaterial(AActor* SearchActor)
{
	int32 i = 0;
	FString ResolvedMaterialString = "";
	UMaterialInstance* CollisionMaterial = nullptr;
	/*
	for (i = 0; i < DamageZones.Num(); i++)
	{
		if (DamageZones[i]->bControlsExternalMesh && SearchActor == DamageZones[i]->MeshOwner)
		{
			ResolvedMaterialString = "T_AAO_Vehicles.Collision.Damage_" + i + "_Zone";
			CollisionMaterial = Cast<UMaterialInstance>(DynamicLoadObject(ResolvedMaterialString, Class'Material'));
			return CollisionMaterial;
		}
	}
	*/
	return nullptr;
}

bool AAGP_Vehicle::CanAttack(AActor* Other)
{
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		return VehicleWeapons[ActiveWeapon]->CanAttack(Other);
	}
	return false;
}

void AAGP_Vehicle::Deploy()
{
}

void AAGP_Vehicle::MayUndeploy()
{
}

bool AAGP_Vehicle::TooCloseToAttack(AActor* Other)
{
	int32 NeededPitch = 0;
	int32 i = 0;
	bool bControlledWeaponPawn = false;
	/*
	if (VSize((Location - Other.Location)) > float(2500))
	{
		return false;
	}
	*/
	if (!HasWeapon())
	{
		if (Positions.Num() == 0)
		{
			return false;
		}
		for (i = 0; i < Positions.Num(); i++)
		{
			/*
			if (Positions[i]->Controller != nullptr)
			{
				bControlledWeaponPawn = true;
				if (!Positions[i]->TooCloseToAttack(Other))
				{
					return false;
				}
			}
			*/
		}
		if (!bControlledWeaponPawn)
		{
			return false;
		}
		return true;
	}
	//NeededPitch = rotator((Other.Location - VehicleWeapons[ActiveWeapon].WeaponFireLocation)).Pitch;
	//NeededPitch = (NeededPitch & 65535);
	return (LimitPitch(NeededPitch) != NeededPitch);

}

void AAGP_Vehicle::ChooseFireAt(AActor* A)
{
	/*
	if (!bHasAltFire)
	{
		Fire(0);
	}
	else
	{
		if (ActiveWeapon < VehicleWeapons.Num())
		{
			if (VehicleWeapons[ActiveWeapon].BestMode() == 0)
			{
				Fire(0);
			}
			else
			{
				AltFire(0);
			}
		}
	}
	*/
}

float AAGP_Vehicle::RefireRate()
{
	/*
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			return VehicleWeapons[ActiveWeapon].AIInfo[1].RefireRate;
		}
		else
		{
			return VehicleWeapons[ActiveWeapon].AIInfo[0].RefireRate;
		}
	}
	*/
	return 0;
}

bool AAGP_Vehicle::IsFiring()
{
	return ((ActiveWeapon < VehicleWeapons.Num()) && (bWeaponisFiring || (bWeaponisAltFiring && bHasAltFire)));
}

bool AAGP_Vehicle::NeedToTurn(FVector targ)
{
	return (!((ActiveWeapon < VehicleWeapons.Num()) && VehicleWeapons[ActiveWeapon]->bCorrectAim));
}

bool AAGP_Vehicle::FireOnRelease()
{
	/*
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			return VehicleWeapons[ActiveWeapon].AIInfo[1].bFireOnRelease;
		}
		else
		{
			return VehicleWeapons[ActiveWeapon].AIInfo[0].bFireOnRelease;
		}
	}
	*/
	return false;
}

float AAGP_Vehicle::ModifyThreat(float Current, APawn* Threat)
{
	/*
	if (Threat.bCanFly && ActiveWeapon < VehicleWeapons.Num() && !VehicleWeapons[ActiveWeapon].AIInfo[0].bInstantHit)
	{
		return Current - 3;
	}
	*/
	return Current;
}

bool AAGP_Vehicle::ChangedReservation(APawn* p)
{
	return false;
}

float AAGP_Vehicle::ReservationCostMultiplier()
{
	return 1;
}

float AAGP_Vehicle::NewReservationCostMultiplier(APawn* p)
{
	return ReservationCostMultiplier();
}

bool AAGP_Vehicle::SpokenFor(AController* C)
{
	return false;
}

void AAGP_Vehicle::SetReservation(AController* C)
{
}

AVehicle* AAGP_Vehicle::OpenPositionFor(APawn* p)
{
	int32 i = 0;
	if (Controller == nullptr)
	{
		return this;
	}
	/*
	if (!Controller->SameTeamAs(p->Controller))
	{
		return nullptr;
	}
	*/
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i]->Controller == nullptr)
		{
			return Positions[i];
		}
	}
	return nullptr;
}

void AAGP_Vehicle::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	//DisplayVehicleDebug(Canvas, YL, YPos);
}

void AAGP_Vehicle::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
		int32 i = 0;
	DisplayDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.DrawText(DebugInfo);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("AmbientSound: " + AmbientSound);
	for (i = 0; i < VehicleWeapons.Num(); i++)
	{
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.SetDrawColor(0, 0, 255);
		Canvas.DrawText("-- Weapon: " + i + " - " + VehicleWeapons[i]);
		YPos += YL;
		Canvas.SetPos(4, YPos);
		VehicleWeapons[i].DisplayDebug(Canvas, YL, YPos);
	}
	YPos += YL;
	DebugInfo = "";
	*/
}

void AAGP_Vehicle::PostNetBeginPlay()
{
	/*
	int32 i = 0;
	PostNetBeginPlay();
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		for (i = 0; i < DriverWeapons.Num(); i++)
		{
			VehicleWeapons[i] = Spawn(DriverWeapons[i].WeaponClass, this, , Location, FRotator(0 0 0));
			AttachToBone(VehicleWeapons[i], DriverWeapons[i].WeaponBone);
			if (!VehicleWeapons[i].bAimable)
			{
				VehicleWeapons[i].CurrentAim = FRotator(0 32768 0);
			}
		}
		if (ActiveWeapon < VehicleWeapons.Num())
		{
			PitchUpLimit = VehicleWeapons[ActiveWeapon].PitchUpLimit;
			PitchDownLimit = VehicleWeapons[ActiveWeapon].PitchDownLimit;
		}
		for (i = 0; i < PositionTypes.Num(); i++)
		{
			Positions[i] = Spawn(PositionTypes[i].VehiclePositionClass, this, , Location);
			if (VehicleReplicationInfo != nullptr)
			{
				Positions[i].VehicleReplicationInfo = VehicleReplicationInfo;
			}
			Positions[i].SetBase(this);
			Positions[i].AttachToVehicle(this, PositionTypes[i].WeaponBone);
			Positions[i].DriverBone = PositionTypes[i].PositionBone;
			Positions[i].DriverPosOffset = PositionTypes[i].PosOffset;
			Positions[i].DriverRotOffset = PositionTypes[i].RotOffset;
			Positions[i].FPCamPos = PositionTypes[i].FPCameraOffset;
			Positions[i].PositionsIndex = i;
			if (!Positions[i].bHasOwnHealth)
			{
				Positions[i].HealthMax = HealthMax;
			}
			Positions[i].ObjectiveGetOutDist = ObjectiveGetOutDist;
			if (Positions[i].Gun != nullptr)
			{
				ActiveWeapon = 0;
				VehicleWeapons[0] = Positions[i].Gun;
			}
		}
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer && Level.bUseHeadlights && !Level.bDropDetail || Level.DetailMode == 0)
	{
		HeadlightCorona.Num() = HeadlightCoronaOffset.Num();
		for (i = 0; i < HeadlightCoronaOffset.Num(); i++)
		{
			HeadlightCorona[i] = Spawn('HeadlightCorona', this, , Location + HeadlightCoronaOffset[i] >> Rotation);
			HeadlightCorona[i].SetBase(this);
			HeadlightCorona[i].SetRelativeRotation(FRotator(0 0 0));
			HeadlightCorona[i].Skins[0] = HeadlightCoronaMaterial;
			HeadlightCorona[i].MaxCoronaSize = HeadlightCoronaMaxSize * Level.HeadlightScaling;
		}
		if (HeadlightProjectorMaterial != nullptr && Level.DetailMode == 2)
		{
			HeadlightProjector = Spawn('HeadlightProjector', this, , Location + HeadlightProjectorOffset >> Rotation);
			HeadlightProjector.SetBase(this);
			HeadlightProjector.SetRelativeRotation(HeadlightProjectorRotation);
			HeadlightProjector.ProjTexture = HeadlightProjectorMaterial;
			HeadlightProjector.SetDrawScale(HeadlightProjectorScale);
			HeadlightProjector.CullDistance = ShadowCullDistance;
		}
	}
	if (PawnShadow != nullptr)
	{
		PawnShadow.Destroy();
	}
	if (Shadow != nullptr)
	{
		Shadow.Destroy();
	}
	SetTeamNum(Team);
	TeamChanged();
	for (i = 0; i < DefaultDamageZones.Num(); i++)
	{
		DamageZones[i] = new (None) UVehicleDamageZone::StaticClass();
	}
	CopyDefaultDamageZonesToDamageZones();
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		InitServerDamageZones();
	}
	else
	{
		if (Role < 4)
		{
			Positions.insert(0, PositionTypes.Num());
		}
	}
	*/
}

AActor* AAGP_Vehicle::GetPosition(int32 iPosition)
{
	if (iPosition < Positions.Num())
	{
		return Positions[iPosition];
	}
	else
	{
		return nullptr;
	}
}

FRotator AAGP_Vehicle::GetWeaponAim()
{
	return VehicleWeapons[0]->CurrentAim;
}

void AAGP_Vehicle::InitServerDamageZones()
{
	/*
	int32 i = 0;
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i] != nullptr)
		{
			if (Positions[i].GunClass != nullptr && Positions[i].Gun == nullptr)
			{
				DebugLog(DEBUG_Vehicle, this + " Position[" + i + "] doesn't have a gun spawned");
				return;
			}
		}
		else
		{
			DebugLog(DEBUG_Vehicle, "positions == nullptr in InitServerDamageZones");
			return;
		}
	}
	InitializeDamageZones();
	*/
}

void AAGP_Vehicle::IniExportDebugIniValues()
{
	/*
	StaticClearConfig();
	ClearConfig();
	IniExportDefaultDamageZonesToIni();
	IniExportParticleInfo();
	SaveConfig();
	*/
}

void AAGP_Vehicle::IniExportDefaultDamageZonesToIni()
{
	/*
	int32 i = 0;
	if (TestDamageZones.Num() != 0)
	{
		TestDamageZones.RemoveAt(0, TestDamageZones.Num());
	}
	TestDamageZones.insert(0, DefaultDamageZones.Num());
	for (i = 0; i < DefaultDamageZones.Num(); i++)
	{
		TestDamageZones[i]->ZoneName = DefaultDamageZones[i]->Name;
		TestDamageZones[i]->ZoneNumber = i;
		TestDamageZones[i]->ArmorThreshold = DefaultDamageZones[i]->ArmorThreshold;
		TestDamageZones[i]->MaxHitPoints = DefaultDamageZones[i]->MaxHitPoints;
		TestDamageZones[i]->DamageModifier = DefaultDamageZones[i]->DamageModifier;
		TestDamageZones[i]->bInitialSyncToVehicleHealth = BoolToByte(DefaultDamageZones[i]->bInitialSyncToVehicleHealth);
		TestDamageZones[i]->bNoPassDamageToVehicle = BoolToByte(DefaultDamageZones[i]->bNoPassDamageToVehicle);
		if (DefaultDamageZones[i]->DamageStates.Num() >= 2)
		{
			TestDamageZones[i]->DS1HealthPct = DefaultDamageZones[i]->DamageStates[1].DamagePct;
		}
		if (DefaultDamageZones[i]->DamageStates.Num() >= 3)
		{
			TestDamageZones[i]->DS2HealthPct = DefaultDamageZones[i]->DamageStates[2].DamagePct;
		}
	}
	SaveConfig();
	*/
}

FString AAGP_Vehicle::IniGetString(FString Value)
{
	return Value;
}

void AAGP_Vehicle::IniExportParticleInfo()
{
	/*
	int32 i = 0;
	if (ParticleInfo.Num() != 0)
	{
		ParticleInfo.RemoveAt(0, ParticleInfo.Num());
	}
	ParticleInfo.insert(0, DefaultDamageZones.Num());
	for (i = 0; i < DefaultDamageZones.Num(); i++)
	{
		ParticleInfo[i].ZoneName = DefaultDamageZones[i]->Name;
		if (DefaultDamageZones[i]->DamageStates.Num() >= 2)
		{
			ParticleInfo[i].DS1ParticleString = IniGetString(DefaultDamageZones[i]->DamageStates[1].VisualEffectClass);
		}
		if (DefaultDamageZones[i]->DamageStates.Num() >= 3)
		{
			ParticleInfo[i].DS2ParticleString = IniGetString(DefaultDamageZones[i]->DamageStates[2].VisualEffectClass);
		}
	}
	*/
}

void AAGP_Vehicle::ResetVehicleIni()
{
	/*
	StaticClearConfig();
	ClearConfig();
	IniExportDefaultDamageZonesToIni();
	*/
}

void AAGP_Vehicle::CannotAimAtEnemy()
{
	//NPCBasePreCrewedVehicleController(Controller).CannotAimAtEnemy();
}

void AAGP_Vehicle::IniImportDamageValues()
{
	/*
	int32 i = 0;
	if (TestDamageZones.Num() == DefaultDamageZones.Num())
	{
		DebugLog(DEBUG_Vehicle, "Importing damage zones properties from INI file for vehicle " + Self);
		for (i = 0; i < DefaultDamageZones.Num(); i++)
		{
			if (DefaultDamageZones[i] != nullptr)
			{
				DefaultDamageZones[i]->ArmorThreshold = TestDamageZones[i]->ArmorThreshold;
				DefaultDamageZones[i]->MaxHitPoints = TestDamageZones[i]->MaxHitPoints;
				DefaultDamageZones[i]->DamageModifier = TestDamageZones[i]->DamageModifier;
				DefaultDamageZones[i]->bInitialSyncToVehicleHealth = ByteToBool(TestDamageZones[i]->bInitialSyncToVehicleHealth);
				DefaultDamageZones[i]->bNoPassDamageToVehicle = ByteToBool(TestDamageZones[i]->bNoPassDamageToVehicle);
				if (DefaultDamageZones[i]->DamageStates.Num() >= 2)
				{
					DefaultDamageZones[i]->DamageStates[1].DamagePct = TestDamageZones[i]->DS1HealthPct;
				}
				if (DefaultDamageZones[i]->DamageStates.Num() >= 3)
				{
					DefaultDamageZones[i]->DamageStates[2].DamagePct = TestDamageZones[i]->DS2HealthPct;
				}
			}
		}
	}
	else
	{
		DebugLog(DEBUG_Vehicle, "Mismatch in TestDamageZones " + TestDamageZones.Num() + " and DefaultDamageZones " + DefaultDamageZones.Num() + " array size for " + Self);
	}
	*/
}

void AAGP_Vehicle::IniImportParticleValues()
{
	int32 i = 0;
	AEmitter* ParticleEffect = nullptr;
	/*
	DebugLog(DEBUG_Vehicle, "Importing particle properties from INI files for vehicle " + Self);
	for (i = 0; i < DefaultDamageZones.Num(); i++)
	{
		if (ParticleInfo.Num() <= i)
		{
			DebugLog(DEBUG_Vehicle, this @ "ParticleInfo[" + i + "] and above not defined in INI file: Vehicle_Particles");
			return;
		}
		if (DefaultDamageZones[i]->DamageStates.Num() >= 2)
		{
			if (Len(ParticleInfo[i].DS1ParticleString) > 0 && ParticleInfo[i].DS1ParticleString != "None")
			{
				ParticleEffect = class<Emitter>(DynamicLoadObject(ParticleInfo[i].DS1ParticleString, Class'Class'));
			}
			if (ParticleEffect != nullptr)
			{
				if (DefaultDamageZones[i]->DamageStates[1].VisualEffectClass != ParticleEffect)
				{
					DefaultDamageZones[i]->DamageStates[1].VisualEffectClass = ParticleEffect;
				}
				ParticleEffect = nullptr;
			}
			else
			{
				DebugLog(DEBUG_Vehicle, this @ "ParticleInfo[" + i + "].DS1ParticleString is not a valid particle! Vehicle_Particles");
			}
		}
		if (DefaultDamageZones[i]->DamageStates.Num() >= 3)
		{
			if (Len(ParticleInfo[i].DS2ParticleString) > 0 && ParticleInfo[i].DS2ParticleString != "None")
			{
				ParticleEffect = class<Emitter>(DynamicLoadObject(ParticleInfo[i].DS2ParticleString, Class'Class'));
			}
			if (ParticleEffect != nullptr)
			{
				if (DefaultDamageZones[i]->DamageStates[2].VisualEffectClass != ParticleEffect)
				{
					DefaultDamageZones[i]->DamageStates[2].VisualEffectClass = ParticleEffect;
				}
				ParticleEffect = nullptr;
			}
			else
			{
				DebugLog(DEBUG_Vehicle, this @ "ParticleInfo[" + i + "].DS2ParticleString is not a valid particle!: Vehicle_Particles");
			}
		}
	}
	*/
}

void AAGP_Vehicle::IniDetermineIniImports()
{
	/*
	if (bImportIniDamageZones && GetWorld()->GetNetMode() == 0)
	{
		IniImportDamageValues();
	}
	if (bImportIniParticleInfo && GetWorld()->GetNetMode() == 0)
	{
		IniImportParticleValues();
	}
	*/
}
void AAGP_Vehicle::CopyDefaultDamageZonesToDamageZones()
{
	/*
	int32 i = 0;
	IniDetermineIniImports();
	for (i = 0; i < DefaultDamageZones.Num(); i++)
	{
		if (DefaultDamageZones[i] != nullptr && DamageZones[i] != nullptr)
		{
			DamageZones[i]->CopyDamageZones(DefaultDamageZones[i]);
		}
	}
	IniExportDebugIniValues();
	*/
}
/*
void AAGP_Vehicle::ClientRegisterVehicleWeapon(AVehicleWeapon* W, int32 Index)
{
	
	if (W == nullptr)
	{
		ServerVerifyVehicleWeapon(Index);
	}
	else
	{
		VehicleWeapons[Index] = W;
	}
	
}
*/

void AAGP_Vehicle::ServerVerifyVehicleWeapon(int32 Index)
{
	/*
	if (Index < VehicleWeapons.Num() && VehicleWeapons[Index] != nullptr)
	{
		ClientRegisterVehicleWeapon(VehicleWeapons[Index], Index);
	}
	*/
}

AVehicle* AAGP_Vehicle::FindEntryVehicle(APawn* p)
{
	int32 X = 0;
	float dist = 0;
	float ClosestDist = 0;
	UVehicleEntryPoint* ClosestEntryPoint = nullptr;
	if (bAIDriversOnly)
	{
		return nullptr;
	}
	ClosestDist = 100000;
	/*
	for (X = 0; X < EntryPoints.Num(); X++)
	{
		DebugLog(DEBUG_Vehicle, "Checking EntryPoint: " + FString::FromInt(EntryPoints[X]));
		dist = VSize((p.Location - GetBoneCoords(EntryPoints[X].EntryBone).Origin));
		if ((dist < EntryPoints[X].EntryRadius) && (dist < ClosestDist))
		{
			ClosestDist = dist;
			ClosestEntryPoint = EntryPoints[X];
		}
	}
	if (ClosestEntryPoint == nullptr)
	{
		return nullptr;
	}
	DebugLog(DEBUG_Vehicle, "Closest Entry Point: " + FString::FromInt(ClosestEntryPoint.Name));
	if (ClosestEntryPoint.bDriverEntry && (Controller == nullptr))
	{
		return this;
	}
	for (X = 0; X < ClosestEntryPoint.PositionIndex.Num(); X++)
	{
		if (!Positions[ClosestEntryPoint.PositionIndex[X]].bDriving)
		{
			return Positions[ClosestEntryPoint.PositionIndex[X]];
		}
	}
	*/
	return nullptr;
}

bool AAGP_Vehicle::TryToDrive(APawn* p)
{
	int32 X = 0;
	APawn* OldPawn = nullptr;
	if (FlipTimeLeft > 0)
	{
		return false;
	}
	/*
	if (NeedsFlip())
	{
		Flip(Vector(p.Rotation), 1);
		return false;
	}
	if (!bTeamLocked && p.GetTeamNum() != Team)
	{
		for (X = 0; X < Positions.Num(); X++)
		{
			if (Positions[X].Driver != nullptr)
			{
				VehicleLocked(p);
				return false;
			}
		}
	}
	if (Driver != nullptr && Cast<AHumanController>(Controller) == nullptr && Cast<AHumanController>(p->Controller) != nullptr)
	{
		OldPawn = Driver;
		KDriverLeave(true);
		OldPawn.Destroy();
	}
	return TryToDrive(p);
	*/

	return false;    //FAKE    /ELiZ
}

void AAGP_Vehicle::IdleSoundTimer()
{
	PlayIdleSound();
	bPlayedStartup = true;
}

void AAGP_Vehicle::KDriverEnter(APawn* p)
{
	int32 X = 0;
	/*
	ResetTime = GetWorld()->GetTimeSeconds() - 1;
	Instigator = this;
	DebugLog(DEBUG_Vehicle, "Starting AGP_Vehicle::KDriverEnter");
	DebugLog(DEBUG_Vehicle, "do we have a driver animation? " + p.HasAnim(DriveAnim));
	KDriverEnter(p);
	CloseDoor(0);
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		VehicleWeapons[ActiveWeapon].bActive = true;
	}
	Driver.bSetPCRotOnPossess = false;
	for (X = 0; X < VehicleWeapons.Num(); X++)
	{
		if (VehicleWeapons[X] == nullptr)
		{
			VehicleWeapons.RemoveAt(X, 1);
			X--;
		}
		else
		{
			VehicleWeapons[X].NetUpdateFrequency = 20;
			ClientRegisterVehicleWeapon(VehicleWeapons[X], X);
		}
	}
	DebugLog(DEBUG_Vehicle, "Leaving AGP_Vehicle::KDriverEnter");
	*/
}

bool AAGP_Vehicle::KDriverLeave(bool bForceLeave)
{
	AController* C = nullptr;
	int32 X = 0;
	/*
	DebugLog(DEBUG_Vehicle, "AGP_Vehicle::KDriverLeave start");
	if (bDriverCannotLeaveVehicle)
	{
		if (FlipTimeLeft > 0)
		{
			return false;
		}
		if (NeedsFlip())
		{
			Flip(Vector(Rotation + FRotator(0 16384 0)), 1);
			return false;
		}
		return false;
	}
	C = Controller;
	if (KDriverLeave(bForceLeave) || bForceLeave)
	{
		if (C != nullptr)
		{
			C.Pawn.bSetPCRotOnPossess = C.Pawn.Default.bSetPCRotOnPossess;
			Instigator = C.Pawn;
		}
		for (X = 0; X < VehicleWeapons.Num(); X++)
		{
			VehicleWeapons[X].FlashCount = 0;
			VehicleWeapons[X].NetUpdateFrequency = VehicleWeapons[X].Default.NetUpdateFrequency;
		}
		return true;
	}
	else
	{
		return false;
	}
	*/

	return false;    //FAKE    /ELiZ
}

void AAGP_Vehicle::DriverDied()
{
	//Super::DriverDied();
}

AActor* AAGP_Vehicle::GetActiveWeaponSystem()
{
	return VehicleWeapons[ActiveWeapon];
}

void AAGP_Vehicle::SetActiveWeapon(int32 i)
{
	/*
	VehicleWeapons[ActiveWeapon].bActive = false;
	ActiveWeapon = i;
	VehicleWeapons[ActiveWeapon].bActive = true;
	PitchUpLimit = VehicleWeapons[ActiveWeapon].PitchUpLimit;
	PitchDownLimit = VehicleWeapons[ActiveWeapon].PitchDownLimit;
	*/
}

void AAGP_Vehicle::VehicleLocked(APawn* p)
{
}

void AAGP_Vehicle::DriverLeft()
{
	/*
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		VehicleWeapons[ActiveWeapon].bActive = false;
	}
	if (!bNeverReset && ParentFactory != nullptr && VSize(Location - ParentFactory.Location) > 5000 || !FastTrace(ParentFactory->GetActorLocation(), Location))
	{
		if (bKeyVehicle)
		{
			ResetTime = GetWorld()->GetTimeSeconds() + 15;
		}
		else
		{
			ResetTime = GetWorld()->GetTimeSeconds() + 30;
		}
	}
	Super::DriverLeft();
	*/
}

void AAGP_Vehicle::CheckReset()
{
}

int32 AAGP_Vehicle::NumPassengers()
{
	int32 Num = 0;
	/*
	int32 i = 0;
	
	if (Driver != nullptr)
	{
		Num = 1;
	}
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i].Driver != nullptr)
		{
			Num++;
		}
	}
	*/
	return Num;
}

AaAIController* AAGP_Vehicle::GetBotPassenger()
{
	int32 i = 0;
	for (i = 0; i < Positions.Num(); i++)
	{
		/*
		if (Cast<AAIController>(Positions[i].Controller) != nullptr)
		{
			return AIController(Positions[i].Controller);
		}
		*/
	}
	return nullptr;
}

APawn* AAGP_Vehicle::GetInstigator()
{
	/*
	int32 i = 0;
	if (Controller != nullptr)
	{
		return this;
	}
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i].Controller != nullptr)
		{
			return Positions[i];
		}
	}
	*/
	return this;
}

bool AAGP_Vehicle::IsVehicleEmpty()
{
	/*
	int32 i = 0;
	if (Driver != nullptr)
	{
		return false;
	}
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i].Driver != nullptr)
		{
			return false;
		}
	}
	*/
	return true;
}

bool AAGP_Vehicle::HasOccupiedTurret()
{
	/*
	int32 i = 0;
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i].Driver != nullptr)
		{
			return true;
		}
	}
	*/
	return false;
}

void AAGP_Vehicle::ClientKDriverEnter(APlayerController* PC)
{
	/*
	ClientKDriverEnter(PC);
	if (PC.bEnableGUIForceFeedback)
	{
		PC.ClientPlayForceFeedback(StartUpForce);
	}
	*/
}

void AAGP_Vehicle::ClientKDriverLeave(APlayerController* PC)
{
	/*
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		if (bWeaponisFiring)
		{
			VehicleWeapons[ActiveWeapon].ClientStopFire(PC, false);
		}
		if (bWeaponisAltFiring)
		{
			VehicleWeapons[ActiveWeapon].ClientStopFire(PC, true);
		}
	}
	if (PC.bEnableGUIForceFeedback)
	{
		PC.StopForceFeedback(StartUpForce);
	}
	Super::ClientKDriverLeave(PC);
	*/
}

void AAGP_Vehicle::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
	int32 X = 0;
	APlayerController* PC = nullptr;
	AController* C = nullptr;
	/*
	DebugLog(DEBUG_Vehicle, "Died from: " + DamageType);
	DebugLog(DEBUG_Vehicle, "Died Called: Destroy Track");
	if (bDeleteMe || Level.bLevelChange || bVehicleDestroyed)
	{
		return;
	}
	bVehicleDestroyed = true;
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 28, , "AGPVehicleDied");
	}
	if (Physics != 13)
	{
		Died(Killer, DamageType, HitLocation);
		return;
	}
	Health = FMath::Min(0, Health);
	if (Controller != nullptr)
	{
		C = Controller;
		if (C.bIsPlayer)
		{
			PC = Cast<APlayerController>(C);
			if (PC != nullptr)
			{
				ClientKDriverLeave(PC);
			}
			else
			{
				ClientClearController();
			}
			if (bRemoteControlled || bEjectDriver && Driver != nullptr && Driver.Health > 0)
			{
				C.UnPossess();
				C.Possess(Driver);
				if (bEjectDriver)
				{
					EjectDriver();
				}
				Driver = nullptr;
			}
			else
			{
				C.PawnDied(this);
			}
		}
		else
		{
			if (C->IsA(AaAIController::StaticClass()))
			{
				Level.Game.Killed(Killer, C, this, DamageType);
			}
		}
		if (Driver != nullptr)
		{
			if (!bRemoteControlled && !bEjectDriver)
			{
				if (!bDrawDriverInTP && PlaceExitingDriver())
				{
					Driver.StopDriving(this);
					Driver.DrivenVehicle = this;
				}
				Driver.TearOffMomentum = Velocity * 0.25;
				Driver.Died(Controller, ADamRanOver::StaticClass(), Driver.Location);
			}
			else
			{
				if (bEjectDriver)
				{
					EjectDriver();
				}
				else
				{
					KDriverLeave(false);
				}
			}
		}
		bDriving = false;
	}
	else
	{
		Level.Game.Killed(Killer, Cast<AController>(GetOwner()), this, DamageType);
	}
	if (Killer != nullptr)
	{
		TriggerEvent(Event, this, Killer.Pawn);
		Instigator = Killer.Pawn;
	}
	else
	{
		TriggerEvent(Event, this, None);
	}
	RanOverDamageType = DestroyedRoadKillDamageType;
	CrushedDamageType = DestroyedRoadKillDamageType;
	if (IsHumanControlled())
	{
		Cast<APlayerController>(Controller).ForceDeathUpdate();
	}
	for (X = 0; X < Positions.Num(); X++)
	{
		if (bRemoteControlled || bEjectDriver)
		{
			if (bEjectDriver)
			{
				Positions[X].EjectDriver();
			}
			else
			{
				Positions[X].KDriverLeave(false);
			}
		}
		Positions[X].Died(Killer, DamageType, HitLocation);
	}
	if (ParentFactory != nullptr)
	{
		ParentFactory.VehicleDestroyed(this);
		ParentFactory = nullptr;
	}
	GotoState('VehicleDestroyed');
	*/
}

void AAGP_Vehicle::Destroyed()
{
	/*
	int32 i = 0;
	DebugLog(DEBUG_Vehicle, this + " destroyed called: vehicle_damage");
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		for (i = 0; i < VehicleWeapons.Num(); i++)
		{
			VehicleWeapons[i].Destroy();
		}
		for (i = 0; i < Positions.Num(); i++)
		{
			Positions[i].Destroy();
		}
	}
	VehicleWeapons.Num() = 0;
	Positions.Num() = 0;
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		for (i = 0; i < HeadlightCorona.Num(); i++)
		{
			HeadlightCorona[i].Destroy();
		}
		HeadlightCorona.Num() = 0;
		if (HeadlightProjector != nullptr)
		{
			HeadlightProjector.Destroy();
		}
		for (i = 0; i < AttachedActors.Num(); i++)
		{
			AttachedActors[i].Destroy();
		}
		AttachedActors.Num() = 0;
	}
	CleanUpDamageZones();
	TriggerEvent(Event, this, None);
	*/
	Super::Destroyed();
}

void AAGP_Vehicle::CleanUpDamageZones()
{
	/*
	int32 i = 0;
	DebugLog(DEBUG_Vehicle, this + " CleanUpDamageZones");
	for (i = 0; i < DamageZones.Num(); i++)
	{
		if (DamageZones[i] != nullptr)
		{
			DamageZones[i]->MeshOwner = nullptr;
			DamageZones[i]->Destroyed();
		}
		DamageZones[i] = nullptr;
	}
	DamageZones.RemoveAt(0, DamageZones.Num());
	*/
}

void AAGP_Vehicle::VehicleCeaseFire(bool bWasAltFire)
{
	/*
	VehicleCeaseFire(bWasAltFire);
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		VehicleWeapons[ActiveWeapon].CeaseFire(Controller);
	}
	*/
}

void AAGP_Vehicle::TeamChanged()
{
	int32 i = 0;
	Super::TeamChanged();
	for (i = 0; i < VehicleWeapons.Num(); i++)
	{
		VehicleWeapons[i]->SetTeam(Team);
	}
}

void AAGP_Vehicle::ApplyDamageMomentum(FVector ForceVector, float Momentum, float NearestZoneDist, FVector ExplosionLocation, float DamageRadius, UaDamageType* DamageType)
{
	float MomentumDampingScale = 0;
	/*
	if (DamageType != nullptr)
	{
		Momentum *= DamageType.Default.VehicleMomentumScaling * MomentumMult;
	}
	if (DamageRadius > 0.1)
	{
		MomentumDampingScale = 1 - NearestZoneDist / DamageRadius;
	}
	else
	{
		MomentumDampingScale = 1 - NearestZoneDist;
	}
	MomentumDampingScale =FMath::Clamp(MomentumDampingScale, 0, 1);
	Momentum *= MomentumDampingScale;
	if (!bDeleteMe)
	{
		KAddImpulse(Momentum * ForceVector, ExplosionLocation);
	}
	*/
}

bool AAGP_Vehicle::TakeRadiusDamage(float DamageAmount, APawn* instigatedBy, FVector ExplosionLocation, float Momentum, UaDamageType* InDamageType, float DamageRadius)
{
	int32 i = 0;
	int32 j = 0;
	int32 NearestZone = 0;
	FVector BoneLoc = FVector(0,0,0);
	FVector NearHitVec = FVector(0, 0, 0);
	float damageScale = 0;
	float dist = 0;
	float NearestZoneDist = 0;
	float DamageDot = 0;
	TArray<int32> HitZoneNums = {};
	TArray<FVector> HitZoneLocations = {};
	TArray<float> HitZoneDist ={};
	float proctime = 0;
	float ActualDamage = 0;
	AController* Killer = nullptr;
	//Clock(proctime);
	NearestZoneDist = 100000000;
	/*
	for (i = 0; i < DamageZones.Num(); i++)
	{
		if (DamageZones[i]->DamageStates.Num() == 0 || DamageZones[i]->DamageStates[0].DamageBones[0] == "None")
		{
		}
		BoneLoc = GetBoneCoords(DamageZones[i]->DamageStates[0].DamageBones[0]).Origin;
		dist = VSize(BoneLoc - ExplosionLocation);
		if (dist < DamageRadius)
		{
			HitZoneNums[j] = i;
			HitZoneLocations[j] = BoneLoc;
			HitZoneDist[j] = dist;
			if (dist < NearestZoneDist)
			{
				NearestZone = j;
				NearestZoneDist = dist;
			}
			j++;
		}
	}
	if (HitZoneNums.Num() == 0)
	{
		return false;
	}
	NearHitVec = Normal(HitZoneLocations[NearestZone] - ExplosionLocation);
	if (Health > 0)
	{
		if (InDamageType == nullptr)
		{
			DebugLog(DEBUG_Vehicle, "No DamageType was given for TakeRadiusDamge() on " + Self);
			return false;
		}
		i = 0;
		if (i < HitZoneNums.Num())
		{
			ActualDamage = 0;
			if (bDamageSystemCompatibilityHack)
			{
				ActualDamage = DamageAmount;
			}
			else
			{
				if (InDamageType.Default.bOverrideDamageValues)
				{
					if (DamageZones[HitZoneNums[i]].bWheelZone)
					{
						ActualDamage = 0;
					}
					else
					{
						ActualDamage = DamageAmount;
					}
				}
				else
				{
					if (FMath::FRand() > 1 - FMax(0, 4 * HitZoneDist[i] / DamageRadius))
					{
						ActualDamage = 0;
					}
					else
					{
						ActualDamage = InDamageType.GetSplashDamage(DamageZones[HitZoneNums[i]].ArmorThreshold);
					}
				}
			}
			ActualDamage *= DamageZones[HitZoneNums[i]].DamageModifier;
			damageScale = 1 - FMax(0, HitZoneDist[i] / DamageRadius);
			FClamp(damageScale, 0, 1);
			if (InDamageType.Default.bOverrideDamageValues)
			{
				ActualDamage *= Loge(10 * damageScale);
			}
			else
			{
				if (i == NearestZone)
				{
					ActualDamage *= damageScale;
				}
				else
				{
					DamageDot = FMax(0, NearHitVec Dot Normal(HitZoneLocations[i] - HitZoneLocations[NearestZone]));
					FClamp(DamageDot, 0, 1);
					damageScale *= 1 - DamageDot;
					ActualDamage *= damageScale;
				}
			}
			if (ActualDamage <= 0)
			{
			}
			if (Health <= 0)
			{
				if (Driver != nullptr && bEjectDriver || bRemoteControlled)
				{
					if (bEjectDriver)
					{
						EjectDriver();
					}
					else
					{
						KDriverLeave(false);
					}
				}
				if (instigatedBy != nullptr)
				{
					Killer = instigatedBy.GetKillerController();
				}
				if (Killer == nullptr && InDamageType != nullptr && InDamageType.Default.bDelayedDamage)
				{
					Killer = DelayedDamageInstigatorController;
				}
				Died(Killer, InDamageType, ExplosionLocation);
			}
			else
			{
				i++;
			}
		}
	}
	UnClock(proctime);
	ApplyDamageMomentum(NearHitVec, Momentum, NearestZoneDist, ExplosionLocation, DamageRadius, InDamageType);
	DebugLog(DEBUG_Vehicle, "Vehicle " + this + " final health is " + Health + " and TakeRadiusDamage took " + proctime + " ms to run");
	*/
	return true;
}

void AAGP_Vehicle::TakeProjectileImpactDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	//TakeDamage(Damage, instigatedBy, HitLocation, Momentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
}

/*
void AAGP_Vehicle::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* InDamageType, optional FBoneInfo Bone, optional AController* KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	FName ClosestBone = "";
	float ActualDamage = 0;
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0,0,0);
	FVector Z = FVector(0,0,0);
	FVector TestLocation = FVector(0,0,0);
	Emitter* TempDamageParticles = nullptr;
	int32 DamInfoIndex = 0;
	int32 i = 0;
	float TempDist = 0;
	bool bHit_Right_Front = false;
	bool bHit_Right_Back = false;
	bool bHit_Left_Front = false;
	bool bHit_Left_Back = false;
	bool bCreateEffect = false;
	bool bWheelDamage = false;
	bool bTreadDamage = false;
	if (Health <= 0)
	{
		DebugLog(DEBUG_Vehicle, this + " Health already below 0, don't apply damage");
		return;
	}
	ClosestBone = GetClosestBone(HitLocation, FVector(0,0,0), TempDist);
	if (ClosestBone != "None" && bUseNewTreadDamage || bUseNewWheelDamage)
	{
		if (bUseNewTreadDamage)
		{
			i = 0;
			if (i < TreadBones.Num() - 1)
			{
				if (ClosestBone == TreadBones[i])
			}
			{
				i++;
			}
		}
		else
		{
			if (bUseNewWheelDamage)
			{
				for (i = 0; i < WheelBones.Num(); i++)
				{
					if (ClosestBone == WheelBones[i])
					{
						bWheelDamage = true;
					}
				}
			}
		}
	}
	GetAxes(Rotation, X, Y, Z);
	TestLocation = Normal(HitLocation - Location);
	if (Vector(Rotation) Cross FVector(0 0 1) Dot HitLocation - Location > 0)
	{
		if (TestLocation Dot X > 0)
		{
			bHit_Left_Front = true;
		}
		else
		{
			bHit_Left_Back = true;
		}
	}
	else
	{
		if (TestLocation Dot X > 0)
		{
			bHit_Right_Front = true;
		}
		else
		{
			bHit_Right_Back = true;
		}
	}
	if (bBulletImpactSparks && InDamageType.Default.bBulletHit)
	{
		TempDamageParticles = Spawn(Aem_bt_metal::StaticClass(), this, , HitLocation);
	}
	DamInfoIndex = 0;
	if (DamInfoIndex < NewDamageInfo.Num())
	{
		if (NewDamageInfo[DamInfoIndex].AcceptsDamage == InDamageType)
		{
			if (bTreadDamage)
			{
				if (bHit_Left_Front || bHit_Left_Back)
				{
					Health_Tread_Left -= Damage * NewDamageInfo[DamInfoIndex].AM_Tread_Left;
					if (Health_Tread_Left <= Default.Health_Tread_Left * NewDamageInfo[DamInfoIndex].DamageEffectPct)
					{
						bCreateEffect = true;
					}
					if (Health_Tread_Left <= 0)
					{
						bTreadDamage = false;
					}
				}
				else
				{
					if (bHit_Right_Front || bHit_Right_Back)
					{
						Health_Tread_Right -= Damage * NewDamageInfo[DamInfoIndex].AM_Tread_Right;
						if (Health_Tread_Right <= Default.Health_Tread_Right * NewDamageInfo[DamInfoIndex].DamageEffectPct)
						{
							bCreateEffect = true;
						}
						if (Health_Tread_Right <= 0)
						{
							bTreadDamage = false;
						}
					}
				}
			}
			else
			{
				if (bWheelDamage)
				{
					if (bHit_Left_Front || bHit_Left_Back)
					{
						Health_Wheels_Left -= Damage * NewDamageInfo[DamInfoIndex].AM_Wheels_Left;
						if (Health_Wheels_Left <= Default.Health_Wheels_Left * NewDamageInfo[DamInfoIndex].DamageEffectPct)
						{
							bCreateEffect = true;
						}
						if (Health_Wheels_Left <= 0)
						{
							bWheelDamage = false;
						}
					}
					else
					{
						if (bHit_Right_Front || bHit_Right_Back)
						{
							Health_Wheels_Right -= Damage * NewDamageInfo[DamInfoIndex].AM_Wheels_Right;
							if (Health_Wheels_Right <= Default.Health_Wheels_Right * NewDamageInfo[DamInfoIndex].DamageEffectPct)
							{
								bCreateEffect = true;
							}
							if (Health_Wheels_Right <= 0)
							{
								bWheelDamage = false;
							}
						}
					}
				}
			}
			if (bHit_Left_Front)
			{
				Health_Front_Left -= Damage * NewDamageInfo[DamInfoIndex].AM_Front_Left;
				if (Health_Front_Left <= Default.Health_Back_Left * NewDamageInfo[DamInfoIndex].DamageEffectPct)
				{
					bCreateEffect = true;
				}
			}
			else
			{
				if (bHit_Left_Back)
				{
					Health_Back_Left -= Damage * NewDamageInfo[DamInfoIndex].AM_Back_Left;
					if (Health_Back_Left <= Default.Health_Back_Left * NewDamageInfo[DamInfoIndex].DamageEffectPct)
					{
						bCreateEffect = true;
					}
				}
				else
				{
					if (bHit_Right_Front)
					{
						Health_Front_Right -= Damage * NewDamageInfo[DamInfoIndex].AM_Front_Right;
						if (Health_Front_Right <= Default.Health_Front_Right * NewDamageInfo[DamInfoIndex].DamageEffectPct)
						{
							bCreateEffect = true;
						}
					}
					else
					{
						if (bHit_Right_Back)
						{
							Health_Back_Right -= Damage * NewDamageInfo[DamInfoIndex].AM_Back_Right;
							if (Health_Back_Right <= Default.Health_Back_Right * NewDamageInfo[DamInfoIndex].DamageEffectPct)
							{
								bCreateEffect = true;
							}
						}
					}
				}
			}
			if (bCreateEffect && NewDamageInfo[DamInfoIndex].DamageEffect != nullptr)
			{
				TempDamageParticles = Spawn(NewDamageInfo[DamInfoIndex].DamageEffect, this);
				AttachToBone(TempDamageParticles, GetClosestBone(HitLocation, FVector(0,0,0), TempDist));
			}
			if (Controller != nullptr && Health_Front_Right > 0 && Health_Front_Left > 0 && Health_Back_Left > 0 && Health_Back_Right > 0)
			{
				Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, InDamageType, Bone);
			}
		}
		else
		{
			DamInfoIndex++;
		}
	}
	if (Health_Front_Right <= 0 || Health_Front_Left <= 0 || Health_Back_Left <= 0 || Health_Back_Right <= 0)
	{
		if (GetWorld()->GetNetMode() != 3 && bSmokeGeneratorOn)
		{
			bSmokeGeneratorOn = false;
		}
		StopWeaponFiring();
		if (instigatedBy.Controller != nullptr)
		{
			Died(instigatedBy.Controller, InDamageType, HitLocation);
		}
		else
		{
			if (instigatedBy.TempController != nullptr)
			{
				Died(instigatedBy.TempController, InDamageType, HitLocation);
			}
			else
			{
				Log(Self + " Warning! " + this + " died without having a AController* OR a tempcontroller!");
				Died(instigatedBy.Controller, InDamageType, HitLocation);
			}
		}
		return;
	}
	if (HitMaterial == nullptr)
	{
		DebugLog(DEBUG_Vehicle, this + " - Vehicle damaged but no material was passed!");
		return;
	}
	TakeDamage(ActualDamage, instigatedBy, HitLocation, Momentum, InDamageType);
}
*/

void AAGP_Vehicle::ZoneTakeDamage(int32 Damage, uint8 ZoneNum, APawn* instigatedBy, UaDamageType* InDamageType, FVector HitLocation)
{
	float DamagePct = 0;
	float ChildDamagePct = 0;
	uint8 CurrentStateNum = 0;
	uint8 NewStateNum = 0;
	int32 i = 0;
	int32 PreHit_HitPoints = 0;
	PreHit_HitPoints = DamageZones[ZoneNum]->HitPoints;
	/*
	DamageZones[ZoneNum].HitPoints -= Damage;
	CurrentStateNum = DamageZones[ZoneNum].CurrentDamageState;
	if (DamageZones[ZoneNum].MaxHitPoints > 0)
	{
		DamagePct = DamageZones[ZoneNum].HitPoints / DamageZones[ZoneNum].MaxHitPoints;
	}
	else
	{
		DamagePct = 0;
	}
	DebugLog(DEBUG_Vehicle, this + " - Zone " + ZoneNum + " hit! - HitPoints: " + DamageZones[ZoneNum].HitPoints + " - DamagePct: " + DamagePct + " at damage state " + DamageZones[ZoneNum].CurrentDamageState + ":Vehicle_Damage");
	NewStateNum = CheckDamageState(ZoneNum, CurrentStateNum, DamagePct);
	if (NewStateNum > CurrentStateNum)
	{
		ChangeDamageState(ZoneNum, NewStateNum);
	}
	ChildDamagePct = DamageZones[ZoneNum].DamageStates[CurrentStateNum].ChildDamagePct;
	for (i = 0; i < DamageZones[ZoneNum].ChildDamageZones.Num(); i++)
	{
		ZoneTakeDamage(Damage * ChildDamagePct, DamageZones[ZoneNum].ChildDamageZones[i], instigatedBy, InDamageType, HitLocation);
	}
	if (PreHit_HitPoints > 0 && DamageZones[ZoneNum].HitPoints < 0 && DamageZones[ZoneNum].bControlsExternalMesh)
	{
		if (DamageZones[ZoneNum].MeshOwnerType == 1)
		{
			VehiclePosition(DamageZones[ZoneNum].MeshOwner).Died(instigatedBy.Controller, InDamageType, HitLocation);
		}
		else
		{
			if (DamageZones[ZoneNum].MeshOwnerType == 2)
			{
				VehiclePosition(DamageZones[ZoneNum].MeshOwner.Owner).Died(instigatedBy.Controller, InDamageType, HitLocation);
			}
		}
		DamageZones[ZoneNum].MeshOwner = nullptr;
	}
	*/
}

uint8 AAGP_Vehicle::CheckDamageState(uint8 ZoneNum, uint8 CurrentState, float DamagePct)
{
	/*
	if (DamageZones[ZoneNum].DamageStates.Num() == 0)
	{
		return 0;
	}
	if (DamageZones[ZoneNum].DamageStates.Num() == CurrentState + 1)
	{
		return CurrentState;
	}
	if (DamagePct <= DamageZones[ZoneNum].DamageStates[CurrentState + 1].DamagePct)
	{
		CurrentState = CheckDamageState(ZoneNum, CurrentState + 1, DamagePct);
	}
	*/
	return CurrentState;
}

bool AAGP_Vehicle::IsReplicationComplete()
{
	int32 i = 0;
	if (Positions.Num() == PositionTypes.Num())
	{
		for (i = 0; i < Positions.Num(); i++)
		{
			if (Positions[i] != nullptr)
			{
				if (!Positions[i]->IsReplicationComplete())
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

void AAGP_Vehicle::InitializeDamageZones()
{
	uint8 i = 0;
	uint8 j = 0;
	uint8 k = 0;
	uint8 BoneSlot = 0;
	float DamagePct = 0;
	for (i = 0; i < DamageZones.Num(); i++)
	{
		if (DamageZones[i] == nullptr)
		{
		}
		if (DamageZones[i]->bInitialSyncToVehicleHealth)
		{
			DamageZones[i]->MaxHitPoints = Health;
		}
		if (DamageZones[i]->HitPoints == 0)
		{
			DamageZones[i]->HitPoints = DamageZones[i]->MaxHitPoints;
		}
		if (DamageZones[i]->MaxHitPoints > 0)
		{
			DamagePct = DamageZones[i]->HitPoints / DamageZones[i]->MaxHitPoints;
		}
		else
		{
			DamagePct = 0;
		}
		if (DamageZones[i]->bControlsExternalMesh)
		{
			if (GetNetMode() != ENetMode::NM_DedicatedServer && DamageZones[i]->MeshOwnerType == EMeshOwnerType::MO_AttachedActor)
			{
				DamageZones[i]->MeshOwner = AttachedActors[DamageZones[i]->VehiclePositionOwnerIndex];
			}
			else
			{
				if (Positions[DamageZones[i]->VehiclePositionOwnerIndex] != nullptr)
				{
					if (DamageZones[i]->MeshOwnerType == EMeshOwnerType::MO_VehiclePosition)
					{
						DamageZones[i]->MeshOwner = Positions[DamageZones[i]->VehiclePositionOwnerIndex];
					}
					else
					{
						if (DamageZones[i]->MeshOwnerType == EMeshOwnerType::MO_VehiclePositionWeapon)
						{
							DamageZones[i]->MeshOwner = Positions[DamageZones[i]->VehiclePositionOwnerIndex]->Gun;
						}
					}
				}
				else
				{
					DamageZones[i]->MeshOwner = this;
				}
			}
		}
		else
		{
			DamageZones[i]->MeshOwner = this;
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			for (j = 0; j < DamageZones[i]->DamageStates.Num(); j++)
			{
				for (k = 0; k < 8; k++)
				{
					if (DamageZones[i]->DamageStates[j].DamageBones[k] == "None")
					{
					}
					DamageZones[i]->DamageStates[j].BoneSlot[k] = BoneSlot;
					BoneSlot++;
					if (!DamageZones[i]->bControlsExternalMesh)
					{
						//SetBoneScale(DamageZones[i]->DamageStates[j]->BoneSlot[k], 0, DamageZones[i]->DamageStates[j].DamageBones[k]);
					}
					else
					{
						//DamageZones[i]->MeshOwner->SetBoneScale(DamageZones[i]->DamageStates[j].BoneSlot[k], 0, DamageZones[i]->DamageStates[j].DamageBones[k]);
					}
				}
			}
		}
		ChangeDamageState(i, CheckDamageState(i, 0, DamagePct));
	}
	VerifyVehicleSystemBones(false);
}

void AAGP_Vehicle::ClientInitializeDamageZones()
{
	if (IsReplicationComplete())
	{
		InitializeDamageZones();
		bClientInitComplete = true;
	}
	else
	{
		//DebugLog(DEBUG_Vehicle, this + " replication incomplete");
	}
}

void AAGP_Vehicle::SetVehicleDamageState(uint8 NewDamageState)
{
	int32 i = 0;
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		return;
	}
	for (i = 0; i < DamageZones.Num(); i++)
	{
		if (NewDamageState > DamageZones[i]->DamageStates.Num() - 1)
		{
			ChangeDamageState(i, DamageZones[i]->DamageStates.Num() - 1);
		}
		else
		{
			ChangeDamageState(i, NewDamageState);
		}
	}
	//SetLocation(Location + 60 * FVector(0 0 1));
	//KAddImpulse(FVector(0,0,0), Location);
}

void AAGP_Vehicle::SourceChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
{
	//ChangeDamageState(ZoneNum, NewStateNum);
}

bool AAGP_Vehicle::VerifyVehicleSystemBones(bool bFoundBadBones)
{
	int32 i = 0;
	int32 j = 0;
	int32 k = 0;
	FName BoneName = "";
	FString BoneVariable = "";
	/*
	if (DriverBone != "None" && DriverBone != "None")
	{
		BoneVariable = "DriverBone";
		bFoundBadBones = LogBadBoneNames(this, DriverBone, bFoundBadBones, BoneVariable);
	}
	for (i = 0; i < EntryPoints.Num(); i++)
	{
		BoneName = EntryPoints[i].EntryBone;
		BoneVariable = "EntryPoints[" + i + "].EntryBone";
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = EntryPoints[i].DoorBone;
		BoneVariable = "EntryPoints[" + i + "].DoorBone";
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = EntryPoints[i].DoorBoneDS1;
		BoneVariable = "EntryPoints[" + i + "].DoorBoneDS1";
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = EntryPoints[i].DoorBoneDS2;
		BoneVariable = "EntryPoints[" + i + "].DoorBoneDS2";
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < PositionTypes.Num(); i++)
	{
		BoneName = PositionTypes[i].PositionBone;
		BoneVariable = "PositionTypes[" + i + "].PositionBone";
		if (BoneName != "None" && BoneName != "None")
		{
			if (!HasBone(BoneName))
			{
				if (Positions[i] != nullptr && Positions[i].Gun != nullptr)
				{
					if (!Positions[i].Gun.HasBone(BoneName))
					{
						bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
						bFoundBadBones = LogBadBoneNames(Positions[i].Gun, BoneName, bFoundBadBones, BoneVariable);
					}
				}
			}
		}
		BoneName = PositionTypes[i].WeaponBone;
		BoneVariable = "PositionTypes[" + i + "].WeaponBone";
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < Wheels.Num(); i++)
	{
		BoneName = Wheels[i]->BoneName;
		BoneVariable = "Wheels[" + i + "].BoneName";
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = Wheels[i]->SupportBoneName;
		BoneVariable = "Wheels[" + i + "].SupportBoneName";
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < DamageZones.Num(); i++)
	{
		if (DamageZones[i] != nullptr)
		{
			if (!DamageZones[i]->bControlsExternalMesh)
			{
				for (j = 0; j < DamageZones[i]->DamageStates.Num(); j++)
				{
					for (k = 0; k < 8; k++)
					{
						BoneName = DamageZones[i]->DamageStates[j].DamageBones[k];
						if (BoneName != "None" && BoneName != "None")
						{
							bFoundBadBones = CheckBadDamageState(DamageZones[i]->MeshOwner, BoneName, bFoundBadBones, i, j, k);
						}
					}
				}
			}
		}
	}
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i] != nullptr && Positions[i].Gun != nullptr)
		{
			bFoundBadBones = Positions[i].Gun.VerifyVehicleSystemBones(bFoundBadBones);
		}
	}
	if (bFoundBadBones)
	{
		DebugLog(DEBUG_Vehicle, "=========================================================== End: Vehicle_Bone_Warning");
	}
	*/
	return bFoundBadBones;
}

bool AAGP_Vehicle::ActorHasBone(AActor* MeshOwner, FName BoneName)
{
	if ((BoneName == "None") && (BoneName == "None"))
	{
		return false;
	}
	/*
	if ((MeshOwner != nullptr) && MeshOwner.HasBone(BoneName))
	{
	}
	*/
	return false;   //FAKE  /ELiZ
}

bool AAGP_Vehicle::LogBadBoneNames(AActor* mo, FName LookupBone, bool bBadBones, FString VariableName, FString AppendString)
{
	FString OutputString = "";
	/*
	if (mo == nullptr)
	{
		DebugLog(DEBUG_Vehicle, "Mesh Owner in LogBadBoneNames is none, breaking out");
		return bBadBones;
	}
	if (!mo.HasBone(LookupBone))
	{
		if (!bBadBones)
		{
			DebugLog(DEBUG_Vehicle, "=========================================================== Start: Vehicle_Bone_Warning");
			DebugLog(DEBUG_Vehicle, "Bad Bones Warning for " + mo.Class + ":Vehicle_Bone_Warning");
			bBadBones = true;
		}
		OutputString = "Bone " + VariableName + " with value " + LookupBone + " isn't valid for skeleton " + mo.Mesh + " " + AppendString;
		DebugLog(DEBUG_Vehicle, OutputString + ":Vehicle_Bone_Warning");
	}
	*/
	return bBadBones;
}

bool AAGP_Vehicle::CheckBadDamageState(AActor* mo, FName LookupBone, bool bBadBones, int32 ZoneNum, int32 StateNum, int32 DamageBonesNum)
{
	FString OutputString = "";
	/*
	if (!mo.HasBone(LookupBone))
	{
		if (ZoneNum >= 0)
		{
			OutputString = OutputString + "DamageZones[" + ZoneNum + "]";
		}
		if (StateNum >= 0)
		{
			OutputString = OutputString + ".DamageStates[" + StateNum + "]";
		}
		if (DamageBonesNum >= 0)
		{
			OutputString = OutputString + ".DamageBones[" + DamageBonesNum + "]";
		}
		bBadBones = LogBadBoneNames(mo, LookupBone, bBadBones, OutputString);
	}
	*/
	return bBadBones;
}

void AAGP_Vehicle::ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
{
	uint8 CurrentStateNum = 0;
	int32 i = 0;
	/*
	if (DamageZones[ZoneNum] == nullptr || DamageZones[ZoneNum]->DamageStates.Num() == 0)
	{
		return;
	}
	CurrentStateNum = DamageZones[ZoneNum].CurrentDamageState;
	for (i = 0; i < 8; i++)
	{
		if (DamageZones[ZoneNum].DamageStates[CurrentStateNum].DamageBones[i] == "None")
		{
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			if (!DamageZones[ZoneNum].bControlsExternalMesh)
			{
				SetBoneScale(DamageZones[ZoneNum].DamageStates[CurrentStateNum].BoneSlot[i], 0, DamageZones[ZoneNum].DamageStates[CurrentStateNum].DamageBones[i]);
				SetBoneScale(DamageZones[ZoneNum].DamageStates[NewStateNum].BoneSlot[i], 1, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[i]);
			}
			else
			{
				if (DamageZones[ZoneNum].MeshOwner != nullptr && !DamageZones[ZoneNum].MeshOwner.bDeleteMe)
				{
					DamageZones[ZoneNum].MeshOwner.SetBoneScale(DamageZones[ZoneNum].DamageStates[CurrentStateNum].BoneSlot[i], 0, DamageZones[ZoneNum].DamageStates[CurrentStateNum].DamageBones[i]);
					DamageZones[ZoneNum].MeshOwner.SetBoneScale(DamageZones[ZoneNum].DamageStates[NewStateNum].BoneSlot[i], 1, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[i]);
				}
				else
				{
					DebugLog(DEBUG_Vehicle, this @ "DamageZones[" + ZoneNum + "] can't process DamageState change from " + CurrentStateNum + " to " + NewStateNum + " because MeshOwner no longer exists!");
				}
			}
		}
		if (DamageZones[ZoneNum].bWheelZone)
		{
			Wheels[DamageZones[ZoneNum].WheelNum].BoneName = DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[i];
		}
	}
	if (DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect != nullptr)
	{
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect.StopEmitter();
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect.Destroy();
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect = nullptr;
	}
	if (DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass != nullptr)
	{
		DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect = Spawn('VehicleVisualEffect', this);
		if (!DamageZones[ZoneNum].bControlsExternalMesh)
		{
			DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.StartEmitter(DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass, this, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[0]);
		}
		else
		{
			if (DamageZones[ZoneNum].MeshOwner != nullptr && !DamageZones[ZoneNum].MeshOwner.bDeleteMe)
			{
				DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.StartEmitter(DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass, DamageZones[ZoneNum].MeshOwner, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[0]);
			}
			else
			{
				DebugLog(DEBUG_Vehicle, this @ "DamageZones[" + ZoneNum + "] can't spawn " + DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass + " because MeshOwner no longer exists!");
			}
		}
	}
	if (DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect != nullptr && DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.EffectEmitter != nullptr)
	{
		DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.EffectEmitter.LifeSpan *= DamageStateParticleTimeScaler;
	}
	if (DamageZones[ZoneNum].DamageStates[CurrentStateNum].PhysicalEffect != nullptr)
	{
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].PhysicalEffect.Deactivate(this);
	}
	if (DamageZones[ZoneNum].DamageStates[NewStateNum].PhysicalEffect != nullptr)
	{
		DamageZones[ZoneNum].DamageStates[NewStateNum].PhysicalEffect.Activate(this, ZoneNum, NewStateNum);
	}
	for (i = 0; i < DamageZones[ZoneNum].WindowDamageZones.Num(); i++)
	{
		if (DamageZones[ZoneNum].WindowDamageZones[i] < DamageZones.Num())
		{
			if (DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].CurrentDamageState < NewStateNum)
			{
				if (NewStateNum < DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates.Num())
				{
					DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].HitPoints *= DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates[NewStateNum].DamagePct;
					ChangeDamageState(DamageZones[ZoneNum].WindowDamageZones[i], NewStateNum);
				}
				else
				{
					DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].HitPoints *= DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates[DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates.Num()].DamagePct;
					ChangeDamageState(DamageZones[ZoneNum].WindowDamageZones[i], DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates.Num());
				}
			}
		}
	}
	DamageZones[ZoneNum].CurrentDamageState = NewStateNum;
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		DamageZoneStates[ZoneNum] = NewStateNum;
	}
	*/
}

void AAGP_Vehicle::DriverRadiusDamage(float DamageAmount, float DamageRadius, AController* EventInstigator, UaDamageType* DamageType, float Momentum, FVector HitLocation)
{
	int32 i = 0;
	/*
	DriverRadiusDamage(DamageAmount, DamageRadius, EventInstigator, DamageType, Momentum, HitLocation);
	for (i = 0; i < Positions.Num(); i++)
	{
		if (!Positions[i].bCollideActors)
		{
			Positions[i].DriverRadiusDamage(DamageAmount, DamageRadius, EventInstigator, DamageType, Momentum, HitLocation);
		}
	}
	*/
}

void AAGP_Vehicle::NPC_Fire(float F, APawn* Enemy)
{
	Fire(F);
}

void AAGP_Vehicle::Fire(float F)
{
	//Super::Fire(F);
	//if (ActiveWeapon < VehicleWeapons.Num() && PlayerController(Controller) != nullptr)
	//{
	//	VehicleWeapons[ActiveWeapon].ClientStartFire(Controller, false);
	//}
}

void AAGP_Vehicle::AltFire(float F)
{
	//Super::AltFire(F);
	//if (!bWeaponisFiring && ActiveWeapon < VehicleWeapons.Num() && PlayerController(Controller) != nullptr)
	//{
	//	VehicleWeapons[ActiveWeapon].ClientStartFire(Controller, true);
	//}
}

void AAGP_Vehicle::ClientVehicleCeaseFire(bool bWasAltFire)
{
	/*
	ClientVehicleCeaseFire(bWasAltFire);
	if (ActiveWeapon < VehicleWeapons.Num())
	{
		VehicleWeapons[ActiveWeapon].ClientStopFire(Controller, bWasAltFire);
		if (!bWasAltFire && bWeaponisAltFiring)
		{
			VehicleWeapons[ActiveWeapon].ClientStartFire(Controller, true);
		}
	}
	*/
}

void AAGP_Vehicle::TakeImpactDamage(float AccelMag)
{
	int32 Damage = 0;
	/*
	Damage = AccelMag * VehicleMass * ImpactDamageModifier();
	TakeRadiusDamage(Damage, this, ImpactInfo.pos, 0, 'DamTypeVehicle', ImpactDamageRadius);
	if (ImpactDamageSounds.Num() > 0)
	{
		PlaySound(ImpactDamageSounds[Rand(ImpactDamageSounds.Num() - 1)], , TransientSoundVolume * 2.5);
	}
	if (Health < 0 && GetWorld()->GetTimeSeconds() - LastImpactExplosionTime > TimeBetweenImpactExplosions)
	{
		VehicleExplosion(Normal(ImpactInfo.impactNorm), 0.5);
		LastImpactExplosionTime = GetWorld()->GetTimeSeconds();
	}
	*/
}

float AAGP_Vehicle::ImpactDamageModifier()
{
	return ImpactDamageMult;
}

void AAGP_Vehicle::KImpact(AActor* Other, FVector pos, FVector impactVel, FVector impactNorm)
{
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		ImpactInfo.Other = Other;
		ImpactInfo.pos = pos;
		ImpactInfo.impactVel = impactVel;
		ImpactInfo.impactNorm = impactNorm;
		ImpactInfo.ImpactAccel = KParams.KAcceleration;
		ImpactTicksLeft = ImpactDamageTicks;
	}
	*/
}

float AAGP_Vehicle::ChargeBar()
{
	return 0;
}

bool AAGP_Vehicle::FastVehicle()
{
	return false;
}

bool AAGP_Vehicle::IsDeployed()
{
	return false;
}

void AAGP_Vehicle::SetTeamNum(uint8 t)
{
	uint8 Temp = 0;
	int32 X = 0;
	Temp = Team;
	PrevTeam = t;
	Team = t;
	if (Temp != t)
	{
		TeamChanged();
	}
	for (X = 0; X < Positions.Num(); X++)
	{
		Positions[X]->SetTeamNum(t);
	}
}

bool AAGP_Vehicle::CanLean()
{
	return true;
}

void AAGP_Vehicle::LeanLeft(bool bFullLeft)
{
	ServerChangePosition(false, Driver);
}

void AAGP_Vehicle::LeanRight(bool bFullRight)
{
	//ServerChangePosition(true, Driver);
}

void AAGP_Vehicle::ServerChangePosition(bool bNext, APawn* p)
{
	int32 Slot = 0;
	int32 i = 0;
	if (!bEnableChangePosition)
	{
		return;
	}
	if (Driver == p)
	{
		KDriverLeave(true);
		Slot = 0;
	}
	else
	{
		i = 0;
		if (i < Positions.Num())
		{
			if (Positions[i]->Driver == p)
			{
				Positions[i]->KDriverLeave(true);
				Slot = i + 1;
			}
			else
			{
				i++;
			}
		}
		if (Slot == 0)
		{
			//DebugLog(DEBUG_Vehicle, "ServerChangePosition() - Can't find Pawn: " + p + " in Vehicle: " + Self);
			return;
		}
	}
	if (bNext)
	{
		for (i = Slot + 1; i <= Positions.Num(); i++)
		{
			if (Positions[i - 1]->TryToDrive(p))
			{
				return;
			}
		}
		if (TryToDrive(p))
		{
			return;
		}
		for (i = 1; i <= Slot; i++)
		{
			if (Positions[i - 1]->TryToDrive(p))
			{
				return;
			}
		}
	}
	else
	{
		for (i = Slot - 1; i >= 1; i--)
		{
			if (Positions[i - 1]->TryToDrive(p))
			{
				return;
			}
		}
		if (Slot > 0 && TryToDrive(p))
		{
			return;
		}
		for (i = Positions.Num(); i >= Slot; i--)
		{
			if (Positions[i - 1]->TryToDrive(p))
			{
				return;
			}
		}
		if (TryToDrive(p))
		{
			return;
		}
	}
	//Log("ServerChangePosition() - Error switching positions, no slot was found. This should never happen.");
}

void AAGP_Vehicle::SpawnDestroyedModels()
{
	int32 i = 0;
	AActor* ExtraTurrets = nullptr;
	AActor* NewBody = nullptr;
	/*
	NewBody = Spawn(DestroyedModelClass, None, , Location, Rotation);
	for (i = 0; i < Positions.Num(); i++)
	{
		if (Positions[i].Gun != nullptr && Positions[i].Gun.DestroyedModelClass != nullptr)
		{
			ExtraTurrets = Spawn(Positions[i].Gun.DestroyedModelClass, None, , Positions[i].Gun->GetActorLocation(), Positions[i].Gun.GetBoneRotation(Positions[i].Gun.YawBone));
			ExtraTurrets.SetBase(NewBody);
			ExtraTurrets = nullptr;
		}
	}
	*/
}

void AAGP_Vehicle::SpawnDestructionEffects()
{
	AEmitter* DestructionEffect = nullptr;
	/*
	DestructionEffect = Spawn(AVehicleHulkBurn::StaticClass(), this);
	DestructionEffect.SetBase(this);
	DestructionEffect = Spawn(Aem_bt_PG7Bexplosion::StaticClass(), this);
	DestructionEffect.SetBase(this);
	*/
}

void AAGP_Vehicle::DestroyAppearance()
{
	int32 i = 0;
	UKarmaParams* KP = nullptr;
	bDestroyAppearance = true;
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		for (i = 0; i < VehicleWeapons.Num(); i++)
		{
			if (VehicleWeapons[i].DestroyedWeaponStaticMesh != nullptr)
			{
				DetachFromBone(VehicleWeapons[i]);
				VehicleWeapons[i].SetDrawType(8);
				VehicleWeapons[i].SetStaticMesh(VehicleWeapons[i].DestroyedWeaponStaticMesh);
			}
			else
			{
				VehicleWeapons[i].Destroy();
			}
		}
	}
	CleanUpDamageZones();
	SetDrawType(8);
	AmbientSound = nullptr;
	SetStaticMesh(DestroyedVehicleMesh);
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		bNoTeamBeacon = true;
		for (i = 0; i < HeadlightCorona.Num(); i++)
		{
			HeadlightCorona[i].Destroy();
		}
		HeadlightCorona.Num() = 0;
		if (HeadlightProjector != nullptr)
		{
			HeadlightProjector.Destroy();
		}
		SpawnDestructionEffects();
	}
	KP = KarmaParams(KParams);
	if (KP != nullptr)
	{
		KP.KStartLinVel = Velocity;
	}
	SetPhysics(0);
	KSetBlockKarma(false);
	KSetBlockKarma(true);
	SetPhysics(13);
	Skins.Num() = 0;
	*/
}

void AAGP_Vehicle::VehicleExplosion(FVector MomentumNormal, float PercentMomentum)
{
	FVector LinearImpulse = FVector(0,0,0);
	FVector AngularImpulse = FVector(0, 0, 0);
	/*
	HurtRadius(ExplosionDamage, ExplosionRadius, ExplosionDamageType, ExplosionMomentum, Location);
	if (!bDisintegrateVehicle)
	{
		ExplosionCount++;
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			ClientVehicleExplosion(false);
		}
		LinearImpulse = PercentMomentum * RandRange(DestructionLinearMomentum.Min, DestructionLinearMomentum.Max) * MomentumNormal;
		AngularImpulse = PercentMomentum * RandRange(DestructionAngularMomentum.Min, DestructionAngularMomentum.Max) * VRand();
		NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
		KAddImpulse(LinearImpulse, FVector(0,0,0));
		KAddAngularImpulse(AngularImpulse);
	}
	*/
}

void AAGP_Vehicle::ClientVehicleExplosion(bool bFinal)
{
	int32 SoundNum = 0;
	APlayerController* PC = nullptr;
	float dist = 0;
	float Scale = 0;
	/*
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		PC = Level.GetLocalPlayerController();
		if (PC != nullptr && PC.ViewTarget != nullptr)
		{
			dist = VSize(Location - PC.ViewTarget.Location);
			if (dist < ExplosionRadius * 2.5)
			{
				if (dist < ExplosionRadius)
				{
					Scale = 1;
				}
				else
				{
					Scale = ExplosionRadius * 2.5 - dist / ExplosionRadius;
				}
				PC.ShakeView(ShakeRotMag * Scale, ShakeRotRate, ShakeRotTime, ShakeOffsetMag * Scale, ShakeOffsetRate, ShakeOffsetTime);
			}
		}
	}
	if (ExplosionSounds.Num() > 0)
	{
		SoundNum = Rand(ExplosionSounds.Num());
		PlaySound(ExplosionSounds[SoundNum], 0, ExplosionSoundVolume * TransientSoundVolume, , ExplosionSoundRadius);
	}
	if (bFinal)
	{
		GotoState('VehicleDisintegrated');
	}
	*/
}

void AAGP_Vehicle::PlayDoorAnim(int32 Position)
{
	int32 ch0 = 0;
	int32 ch1 = 0;
	int32 ch2 = 0;
	/*
	if (Position >= EntryPoints.Num())
	{
		return;
	}
	if (EntryPoints[Position].DoorAnim != "None")
	{
		ch0 = 3 * Position;
		ch1 = ch0 + 1;
		ch2 = ch0 + 2;
		AnimBlendParams(ch0, 1, 0, 0, EntryPoints[Position].DoorBone);
		AnimBlendParams(ch1, 1, 0, 0, EntryPoints[Position].DoorBoneDS1);
		AnimBlendParams(ch2, 1, 0, 0, EntryPoints[Position].DoorBoneDS2);
		PlayAnim(EntryPoints[Position].DoorAnim, 1, 0, ch0);
		PlayAnim(EntryPoints[Position].DoorAnim, 1, 0, ch1);
		PlayAnim(EntryPoints[Position].DoorAnim, 1, 0, ch2);
	}
	*/
}

void AAGP_Vehicle::OpenDoor(int32 Position)
{
	FRotator DoorAxis = FRotator(0,0,0);
	/*
	if (Position >= EntryPoints.Num())
	{
		return;
	}
	if (EntryPoints[Position].DoorBone != "None")
	{
		DoorAxis.Yaw = EntryPoints[Position].DoorOpenAngle;
		SetBoneRotation(EntryPoints[Position].DoorBone, DoorAxis, , 1);
		SetBoneRotation(EntryPoints[Position].DoorBoneDS1, DoorAxis, , 1);
		SetBoneRotation(EntryPoints[Position].DoorBoneDS2, DoorAxis, , 1);
	}
	*/
}

void AAGP_Vehicle::CloseDoor(int32 Position)
{
	/*
	if (Position >= EntryPoints.Num())
	{
		return;
	}
	if (EntryPoints[Position].DoorBone != "None")
	{
		SetBoneRotation(EntryPoints[Position].DoorBone, FRotator(0 0 0), , 1);
		SetBoneRotation(EntryPoints[Position].DoorBoneDS1, FRotator(0 0 0), , 1);
		SetBoneRotation(EntryPoints[Position].DoorBoneDS2, FRotator(0 0 0), , 1);
	}
	*/
}

void AAGP_Vehicle::SVehicleUpdateParams()
{
	/*
	int32 i = 0;
	SVehicleUpdateParams();
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		for (i = 0; i < HeadlightCorona.Num(); i++)
		{
			HeadlightCorona[i].SetBase(nullptr);
			HeadlightCorona[i].SetLocation(Location + HeadlightCoronaOffset[i] >> Rotation);
			HeadlightCorona[i].SetBase(this);
			HeadlightCorona[i].Skins[0] = HeadlightCoronaMaterial;
			HeadlightCorona[i].MaxCoronaSize = HeadlightCoronaMaxSize * Level.HeadlightScaling;
		}
		if (HeadlightProjector != nullptr)
		{
			HeadlightProjector.SetBase(nullptr);
			HeadlightProjector.SetLocation(Location + HeadlightProjectorOffset >> Rotation);
			HeadlightProjector.SetBase(this);
			HeadlightProjector.SetRelativeRotation(HeadlightProjectorRotation);
			HeadlightProjector.ProjTexture = HeadlightProjectorMaterial;
			HeadlightProjector.SetDrawScale(HeadlightProjectorScale);
		}
	}
	*/
}

int32 AAGP_Vehicle::LimitPitch(int32 Pitch)
{
	if (ActiveWeapon >= VehicleWeapons.Num())
	{
		//return Super::LimitPitch(Pitch);
	}
	return VehicleWeapons[ActiveWeapon]->LimitPitch(Pitch, GetActorRotation(),0);
}

void AAGP_Vehicle::ServerPlayHorn(int32 HornIndex)
{
	int32 i = 0;
	int32 NumPositions = 0;
	Super::ServerPlayHorn(HornIndex);
	/*
	if (HornIndex > 0 || PlayerController(Controller) == nullptr)
	{
		return;
	}
	i = 0;
	if (i < Positions.Num())
	{
		if (Positions[i].Driver == nullptr)
		{
			NumPositions++;
		}
		else
		{
			i++;
		}
	}
	*/
}

void AAGP_Vehicle::DrawHUD(UCanvas* Canvas)
{
	APlayerController* PC = nullptr;
	FVector CameraLocation = FVector(0, 0, 0);
	FRotator CameraRotation = FRotator(0,0,0);
	AActor* ViewActor = nullptr;
	/*
	if (IsLocallyControlled() && ActiveWeapon < VehicleWeapons.Num() && VehicleWeapons[ActiveWeapon] != nullptr && VehicleWeapons[ActiveWeapon].bCorrectAim)
	{
		Canvas.DrawColor = CrossHairColor;
		Canvas.DrawColor.A = 255;
		Canvas.Style = 6;
		Canvas.SetPos(Canvas.SizeX * 0.5 - CrosshairX, Canvas.SizeY * 0.5 - CrosshairY);
		Canvas.DrawTile(CrosshairTexture, CrosshairX * 2, CrosshairY * 2, 0, 0, CrosshairTexture.USize, CrosshairTexture.VSize);
	}
	PC = Cast<APlayerController>(Controller);
	if (PC != nullptr && !PC.bBehindView && HudOverlay != nullptr)
	{
		if (!Level.IsSoftwareRendering())
		{
			CameraRotation = PC.Rotation;
			SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
			HudOverlay.SetLocation(CameraLocation + HUDOverlayOffset >> CameraRotation);
			HudOverlay.SetRotation(CameraRotation);
			Canvas.DrawActor(HudOverlay, false, False,FMath::Clamp(HUDOverlayFOV * PC.DesiredFOV / PC.DefaultFOV, 1, 170));
		}
	}
	else
	{
		ActivateOverlay(false);
	}
	*/
}

void AAGP_Vehicle::PlayHit(float Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FVector Momentum)
{
	int32 i = 0;
	/*
	PlayHit(Damage, instigatedBy, HitLocation, DamageType, Momentum);
	for (i = 0; i < Positions.Num(); i++)
	{
		if (!Positions[i].bHasOwnHealth && Positions[i].Controller != nullptr)
		{
			Positions[i].Controller.NotifyTakeHit(instigatedBy, HitLocation, Damage, DamageType, Momentum);
		}
	}
	*/
}

TArray<AVehicle*> AAGP_Vehicle::GetTurrets()
{
	//return Positions;
	return {};     //FAKE  /ELiZ
}

void AAGP_Vehicle::PrecacheAnnouncer(AAnnouncerVoice* V, bool bRewardSounds)
{
}

void AAGP_Vehicle::StaticPrecache(ALevelInfo* L)
{
	int32 i = 0;
	/*
	for (i = 0; i < Default.DriverWeapons.Num(); i++)
	{
		Default.DriverWeapons[i].WeaponClass.StaticPrecache(L);
	}
	for (i = 0; i < Default.PositionTypes.Num(); i++)
	{
		Default.PositionTypes[i].VehiclePositionClass.StaticPrecache(L);
	}
	if (Default.DestroyedVehicleMesh != nullptr)
	{
		L.AddPrecacheStaticMesh(Default.DestroyedVehicleMesh);
	}
	if (Default.HeadlightCoronaMaterial != nullptr)
	{
		L->AddPrecacheMaterial(Default.HeadlightCoronaMaterial);
	}
	if (Default.HeadlightProjectorMaterial != nullptr)
	{
		L->AddPrecacheMaterial(Default.HeadlightProjectorMaterial);
	}
	*/
}

void AAGP_Vehicle::UpdatePrecacheStaticMeshes()
{
	/*
	Super::UpdatePrecacheStaticMeshes();
	if (DestroyedVehicleMesh != nullptr)
	{
		Level.AddPrecacheStaticMesh(DestroyedVehicleMesh);
	}
	*/
}

void AAGP_Vehicle::UpdatePrecacheMaterials()
{
	if (HeadlightCoronaMaterial != nullptr)
	{
		//LeveL->AddPrecacheMaterial(HeadlightCoronaMaterial);
	}
	if (HeadlightProjectorMaterial != nullptr)
	{
		//LeveL->AddPrecacheMaterial(HeadlightProjectorMaterial);
	}
	//Super::UpdatePrecacheMaterials();
}

void AAGP_Vehicle::NotifyControllerOutOfBounds(int32 Seconds)
{
	/*
	if (Controller != nullptr)
	{
		if (Cast<APlayerController>(Controller) != nullptr)
		{
			Cast<APlayerController>(Controller).myHUD.DisplayCenteredMessage(1.1, "You have left the combat zone!", "You have" @ Seconds @ "seconds to return...");
		}
	}
	*/
}

void AAGP_Vehicle::AlertClientReturnedToCombat()
{
	/*
	if (Controller != nullptr)
	{
		if (Cast<APlayerController>(Controller) != nullptr)
		{
			Cast<APlayerController>(Controller).myHUD.DisplayCenteredMessage(3, "You have returned to combat.");
		}
	}
	*/
}

void AAGP_Vehicle::KillControllerOutOfBounds()
{
	/*
	if (Controller != nullptr)
	{
		if (Cast<APlayerController>(Controller) != nullptr)
		{
			Cast<APlayerController>(Controller).myHUD.DisplayCenteredMessage(3, "Failed to return to combat.");
		}
	}
	*/
}

void AAGP_Vehicle::VehicleOutOfBoundsCheck()
{
	/*
	int32 i = 0;
	if (Cast<APlayerController>(Controller) == nullptr)
	{
		return;
	}
	if (OutOfBounds > 0)
	{
		TimeOutOfBounds += 0.5;
		NotifyControllerOutOfBounds(Ceil(CurrentZoneTimeToKill - TimeOutOfBounds));
		for (i = 0; i < Positions.Num(); i++)
		{
			Positions[i].NotifyControllerOutOfBounds(Ceil(CurrentZoneTimeToKill - TimeOutOfBounds));
		}
	}
	if (CurrentZoneTimeToKill - TimeOutOfBounds <= 0)
	{
		StopCustomTimer('VehicleOutOfBoundsCheck');
		OutOfBounds++;
		KilledBy(this);
	}
	*/
}

bool AAGP_Vehicle::PlaceExitingDriver()
{
	AAGP_Pawn* p = nullptr;
	p = Cast<AAGP_Pawn>(Driver);
	if ((p != nullptr) && (OutOfBounds > 0))
	{
		p->TimeOutOfBounds = TimeOutOfBounds;
		p->OutOfBounds = OutOfBounds;
	}
	return Super::PlaceExitingDriver();
}

void AAGP_Vehicle::Timer()
{
	//Super::Timer();
	CheckSmokeGenerator();
}

void AAGP_Vehicle::CheckSmokeGenerator()
{
	/*
	if (GetWorld()->GetNetMode() == 1 || GetWorld()->GetNetMode() == 0 && bSmokeGeneratorOn && GetWorld()->GetTimeSeconds() > fpSmokeEndTime && fpSmokeEndTime > 0)
	{
		bSmokeGeneratorOn = false;
		return;
	}
	if (SmokeGenerator != nullptr && !bSmokeGeneratorOn)
	{
		SmokeGenerator.Kill();
		SmokeGenerator = nullptr;
		return;
	}
	if (bSmokeGeneratorOn && SmokeGenerator == nullptr)
	{
		SpawnSmokeGenerator(45);
	}
	*/
}

void AAGP_Vehicle::SpawnSmokeGenerator(float fpSmokeLengthSeconds)
{
	/*
	SmokeGenerator = Spawn(AM83SmokeEmitter::StaticClass(), this, , Location, FRotator(16384 0 0));
	if (SmokeGenerator == nullptr)
	{
		bSmokeGeneratorOn = false;
		return;
	}
	SmokeGenerator.SetBase(this);
	AttachToBone(SmokeGenerator, SmokeGeneratorAttachmentBone);
	SmokeGenerator._EffectDuration = fpSmokeLengthSeconds;
	fpSmokeEndTime = GetWorld()->GetTimeSeconds() + fpSmokeLengthSeconds;
	*/
}

void AAGP_Vehicle::StartSmokeGenerator()
{
	bSmokeGeneratorOn = true;
}

void AAGP_Vehicle::StopSmokeGenerator()
{
	bSmokeGeneratorOn = false;
}
