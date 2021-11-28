// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"

AAGP_Vehicle::AAGP_Vehicle()
{
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
	//ExplosionDamageType = class'AGP_Vehicles.DamTypeVehicle';
	//DamagedEffectClass = class'AGP_Vehicles.DamagedEffect';
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
	//SparkEffectClass = class'AGP_Vehicles.ImpactSparks';
	SparkAdvanceFactor = 1.5;
	MinRunOverWarningAim = 0.88;
	DamageStateParticleTimeScaler = 1;
	CurrentZoneTimeToKill = 9999999;
	//bZeroPCRotOnEntry = false;
	//bEnterringUnlocks = true;
	//Team = 0;
	//DriveAnim = "None";
	//WaterDamage = 150;
	//VehicleDrowningDamType = Class'Gameplay.Drowned';
	//VehicleReplicationInfoClass = Class'AGP.AGP_VehicleReplicationInfo';
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
	void Died(Controller Killer, UaDamageType* DamageType, FVector HitLocation, optional FVector HitDir, optional Actor.BoneInfo Bone)
	{
	}
	void CallDestroy()
	{
		DebugLog(DEBUG_Vehicle,"VehicleDestroyed::CallDestroy() called: Destroy_Track");
	}
}
State VehicleDisintegrated
{
	void Died(Controller Killer, UaDamageType* DamageType, FVector HitLocation, optional FVector HitDir, optional Actor.BoneInfo Bone)
	{
	}
	void CallDestroy()
	{
		DebugLog(DEBUG_Vehicle,"VehicleDisintegrated::CallDestroy() called, Destroy_Track ");
	}
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
void AAGP_Vehicle::WeaponSeePawn(AActor* TargetActor)
{

}

//native void PlayIdleSound();
void AAGP_Vehicle::PlayIdleSound()
{

}

void AAGP_Vehicle::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	local AGP.NPCBasePreCrewedVehicleController NPCController;
	NPCController = NPCBasePreCrewedVehicleController(Controller);
	if (NPCController != None)
	{
		NPCController.NotifyTrigger(Other, EventInstigator);
	}
	Trigger(Other, EventInstigator);
	*/
}

void AAGP_Vehicle::PostBeginPlay()
{
	/*
	local int32 i;
	if (Level.NetMode != 1)
	{
		for (i = 0; i < AttachedActorTypes.Length; i++)
		{
			AttachedActors[i] = Spawn(AttachedActorTypes[i].attachClass, Self, , Location);
			AttachToBone(AttachedActors[i], AttachedActorTypes[i].AttachBone);
		}
	}
	PostBeginPlay();
	SetTimer(1, True);
	*/
}

void AAGP_Vehicle::NotifyEnemyLockedOn()
{
	/*
	local int32 i;
	NotifyEnemyLockedOn();
	if (LockedOnSound != None)
	{
		PlaySound(LockedOnSound);
	}
	for (i = 0; i < Positions.Length; i++)
	{
		Positions[i].NotifyEnemyLockedOn();
	}
	*/
}

void AAGP_Vehicle::NotifyEnemyLostLock()
{
	/*
	local int32 i;
	NotifyEnemyLostLock();
	for (i = 0; i < Positions.Length; i++)
	{
		Positions[i].NotifyEnemyLostLock();
	}
	*/
}

void AAGP_Vehicle::HasWeapon()
{
	//Return ActiveWeapon < VehicleWeapons.Length;
}

UMaterialInstance* AAGP_Vehicle::LookupCollisionMaterial(AActor* SearchActor)
{
	/*
	local int32 i;
	local FString ResolvedMaterialString;
	local Material CollisionMaterial;
	for (i = 0; i < DamageZones.Length; i++)
	{
		if (DamageZones[i].bControlsExternalMesh && SearchActor == DamageZones[i].MeshOwner)
		{
			ResolvedMaterialString = "T_AAO_Vehicles.Collision.Damage_" $ i $ "_Zone";
			CollisionMaterial = Material(DynamicLoadObject(ResolvedMaterialString, Class'Material'));
			Return CollisionMaterial;
		}
	}
	*/
	return nullptr;
}

bool AAGP_Vehicle::CanAttack(AActor* Other)
{
	/*
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		Return VehicleWeapons[ActiveWeapon].CanAttack(Other);
	}
	*/
	return false;
}

void AAGP_Vehicle::Deploy()
{
}

void AAGP_Vehicle::MayUndeploy()
{
}

void AAGP_Vehicle::TooCloseToAttack(AActor* Other)
{
	/*
	local int32 NeededPitch;
	local int32 i;
	local bool bControlledWeaponPawn;
	if (VSize(Location - Other.Location) > 2500)
	{
		return false;
	}
	if (!HasWeapon())
	{
		if (Positions.Length == 0)
		{
			return false;
		}
		for (i = 0; i < Positions.Length; i++)
		{
			if (Positions[i].Controller != None)
			{
				bControlledWeaponPawn = true;
				if (!Positions[i].TooCloseToAttack(Other))
				{
					return false;
				}
			}
		}
		if (!bControlledWeaponPawn)
		{
			return false;
		}
		return true;
	}
	NeededPitch = Other.Location - VehicleWeapons[ActiveWeapon].WeaponFireLocation.Pitch;
	NeededPitch = NeededPitch & 65535;
	Return LimitPitch(NeededPitch) != NeededPitch;
	*/
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
		if (ActiveWeapon < VehicleWeapons.Length)
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

int32 AAGP_Vehicle::RefireRate()
{
	/*
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			Return VehicleWeapons[ActiveWeapon].AIInfo[1].RefireRate;
		}
		else
		{
			Return VehicleWeapons[ActiveWeapon].AIInfo[0].RefireRate;
		}
	}
	*/
	return 0;
}

void AAGP_Vehicle::IsFiring()
{
	//Return ActiveWeapon < VehicleWeapons.Length&& bWeaponisFiring || bWeaponisAltFiring && bHasAltFire;
}

void AAGP_Vehicle::NeedToTurn(FVector targ)
{
	//Return !ActiveWeapon < VehicleWeapons.Length&& VehicleWeapons[ActiveWeapon].bCorrectAim;
}

bool AAGP_Vehicle::FireOnRelease()
{
	/*
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			Return VehicleWeapons[ActiveWeapon].AIInfo[1].bFireOnRelease;
		}
		else
		{
			Return VehicleWeapons[ActiveWeapon].AIInfo[0].bFireOnRelease;
		}
	}
	*/
	return false;
}

float AAGP_Vehicle::ModifyThreat(float Current, APawn* Threat)
{
	/*
	if (Threat.bCanFly && ActiveWeapon < VehicleWeapons.Length && !VehicleWeapons[ActiveWeapon].AIInfo[0].bInstantHit)
	{
		Return Current - 3;
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

void AAGP_Vehicle::OpenPositionFor(APawn* p)
{
	/*
	local int32 i;
	if (Controller == None)
	{
		Return Self;
	}
	if (!Controller.SameTeamAs(p.Controller))
	{
		return nullptr;
	}
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i].Controller == None)
		{
			Return Positions[i];
		}
	}
	return nullptr;
	*/
}

void AAGP_Vehicle::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	//DisplayVehicleDebug(Canvas, YL, YPos);
}

/*
void AAGP_Vehicle::DisplayDebug(UCanvas* Canvas, out float YL, out float YPos)
{
	local int32 i;
	DisplayDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.DrawText(DebugInfo);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("AmbientSound: " $ AmbientSound);
	for (i = 0; i < VehicleWeapons.Length; i++)
	{
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.SetDrawColor(0, 0, 255);
		Canvas.DrawText("-- Weapon: " $ i $ " - " $ VehicleWeapons[i]);
		YPos += YL;
		Canvas.SetPos(4, YPos);
		VehicleWeapons[i].DisplayDebug(Canvas, YL, YPos);
	}
	YPos += YL;
	DebugInfo = "";
}
*/

void AAGP_Vehicle::PostNetBeginPlay()
{
	/*
	local int32 i;
	PostNetBeginPlay();
	if (Role == 4)
	{
		for (i = 0; i < DriverWeapons.Length; i++)
		{
			VehicleWeapons[i] = Spawn(DriverWeapons[i].WeaponClass, Self, , Location, rot(0 0 0));
			AttachToBone(VehicleWeapons[i], DriverWeapons[i].WeaponBone);
			if (!VehicleWeapons[i].bAimable)
			{
				VehicleWeapons[i].CurrentAim = rot(0 32768 0);
			}
		}
		if (ActiveWeapon < VehicleWeapons.Length)
		{
			PitchUpLimit = VehicleWeapons[ActiveWeapon].PitchUpLimit;
			PitchDownLimit = VehicleWeapons[ActiveWeapon].PitchDownLimit;
		}
		for (i = 0; i < PositionTypes.Length; i++)
		{
			Positions[i] = Spawn(PositionTypes[i].VehiclePositionClass, Self, , Location);
			if (VehicleReplicationInfo != None)
			{
				Positions[i].VehicleReplicationInfo = VehicleReplicationInfo;
			}
			Positions[i].SetBase(Self);
			Positions[i].AttachToVehicle(Self, PositionTypes[i].WeaponBone);
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
			if (Positions[i].Gun != None)
			{
				ActiveWeapon = 0;
				VehicleWeapons[0] = Positions[i].Gun;
			}
		}
	}
	if (Level.NetMode != 1 && Level.bUseHeadlights && !Level.bDropDetail || Level.DetailMode == 0)
	{
		HeadlightCorona.Length = HeadlightCoronaOffset.Length;
		for (i = 0; i < HeadlightCoronaOffset.Length; i++)
		{
			HeadlightCorona[i] = Spawn('HeadlightCorona', Self, , Location + HeadlightCoronaOffset[i] >> Rotation);
			HeadlightCorona[i].SetBase(Self);
			HeadlightCorona[i].SetRelativeRotation(rot(0 0 0));
			HeadlightCorona[i].Skins[0] = HeadlightCoronaMaterial;
			HeadlightCorona[i].MaxCoronaSize = HeadlightCoronaMaxSize * Level.HeadlightScaling;
		}
		if (HeadlightProjectorMaterial != None && Level.DetailMode == 2)
		{
			HeadlightProjector = Spawn('HeadlightProjector', Self, , Location + HeadlightProjectorOffset >> Rotation);
			HeadlightProjector.SetBase(Self);
			HeadlightProjector.SetRelativeRotation(HeadlightProjectorRotation);
			HeadlightProjector.ProjTexture = HeadlightProjectorMaterial;
			HeadlightProjector.SetDrawScale(HeadlightProjectorScale);
			HeadlightProjector.CullDistance = ShadowCullDistance;
		}
	}
	if (PawnShadow != None)
	{
		PawnShadow.Destroy();
	}
	if (Shadow != None)
	{
		Shadow.Destroy();
	}
	SetTeamNum(Team);
	TeamChanged();
	for (i = 0; i < DefaultDamageZones.Length; i++)
	{
		DamageZones[i] = new (None) class'VehicleDamageZone';
	}
	CopyDefaultDamageZonesToDamageZones();
	if (Role == 4)
	{
		InitServerDamageZones();
	}
	else
	{
		if (Role < 4)
		{
			Positions.insert(0, PositionTypes.Length);
		}
	}
	*/
}

void AAGP_Vehicle::GetPosition(int32 iPosition)
{
	/*
	if (iPosition < Positions.Length)
	{
		Return Positions[iPosition];
	}
	else
	{
		return nullptr;
	}
	*/
}

void AAGP_Vehicle::GetWeaponAim()
{
	//Return VehicleWeapons[0].CurrentAim;
}

void AAGP_Vehicle::InitServerDamageZones()
{
	/*
	local int32 i;
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i] != None)
		{
			if (Positions[i].GunClass != None && Positions[i].Gun == None)
			{
				DebugLog(DEBUG_Vehicle, Self $ " Position[" $ i $ "] doesn't have a gun spawned");
				Return;
			}
		}
		else
		{
			DebugLog(DEBUG_Vehicle, "positions == none in InitServerDamageZones");
			Return;
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
	local int32 i;
	if (TestDamageZones.Length != 0)
	{
		TestDamageZones.remove(0, TestDamageZones.Length);
	}
	TestDamageZones.insert(0, DefaultDamageZones.Length);
	for (i = 0; i < DefaultDamageZones.Length; i++)
	{
		TestDamageZones[i].ZoneName = DefaultDamageZones[i].Name;
		TestDamageZones[i].ZoneNumber = i;
		TestDamageZones[i].ArmorThreshold = DefaultDamageZones[i].ArmorThreshold;
		TestDamageZones[i].MaxHitPoints = DefaultDamageZones[i].MaxHitPoints;
		TestDamageZones[i].DamageModifier = DefaultDamageZones[i].DamageModifier;
		TestDamageZones[i].bInitialSyncToVehicleHealth = BoolToByte(DefaultDamageZones[i].bInitialSyncToVehicleHealth);
		TestDamageZones[i].bNoPassDamageToVehicle = BoolToByte(DefaultDamageZones[i].bNoPassDamageToVehicle);
		if (DefaultDamageZones[i].DamageStates.Length >= 2)
		{
			TestDamageZones[i].DS1HealthPct = DefaultDamageZones[i].DamageStates[1].DamagePct;
		}
		if (DefaultDamageZones[i].DamageStates.Length >= 3)
		{
			TestDamageZones[i].DS2HealthPct = DefaultDamageZones[i].DamageStates[2].DamagePct;
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
	local int32 i;
	if (ParticleInfo.Length != 0)
	{
		ParticleInfo.remove(0, ParticleInfo.Length);
	}
	ParticleInfo.insert(0, DefaultDamageZones.Length);
	for (i = 0; i < DefaultDamageZones.Length; i++)
	{
		ParticleInfo[i].ZoneName = DefaultDamageZones[i].Name;
		if (DefaultDamageZones[i].DamageStates.Length >= 2)
		{
			ParticleInfo[i].DS1ParticleString = IniGetString(DefaultDamageZones[i].DamageStates[1].VisualEffectClass);
		}
		if (DefaultDamageZones[i].DamageStates.Length >= 3)
		{
			ParticleInfo[i].DS2ParticleString = IniGetString(DefaultDamageZones[i].DamageStates[2].VisualEffectClass);
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
	local int32 i;
	if (TestDamageZones.Length == DefaultDamageZones.Length)
	{
		DebugLog(DEBUG_Vehicle, "Importing damage zones properties from INI file for vehicle " $ Self);
		for (i = 0; i < DefaultDamageZones.Length; i++)
		{
			if (DefaultDamageZones[i] != None)
			{
				DefaultDamageZones[i].ArmorThreshold = TestDamageZones[i].ArmorThreshold;
				DefaultDamageZones[i].MaxHitPoints = TestDamageZones[i].MaxHitPoints;
				DefaultDamageZones[i].DamageModifier = TestDamageZones[i].DamageModifier;
				DefaultDamageZones[i].bInitialSyncToVehicleHealth = ByteToBool(TestDamageZones[i].bInitialSyncToVehicleHealth);
				DefaultDamageZones[i].bNoPassDamageToVehicle = ByteToBool(TestDamageZones[i].bNoPassDamageToVehicle);
				if (DefaultDamageZones[i].DamageStates.Length >= 2)
				{
					DefaultDamageZones[i].DamageStates[1].DamagePct = TestDamageZones[i].DS1HealthPct;
				}
				if (DefaultDamageZones[i].DamageStates.Length >= 3)
				{
					DefaultDamageZones[i].DamageStates[2].DamagePct = TestDamageZones[i].DS2HealthPct;
				}
			}
		}
	}
	else
	{
		DebugLog(DEBUG_Vehicle, "Mismatch in TestDamageZones " $ TestDamageZones.Length $ " and DefaultDamageZones " $ DefaultDamageZones.Length $ " array size for " $ Self);
	}
	*/
}

void AAGP_Vehicle::IniImportParticleValues()
{
	/*
	local int32 i;
	local class<Emitter>  ParticleEffect;
	DebugLog(DEBUG_Vehicle, "Importing particle properties from INI files for vehicle " $ Self);
	for (i = 0; i < DefaultDamageZones.Length; i++)
	{
		if (ParticleInfo.Length <= i)
		{
			DebugLog(DEBUG_Vehicle, Self @ "ParticleInfo[" $ i $ "] and above not defined in INI file: Vehicle_Particles");
			Return;
		}
		if (DefaultDamageZones[i].DamageStates.Length >= 2)
		{
			if (Len(ParticleInfo[i].DS1ParticleString) > 0 && ParticleInfo[i].DS1ParticleString != "None")
			{
				ParticleEffect = class<Emitter>(DynamicLoadObject(ParticleInfo[i].DS1ParticleString, Class'Class'));
			}
			if (ParticleEffect != None)
			{
				if (DefaultDamageZones[i].DamageStates[1].VisualEffectClass != ParticleEffect)
				{
					DefaultDamageZones[i].DamageStates[1].VisualEffectClass = ParticleEffect;
				}
				ParticleEffect = None;
			}
			else
			{
				DebugLog(DEBUG_Vehicle, Self @ "ParticleInfo[" $ i $ "].DS1ParticleString is not a valid particle! Vehicle_Particles");
			}
		}
		if (DefaultDamageZones[i].DamageStates.Length >= 3)
		{
			if (Len(ParticleInfo[i].DS2ParticleString) > 0 && ParticleInfo[i].DS2ParticleString != "None")
			{
				ParticleEffect = class<Emitter>(DynamicLoadObject(ParticleInfo[i].DS2ParticleString, Class'Class'));
			}
			if (ParticleEffect != None)
			{
				if (DefaultDamageZones[i].DamageStates[2].VisualEffectClass != ParticleEffect)
				{
					DefaultDamageZones[i].DamageStates[2].VisualEffectClass = ParticleEffect;
				}
				ParticleEffect = None;
			}
			else
			{
				DebugLog(DEBUG_Vehicle, Self @ "ParticleInfo[" $ i $ "].DS2ParticleString is not a valid particle!: Vehicle_Particles");
			}
		}
	}
	*/
}

void AAGP_Vehicle::IniDetermineIniImports()
{
	/*
	if (bImportIniDamageZones && Level.NetMode == 0)
	{
		IniImportDamageValues();
	}
	if (bImportIniParticleInfo && Level.NetMode == 0)
	{
		IniImportParticleValues();
	}
	*/
}
void AAGP_Vehicle::CopyDefaultDamageZonesToDamageZones()
{
	/*
	local int32 i;
	IniDetermineIniImports();
	for (i = 0; i < DefaultDamageZones.Length; i++)
	{
		if (DefaultDamageZones[i] != None && DamageZones[i] != None)
		{
			DamageZones[i].CopyDamageZones(DefaultDamageZones[i]);
		}
	}
	IniExportDebugIniValues();
	*/
}
/*
void AAGP_Vehicle::ClientRegisterVehicleWeapon(AVehicleWeapon* W, int32 Index)
{
	
	if (W == None)
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
	if (Index < VehicleWeapons.Length && VehicleWeapons[Index] != None)
	{
		ClientRegisterVehicleWeapon(VehicleWeapons[Index], Index);
	}
	*/
}

void AAGP_Vehicle::FindEntryVehicle(APawn* p)
{
	/*
	local int32 X;
	local float dist;
	local float ClosestDist;
	local VehicleEntryPoint ClosestEntryPoint;
	if (bAIDriversOnly)
	{
		return nullptr;
	}
	ClosestDist = 100000;
	for (X = 0; X < EntryPoints.Length; X++)
	{
		DebugLog(DEBUG_Vehicle, "Checking EntryPoint: " $ EntryPoints[X]);
		dist = VSize(p.Location - GetBoneCoords(EntryPoints[X].EntryBone).Origin);
		if (dist < EntryPoints[X].EntryRadius && dist < ClosestDist)
		{
			ClosestDist = dist;
			ClosestEntryPoint = EntryPoints[X];
		}
	}
	if (ClosestEntryPoint == None)
	{
		return nullptr;
	}
	DebugLog(DEBUG_Vehicle, "Closest Entry Point: " $ ClosestEntryPoint.Name);
	if (ClosestEntryPoint.bDriverEntry && AController* == None)
	{
		Return Self;
	}
	for (X = 0; X < ClosestEntryPoint.PositionIndex.Length; X++)
	{
		if (!Positions[ClosestEntryPoint.PositionIndex[X]].bDriving)
		{
			Return Positions[ClosestEntryPoint.PositionIndex[X]];
		}
	}
	return nullptr;
	*/
}

bool AAGP_Vehicle::TryToDrive(APawn* p)
{
	/*
	local int32 X;
	local APawn* OldPawn;
	if (FlipTimeLeft > 0)
	{
		return false;
	}
	if (NeedsFlip())
	{
		Flip(Vector(p.Rotation), 1);
		return false;
	}
	if (!bTeamLocked && p.GetTeamNum() != Team)
	{
		for (X = 0; X < Positions.Length; X++)
		{
			if (Positions[X].Driver != None)
			{
				VehicleLocked(p);
				return false;
			}
		}
	}
	if (Driver != None && HumanController(Controller) == None && HumanController(p.Controller) != None)
	{
		OldPawn = Driver;
		KDriverLeave(True);
		OldPawn.Destroy();
	}
	Return TryToDrive(p);
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
	/*
	local int32 X;
	ResetTime = Level.TimeSeconds - 1;
	Instigator = Self;
	DebugLog(DEBUG_Vehicle, "Starting AGP_Vehicle::KDriverEnter");
	DebugLog(DEBUG_Vehicle, "do we have a driver animation? " $ p.HasAnim(DriveAnim));
	KDriverEnter(p);
	CloseDoor(0);
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		VehicleWeapons[ActiveWeapon].bActive = true;
	}
	Driver.bSetPCRotOnPossess = false;
	for (X = 0; X < VehicleWeapons.Length; X++)
	{
		if (VehicleWeapons[X] == None)
		{
			VehicleWeapons.remove(X, 1);
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
	/*
	local AController* C;
	local int32 X;
	DebugLog(DEBUG_Vehicle, "AGP_Vehicle::KDriverLeave start");
	if (bDriverCannotLeaveVehicle)
	{
		if (FlipTimeLeft > 0)
		{
			return false;
		}
		if (NeedsFlip())
		{
			Flip(Vector(Rotation + rot(0 16384 0)), 1);
			return false;
		}
		return false;
	}
	C = Controller;
	if (KDriverLeave(bForceLeave) || bForceLeave)
	{
		if (C != None)
		{
			C.Pawn.bSetPCRotOnPossess = C.Pawn.Default.bSetPCRotOnPossess;
			Instigator = C.Pawn;
		}
		for (X = 0; X < VehicleWeapons.Length; X++)
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

void AAGP_Vehicle::GetActiveWeaponSystem()
{
	//Return VehicleWeapons[ActiveWeapon];
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
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		VehicleWeapons[ActiveWeapon].bActive = false;
	}
	if (!bNeverReset && ParentFactory != None && VSize(Location - ParentFactory.Location) > 5000 || !FastTrace(ParentFactory.Location, Location))
	{
		if (bKeyVehicle)
		{
			ResetTime = Level.TimeSeconds + 15;
		}
		else
		{
			ResetTime = Level.TimeSeconds + 30;
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
	local int32 i;
	
	if (Driver != None)
	{
		Num = 1;
	}
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i].Driver != None)
		{
			Num++;
		}
	}
	*/
	return Num;
}

void AAGP_Vehicle::GetBotPassenger()
{
	/*
	local int32 i;
	for (i = 0; i < Positions.Length; i++)
	{
		if (AIController(Positions[i].Controller) != None)
		{
			Return AIController(Positions[i].Controller);
		}
	}
	return nullptr;
	*/
}

void AAGP_Vehicle::GetInstigator()
{
	/*
	local int32 i;
	if (Controller != None)
	{
		Return Self;
	}
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i].Controller != None)
		{
			Return Positions[i];
		}
	}
	Return Self;
	*/
}

bool AAGP_Vehicle::IsVehicleEmpty()
{
	/*
	local int32 i;
	if (Driver != None)
	{
		return false;
	}
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i].Driver != None)
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
	local int32 i;
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i].Driver != None)
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
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		if (bWeaponisFiring)
		{
			VehicleWeapons[ActiveWeapon].ClientStopFire(PC, False);
		}
		if (bWeaponisAltFiring)
		{
			VehicleWeapons[ActiveWeapon].ClientStopFire(PC, True);
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
	/*
	local int32 X;
	local PlayerController PC;
	local AController* C;
	DebugLog(DEBUG_Vehicle, "Died from: " $ DamageType);
	DebugLog(DEBUG_Vehicle, "Died Called: Destroy Track");
	if (bDeleteMe || Level.bLevelChange || bVehicleDestroyed)
	{
		Return;
	}
	bVehicleDestroyed = true;
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 28, , "AGPVehicleDied");
	}
	if (Physics != 13)
	{
		Died(Killer, DamageType, HitLocation);
		Return;
	}
	Health = Min(0, Health);
	if (Controller != None)
	{
		C = Controller;
		if (C.bIsPlayer)
		{
			PC = PlayerController(C);
			if (PC != None)
			{
				ClientKDriverLeave(PC);
			}
			else
			{
				ClientClearController();
			}
			if (bRemoteControlled || bEjectDriver && Driver != None && Driver.Health > 0)
			{
				C.UnPossess();
				C.Possess(Driver);
				if (bEjectDriver)
				{
					EjectDriver();
				}
				Driver = None;
			}
			else
			{
				C.PawnDied(Self);
			}
		}
		else
		{
			if (C.IsA('AIController'))
			{
				Level.Game.Killed(Killer, C, Self, DamageType);
			}
		}
		if (Driver != None)
		{
			if (!bRemoteControlled && !bEjectDriver)
			{
				if (!bDrawDriverInTP && PlaceExitingDriver())
				{
					Driver.StopDriving(Self);
					Driver.DrivenVehicle = Self;
				}
				Driver.TearOffMomentum = Velocity * 0.25;
				Driver.Died(Controller, Class'DamRanOver', Driver.Location);
			}
			else
			{
				if (bEjectDriver)
				{
					EjectDriver();
				}
				else
				{
					KDriverLeave(False);
				}
			}
		}
		bDriving = false;
	}
	else
	{
		Level.Game.Killed(Killer, Controller(Owner), Self, DamageType);
	}
	if (Killer != None)
	{
		TriggerEvent(Event, Self, Killer.Pawn);
		Instigator = Killer.Pawn;
	}
	else
	{
		TriggerEvent(Event, Self, None);
	}
	RanOverDamageType = DestroyedRoadKillDamageType;
	CrushedDamageType = DestroyedRoadKillDamageType;
	if (IsHumanControlled())
	{
		PlayerController(Controller).ForceDeathUpdate();
	}
	for (X = 0; X < Positions.Length; X++)
	{
		if (bRemoteControlled || bEjectDriver)
		{
			if (bEjectDriver)
			{
				Positions[X].EjectDriver();
			}
			else
			{
				Positions[X].KDriverLeave(False);
			}
		}
		Positions[X].Died(Killer, DamageType, HitLocation);
	}
	if (ParentFactory != None)
	{
		ParentFactory.VehicleDestroyed(Self);
		ParentFactory = None;
	}
	GotoState('VehicleDestroyed');
	*/
}

void AAGP_Vehicle::Destroyed()
{
	/*
	local int32 i;
	DebugLog(DEBUG_Vehicle, Self $ " destroyed called: vehicle_damage");
	if (Role == 4)
	{
		for (i = 0; i < VehicleWeapons.Length; i++)
		{
			VehicleWeapons[i].Destroy();
		}
		for (i = 0; i < Positions.Length; i++)
		{
			Positions[i].Destroy();
		}
	}
	VehicleWeapons.Length = 0;
	Positions.Length = 0;
	if (Level.NetMode != 1)
	{
		for (i = 0; i < HeadlightCorona.Length; i++)
		{
			HeadlightCorona[i].Destroy();
		}
		HeadlightCorona.Length = 0;
		if (HeadlightProjector != None)
		{
			HeadlightProjector.Destroy();
		}
		for (i = 0; i < AttachedActors.Length; i++)
		{
			AttachedActors[i].Destroy();
		}
		AttachedActors.Length = 0;
	}
	CleanUpDamageZones();
	TriggerEvent(Event, Self, None);
	*/
	Super::Destroyed();
}

void AAGP_Vehicle::CleanUpDamageZones()
{
	/*
	local int32 i;
	DebugLog(DEBUG_Vehicle, Self $ " CleanUpDamageZones");
	for (i = 0; i < DamageZones.Length; i++)
	{
		if (DamageZones[i] != None)
		{
			DamageZones[i].MeshOwner = None;
			DamageZones[i].Destroyed();
		}
		DamageZones[i] = None;
	}
	DamageZones.remove(0, DamageZones.Length);
	*/
}

void AAGP_Vehicle::VehicleCeaseFire(bool bWasAltFire)
{
	/*
	VehicleCeaseFire(bWasAltFire);
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		VehicleWeapons[ActiveWeapon].CeaseFire(Controller);
	}
	*/
}

void AAGP_Vehicle::TeamChanged()
{
	/*
	local int32 i;
	TeamChanged();
	for (i = 0; i < VehicleWeapons.Length; i++)
	{
		VehicleWeapons[i].SetTeam(Team);
	}
	*/
}

void AAGP_Vehicle::ApplyDamageMomentum(FVector ForceVector, float Momentum, float NearestZoneDist, FVector ExplosionLocation, float DamageRadius, UaDamageType* DamageType)
{
	/*
	local float MomentumDampingScale;
	if (DamageType != None)
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
	MomentumDampingScale = FClamp(MomentumDampingScale, 0, 1);
	Momentum *= MomentumDampingScale;
	if (!bDeleteMe)
	{
		KAddImpulse(Momentum * ForceVector, ExplosionLocation);
	}
	*/
}

bool AAGP_Vehicle::TakeRadiusDamage(float DamageAmount, APawn* instigatedBy, FVector ExplosionLocation, float Momentum, UaDamageType* InDamageType, float DamageRadius)
{
	/*
	local int32 i;
	local int32 j;
	local int32 NearestZone;
	local FVector BoneLoc;
	local FVector NearHitVec;
	local float damageScale;
	local float dist;
	local float NearestZoneDist;
	local float DamageDot;
	local array<int> HitZoneNums;
	local array<Vector> HitZoneLocations;
	local array<float> HitZoneDist;
	local float proctime;
	local float ActualDamage;
	local AController* Killer;
	Clock(proctime);
	NearestZoneDist = 100000000;
	for (i = 0; i < DamageZones.Length; i++)
	{
		if (DamageZones[i].DamageStates.Length == 0 || DamageZones[i].DamageStates[0].DamageBones[0] == 'None')
		{
		}
		BoneLoc = GetBoneCoords(DamageZones[i].DamageStates[0].DamageBones[0]).Origin;
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
	if (HitZoneNums.Length == 0)
	{
		return false;
	}
	NearHitVec = Normal(HitZoneLocations[NearestZone] - ExplosionLocation);
	if (Health > 0)
	{
		if (InDamageType == None)
		{
			DebugLog(DEBUG_Vehicle, "No DamageType was given for TakeRadiusDamge() on " $ Self);
			return false;
		}
		i = 0;
		if (i < HitZoneNums.Length)
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
					if (FRand() > 1 - FMax(0, 4 * HitZoneDist[i] / DamageRadius))
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
				if (Driver != None && bEjectDriver || bRemoteControlled)
				{
					if (bEjectDriver)
					{
						EjectDriver();
					}
					else
					{
						KDriverLeave(False);
					}
				}
				if (instigatedBy != None)
				{
					Killer = instigatedBy.GetKillerController();
				}
				if (Killer == None && InDamageType != None && InDamageType.Default.bDelayedDamage)
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
	DebugLog(DEBUG_Vehicle, "Vehicle " $ Self $ " final health is " $ Health $ " and TakeRadiusDamage took " $ proctime $ " ms to run");
	*/
	return true;
}

void AAGP_Vehicle::TakeProjectileImpactDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	//TakeDamage(Damage, instigatedBy, HitLocation, Momentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
}

/*
void AAGP_Vehicle::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* InDamageType, optional Actor.BoneInfo Bone, optional AController* KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	local FName ClosestBone;
	local float ActualDamage;
	local FVector X;
	local FVector Y;
	local FVector Z;
	local FVector TestLocation;
	local Emitter TempDamageParticles;
	local int32 DamInfoIndex;
	local int32 i;
	local float TempDist;
	local bool bHit_Right_Front;
	local bool bHit_Right_Back;
	local bool bHit_Left_Front;
	local bool bHit_Left_Back;
	local bool bCreateEffect;
	local bool bWheelDamage;
	local bool bTreadDamage;
	if (Health <= 0)
	{
		DebugLog(DEBUG_Vehicle, Self $ " Health already below 0, don't apply damage");
		Return;
	}
	ClosestBone = GetClosestBone(HitLocation, vect(0 0 0), TempDist);
	if (ClosestBone != 'None' && bUseNewTreadDamage || bUseNewWheelDamage)
	{
		if (bUseNewTreadDamage)
		{
			i = 0;
			if (i < TreadBones.Length - 1)
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
				for (i = 0; i < WheelBones.Length; i++)
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
	if (Vector(Rotation) Cross vect(0 0 1) Dot HitLocation - Location > 0)
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
		TempDamageParticles = Spawn(Class'em_bt_metal', Self, , HitLocation);
	}
	DamInfoIndex = 0;
	if (DamInfoIndex < NewDamageInfo.Length)
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
			if (bCreateEffect && NewDamageInfo[DamInfoIndex].DamageEffect != None)
			{
				TempDamageParticles = Spawn(NewDamageInfo[DamInfoIndex].DamageEffect, Self);
				AttachToBone(TempDamageParticles, GetClosestBone(HitLocation, vect(0 0 0), TempDist));
			}
			if (Controller != None && Health_Front_Right > 0 && Health_Front_Left > 0 && Health_Back_Left > 0 && Health_Back_Right > 0)
			{
				AIController(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, InDamageType, Bone);
			}
		}
		else
		{
			DamInfoIndex++;
		}
	}
	if (Health_Front_Right <= 0 || Health_Front_Left <= 0 || Health_Back_Left <= 0 || Health_Back_Right <= 0)
	{
		if (Level.NetMode != 3 && bSmokeGeneratorOn)
		{
			bSmokeGeneratorOn = false;
		}
		StopWeaponFiring();
		if (instigatedBy.Controller != None)
		{
			Died(instigatedBy.Controller, InDamageType, HitLocation);
		}
		else
		{
			if (instigatedBy.TempController != None)
			{
				Died(instigatedBy.TempController, InDamageType, HitLocation);
			}
			else
			{
				Log(Self $ " Warning! " $ Self $ " died without having a AController* OR a tempcontroller!");
				Died(instigatedBy.Controller, InDamageType, HitLocation);
			}
		}
		Return;
	}
	if (HitMaterial == None)
	{
		DebugLog(DEBUG_Vehicle, Self $ " - Vehicle damaged but no material was passed!");
		Return;
	}
	TakeDamage(ActualDamage, instigatedBy, HitLocation, Momentum, InDamageType);
}
*/

void AAGP_Vehicle::ZoneTakeDamage(int32 Damage, uint8 ZoneNum, APawn* instigatedBy, UaDamageType* InDamageType, FVector HitLocation)
{
	/*
	local float DamagePct;
	local float ChildDamagePct;
	local uint8 CurrentStateNum;
	local uint8 NewStateNum;
	local int32 i;
	local int32 PreHit_HitPoints;
	PreHit_HitPoints = DamageZones[ZoneNum].HitPoints;
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
	DebugLog(DEBUG_Vehicle, Self $ " - Zone " $ ZoneNum $ " hit! - HitPoints: " $ DamageZones[ZoneNum].HitPoints $ " - DamagePct: " $ DamagePct $ " at damage state " $ DamageZones[ZoneNum].CurrentDamageState $ ":Vehicle_Damage");
	NewStateNum = CheckDamageState(ZoneNum, CurrentStateNum, DamagePct);
	if (NewStateNum > CurrentStateNum)
	{
		ChangeDamageState(ZoneNum, NewStateNum);
	}
	ChildDamagePct = DamageZones[ZoneNum].DamageStates[CurrentStateNum].ChildDamagePct;
	for (i = 0; i < DamageZones[ZoneNum].ChildDamageZones.Length; i++)
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
		DamageZones[ZoneNum].MeshOwner = None;
	}
	*/
}

uint8 AAGP_Vehicle::CheckDamageState(uint8 ZoneNum, uint8 CurrentState, float DamagePct)
{
	/*
	if (DamageZones[ZoneNum].DamageStates.Length == 0)
	{
		Return 0;
	}
	if (DamageZones[ZoneNum].DamageStates.Length == CurrentState + 1)
	{
		Return CurrentState;
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
	/*
	local int32 i;
	if (Positions.Length == PositionTypes.Length)
	{
		for (i = 0; i < Positions.Length; i++)
		{
			if (Positions[i] != None)
			{
				if (!Positions[i].IsReplicationComplete())
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
	*/
	return true;
}

void AAGP_Vehicle::InitializeDamageZones()
{
	/*
	local uint8 i;
	local uint8 j;
	local uint8 k;
	local uint8 BoneSlot;
	local float DamagePct;
	for (i = 0; i < DamageZones.Length; i++)
	{
		if (DamageZones[i] == None)
		{
		}
		if (DamageZones[i].bInitialSyncToVehicleHealth)
		{
			DamageZones[i].MaxHitPoints = Health;
		}
		if (DamageZones[i].HitPoints == 0)
		{
			DamageZones[i].HitPoints = DamageZones[i].MaxHitPoints;
		}
		if (DamageZones[i].MaxHitPoints > 0)
		{
			DamagePct = DamageZones[i].HitPoints / DamageZones[i].MaxHitPoints;
		}
		else
		{
			DamagePct = 0;
		}
		if (DamageZones[i].bControlsExternalMesh)
		{
			if (Level.NetMode != 1 && DamageZones[i].MeshOwnerType == 3)
			{
				DamageZones[i].MeshOwner = AttachedActors[DamageZones[i].VehiclePositionOwnerIndex];
			}
			else
			{
				if (Positions[DamageZones[i].VehiclePositionOwnerIndex] != None)
				{
					if (DamageZones[i].MeshOwnerType == 1)
					{
						DamageZones[i].MeshOwner = Positions[DamageZones[i].VehiclePositionOwnerIndex];
					}
					else
					{
						if (DamageZones[i].MeshOwnerType == 2)
						{
							DamageZones[i].MeshOwner = Positions[DamageZones[i].VehiclePositionOwnerIndex].Gun;
						}
					}
				}
				else
				{
					DamageZones[i].MeshOwner = Self;
				}
			}
		}
		else
		{
			DamageZones[i].MeshOwner = Self;
		}
		if (Level.NetMode != 1)
		{
			for (j = 0; j < DamageZones[i].DamageStates.Length; j++)
			{
				for (k = 0; k < 8; k++)
				{
					if (DamageZones[i].DamageStates[j].DamageBones[k] == 'None')
					{
					}
					DamageZones[i].DamageStates[j].BoneSlot[k] = BoneSlot;
					BoneSlot++;
					if (!DamageZones[i].bControlsExternalMesh)
					{
						SetBoneScale(DamageZones[i].DamageStates[j].BoneSlot[k], 0, DamageZones[i].DamageStates[j].DamageBones[k]);
					}
					else
					{
						DamageZones[i].MeshOwner.SetBoneScale(DamageZones[i].DamageStates[j].BoneSlot[k], 0, DamageZones[i].DamageStates[j].DamageBones[k]);
					}
				}
			}
		}
		ChangeDamageState(i, CheckDamageState(i, 0, DamagePct));
	}
	VerifyVehicleSystemBones(False);
	*/
}

void AAGP_Vehicle::ClientInitializeDamageZones()
{
	/*
	if (IsReplicationComplete())
	{
		InitializeDamageZones();
		bClientInitComplete = true;
	}
	else
	{
		DebugLog(DEBUG_Vehicle, Self $ " replication incomplete");
	}
	*/
}

void AAGP_Vehicle::SetVehicleDamageState(uint8 NewDamageState)
{
	/*
	local int32 i;
	if (Level.NetMode != 0)
	{
		Return;
	}
	for (i = 0; i < DamageZones.Length; i++)
	{
		if (NewDamageState > DamageZones[i].DamageStates.Length - 1)
		{
			ChangeDamageState(i, DamageZones[i].DamageStates.Length - 1);
		}
		else
		{
			ChangeDamageState(i, NewDamageState);
		}
	}
	SetLocation(Location + 60 * vect(0 0 1));
	KAddImpulse(vect(0 0 0), Location);
	*/
}

void AAGP_Vehicle::SourceChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
{
	//ChangeDamageState(ZoneNum, NewStateNum);
}

bool AAGP_Vehicle::VerifyVehicleSystemBones(bool bFoundBadBones)
{
	/*
	local int32 i;
	local int32 j;
	local int32 k;
	local FName BoneName;
	local FString BoneVariable;
	if (DriverBone != 'None' && DriverBone != 'None')
	{
		BoneVariable = "DriverBone";
		bFoundBadBones = LogBadBoneNames(Self, DriverBone, bFoundBadBones, BoneVariable);
	}
	for (i = 0; i < EntryPoints.Length; i++)
	{
		BoneName = EntryPoints[i].EntryBone;
		BoneVariable = "EntryPoints[" $ i $ "].EntryBone";
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = EntryPoints[i].DoorBone;
		BoneVariable = "EntryPoints[" $ i $ "].DoorBone";
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = EntryPoints[i].DoorBoneDS1;
		BoneVariable = "EntryPoints[" $ i $ "].DoorBoneDS1";
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = EntryPoints[i].DoorBoneDS2;
		BoneVariable = "EntryPoints[" $ i $ "].DoorBoneDS2";
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < PositionTypes.Length; i++)
	{
		BoneName = PositionTypes[i].PositionBone;
		BoneVariable = "PositionTypes[" $ i $ "].PositionBone";
		if (BoneName != 'None' && BoneName != 'None')
		{
			if (!HasBone(BoneName))
			{
				if (Positions[i] != None && Positions[i].Gun != None)
				{
					if (!Positions[i].Gun.HasBone(BoneName))
					{
						bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
						bFoundBadBones = LogBadBoneNames(Positions[i].Gun, BoneName, bFoundBadBones, BoneVariable);
					}
				}
			}
		}
		BoneName = PositionTypes[i].WeaponBone;
		BoneVariable = "PositionTypes[" $ i $ "].WeaponBone";
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < Wheels.Length; i++)
	{
		BoneName = Wheels[i].BoneName;
		BoneVariable = "Wheels[" $ i $ "].BoneName";
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
		BoneName = Wheels[i].SupportBoneName;
		BoneVariable = "Wheels[" $ i $ "].SupportBoneName";
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < DamageZones.Length; i++)
	{
		if (DamageZones[i] != None)
		{
			if (!DamageZones[i].bControlsExternalMesh)
			{
				for (j = 0; j < DamageZones[i].DamageStates.Length; j++)
				{
					for (k = 0; k < 8; k++)
					{
						BoneName = DamageZones[i].DamageStates[j].DamageBones[k];
						if (BoneName != 'None' && BoneName != 'None')
						{
							bFoundBadBones = CheckBadDamageState(DamageZones[i].MeshOwner, BoneName, bFoundBadBones, i, j, k);
						}
					}
				}
			}
		}
	}
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i] != None && Positions[i].Gun != None)
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

void AAGP_Vehicle::ActorHasBone(AActor* MeshOwner, FName BoneName)
{
	/*
	if (BoneName == 'None' && BoneName == 'None')
	{
		return false;
	}
	if (MeshOwner != None && MeshOwner.HasBone(BoneName))
	{
	}
	*/
}

bool AAGP_Vehicle::LogBadBoneNames(AActor* mo, FName LookupBone, bool bBadBones, FString VariableName, FString AppendString)
{
	/*
	local FString OutputString;
	if (mo == None)
	{
		DebugLog(DEBUG_Vehicle, "Mesh Owner in LogBadBoneNames is none, breaking out");
		Return bBadBones;
	}
	if (!mo.HasBone(LookupBone))
	{
		if (!bBadBones)
		{
			DebugLog(DEBUG_Vehicle, "=========================================================== Start: Vehicle_Bone_Warning");
			DebugLog(DEBUG_Vehicle, "Bad Bones Warning for " $ mo.Class $ ":Vehicle_Bone_Warning");
			bBadBones = true;
		}
		OutputString = "Bone " $ VariableName $ " with value " $ LookupBone $ " isn't valid for skeleton " $ mo.Mesh $ " " $ AppendString;
		DebugLog(DEBUG_Vehicle, OutputString $ ":Vehicle_Bone_Warning");
	}
	*/
	return bBadBones;
}

bool AAGP_Vehicle::CheckBadDamageState(AActor* mo, FName LookupBone, bool bBadBones, int32 ZoneNum, int32 StateNum, int32 DamageBonesNum)
{
	/*
	local FString OutputString;
	if (!mo.HasBone(LookupBone))
	{
		if (ZoneNum >= 0)
		{
			OutputString = OutputString $ "DamageZones[" $ ZoneNum $ "]";
		}
		if (StateNum >= 0)
		{
			OutputString = OutputString $ ".DamageStates[" $ StateNum $ "]";
		}
		if (DamageBonesNum >= 0)
		{
			OutputString = OutputString $ ".DamageBones[" $ DamageBonesNum $ "]";
		}
		bBadBones = LogBadBoneNames(mo, LookupBone, bBadBones, OutputString);
	}
	*/
	return bBadBones;
}

void AAGP_Vehicle::ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
{
	/*
	local uint8 CurrentStateNum;
	local int32 i;
	if (DamageZones[ZoneNum] == None || DamageZones[ZoneNum].DamageStates.Length == 0)
	{
		Return;
	}
	CurrentStateNum = DamageZones[ZoneNum].CurrentDamageState;
	for (i = 0; i < 8; i++)
	{
		if (DamageZones[ZoneNum].DamageStates[CurrentStateNum].DamageBones[i] == 'None')
		{
		}
		if (Level.NetMode != 1)
		{
			if (!DamageZones[ZoneNum].bControlsExternalMesh)
			{
				SetBoneScale(DamageZones[ZoneNum].DamageStates[CurrentStateNum].BoneSlot[i], 0, DamageZones[ZoneNum].DamageStates[CurrentStateNum].DamageBones[i]);
				SetBoneScale(DamageZones[ZoneNum].DamageStates[NewStateNum].BoneSlot[i], 1, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[i]);
			}
			else
			{
				if (DamageZones[ZoneNum].MeshOwner != None && !DamageZones[ZoneNum].MeshOwner.bDeleteMe)
				{
					DamageZones[ZoneNum].MeshOwner.SetBoneScale(DamageZones[ZoneNum].DamageStates[CurrentStateNum].BoneSlot[i], 0, DamageZones[ZoneNum].DamageStates[CurrentStateNum].DamageBones[i]);
					DamageZones[ZoneNum].MeshOwner.SetBoneScale(DamageZones[ZoneNum].DamageStates[NewStateNum].BoneSlot[i], 1, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[i]);
				}
				else
				{
					DebugLog(DEBUG_Vehicle, Self @ "DamageZones[" $ ZoneNum $ "] can't process DamageState change from " $ CurrentStateNum $ " to " $ NewStateNum $ " because MeshOwner no longer exists!");
				}
			}
		}
		if (DamageZones[ZoneNum].bWheelZone)
		{
			Wheels[DamageZones[ZoneNum].WheelNum].BoneName = DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[i];
		}
	}
	if (DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect != None)
	{
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect.StopEmitter();
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect.Destroy();
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].VisualEffect = None;
	}
	if (DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass != None)
	{
		DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect = Spawn('VehicleVisualEffect', Self);
		if (!DamageZones[ZoneNum].bControlsExternalMesh)
		{
			DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.StartEmitter(DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass, Self, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[0]);
		}
		else
		{
			if (DamageZones[ZoneNum].MeshOwner != None && !DamageZones[ZoneNum].MeshOwner.bDeleteMe)
			{
				DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.StartEmitter(DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass, DamageZones[ZoneNum].MeshOwner, DamageZones[ZoneNum].DamageStates[NewStateNum].DamageBones[0]);
			}
			else
			{
				DebugLog(DEBUG_Vehicle, Self @ "DamageZones[" $ ZoneNum $ "] can't spawn " $ DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffectClass $ " because MeshOwner no longer exists!");
			}
		}
	}
	if (DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect != None && DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.EffectEmitter != None)
	{
		DamageZones[ZoneNum].DamageStates[NewStateNum].VisualEffect.EffectEmitter.LifeSpan *= DamageStateParticleTimeScaler;
	}
	if (DamageZones[ZoneNum].DamageStates[CurrentStateNum].PhysicalEffect != None)
	{
		DamageZones[ZoneNum].DamageStates[CurrentStateNum].PhysicalEffect.Deactivate(Self);
	}
	if (DamageZones[ZoneNum].DamageStates[NewStateNum].PhysicalEffect != None)
	{
		DamageZones[ZoneNum].DamageStates[NewStateNum].PhysicalEffect.Activate(Self, ZoneNum, NewStateNum);
	}
	for (i = 0; i < DamageZones[ZoneNum].WindowDamageZones.Length; i++)
	{
		if (DamageZones[ZoneNum].WindowDamageZones[i] < DamageZones.Length)
		{
			if (DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].CurrentDamageState < NewStateNum)
			{
				if (NewStateNum < DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates.Length)
				{
					DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].HitPoints *= DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates[NewStateNum].DamagePct;
					ChangeDamageState(DamageZones[ZoneNum].WindowDamageZones[i], NewStateNum);
				}
				else
				{
					DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].HitPoints *= DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates[DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates.Length].DamagePct;
					ChangeDamageState(DamageZones[ZoneNum].WindowDamageZones[i], DamageZones[DamageZones[ZoneNum].WindowDamageZones[i]].DamageStates.Length);
				}
			}
		}
	}
	DamageZones[ZoneNum].CurrentDamageState = NewStateNum;
	if (Role == 4)
	{
		DamageZoneStates[ZoneNum] = NewStateNum;
	}
	*/
}

void AAGP_Vehicle::DriverRadiusDamage(float DamageAmount, float DamageRadius, AController* EventInstigator, UaDamageType* DamageType, float Momentum, FVector HitLocation)
{
	/*
	local int32 i;
	DriverRadiusDamage(DamageAmount, DamageRadius, EventInstigator, DamageType, Momentum, HitLocation);
	for (i = 0; i < Positions.Length; i++)
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
	//if (ActiveWeapon < VehicleWeapons.Length && PlayerController(Controller) != None)
	//{
	//	VehicleWeapons[ActiveWeapon].ClientStartFire(Controller, False);
	//}
}

void AAGP_Vehicle::AltFire(float F)
{
	//Super::AltFire(F);
	//if (!bWeaponisFiring && ActiveWeapon < VehicleWeapons.Length && PlayerController(Controller) != None)
	//{
	//	VehicleWeapons[ActiveWeapon].ClientStartFire(Controller, True);
	//}
}

void AAGP_Vehicle::ClientVehicleCeaseFire(bool bWasAltFire)
{
	/*
	ClientVehicleCeaseFire(bWasAltFire);
	if (ActiveWeapon < VehicleWeapons.Length)
	{
		VehicleWeapons[ActiveWeapon].ClientStopFire(Controller, bWasAltFire);
		if (!bWasAltFire && bWeaponisAltFiring)
		{
			VehicleWeapons[ActiveWeapon].ClientStartFire(Controller, True);
		}
	}
	*/
}

void AAGP_Vehicle::TakeImpactDamage(float AccelMag)
{
	/*
	local int32 Damage;
	Damage = AccelMag * VehicleMass * ImpactDamageModifier();
	TakeRadiusDamage(Damage, Self, ImpactInfo.pos, 0, 'DamTypeVehicle', ImpactDamageRadius);
	if (ImpactDamageSounds.Length > 0)
	{
		PlaySound(ImpactDamageSounds[Rand(ImpactDamageSounds.Length - 1)], , TransientSoundVolume * 2.5);
	}
	if (Health < 0 && Level.TimeSeconds - LastImpactExplosionTime > TimeBetweenImpactExplosions)
	{
		VehicleExplosion(Normal(ImpactInfo.impactNorm), 0.5);
		LastImpactExplosionTime = Level.TimeSeconds;
	}
	*/
}

void AAGP_Vehicle::ImpactDamageModifier()
{
	//Return ImpactDamageMult;
}

void AAGP_Vehicle::KImpact(AActor* Other, FVector pos, FVector impactVel, FVector impactNorm)
{
	/*
	if (Role == 4)
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

int32 AAGP_Vehicle::ChargeBar()
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
	/*
	local uint8 Temp;
	local int32 X;
	Temp = Team;
	PrevTeam = t;
	Team = t;
	if (Temp != t)
	{
		TeamChanged();
	}
	for (X = 0; X < Positions.Length; X++)
	{
		Positions[X].SetTeamNum(t);
	}
	*/
}

bool AAGP_Vehicle::CanLean()
{
	return true;
}
void AAGP_Vehicle::LeanLeft(bool bFullLeft)
{
	//ServerChangePosition(False, Driver);
}

void AAGP_Vehicle::LeanRight(bool bFullRight)
{
	//ServerChangePosition(True, Driver);
}

void AAGP_Vehicle::ServerChangePosition(bool bNext, APawn* p)
{
	/*
	local int32 Slot;
	local int32 i;
	if (!bEnableChangePosition)
	{
		Return;
	}
	if (Driver == p)
	{
		KDriverLeave(True);
		Slot = 0;
	}
	else
	{
		i = 0;
		if (i < Positions.Length)
		{
			if (Positions[i].Driver == p)
			{
				Positions[i].KDriverLeave(True);
				Slot = i + 1;
			}
			else
			{
				i++;
			}
		}
		if (Slot == 0)
		{
			DebugLog(DEBUG_Vehicle, "ServerChangePosition() - Can't find Pawn: " $ p $ " in Vehicle: " $ Self);
			Return;
		}
	}
	if (bNext)
	{
		for (i = Slot + 1; i <= Positions.Length; i++)
		{
			if (Positions[i - 1].TryToDrive(p))
			{
				Return;
			}
		}
		if (TryToDrive(p))
		{
			Return;
		}
		for (i = 1; i <= Slot; i++)
		{
			if (Positions[i - 1].TryToDrive(p))
			{
				Return;
			}
		}
	}
	else
	{
		for (i = Slot - 1; i >= 1; i--)
		{
			if (Positions[i - 1].TryToDrive(p))
			{
				Return;
			}
		}
		if (Slot > 0 && TryToDrive(p))
		{
			Return;
		}
		for (i = Positions.Length; i >= Slot; i--)
		{
			if (Positions[i - 1].TryToDrive(p))
			{
				Return;
			}
		}
		if (TryToDrive(p))
		{
			Return;
		}
	}
	Log("ServerChangePosition() - Error switching positions, no slot was found. This should never happen.");
	*/
}

void AAGP_Vehicle::SpawnDestroyedModels()
{
	/*
	local int32 i;
	local Actor ExtraTurrets;
	local Actor NewBody;
	NewBody = Spawn(DestroyedModelClass, None, , Location, Rotation);
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i].Gun != None && Positions[i].Gun.DestroyedModelClass != None)
		{
			ExtraTurrets = Spawn(Positions[i].Gun.DestroyedModelClass, None, , Positions[i].Gun.Location, Positions[i].Gun.GetBoneRotation(Positions[i].Gun.YawBone));
			ExtraTurrets.SetBase(NewBody);
			ExtraTurrets = None;
		}
	}
	*/
}

void AAGP_Vehicle::SpawnDestructionEffects()
{
	/*
	local Emitter DestructionEffect;
	DestructionEffect = Spawn(Class'VehicleHulkBurn', Self);
	DestructionEffect.SetBase(Self);
	DestructionEffect = Spawn(Class'em_bt_PG7Bexplosion', Self);
	DestructionEffect.SetBase(Self);
	*/
}

void AAGP_Vehicle::DestroyAppearance()
{
	/*
	local int32 i;
	local KarmaParams KP;
	bDestroyAppearance = true;
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	if (Role == 4)
	{
		for (i = 0; i < VehicleWeapons.Length; i++)
		{
			if (VehicleWeapons[i].DestroyedWeaponStaticMesh != None)
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
	AmbientSound = None;
	SetStaticMesh(DestroyedVehicleMesh);
	if (Level.NetMode != 1)
	{
		bNoTeamBeacon = true;
		for (i = 0; i < HeadlightCorona.Length; i++)
		{
			HeadlightCorona[i].Destroy();
		}
		HeadlightCorona.Length = 0;
		if (HeadlightProjector != None)
		{
			HeadlightProjector.Destroy();
		}
		SpawnDestructionEffects();
	}
	KP = KarmaParams(KParams);
	if (KP != None)
	{
		KP.KStartLinVel = Velocity;
	}
	SetPhysics(0);
	KSetBlockKarma(False);
	KSetBlockKarma(True);
	SetPhysics(13);
	Skins.Length = 0;
	*/
}

void AAGP_Vehicle::VehicleExplosion(FVector MomentumNormal, float PercentMomentum)
{
	/*
	local FVector LinearImpulse;
	local FVector AngularImpulse;
	HurtRadius(ExplosionDamage, ExplosionRadius, ExplosionDamageType, ExplosionMomentum, Location);
	if (!bDisintegrateVehicle)
	{
		ExplosionCount++;
		if (Level.NetMode != 1)
		{
			ClientVehicleExplosion(False);
		}
		LinearImpulse = PercentMomentum * RandRange(DestructionLinearMomentum.Min, DestructionLinearMomentum.Max) * MomentumNormal;
		AngularImpulse = PercentMomentum * RandRange(DestructionAngularMomentum.Min, DestructionAngularMomentum.Max) * VRand();
		NetUpdateTime = Level.TimeSeconds - 1;
		KAddImpulse(LinearImpulse, vect(0 0 0));
		KAddAngularImpulse(AngularImpulse);
	}
	*/
}

void AAGP_Vehicle::ClientVehicleExplosion(bool bFinal)
{
	/*
	local int32 SoundNum;
	local PlayerController PC;
	local float dist;
	local float Scale;
	if (Level.NetMode != 1)
	{
		PC = Level.GetLocalPlayerController();
		if (PC != None && PC.ViewTarget != None)
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
	if (ExplosionSounds.Length > 0)
	{
		SoundNum = Rand(ExplosionSounds.Length);
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
	/*
	local int32 ch0;
	local int32 ch1;
	local int32 ch2;
	if (Position >= EntryPoints.Length)
	{
		Return;
	}
	if (EntryPoints[Position].DoorAnim != 'None')
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
	/*
	local FRotator DoorAxis;
	if (Position >= EntryPoints.Length)
	{
		Return;
	}
	if (EntryPoints[Position].DoorBone != 'None')
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
	if (Position >= EntryPoints.Length)
	{
		Return;
	}
	if (EntryPoints[Position].DoorBone != 'None')
	{
		SetBoneRotation(EntryPoints[Position].DoorBone, rot(0 0 0), , 1);
		SetBoneRotation(EntryPoints[Position].DoorBoneDS1, rot(0 0 0), , 1);
		SetBoneRotation(EntryPoints[Position].DoorBoneDS2, rot(0 0 0), , 1);
	}
	*/
}

void AAGP_Vehicle::SVehicleUpdateParams()
{
	/*
	local int32 i;
	SVehicleUpdateParams();
	if (Level.NetMode != 1)
	{
		for (i = 0; i < HeadlightCorona.Length; i++)
		{
			HeadlightCorona[i].SetBase(None);
			HeadlightCorona[i].SetLocation(Location + HeadlightCoronaOffset[i] >> Rotation);
			HeadlightCorona[i].SetBase(Self);
			HeadlightCorona[i].Skins[0] = HeadlightCoronaMaterial;
			HeadlightCorona[i].MaxCoronaSize = HeadlightCoronaMaxSize * Level.HeadlightScaling;
		}
		if (HeadlightProjector != None)
		{
			HeadlightProjector.SetBase(None);
			HeadlightProjector.SetLocation(Location + HeadlightProjectorOffset >> Rotation);
			HeadlightProjector.SetBase(Self);
			HeadlightProjector.SetRelativeRotation(HeadlightProjectorRotation);
			HeadlightProjector.ProjTexture = HeadlightProjectorMaterial;
			HeadlightProjector.SetDrawScale(HeadlightProjectorScale);
		}
	}
	*/
}

void AAGP_Vehicle::LimitPitch(int32 Pitch)
{
	/*
	if (ActiveWeapon >= VehicleWeapons.Length)
	{
		Return LimitPitch(Pitch);
	}
	Return VehicleWeapons[ActiveWeapon].LimitPitch(Pitch, Rotation);
	*/
}

void AAGP_Vehicle::ServerPlayHorn(int32 HornIndex)
{
	/*
	local int32 i;
	local int32 NumPositions;
	ServerPlayHorn(HornIndex);
	if (HornIndex > 0 || PlayerController(Controller) == None)
	{
		Return;
	}
	i = 0;
	if (i < Positions.Length)
	{
		if (Positions[i].Driver == None)
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
	/*
	local PlayerController PC;
	local FVector CameraLocation;
	local FRotator CameraRotation;
	local Actor ViewActor;
	if (IsLocallyControlled() && ActiveWeapon < VehicleWeapons.Length && VehicleWeapons[ActiveWeapon] != None && VehicleWeapons[ActiveWeapon].bCorrectAim)
	{
		Canvas.DrawColor = CrossHairColor;
		Canvas.DrawColor.A = 255;
		Canvas.Style = 6;
		Canvas.SetPos(Canvas.SizeX * 0.5 - CrosshairX, Canvas.SizeY * 0.5 - CrosshairY);
		Canvas.DrawTile(CrosshairTexture, CrosshairX * 2, CrosshairY * 2, 0, 0, CrosshairTexture.USize, CrosshairTexture.VSize);
	}
	PC = PlayerController(Controller);
	if (PC != None && !PC.bBehindView && HudOverlay != None)
	{
		if (!Level.IsSoftwareRendering())
		{
			CameraRotation = PC.Rotation;
			SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
			HudOverlay.SetLocation(CameraLocation + HUDOverlayOffset >> CameraRotation);
			HudOverlay.SetRotation(CameraRotation);
			Canvas.DrawActor(HudOverlay, False, False, FClamp(HUDOverlayFOV * PC.DesiredFOV / PC.DefaultFOV, 1, 170));
		}
	}
	else
	{
		ActivateOverlay(False);
	}
	*/
}

void AAGP_Vehicle::PlayHit(float Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FVector Momentum)
{
	/*
	local int32 i;
	PlayHit(Damage, instigatedBy, HitLocation, DamageType, Momentum);
	for (i = 0; i < Positions.Length; i++)
	{
		if (!Positions[i].bHasOwnHealth && Positions[i].Controller != None)
		{
			Positions[i].Controller.NotifyTakeHit(instigatedBy, HitLocation, Damage, DamageType, Momentum);
		}
	}
	*/
}

void AAGP_Vehicle::GetTurrets()
{
	//Return Positions;
}

void AAGP_Vehicle::PrecacheAnnouncer(AAnnouncerVoice* V, bool bRewardSounds)
{
}

/*
void AAGP_Vehicle::StaticPrecache(LevelInfo L)
{

	local int32 i;
	for (i = 0; i < Default.DriverWeapons.Length; i++)
	{
		Default.DriverWeapons[i].WeaponClass.StaticPrecache(L);
	}
	for (i = 0; i < Default.PositionTypes.Length; i++)
	{
		Default.PositionTypes[i].VehiclePositionClass.StaticPrecache(L);
	}
	if (Default.DestroyedVehicleMesh != None)
	{
		L.AddPrecacheStaticMesh(Default.DestroyedVehicleMesh);
	}
	if (Default.HeadlightCoronaMaterial != None)
	{
		L.AddPrecacheMaterial(Default.HeadlightCoronaMaterial);
	}
	if (Default.HeadlightProjectorMaterial != None)
	{
		L.AddPrecacheMaterial(Default.HeadlightProjectorMaterial);
	}

}
*/
void AAGP_Vehicle::UpdatePrecacheStaticMeshes()
{
	/*
	UpdatePrecacheStaticMeshes();
	if (DestroyedVehicleMesh != None)
	{
		Level.AddPrecacheStaticMesh(DestroyedVehicleMesh);
	}
	*/
}

void AAGP_Vehicle::UpdatePrecacheMaterials()
{
	/*
	if (HeadlightCoronaMaterial != None)
	{
		Level.AddPrecacheMaterial(HeadlightCoronaMaterial);
	}
	if (HeadlightProjectorMaterial != None)
	{
		Level.AddPrecacheMaterial(HeadlightProjectorMaterial);
	}
	Super::UpdatePrecacheMaterials();
	*/
}

void AAGP_Vehicle::NotifyControllerOutOfBounds(int32 Seconds)
{
	/*
	if (Controller != None)
	{
		if (PlayerController(Controller) != None)
		{
			PlayerController(Controller).myHUD.DisplayCenteredMessage(1.1, "You have left the combat zone!", "You have" @ Seconds @ "seconds to return...");
		}
	}
	*/
}

void AAGP_Vehicle::AlertClientReturnedToCombat()
{
	/*
	if (Controller != None)
	{
		if (PlayerController(Controller) != None)
		{
			PlayerController(Controller).myHUD.DisplayCenteredMessage(3, "You have returned to combat.");
		}
	}
	*/
}

void AAGP_Vehicle::KillControllerOutOfBounds()
{
	/*
	if (Controller != None)
	{
		if (PlayerController(Controller) != None)
		{
			PlayerController(Controller).myHUD.DisplayCenteredMessage(3, "Failed to return to combat.");
		}
	}
	*/
}

void AAGP_Vehicle::VehicleOutOfBoundsCheck()
{
	/*
	local int32 i;
	if (PlayerController(Controller) == None)
	{
		Return;
	}
	if (OutOfBounds > 0)
	{
		TimeOutOfBounds += 0.5;
		NotifyControllerOutOfBounds(Ceil(CurrentZoneTimeToKill - TimeOutOfBounds));
		for (i = 0; i < Positions.Length; i++)
		{
			Positions[i].NotifyControllerOutOfBounds(Ceil(CurrentZoneTimeToKill - TimeOutOfBounds));
		}
	}
	if (CurrentZoneTimeToKill - TimeOutOfBounds <= 0)
	{
		StopCustomTimer('VehicleOutOfBoundsCheck');
		OutOfBounds++;
		KilledBy(Self);
	}
	*/
}

void AAGP_Vehicle::PlaceExitingDriver()
{
	/*
	local AGP.AGP_Pawn p;
	p = AGP_Pawn(Driver);
	if (p != None && OutOfBounds > 0)
	{
		p.TimeOutOfBounds = TimeOutOfBounds;
		p.OutOfBounds = OutOfBounds;
	}
	Return PlaceExitingDriver();
	*/
}

void AAGP_Vehicle::Timer()
{
	//Super::Timer();
	CheckSmokeGenerator();
}

void AAGP_Vehicle::CheckSmokeGenerator()
{
	/*
	if (Level.NetMode == 1 || Level.NetMode == 0 && bSmokeGeneratorOn && Level.TimeSeconds > fpSmokeEndTime && fpSmokeEndTime > 0)
	{
		bSmokeGeneratorOn = false;
		Return;
	}
	if (SmokeGenerator != None && !bSmokeGeneratorOn)
	{
		SmokeGenerator.Kill();
		SmokeGenerator = None;
		Return;
	}
	if (bSmokeGeneratorOn && SmokeGenerator == None)
	{
		SpawnSmokeGenerator(45);
	}
	*/
}

void AAGP_Vehicle::SpawnSmokeGenerator(float fpSmokeLengthSeconds)
{
	/*
	SmokeGenerator = Spawn(Class'M83SmokeEmitter', Self, , Location, rot(16384 0 0));
	if (SmokeGenerator == None)
	{
		bSmokeGeneratorOn = false;
		Return;
	}
	SmokeGenerator.SetBase(Self);
	AttachToBone(SmokeGenerator, SmokeGeneratorAttachmentBone);
	SmokeGenerator._EffectDuration = fpSmokeLengthSeconds;
	fpSmokeEndTime = Level.TimeSeconds + fpSmokeLengthSeconds;
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
