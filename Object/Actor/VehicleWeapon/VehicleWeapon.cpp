// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/BaseShellEmitter.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/AGP_DestroyedVehicleModels.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"

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
	ShellEjectionRandomizer = FRotationRandomizer({FVector(0, 0, 0), 1, 25, 10, 1, 1, 95, 10, 1, 0, 0, 0, 0, 500, 200, 1, FRotator(0, 0, 0)});
	Shell1p = FBoneOffset({ FVector(0, 1, -4.5), FRotator(0, 0, 0), "None" });
	shell3p = FBoneOffset({ FVector(11, 7, -7), FRotator(0, 0, 0), "None" });
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

	//DrawType = DT_Mesh;
	//bIgnoreEncroachers = true;
	//bReplicateInstigator = true;
	//RemoteRole = ROLE_SimulatedProxy;
	NetUpdateFrequency = 5;
	//SoundVolume = 255;
	//SoundRadius = 100;
	//bCollideActors = true;
	//bBlockActors = true;
	//bProjTarget = true;
	//bNetNotify = true;
	//bUseCollisionStaticMesh = true;
	//bBlockBulletTraces = false;
	//bNoRepMesh = true;
}

/*
State InstantFireMode
{
	Function Fire(AController* C)
	{
		FlashMuzzleFlash();
		EjectShell();
		if (bAmbientFireSound)
		{
			AmbientSound=FireSoundClass;
		}
		else
		{
			PlayOwnedSound(FireSoundClass,0,(FireSoundVolume / 255),,FireSoundRadius,FireSoundPitch,false);
		}
		TraceFire(WeaponFireLocation,WeaponFireRotation);
		TracerCounter ++;
		if (ShouldSpawnTracer())
		{
			SpawnTracer(WeaponFireLocation,WeaponFireRotation);
		}
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(Self,23,Instigator,"InstantFireMode");
		}
	}
	Function AltFire(AController* C)
	{
	}
	simulated Event ClientSpawnHitEffects()
	{
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector offset = FVector(0,0,0);
		AActor* HitActor = nullptr;
		UMaterial* HitMaterial = nullptr;
		if (Level.NetMode == NM_Standalone)
		{
			return;
		}
		offset=(float(20) * Normal((WeaponFireLocation - LastHitLocation)));
		HitActor=Trace(HitLocation,HitNormal,(LastHitLocation - offset),(LastHitLocation + offset),true,,HitMaterial);
		SpawnHitEffects(HitActor,LastHitLocation,HitNormal,HitMaterial);
	}
	simulated Function SpawnHitEffects(AActor* HitActor, Vector HitLocation, Vector HitNormal, UMaterial* HitMaterial)
	{
		APlayerController* PC = nullptr;
		if (Level.NetMode == NM_DedicatedServer)
		{
			return;
		}
		PC=Level.GetLocalPlayerController();
		DoBulletEffect(HitActor,HitMaterial,HitLocation,HitNormal,0);
		if ((PC != nullptr) && (((Instigator != nullptr) && (Instigator.Controller == PC)) || (VSize((PC.ViewTarget.Location - HitLocation)) < float(5000))))
		{
		}
	}
}
*/

/*
State ProjectileFireMode
{
	Function Fire(AController* C)
	{
		AVehiclePosition* WeaponPawn = nullptr;
		FRotator ImpulseRot = FRotator(0,0,0);
		WeaponPawn=VehiclePosition(Owner);
		if (((WeaponPawn != nullptr) && (WeaponPawn.VehicleBase != nullptr)) && (WeaponPawn.VehicleBase.RecoilImpulse != 0))
		{
			ImpulseRot=GetBoneRotation(YawBone);
			ImpulseRot.Pitch=0;
			WeaponPawn.VehicleBase.KAddImpulse(((Normal( Vector(ImpulseRot)) * WeaponPawn.VehicleBase.RecoilImpulse) + vect(0,0,-2500)),WeaponPawn.VehicleBase.Location,"Weapon_1_Bone");
		}
		SpawnProjectile(ProjectileClass,false);
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(Self,23,Instigator,"ProjectileFireMode");
		}
	}
	Function AltFire(AController* C)
	{
		if (AltFireProjectileClass == nullptr)
		{
			Fire(C);
		}
		else
		{
			SpawnProjectile(AltFireProjectileClass,true);
		}
	}
}
*/

// Called when the game starts or when spawned
void AVehicleWeapon::BeginPlay()
{
	//Super::BeginPlay();
}

// Called every frame
void AVehicleWeapon::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
}

//native void LimitPitch(int Pitch, FRotator ForwardRotation, optional int32 WeaponYaw);
int32 AVehicleWeapon::LimitPitch(int32 Pitch, FRotator ForwardRotation, int32 WeaponYaw)
{
	return 0;    //FAKE   /ELiZ
}

void AVehicleWeapon::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.DrawText("bActive: " $ bActive @ "bCorrectAim: " $ bCorrectAim $ " AmbientSound: " $ AmbientSound);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("DebugInfo: " $ DebugInfo);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (Owner != nullptr)
	{
		Canvas.DrawText("WeaponRotation is : " $ Owner.RelativeRotation);
		YPos += YL;
		Canvas.SetPos(4, YPos);
	}
	*/
}

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
	if (bSetInstantFire != bInstantFire)
	{
		bInstantFire = bSetInstantFire;
		//NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
		if (bInstantFire)
		{
			//GotoState('InstantFireMode');
		}
		else
		{
			//GotoState('ProjectileFireMode');
		}
	}
}

void AVehicleWeapon::ClientToggleFireMode()
{
	if (bInstantFire)
	{
		//GotoState('InstantFireMode');
	}
	else
	{
		//GotoState('ProjectileFireMode');
	}
}

bool AVehicleWeapon::VerifyVehicleSystemBones(bool bFoundBadBones)
{
	FName BoneName = "";
	FString BoneVariableName = "";
	AAGP_Vehicle* LocalVehicle = nullptr;
	/*
	if (VehiclePosition(Owner) != nullptr)
	{
		LocalVehicle = VehiclePosition(Owner).VehicleBase;
	}
	if (LocalVehicle == nullptr)
	{
		return false;
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
	*/
	return bFoundBadBones;
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
	if (bShowChargingBar && Owner != nullptr)
	{
		Vehicle(Owner).bShowChargingBar = true;
	}
	if (Level.GRI != nullptr && Level.GRI.WeaponBerserk > 1)
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
	if (Pawn(Owner) != nullptr)
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
	if (FlashEmitterClass != nullptr && FlashEmitter == nullptr || FlashEmitter.bDeleteMe)
	{
		FlashEmitter = Spawn(FlashEmitterClass, Self);
		if (FlashEmitter != nullptr)
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
	if (ShellEjectionEmitterClass != nullptr && ShellEjectionEmitter == nullptr || ShellEjectionEmitter.bDeleteMe && ShellEjectionBone != 'None')
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
	if (Instigator == nullptr)
	{
		Return;
	}
	p = PlayerController(Instigator.Controller);
	if (p != nullptr)
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
	if (Instigator == nullptr)
	{
		Return;
	}
	PC = PlayerController(Instigator.Controller);
	if (PC != nullptr && PC.bEnableGUIForceFeedback)
	{
		PC.ClientPlayForceFeedback(EffectName);
	}
	*/
}
void AVehicleWeapon::StopForceFeedback(FString EffectName)
{
	/*
	local PlayerController PC;
	if (Instigator == nullptr)
	{
		Return;
	}
	PC = PlayerController(Instigator.Controller);
	if (PC != nullptr && PC.bEnableGUIForceFeedback)
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
	if (WeaponPawn != nullptr && WeaponPawn.VehicleBase != nullptr)
	{
		if (HitMaterial == nullptr)
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
				PlaySound(AltFireSoundClass, 0, FireSoundVolume / 255, , AltFireSoundRadius, , false);
			}
			else
			{
				PlaySound(FireSoundClass, 0, FireSoundVolume / 255, , FireSoundRadius, , false);
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
		return false;
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
		return true;
	}
	*/
	return false;
}

FRotator AVehicleWeapon::AdjustAim(bool bAltFire)
{
	FRotator AdjustedAim = FRotator(0, 0, 0);
	FRotator ControllerAim = FRotator(0,0,0);
	int32 N = 0;
	if (bAltFire)
	{
		N = 1;
	}
	/*
	if (!SavedFireProperties[N].bInitialized)
	{
		SavedFireProperties[N].AmmoClass = nullptr;
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
	if (Instigator.IsA('VehiclePosition') && Instigator.Controller == nullptr)
	{
		ControllerAim = Pawn(Instigator.Owner).Controller.Rotation;
	}
	else
	{
		ControllerAim = Instigator.Controller.Rotation;
	}
	if (AdjustedAim == Instigator.Rotation || AdjustedAim == ControllerAim)
	{
		return WeaponFireRotation;
	}
	else
	{
		return WeaponFireRotation;
		AdjustedAim.Pitch = Instigator.LimitPitch(AdjustedAim.Pitch);
		return AdjustedAim;
	}
	*/
	return FRotator(0, 0, 0);
}

uint8 AVehicleWeapon::BestMode()
{
	return FMath::Rand() * 2;
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
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		return false;
	}
	dist = VSize(Instigator.Location - Other.Location);
	if (dist > MaxRange())
	{
		return false;
	}
	if (!Instigator.Controller.LineOfSightTo(Other))
	{
		return false;
	}
	if (ProjectileClass != nullptr)
	{
		CheckDist = FMax(CheckDist, 0.5 * ProjectileClass.Default.Speed);
		CheckDist = FMax(CheckDist, 300);
		CheckDist = FMin(CheckDist, VSize(Other.Location - Location));
	}
	if (AltFireProjectileClass != nullptr)
	{
		CheckDist = FMax(CheckDist, 0.5 * AltFireProjectileClass.Default.Speed);
		CheckDist = FMax(CheckDist, 300);
		CheckDist = FMin(CheckDist, VSize(Other.Location - Location));
	}
	projStart = WeaponFireLocation;
	if (bInstantFire)
	{
		HitActor = Trace(HitLocation, HitNormal, Other.Location + Other.CollisionHeight * vect(0 0 0.8), projStart, true);
	}
	else
	{
		HitActor = Trace(HitLocation, HitNormal, projStart + CheckDist * Normal(Other.Location + Other.CollisionHeight * vect(0 0 0.8) - Location), projStart, true);
	}
	if (HitActor == nullptr || HitActor == Other || Pawn(HitActor) == nullptr || Pawn(HitActor).Controller == nullptr || !Instigator.Controller.SameTeamAs(Pawn(HitActor).Controller))
	{
		return true;
	}
	*/
	return false;
}

float AVehicleWeapon::MaxRange()
{
	/*
	if (bInstantFire)
	{
		if (Instigator != nullptr && Instigator.Region.Zone != nullptr && Instigator.Region.Zone.bDistanceFog)
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
		if (ProjectileClass != nullptr)
		{
			AimTraceRange = ProjectileClass.GetRange();
		}
		else
		{
			AimTraceRange = 10000;
		}
	}
	*/
	return AimTraceRange;
}

bool AVehicleWeapon::ShouldSpawnTracer()
{
	/*
	if (TracerClass != nullptr && TracerCounter >= ShotsPerTracer)
	{
		return true;
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

AActor* AVehicleWeapon::GetSource()
{
	return GetInstigator();
}

void AVehicleWeapon::DoBulletEffect(AActor* HitActor, UMaterialInstance* HitMaterial, FVector HitLocation, FVector HitNormal, EBulletImpactType BType)
{
	/*
	if (HitActor != nullptr && HitMaterial != nullptr)
	{
		HitMaterial.PlayBulletContactSound(GetSource(), HitLocation, HitNormal, BType);
		HitMaterial.PlayBulletContactProjector(HitActor, HitLocation, HitNormal, BType);
		HitMaterial.PlayBulletContactEmitter(GetSource(), HitLocation, HitNormal, BType);
	}
	*/
}

AProjectile* AVehicleWeapon::SpawnProjectile(AProjectile* ProjClass, bool bAltFire)
{
	AProjectile* p = nullptr;
	AVehiclePosition* WeaponPawn = nullptr;
	FVector StartLocation = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector Extent = FVector(0,0,0);
	/*
	CalcWeaponFire();
	if (bDoOffsetTrace)
	{
		Extent = ProjClass.Default.CollisionRadius * vect(1 1 0);
		Extent.Z = ProjClass.Default.CollisionHeight;
		WeaponPawn = VehiclePosition(Owner);
		if (WeaponPawn != nullptr && WeaponPawn.VehicleBase != nullptr)
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
	if (p != nullptr)
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
				PlayOwnedSound(AltFireSoundClass, 0, FireSoundVolume / 255, , AltFireSoundRadius, , false);
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
				PlayOwnedSound(FireSoundClass, 0, FireSoundVolume / 255, , FireSoundRadius, , false);
			}
		}
	}
	*/
	return p;
}

void AVehicleWeapon::CeaseFire(AController* C)
{
	FlashCount = 0;
	HitCount = 0;
	if (bAmbientFireSound || bAmbientAltFireSound)
	{
		//AmbientSound = nullptr;
	}
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
	if (FlashEmitter != nullptr)
	{
		MuzzleFlash();
	}
	*/
}

void AVehicleWeapon::MuzzleFlash()
{
	/*
	local int32 i;
	if (FlashEmitter != nullptr)
	{
		for (i = 0; i < FlashEmitter.EmitterCount(); i++)
		{
			FlashEmitter.Emitters[i].SpawnParticle(FlashEmitter.Emitters[i].iFlashSpawnCount);
		}
		if (BaseMuzzleFlashEmitter(FlashEmitter) != nullptr)
		{
			BaseMuzzleFlashEmitter(FlashEmitter).DynamicFlash();
		}
	}
	*/
}

void AVehicleWeapon::EjectShell()
{
	if (ShellEjectionEmitter != nullptr)
	{
		ShellEjectionEmitter->SetFirstPerson(false,false);
		ShellEjectionEmitter->Eject(false);
	}
}

void AVehicleWeapon::Destroyed()
{
	DestroyEffects();
	Destroyed();
}

void AVehicleWeapon::DestroyEffects()
{
	if (FlashEmitter != nullptr)
	{
		FlashEmitter->Destroy();
	}
	if (EffectEmitter != nullptr)
	{
		EffectEmitter->Destroy();
	}
	if (ShellEjectionEmitter != nullptr)
	{
		ShellEjectionEmitter->Destroy();
	}
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
		if (WeaponPawn != nullptr && WeaponPawn.VehicleBase != nullptr)
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
	if (VehicleInstigator != nullptr && VehicleInstigator.Driver != nullptr)
	{
		VehicleInstigator.Driver.bBlockZeroExtentTraces = false;
		Other = Trace(HitLocation, HitNormal, End, Start, true);
		VehicleInstigator.Driver.bBlockZeroExtentTraces = true;
	}
	else
	{
		Other = Trace(HitLocation, HitNormal, End, Start, True);
	}
	if (Other != nullptr && Other != Instigator)
	{
		if (!Other.bWorldGeometry)
		{
			if (Vehicle(Other) != nullptr || Pawn(Other) == nullptr)
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
		if (WeaponPawn != nullptr && WeaponPawn.VehicleBase != nullptr)
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
	if (true)
	{
		bDoReflect = false;
		X = Vector(Dir);
		End = Start + TraceRange * X;
		if (WeaponPawn.VehicleBase != nullptr)
		{
			WeaponPawn.VehicleBase.SetVehicleZeroExtentCollision(false);
			Other = BoneTrace(HitLocation, HitNormal, End, Start, HitMaterial, HitBone, true);
			WeaponPawn.VehicleBase.SetVehicleZeroExtentCollision(true);
		}
		if (Other != nullptr && Other != Instigator || ReflectNum > 0)
		{
			if (!Other.bWorldGeometry)
			{
				Damage = DamageMin + Rand(DamageMax - DamageMin);
				if (Vehicle(Other) != nullptr || Pawn(Other) == nullptr)
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
	if (Instigator == nullptr)
	{
		Instigator = Pawn(Owner);
	}
	if (VehiclePosition(Owner) != nullptr && VehiclePosition(Owner).Gun == nullptr)
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

void AVehicleWeapon::StaticPrecache(ALevelInfo* L)
{
	//L.AddPrecacheStaticMesh(Default.DestroyedWeaponStaticMesh);
}

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

