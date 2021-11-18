// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"

// Sets default values
AVehicleWeapon::AVehicleWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	YawEndConstraint = 65535;
	PitchUpLimit = 5000;
	PitchDownLimit = -5536;
	RotationsPerSecond = 0.75;
	bAimable = true;
	bCorrectAim = true;
	FireInterval = 0.5;
	//ShellEjectionEmitterClass = Class'AGP_Effects.Shell_762mm_Emitter';
	//ShellEjectionRandomizer = (MeanDirection = (X = 0, Y = 0, Z = 0), bPitch = 1, PitchMean = 25, PitchMaxDeviation = 10, PitchFalloff = 1, bYaw = 1, YawMean = 95, YawMaxDeviation = 10, YawFalloff = 1, bRoll = 0, RollMean = 0, RollMaxDeviation = 0, RollFalloff = 0, SpeedMean = 500, SpeedMaxDeviation = 200, SpeedFalloff = 1, Base = (Pitch = 0, Yaw = 0, Roll = 0));
	//Shell1p = (VOffset = (X = 0, Y = 1, Z = -45), ROffset = (Pitch = 0, Yaw = 0, Roll = 0), nBone = "None");
	//shell3p = (VOffset = (X = 11, Y = 7, Z = -7), ROffset = (Pitch = 0, Yaw = 0, Roll = 0), nBone = "None");
	ShotsPerTracer = 5;
	FireSoundVolume = 255;
	FireSoundRadius = 300;
	FireSoundPitch = 1;
	AltFireSoundVolume = 160;
	AltFireSoundRadius = 300;
	AmbientSoundScaling = 2;
	DamageMin = 6;
	DamageMax = 6;
	TraceRange = 10000;
	Momentum = 1;
	PitchAnimScale = 1;
	YawAnimScale = 1;
	bAdjustAfterFire = true;
	bUseAimErrorTime = true;
	//	\\AIInfo(0) = ;
	//	\\AIInfo(1) = ;
	//DrawType = 2;
	//bIgnoreEncroachers = true;
	//bReplicateInstigator = true;
	//RemoteRole = 2;
	//NetUpdateFrequency = 5;
	//SoundVolume = 255;
	//SoundRadius = 100;
	//bCollideActors = true;
	//bBlockActors = true;
	//bProjTarget = true;
	//bNetNotify = true;
	//bUseCollisionStaticMesh = true;
	//bBlockBulletTraces = False;
	//bNoRepMesh = true;
}

// Called when the game starts or when spawned
void AVehicleWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicleWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*

State InstantFireMode
{
	void SpawnHitEffects(Actor HitActor, FVector HitLocation, FVector HitNormal, optional Material HitMaterial)
	{
		local PlayerController PC;
		if (Level.NetMode == 1)
		{
			Return;
		}
		PC = Level.GetLocalPlayerController();
		DoBulletEffect(HitActor,HitMaterial,HitLocation,HitNormal,0);
		if (PC != None && Instigator != None && Instigator.Controller == PC || VSize(PC.ViewTarget.Location - HitLocation) < 5000)
	}
	{
	}
	simulated Event ClientSpawnHitEffects()
	{
		local FVector HitLocation;
		local FVector HitNormal;
		local FVector offset;
		local Actor HitActor;
		local Material HitMaterial;
		if (Level.NetMode == 0)
		{
			Return;
		}
		offset = 20 * Normal(WeaponFireLocation - LastHitLocation);
		HitActor = Trace(HitLocation,HitNormal,LastHitLocation - offset,LastHitLocation + offset,True,,HitMaterial);
		SpawnHitEffects(HitActor,LastHitLocation,HitNormal,HitMaterial);
	}
	void AltFire(Controller C)
	{
	}
	void Fire(Controller C)
	{
		FlashMuzzleFlash();
		EjectShell();
		if (bAmbientFireSound)
		{
			AmbientSound = FireSoundClass;
		}
		else
		{
			PlayOwnedSound(FireSoundClass,0,FireSoundVolume / 255,,FireSoundRadius,FireSoundPitch,False);
		}
		TraceFire(WeaponFireLocation,WeaponFireRotation);
		TracerCounter++;
		if (ShouldSpawnTracer())
		{
			SpawnTracer(WeaponFireLocation,WeaponFireRotation);
		}
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,23,Instigator,"InstantFireMode");
		}
	}
}
State ProjectileFireMode
{
	void AltFire(Controller C)
	{
		if (AltFireProjectileClass == None)
		{
			Fire(C);
		}
		else
		{
			SpawnProjectile(AltFireProjectileClass,True);
		}
	}
	void Fire(Controller C)
	{
		local VehiclePosition WeaponPawn;
		local FRotator ImpulseRot;
		WeaponPawn = VehiclePosition(Owner);
		if (WeaponPawn != None && WeaponPawn.VehicleBase != None && WeaponPawn.VehicleBase.RecoilImpulse != 0)
		{
			ImpulseRot = GetBoneRotation(YawBone);
			ImpulseRot.Pitch = 0;
			WeaponPawn.VehicleBase.KAddImpulse(Normal(Vector(ImpulseRot)) * WeaponPawn.VehicleBase.RecoilImpulse + vect(0 0 - 2500),WeaponPawn.VehicleBase.Location,'Weapon_1_Bone');
		}
		SpawnProjectile(ProjectileClass,False);
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,23,Instigator,"ProjectileFireMode");
		}
	}
}
*/


//native void LimitPitch(int Pitch, FRotator ForwardRotation, optional int32 WeaponYaw);
void AVehicleWeapon::LimitPitch(int32 Pitch, FRotator ForwardRotation, int32 WeaponYaw)
{

}


/*
void AVehicleWeapon::DisplayDebug(Canvas Canvas, out float YL, out float YPos)
{
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.DrawText("bActive: " $ bActive @ "bCorrectAim: " $ bCorrectAim $ " AmbientSound: " $ AmbientSound);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("DebugInfo: " $ DebugInfo);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (Owner != None)
	{
		Canvas.DrawText("WeaponRotation is : " $ Owner.RelativeRotation);
		YPos += YL;
		Canvas.SetPos(4, YPos);
	}
}
*/

void AVehicleWeapon::SetInstantFire(bool bInstant)
{
	/*
	if (bInstantFire != bInstant)
	{
		SetInstantFireMode(bInstant);
	}
	*/
}

void AVehicleWeapon::SetInstantFireMode(bool bSetInstantFire)
{
	/*
	if (bSetInstantFire != bInstantFire)
	{
		bInstantFire = bSetInstantFire;
		NetUpdateTime = Level.TimeSeconds - 1;
		if (bInstantFire)
		{
			GotoState('InstantFireMode');
		}
		else
		{
			GotoState('ProjectileFireMode');
		}
	}
	*/
}

void AVehicleWeapon::ClientToggleFireMode()
{
	/*
	if (bInstantFire)
	{
		GotoState('InstantFireMode');
	}
	else
	{
		GotoState('ProjectileFireMode');
	}
	*/
}

void AVehicleWeapon::VerifyVehicleSystemBones(bool bFoundBadBones)
{
	/*
	local name BoneName;
	local string BoneVariableName;
	local AGP_Vehicle LocalVehicle;
	if (VehiclePosition(Owner) != None)
	{
		LocalVehicle = VehiclePosition(Owner).VehicleBase;
	}
	if (LocalVehicle == None)
	{
		Return False;
	}
	BoneName = YawBone;
	BoneVariableName = "YawBone";
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LocalVehicle.LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariableName);
	}
	BoneName = PitchBone;
	BoneVariableName = "PitchBone";
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LocalVehicle.LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariableName);
	}
	BoneName = WeaponFireAttachmentBone;
	BoneVariableName = "WeaponFireAttachmentBone";
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LocalVehicle.LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariableName);
	}
	BoneName = GunnerAttachmentBone;
	BoneVariableName = "GunnerAttachmentBone";
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LocalVehicle.LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariableName);
	}
	BoneName = ShellEjectionBone;
	BoneVariableName = "ShellEjectionBone";
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LocalVehicle.LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariableName);
	}
	Return bFoundBadBones;
	*/
}

void AVehicleWeapon::PostBeginPlay()
{
	/*
	YawConstraintDelta = YawEndConstraint - YawStartConstraint & 65535;
	if (AltFireInterval ~= 0)
	{
		AltFireInterval = FireInterval;
		AIInfo[1] = AIInfo[0];
	}
	if (bShowChargingBar && Owner != None)
	{
		Vehicle(Owner).bShowChargingBar = true;
	}
	if (Level.GRI != None && Level.GRI.WeaponBerserk > 1)
	{
		SetFireRateModifier(Level.GRI.WeaponBerserk);
	}
	*/
}

void AVehicleWeapon::PostNetBeginPlay()
{
	/*
	bOldInstantFire = bInstantFire;
	if (bInstantFire)
	{
		GotoState('InstantFireMode');
	}
	else
	{
		GotoState('ProjectileFireMode');
	}
	PostNetBeginPlay();
	InitEffects();
	MaxRange();
	if (Pawn(Owner) != None)
	{
		Instigator = Pawn(Owner);
	}
	*/
}

void AVehicleWeapon::MatchEnding()
{
	/*
	SetDrawType(0);
	MatchEnding();
	*/
}

void AVehicleWeapon::ToggleZoom()
{
	/*
	bOwnerNoSee = !bOwnerNoSee;
	VehiclePosition(Owner).bDrawGunOverlay = bOwnerNoSee;
	*/
}

void AVehicleWeapon::InitEffects()
{
	/*
	if (Level.NetMode == 1)
	{
		Return;
	}
	if (FlashEmitterClass != None && FlashEmitter == None || FlashEmitter.bDeleteMe)
	{
		FlashEmitter = Spawn(FlashEmitterClass, Self);
		if (FlashEmitter != None)
		{
			FlashEmitter.SetDrawScale(DrawScale);
			if (WeaponFireAttachmentBone == 'None')
			{
				FlashEmitter.SetBase(Owner);
			}
			else
			{
				AttachToBone(FlashEmitter, WeaponFireAttachmentBone);
				FlashEmitter.SetRelativeRotation(rot(0 - 16384 0));
			}
		}
	}
	if (ShellEjectionEmitterClass != None && ShellEjectionEmitter == None || ShellEjectionEmitter.bDeleteMe && ShellEjectionBone != 'None')
	{
		ShellEjectionEmitter = Spawn(ShellEjectionEmitterClass, Self);
		ShellEjectionEmitter.Initialize(ShellEjectionRandomizer, Shell1p, shell3p);
		ShellEjectionEmitter.SetLocation(Self.Location + vect(0 0 30));
		AttachToBone(ShellEjectionEmitter, ShellEjectionBone);
	}
	*/
}

void AVehicleWeapon::SetGRI(AGameReplicationInfo* GRI)
{
	/*
	if (GRI.WeaponBerserk > 1)
	{
		SetFireRateModifier(GRI.WeaponBerserk);
	}
	*/
}

void AVehicleWeapon::SetFireRateModifier(float Modifier)
{
	/*
	if (FireInterval == AltFireInterval)
	{
		FireInterval = Default.FireInterval / Modifier;
		AltFireInterval = FireInterval;
	}
	else
	{
		FireInterval = Default.FireInterval / Modifier;
		AltFireInterval = Default.AltFireInterval / Modifier;
	}
	*/
}

void AVehicleWeapon::SpawnHitEffects(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial)
{
}

void AVehicleWeapon::ClientSpawnHitEffects()
{
}

void AVehicleWeapon::ShakeView()
{
	/*
	local PlayerController p;
	if (Instigator == None)
	{
		Return;
	}
	p = PlayerController(Instigator.Controller);
	if (p != None)
	{
		p.WeaponShakeView(ShakeRotMag, ShakeRotRate, ShakeRotTime, ShakeOffsetMag, ShakeOffsetRate, ShakeOffsetTime);
	}
	*/
}

void AVehicleWeapon::ClientStartFire(AController* C, bool bAltFire)
{
	/*
	bIsAltFire = bAltFire;
	if (FireCountdown <= 0)
	{
		if (bIsRepeatingFF)
		{
			if (bIsAltFire)
			{
				ClientPlayForceFeedback(AltFireForce);
			}
			else
			{
				ClientPlayForceFeedback(FireForce);
			}
		}
		OwnerEffects();
	}
	*/
}

void AVehicleWeapon::ClientStopFire(AController* C, bool bWasAltFire)
{
	/*
	if (bIsRepeatingFF)
	{
		if (bIsAltFire)
		{
			StopForceFeedback(AltFireForce);
		}
		else
		{
			StopForceFeedback(FireForce);
		}
	}
	*/
}

void AVehicleWeapon::ClientPlayForceFeedback(FString EffectName)
{
	/*
	local PlayerController PC;
	if (Instigator == None)
	{
		Return;
	}
	PC = PlayerController(Instigator.Controller);
	if (PC != None && PC.bEnableGUIForceFeedback)
	{
		PC.ClientPlayForceFeedback(EffectName);
	}
	*/
}
void AVehicleWeapon::StopForceFeedback(FString EffectName)
{
	/*
	local PlayerController PC;
	if (Instigator == None)
	{
		Return;
	}
	PC = PlayerController(Instigator.Controller);
	if (PC != None && PC.bEnableGUIForceFeedback)
	{
		PC.StopForceFeedback(EffectName);
	}
	*/
}

void AVehicleWeapon::TakeProjectileImpactDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector aMomentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	/*
	local VehiclePosition WeaponPawn;
	WeaponPawn = VehiclePosition(Owner);
	if (WeaponPawn != None && WeaponPawn.VehicleBase != None)
	{
		if (HitMaterial == None)
		{
			HitMaterial = WeaponPawn.VehicleBase.LookupCollisionMaterial(Self);
		}
		WeaponPawn.VehicleBase.TakeDamage(Damage, instigatedBy, HitLocation, aMomentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
	}
	*/
}
void AVehicleWeapon::OwnerEffects()
{
	/*
	if (!bIsRepeatingFF)
	{
		if (bIsAltFire)
		{
			ClientPlayForceFeedback(AltFireForce);
		}
		else
		{
			ClientPlayForceFeedback(FireForce);
		}
	}
	ShakeView();
	if (Role < 4)
	{
		if (bIsAltFire)
		{
			FireCountdown = AltFireInterval;
		}
		else
		{
			FireCountdown = FireInterval;
		}
		AimLockReleaseTime = Level.TimeSeconds + FireCountdown * FireIntervalAimLock;
		FlashMuzzleFlash();
		if (!bAmbientFireSound)
		{
			if (bIsAltFire)
			{
				PlaySound(AltFireSoundClass, 0, FireSoundVolume / 255, , AltFireSoundRadius, , False);
			}
			else
			{
				PlaySound(FireSoundClass, 0, FireSoundVolume / 255, , FireSoundRadius, , False);
			}
		}
	}
	*/
}

bool AVehicleWeapon::AttemptFire(AController* C, bool bAltFire)
{
	/*
	if (Role != 4 || bForceCenterAim)
	{
		Return False;
	}
	if (FireCountdown <= 0)
	{
		CalcWeaponFire();
		if (bCorrectAim)
		{
			WeaponFireRotation = AdjustAim(bAltFire);
		}
		if (Spread > 0)
		{
			WeaponFireRotation.Pitch += Rand(Spread);
			WeaponFireRotation.Yaw += Rand(Spread);
		}
		DualFireOffset *= -1;
		Instigator.MakeNoise(1);
		if (bAltFire)
		{
			FireCountdown = AltFireInterval;
			AltFire(C);
		}
		else
		{
			FireCountdown = FireInterval;
			Fire(C);
		}
		AimLockReleaseTime = Level.TimeSeconds + FireCountdown * FireIntervalAimLock;
		Return True;
	}
	*/
	return false;
}

void AVehicleWeapon::AdjustAim(bool bAltFire)
{
	/*
	local FRotator AdjustedAim;
	local FRotator ControllerAim;
	local int32 N;
	if (bAltFire)
	{
		N = 1;
	}
	if (!SavedFireProperties[N].bInitialized)
	{
		SavedFireProperties[N].AmmoClass = None;
		if (bAltFire)
		{
			SavedFireProperties[N].ProjectileClass = AltFireProjectileClass;
		}
		else
		{
			SavedFireProperties[N].ProjectileClass = ProjectileClass;
		}
		SavedFireProperties[N].WarnTargetPct = AIInfo[N].WarnTargetPct;
		SavedFireProperties[N].MaxRange = MaxRange();
		SavedFireProperties[N].bTossed = AIInfo[N].bTossed;
		SavedFireProperties[N].bTrySplash = AIInfo[N].bTrySplash;
		SavedFireProperties[N].bLeadTarget = AIInfo[N].bLeadTarget;
		SavedFireProperties[N].bInstantHit = AIInfo[N].bInstantHit;
		SavedFireProperties[N].bInitialized = true;
	}
	if (Instigator.IsA('VehiclePosition') && Instigator.Controller == None)
	{
		ControllerAim = Pawn(Instigator.Owner).Controller.Rotation;
	}
	else
	{
		ControllerAim = Instigator.Controller.Rotation;
	}
	if (AdjustedAim == Instigator.Rotation || AdjustedAim == ControllerAim)
	{
		Return WeaponFireRotation;
	}
	else
	{
		Return WeaponFireRotation;
		AdjustedAim.Pitch = Instigator.LimitPitch(AdjustedAim.Pitch);
		Return AdjustedAim;
	}
	*/
}
void AVehicleWeapon::BestMode()
{
	//Return Rand(2);
}

void AVehicleWeapon::Fire(AController* C)
{
}

void AVehicleWeapon::AltFire(AController* C)
{
}

bool AVehicleWeapon::CanAttack(AActor* Other)
{
	/*
	local float dist;
	local float CheckDist;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector projStart;
	local Actor HitActor;
	if (Instigator == None || Instigator.Controller == None)
	{
		Return False;
	}
	dist = VSize(Instigator.Location - Other.Location);
	if (dist > MaxRange())
	{
		Return False;
	}
	if (!Instigator.Controller.LineOfSightTo(Other))
	{
		Return False;
	}
	if (ProjectileClass != None)
	{
		CheckDist = FMax(CheckDist, 0.5 * ProjectileClass.Default.Speed);
		CheckDist = FMax(CheckDist, 300);
		CheckDist = FMin(CheckDist, VSize(Other.Location - Location));
	}
	if (AltFireProjectileClass != None)
	{
		CheckDist = FMax(CheckDist, 0.5 * AltFireProjectileClass.Default.Speed);
		CheckDist = FMax(CheckDist, 300);
		CheckDist = FMin(CheckDist, VSize(Other.Location - Location));
	}
	projStart = WeaponFireLocation;
	if (bInstantFire)
	{
		HitActor = Trace(HitLocation, HitNormal, Other.Location + Other.CollisionHeight * vect(0 0 0.8), projStart, True);
	}
	else
	{
		HitActor = Trace(HitLocation, HitNormal, projStart + CheckDist * Normal(Other.Location + Other.CollisionHeight * vect(0 0 0.8) - Location), projStart, True);
	}
	if (HitActor == None || HitActor == Other || Pawn(HitActor) == None || Pawn(HitActor).Controller == None || !Instigator.Controller.SameTeamAs(Pawn(HitActor).Controller))
	{
		Return True;
	}
	*/
	return false;
}

void AVehicleWeapon::MaxRange()
{
	/*
	if (bInstantFire)
	{
		if (Instigator != None && Instigator.Region.Zone != None && Instigator.Region.Zone.bDistanceFog)
		{
			TraceRange = FClamp(Instigator.Region.Zone.DistanceFogEnd, 8000, Default.TraceRange);
		}
		else
		{
			TraceRange = Default.TraceRange;
		}
		AimTraceRange = TraceRange;
	}
	else
	{
		if (ProjectileClass != None)
		{
			AimTraceRange = ProjectileClass.GetRange();
		}
		else
		{
			AimTraceRange = 10000;
		}
	}
	Return AimTraceRange;
	*/
}

bool AVehicleWeapon::ShouldSpawnTracer()
{
	/*
	if (TracerClass != None && TracerCounter >= ShotsPerTracer)
	{
		Return True;
	}
	*/
	return false;
}

void AVehicleWeapon::SpawnTracer(FVector Start, FRotator Dir)
{
	/*
	Spawn(TracerClass, None, , Start, Dir);
	TracerCounter = 0;
	*/
}

void AVehicleWeapon::GetSource()
{
	//Return Instigator;
}

void AVehicleWeapon::DoBulletEffect(AActor* HitActor, UMaterialInstance* HitMaterial, FVector HitLocation, FVector HitNormal, EBulletImpactType BType)
{
	/*
	if (HitActor != None && HitMaterial != None)
	{
		HitMaterial.PlayBulletContactSound(GetSource(), HitLocation, HitNormal, BType);
		HitMaterial.PlayBulletContactProjector(HitActor, HitLocation, HitNormal, BType);
		HitMaterial.PlayBulletContactEmitter(GetSource(), HitLocation, HitNormal, BType);
	}
	*/
}

void AVehicleWeapon::SpawnProjectile(AProjectile* ProjClass, bool bAltFire)
{
	/*
	local Projectile p;
	local VehiclePosition WeaponPawn;
	local FVector StartLocation;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector Extent;
	CalcWeaponFire();
	if (bDoOffsetTrace)
	{
		Extent = ProjClass.Default.CollisionRadius * vect(1 1 0);
		Extent.Z = ProjClass.Default.CollisionHeight;
		WeaponPawn = VehiclePosition(Owner);
		if (WeaponPawn != None && WeaponPawn.VehicleBase != None)
		{
			if (!WeaponPawn.VehicleBase.TraceThisActor(HitLocation, HitNormal, WeaponFireLocation, WeaponFireLocation + Vector(WeaponFireRotation) * WeaponPawn.VehicleBase.CollisionRadius * 1.5, Extent))
			{
				StartLocation = HitLocation;
			}
			else
			{
				StartLocation = WeaponFireLocation + Vector(WeaponFireRotation) * ProjClass.Default.CollisionRadius * 1.1;
			}
		}
		else
		{
			if (!Owner.TraceThisActor(HitLocation, HitNormal, WeaponFireLocation, WeaponFireLocation + Vector(WeaponFireRotation) * Owner.CollisionRadius * 1.5, Extent))
			{
				StartLocation = HitLocation;
			}
			else
			{
				StartLocation = WeaponFireLocation + Vector(WeaponFireRotation) * ProjClass.Default.CollisionRadius * 1.1;
			}
		}
	}
	else
	{
		StartLocation = WeaponFireLocation;
	}
	p = Spawn(ProjClass, Self, , StartLocation + Vector(WeaponFireRotation) * 32, WeaponFireRotation);
	if (p != None)
	{
		if (bInheritVelocity)
		{
			p.Velocity = Instigator.Velocity;
		}
		FlashMuzzleFlash();
		if (bAltFire)
		{
			if (bAmbientAltFireSound)
			{
				AmbientSound = AltFireSoundClass;
			}
			else
			{
				PlayOwnedSound(AltFireSoundClass, 0, FireSoundVolume / 255, , AltFireSoundRadius, , False);
			}
		}
		else
		{
			if (bAmbientFireSound)
			{
				AmbientSound = FireSoundClass;
			}
			else
			{
				PlayOwnedSound(FireSoundClass, 0, FireSoundVolume / 255, , FireSoundRadius, , False);
			}
		}
	}
	Return p;
	*/
}

void AVehicleWeapon::CeaseFire(AController* C)
{
	/*
	FlashCount = 0;
	HitCount = 0;
	if (bAmbientFireSound || bAmbientAltFireSound)
	{
		AmbientSound = None;
	}
	*/
}

void AVehicleWeapon::FlashMuzzleFlash()
{
	/*
	if (Role == 4)
	{
		FlashCount++;
		NetUpdateTime = Level.TimeSeconds - 1;
	}
	else
	{
		CalcWeaponFire();
	}
	if (FlashEmitter != None)
	{
		MuzzleFlash();
	}
	*/
}

void AVehicleWeapon::MuzzleFlash()
{
	/*
	local int32 i;
	if (FlashEmitter != None)
	{
		for (i = 0; i < FlashEmitter.EmitterCount(); i++)
		{
			FlashEmitter.Emitters[i].SpawnParticle(FlashEmitter.Emitters[i].iFlashSpawnCount);
		}
		if (BaseMuzzleFlashEmitter(FlashEmitter) != None)
		{
			BaseMuzzleFlashEmitter(FlashEmitter).DynamicFlash();
		}
	}
	*/
}

void AVehicleWeapon::EjectShell()
{
	/*
	if (ShellEjectionEmitter != None)
	{
		ShellEjectionEmitter.SetFirstPerson(False);
		ShellEjectionEmitter.Eject(False);
	}
	*/
}
void AVehicleWeapon::Destroyed()
{
	/*
	DestroyEffects();
	Destroyed();
	*/
}
void AVehicleWeapon::DestroyEffects()
{
	/*
	if (FlashEmitter != None)
	{
		FlashEmitter.Destroy();
	}
	if (EffectEmitter != None)
	{
		EffectEmitter.Destroy();
	}
	if (ShellEjectionEmitter != None)
	{
		ShellEjectionEmitter.Destroy();
	}
	*/
}
void AVehicleWeapon::SetTeam(uint8 t)
{
	Team = t;
}

void AVehicleWeapon::SimulateTraceFire(FVector &Start, FRotator &Dir, FVector &HitLocation, FVector &HitNormal)
{
	/*
	local FVector X;
	local FVector End;
	local Actor Other;
	local VehiclePosition WeaponPawn;
	local Vehicle VehicleInstigator;
	if (bDoOffsetTrace)
	{
		WeaponPawn = VehiclePosition(Owner);
		if (WeaponPawn != None && WeaponPawn.VehicleBase != None)
		{
			if (!WeaponPawn.VehicleBase.TraceThisActor(HitLocation, HitNormal, Start, Start + Vector(Dir) * WeaponPawn.VehicleBase.CollisionRadius * 1.5))
			{
				Start = HitLocation;
			}
		}
		else
		{
			if (!Owner.TraceThisActor(HitLocation, HitNormal, Start, Start + Vector(Dir) * Owner.CollisionRadius * 1.5))
			{
				Start = HitLocation;
			}
		}
	}
	X = Vector(Dir);
	End = Start + TraceRange * X;
	VehicleInstigator = Vehicle(Instigator);
	if (VehicleInstigator != None && VehicleInstigator.Driver != None)
	{
		VehicleInstigator.Driver.bBlockZeroExtentTraces = False;
		Other = Trace(HitLocation, HitNormal, End, Start, True);
		VehicleInstigator.Driver.bBlockZeroExtentTraces = true;
	}
	else
	{
		Other = Trace(HitLocation, HitNormal, End, Start, True);
	}
	if (Other != None && Other != Instigator)
	{
		if (!Other.bWorldGeometry)
		{
			if (Vehicle(Other) != None || Pawn(Other) == None)
			{
				LastHitLocation = HitLocation;
			}
			HitNormal = vect(0 0 0);
		}
		else
		{
			LastHitLocation = HitLocation;
		}
	}
	else
	{
		HitLocation = End;
		HitNormal = vect(0 0 0);
	}
	*/
}


void AVehicleWeapon::TraceFire(FVector Start, FRotator Dir)
{
	/*
	local FVector X;
	local FVector End;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector RefNormal;
	local Material HitMaterial;
	local Actor.BoneInfo HitBone;
	local Actor Other;
	local VehiclePosition WeaponPawn;
	local int32 Damage;
	local bool bDoReflect;
	local int32 ReflectNum;
	MaxRange();
	WeaponPawn = VehiclePosition(Owner);
	if (bDoOffsetTrace)
	{
		if (WeaponPawn != None && WeaponPawn.VehicleBase != None)
		{
			if (!WeaponPawn.VehicleBase.TraceThisActor(HitLocation, HitNormal, Start, Start + Vector(Dir) * WeaponPawn.VehicleBase.CollisionRadius * 1.5))
			{
				Start = HitLocation;
			}
		}
		else
		{
			if (!Owner.TraceThisActor(HitLocation, HitNormal, Start, Start + Vector(Dir) * Owner.CollisionRadius * 1.5))
			{
				Start = HitLocation;
			}
		}
	}
	ReflectNum = 0;
	if (True)
	{
		bDoReflect = False;
		X = Vector(Dir);
		End = Start + TraceRange * X;
		if (WeaponPawn.VehicleBase != None)
		{
			WeaponPawn.VehicleBase.SetVehicleZeroExtentCollision(False);
			Other = BoneTrace(HitLocation, HitNormal, End, Start, HitMaterial, HitBone, True);
			WeaponPawn.VehicleBase.SetVehicleZeroExtentCollision(True);
		}
		if (Other != None && Other != Instigator || ReflectNum > 0)
		{
			if (!Other.bWorldGeometry)
			{
				Damage = DamageMin + Rand(DamageMax - DamageMin);
				if (Vehicle(Other) != None || Pawn(Other) == None)
				{
					LastHitLocation = HitLocation;
					HitCount++;
					SpawnHitEffects(Other, HitLocation, HitNormal, HitMaterial);
				}
				Other.TakeDamage(Damage, Instigator, HitLocation, Momentum * X, DamageType, HitBone, , Self, HitMaterial);
				HitNormal = vect(0 0 0);
			}
			else
			{
				LastHitLocation = HitLocation;
				HitCount++;
				SpawnHitEffects(Other, HitLocation, HitNormal, HitMaterial);
			}
		}
		else
		{
			HitLocation = End;
			HitNormal = vect(0 0 0);
			HitCount++;
			LastHitLocation = HitLocation;
		}
		SpawnBeamEffect(Start, Dir, HitLocation, HitNormal, ReflectNum);
		if (bDoReflect && ++ReflectNum < 4)
		{
			Start = HitLocation;
			Dir = RefNormal;
		}
		else
		{
		}
	}
	NetUpdateTime = Level.TimeSeconds - 1;
	*/
}
void AVehicleWeapon::SpawnBeamEffect(FVector Start, FRotator Dir, FVector HitLocation, FVector HitNormal, int32 ReflectNum)
{
}
void AVehicleWeapon::CalcWeaponFire()
{
	/*
	local Object.Coords WeaponBoneCoords;
	local FVector CurrentFireOffset;
	WeaponBoneCoords = GetBoneCoords(WeaponFireAttachmentBone);
	CurrentFireOffset = WeaponFireOffset * vect(1 0 0) + DualFireOffset * vect(0 1 0);
	WeaponFireRotation = Vector(CurrentAim) >> Rotation;
	WeaponFireLocation = WeaponBoneCoords.Origin + CurrentFireOffset >> WeaponFireRotation;
	if (bDualIndependantTargeting)
	{
		WeaponFireRotation = CurrentHitLocation - WeaponFireLocation;
	}
	*/
}
void AVehicleWeapon::PostNetReceive()
{
	/*
	if (Instigator == None)
	{
		Instigator = Pawn(Owner);
	}
	if (VehiclePosition(Owner) != None && VehiclePosition(Owner).Gun == None)
	{
		if (VehiclePosition(Owner).Gun == Self)
		{
			Return;
		}
		else
		{
			VehiclePosition(Owner).Gun = Self;
		}
	}
	*/
}

/*
void AVehicleWeapon::StaticPrecache(LevelInfo L)
{
	//L.AddPrecacheStaticMesh(Default.DestroyedWeaponStaticMesh);
}
*/

void AVehicleWeapon::UpdatePrecacheStaticMeshes()
{
	/*
	Level.AddPrecacheStaticMesh(Default.DestroyedWeaponStaticMesh);
	UpdatePrecacheStaticMeshes();
	*/
}

void AVehicleWeapon::UpdatePrecacheMaterials()
{
	//UpdatePrecacheMaterials();
}

