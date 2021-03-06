// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeaponFPOverlay/VehicleWeaponFPOverlay.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "Engine/Canvas.h"

AVehiclePosition::AVehiclePosition()
{
	CameraHistory.SetNum(5);
	bHistoryWarmup = true;
	bHasAltFire = true;
	PositionsIndex = -1;
	bDrawVehicleShadow = false;
	bDrawDriverInTP = true;
	bTurnInPlace = true;
	bFollowLookDir = true;
	bDrawMeshInFP = true;
	bZeroPCRotOnEntry = false;
	bDesiredBehindView = false;
	EntryRadius = 50;
	//bCrawler = true;
	//bIgnoreForces = true;
	//bStationary = true;
	//bSpecialCalcView = true;
	BaseEyeHeight = 300;
	//bSetPCRotOnPossess = false;
	//LandMovementState = "PlayerTurreting";
	//DrawType = 0;
	//bAcceptsProjectors = false;
	//bIgnoreEncroachers = true;
	//bNetInitialRotation = true;
	//NetPriority = 0.5;
	//bCollideActors = false;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bProjTarget = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
}

void AVehiclePosition::CreateVRI()
{
}

int32 AVehiclePosition::GetVehicleNumber()
{
	if (VehicleBase != nullptr)
	{
		return VehicleBase->GetVehicleNumber();
	}
	else
	{
		return -1;
	}
}

int32 AVehiclePosition::GetVehiclePositionIndex(AVehicle* VehiclePosition)
{
	if (VehicleBase != nullptr)
	{
		return VehicleBase->GetVehiclePositionIndex(VehiclePosition);
	}
	else
	{
		return -1;
	}
}

void AVehiclePosition::AttachFlag(AActor* FlagActor)
{
	if (VehicleBase != nullptr)
	{
		VehicleBase->AttachFlag(FlagActor);
	}
	else
	{
		AttachFlag(FlagActor);
	}
}

AVehicle* AVehiclePosition::GetMoveTargetFor(APawn* p)
{
	if (VehicleBase != nullptr)
	{
		return VehicleBase;
	}
	return this;
}

bool AVehiclePosition::HasWeapon()
{
	return Gun != nullptr;
}

APawn* AVehiclePosition::GetAimTarget()
{
	if (VehicleBase != nullptr)
	{
		return VehicleBase;
	}
	return this;
}

bool AVehiclePosition::CanAttack(AActor* Other)
{
	if (Gun != nullptr)
	{
		return Gun->CanAttack(Other);
	}
	return false;
}

bool AVehiclePosition::TooCloseToAttack(AActor* Other)
{
	int32 NeededPitch=0;
	/*
	if (Gun == nullptr || VSize(Location - Other.Location) > 2500)
	{
		return false;
	}
	NeededPitch = Other.Location - Gun.WeaponFireLocation.Pitch;
	NeededPitch = NeededPitch & 65535;
	return LimitPitch(NeededPitch) == NeededPitch;
	*/

	return false;    //FAKE    /ELiZ
}

void AVehiclePosition::ChooseFireAt(AActor* A)
{
	/*
	if (!bHasAltFire)
	{
		Fire(0);
	}
	else
	{
		if (Gun != nullptr)
		{
			if (Gun.BestMode() == 0)
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

float AVehiclePosition::RefireRate()
{
	if (Gun != nullptr)
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			return Gun->AIInfo[1].RefireRate;
		}
		else
		{
			return Gun->AIInfo[0].RefireRate;
		}
	}
	return 0;
}

bool AVehiclePosition::IsFiring()
{
	return ((Gun != nullptr) && (bWeaponisFiring || (bWeaponisAltFiring && bHasAltFire)));
}

bool AVehiclePosition::NeedToTurn(FVector targ)
{
	return (!((Gun != nullptr) && Gun->bCorrectAim));
}

bool AVehiclePosition::FireOnRelease()
{
	if (Gun != nullptr)
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			return Gun->AIInfo[1].bFireOnRelease;
		}
		else
		{
			return Gun->AIInfo[0].bFireOnRelease;
		}
	}
	return false;
}

bool AVehiclePosition::IndependentVehicle()
{
	return false;
}

void AVehiclePosition::ToggleZoom()
{
	if (Gun != nullptr)
	{
		Gun->ToggleZoom();
	}
}

void AVehiclePosition::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Super::DisplayDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.DrawText("VehiclePosition ----- " + DebugInfo);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText(DebugInfo);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.SetDrawColor(0, 0, 255);
	Canvas.DrawText("-- Gun: " + Gun);
	if (Gun != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Gun.DisplayDebug(Canvas, YL, YPos);
	}
	Canvas.SetPos(4, YPos);
	DebugInfo = "";
	*/
}

void AVehiclePosition::PostBeginPlay()
{
	BeginPlay();
}

void AVehiclePosition::PostNetBeginPlay()
{
	bool OldCollideActors = nullptr;
	bool OldBlockActors = nullptr;
	//Super::PostNetBeginPlay();
	/*
	if (bCollideActors)
	{
		OldCollideActors = bCollideActors;
		OldBlockActors = bBlockActors;
		GetBoneCoords("None");
		SetCollision(false, false);
		SetCollision(OldCollideActors, OldBlockActors);
	}
	TeamChanged();
	if (PawnShadow != nullptr)
	{
		PawnShadow.Destroy();
		PawnShadow = nullptr;
	}
	if (Shadow != nullptr)
	{
		Shadow.Destroy();
		Shadow = nullptr;
	}
	if (Role < 4)
	{
		bClientInitComplete = true;
		return;
	}
	if (Role == 4 && GunClass != nullptr)
	{
		Gun = Spawn(GunClass, this, , Location);
		if (Gun != nullptr)
		{
			Gun.SetOwner(this);
			PitchUpLimit = Gun.PitchUpLimit;
			PitchDownLimit = Gun.PitchDownLimit;
		}
		else
		{
			if (GunClass != nullptr)
			{
				DebugLog(DEBUG_Vehicle, this + " gun was not spawned with GunClass " + GunClass);
			}
		}
	}
	*/
}

bool AVehiclePosition::IsReplicationComplete()
{
	/*
	if (Role < 4)
	{
		if (!bClientInitComplete || VehicleBase == nullptr || PositionsIndex == -1)
		{
			return false;
		}
		if (GunClass != nullptr)
		{
			if (Gun == nullptr)
			{
				return false;
			}
		}
	}
	*/
	return true;
}

void AVehiclePosition::TeamChanged()
{
	Super::TeamChanged();
	if (Gun != nullptr)
	{
		Gun->SetTeam(Team);
	}
}

AVehicle* AVehiclePosition::GetVehicleBase()
{
	return VehicleBase;
}

void AVehiclePosition::AttachToVehicle(AAGP_Vehicle* VehiclePawn, FName WeaponBone)
{
	if (GetNetMode() != ENetMode::NM_Client)
	{
		VehicleBase = VehiclePawn;
		if (Gun != nullptr)
		{
			//VehicleBase->AttachToBone(Gun, WeaponBone);
			//Gun->SetBase(VehicleBase);
		}
	}
}

FRotator AVehiclePosition::RotatorAlign(FRotator A, FRotator B)
{
	FVector tempvector = FVector(0, 0, 0);
	/*
	A = Normalize(A);
	tempvector = Vector(A);
	tempvector = (tempvector >> B);
	return rotator(tempvector);
	*/
	return FRotator(0, 0, 0);
}

void AVehiclePosition::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	FQuat CarQuat = FQuat(0, 0, 0, 0);
	FQuat LookQuat = FQuat(0, 0, 0, 0);
	FQuat ResultQuat = FQuat(0,0,0,0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector VehicleZ = FVector(0, 0, 0);
	FVector CamViewOffsetWorld = FVector(0,0,0);
	float CamViewOffsetZAmount = 0;
	FCoords CamBoneCoords;
	/*
	if (Driver != nullptr)
	{
		Driver.bOwnerNoSee = true;
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = this;
	CameraRotation = Rotation;
	if (bPCRelativeFPRotation && bLockFirstPersonView == false)
	{
		CarQuat = QuatFromRotator(Normalize(VehicleBase.Rotation));
		CameraRotation = Normalize(PC.Rotation);
		LookQuat = QuatFromRotator(CameraRotation);
		ResultQuat = QuatProduct(LookQuat, CarQuat);
		CameraRotation = QuatToRotator(ResultQuat);
	}
	else
	{
		if (bLockFirstPersonView)
		{
			CameraRotation.Yaw = VehicleBase.Rotation.Yaw & 65535;
			CameraRotation.Pitch = VehicleBase.Rotation.Pitch & 65535;
			CameraRotation.Roll = VehicleBase.Rotation.Roll & 65535;
		}
		else
		{
			CameraRotation = PC.Rotation;
		}
	}
	CamViewOffsetWorld = FPCamViewOffset >> CameraRotation;
	if (CameraBone != "None" && Gun != nullptr)
	{
		CamBoneCoords = Gun.GetBoneCoords(CameraBone);
		CameraLocation = CamBoneCoords.Origin + FPCamPos >> Rotation + CamViewOffsetWorld;
	}
	else
	{
		CameraLocation = GetCameraLocationStart() + FPCamPos >> VehicleBase.Rotation + CamViewOffsetWorld;
	}
	if (bFPNoZFromCameraPitch)
	{
		VehicleZ = FVector(0 0 1) >> VehicleBase.Rotation;
		CamViewOffsetZAmount = CamViewOffsetWorld Dot VehicleZ;
		CameraLocation -= CamViewOffsetZAmount * VehicleZ;
	}
	CameraRotation = Normalize(CameraRotation + PC.ShakeRot);
	CameraLocation = CameraLocation + PC.ShakeOffset.X * X + PC.ShakeOffset.Y * Y + PC.ShakeOffset.Z * Z;
	*/
}

FVector AVehiclePosition::GetCameraLocationStart()
{
	if ((VehicleBase != nullptr) && (Gun != nullptr))
	{
		//return VehicleBase->GetBoneCoords(Gun->AttachmentBone).Origin;
	}
	else
	{
		if (VehicleBase != nullptr)
		{
			//return VehicleBase->GetActorBoundso)rLocation();
		}
		else
		{
			//return Super::GetCameraLocationStart();
		}
	}
	return FVector(0, 0, 0);   //FAKE   /ELiZ
}

void AVehiclePosition::Destroyed()
{
	/*
	if (Gun != nullptr)
	{
		Gun.Destroy();
	}
	Super::Destroyed();
	*/
}

void AVehiclePosition::EncroachedBy(AActor* Other)
{
}

void AVehiclePosition::BaseChange()
{
}

void AVehiclePosition::NPC_Fire(float F, APawn* Enemy)
{
	/*
	if (CanAttack(Enemy))
	{
		Fire(F);
	}
	else
	{
		VehicleCeaseFire(false);
	}
	*/
}

void AVehiclePosition::SetInstantFire(bool bInstant)
{
	/*
	if (Gun == nullptr)
	{
		return;
	}
	if (Gun.bInstantFire != bInstant)
	{
		Gun.SetInstantFireMode(bInstant);
	}
	*/
}

void AVehiclePosition::Fire(float F)
{
	/*
	Super::Fire(F);
	if (Gun != nullptr && PlayerController(Controller) != nullptr)
	{
		Gun.ClientStartFire(Controller, false);
	}
	*/
}

void AVehiclePosition::AltFire(float F)
{
	/*
	AltFire(F);
	if (!bWeaponisFiring && Gun != nullptr && PlayerController(Controller) != nullptr)
	{
		Gun.ClientStartFire(Controller, true);
	}
	*/
}

void AVehiclePosition::ClientVehicleCeaseFire(bool bWasAltFire)
{
	/*
	ClientVehicleCeaseFire(bWasAltFire);
	if (Gun != nullptr)
	{
		Gun.ClientStopFire(Controller, bWasAltFire);
		if (!bWasAltFire && bWeaponisAltFiring)
		{
			Gun.ClientStartFire(Controller, true);
		}
	}
	*/
}

void AVehiclePosition::VehicleCeaseFire(bool bWasAltFire)
{
	/*
	VehicleCeaseFire(bWasAltFire);
	if (Gun != nullptr)
	{
		Gun.CeaseFire(Controller);
	}
	*/
}

bool AVehiclePosition::TryToDrive(APawn* p)
{
	APawn* OldPawn = nullptr;
	/*
	DebugLog(DEBUG_Vehicle, "VehiclePosition::TryToDrive start");
	if (VehicleBase != nullptr)
	{
		if (VehicleBase.NeedsFlip())
		{
			VehicleBase.Flip(Vector(p.Rotation), 1);
			return false;
		}
	}
	if (Driver != nullptr && Cast<AHumanController>(Controller) == nullptr && Cast<AHumanController>(p->Controller) != nullptr)
	{
		OldPawn = Driver;
		KDriverLeave(true);
		OldPawn.Destroy();
	}
	return Super::TryToDrive(p);
	*/
	return false;   //FAKE    /ELiZ
}

void AVehiclePosition::KDriverEnter(APawn* p)
{
	FRotator NewRotation = FRotator(0,0,0);
	/*
	DebugLog(DEBUG_Vehicle, "VehiclePosition::KDriverEnter start");
	KDriverEnter(p);
	if (VehicleBase != nullptr && VehicleBase.bTeamLocked && VehicleBase.bEnterringUnlocks)
	{
		VehicleBase.bTeamLocked = false;
	}
	if (!bHasOwnHealth && VehicleBase == nullptr)
	{
		Health = Driver.Health;
		HealthMax = Driver.HealthMax;
	}
	NewRotation = Controller.Rotation;
	NewRotation.Pitch = LimitPitch(NewRotation.Pitch);
	SetActorRotation(NewRotation);
	Driver.bSetPCRotOnPossess = false;
	if (Gun != nullptr && Gun.bActive)
	{
		Gun.NetPriority = 1.5;
		Gun.NetUpdateFrequency = 10;
	}
	*/
}

bool AVehiclePosition::KDriverLeave(bool bForceLeave)
{
	AController* C = nullptr;
	AAGP_Pawn* p = nullptr;
	/*
	DebugLog(DEBUG_Vehicle, "VehiclePosition::KDriverLeave");
	C = Controller;
	if (KDriverLeave(bForceLeave) || bForceLeave)
	{
		bWeaponisFiring = false;
		if (!bHasOwnHealth && VehicleBase == nullptr)
		{
			HealthMax = Default.HealthMax;
			Health = HealthMax;
		}
		if (C != nullptr)
		{
			if (C.Pawn != nullptr)
			{
				C.Pawn.bSetPCRotOnPossess = C.Pawn.Default.bSetPCRotOnPossess;
			}
			p = Cast<AAGP_Pawn>(C.Pawn);
			if (p != nullptr && VehicleBase.OutOfBounds > 0)
			{
				p.TimeOutOfBounds = VehicleBase.TimeOutOfBounds;
				p.OutOfBounds = VehicleBase.OutOfBounds;
			}
		}
		if (Gun != nullptr)
		{
			Gun.bActive = false;
			Gun.FlashCount = 0;
			Gun.NetUpdateFrequency = Gun.Default.NetUpdateFrequency;
			Gun.NetPriority = Gun.Default.NetPriority;
		}
		return true;
	}
	else
	{
		DebugLog(DEBUG_Vehicle, "Cannot leave " + Self);
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void AVehiclePosition::DriverDied()
{
}

void AVehiclePosition::ClientKDriverEnter(APlayerController* PC)
{
	FRotator NewRotation = FRotator(0,0,0);
	/*
	ClientKDriverEnter(PC);
	NewRotation = PC.Rotation;
	NewRotation.Pitch = LimitPitch(NewRotation.Pitch);
	SetActorRotation(NewRotation);
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		SpawnFPVehicleWeaponOverlay(PC);
	}
	*/
}

void AVehiclePosition::ClientKDriverLeave(APlayerController* PC)
{
	/*
	if (Gun != nullptr)
	{
		if (bWeaponisFiring)
		{
			Gun.ClientStopFire(PC, false);
		}
		if (bWeaponisAltFiring)
		{
			Gun.ClientStopFire(PC, true);
		}
	}
	if (GunOverlay != nullptr)
	{
		GunOverlay.Destroy();
	}
	ClientKDriverLeave(PC);
	*/
}

void AVehiclePosition::SpawnFPVehicleWeaponOverlay(APlayerController* PC)
{
	/*
	if (GunOverlayClass != nullptr && GunOverlay == nullptr && Gun != nullptr)
	{
		GunOverlay = Spawn(GunOverlayClass, PC);
	}
	if (GunOverlay != nullptr)
	{
		GunOverlay.Weapon = Gun;
	}
	*/
}

void AVehiclePosition::DrivingStatusChanged()
{
	/*
	DrivingStatusChanged();
	if (VehicleBase != nullptr)
	{
		SetBase(VehicleBase);
	}
	*/
}

bool AVehiclePosition::PlaceExitingDriver()
{
	int32 i = 0;
	FVector tryPlace = FVector(0, 0, 0);
	FVector Extent = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector ZOffset = FVector(0,0,0);
	/*
	Extent = Driver.Default.CollisionRadius * FVector(1 1 0);
	Extent.Z = Driver.Default.CollisionHeight;
	ZOffset = Driver.Default.CollisionHeight * FVector(0 0 0.5);
	if (VehicleBase != nullptr && VSize(VehicleBase.Velocity) > 100)
	{
		tryPlace = Normal(VehicleBase.Velocity Cross FVector(0 0 1)) * VehicleBase.CollisionRadius * 1.25;
		if (FMath::FRand() < 0.5)
		{
			tryPlace *= -1;
		}
		if (VehicleBase.Trace(HitLocation, HitNormal, VehicleBase.Location + tryPlace + ZOffset, VehicleBase.Location + ZOffset, false, Extent) == nullptr && Driver.SetLocation(VehicleBase.Location + tryPlace + ZOffset) || VehicleBase.Trace(HitLocation, HitNormal, VehicleBase.Location - tryPlace + ZOffset, VehicleBase.Location + ZOffset, false, Extent) == nullptr && Driver.SetLocation(VehicleBase.Location - tryPlace + ZOffset))
		{
			return true;
		}
	}
	if (VehicleBase != nullptr)
	{
		for (i = 0; i < VehicleBase.ExitPositions.Num(); i++)
		{
			if (bRelativeExitPos)
			{
				if (VehicleBase != nullptr)
				{
					tryPlace = VehicleBase.Location + VehicleBase.ExitPositions[i] >> VehicleBase.Rotation + ZOffset;
				}
				else
				{
					if (Gun != nullptr)
					{
						tryPlace = Gun.Location + VehicleBase.ExitPositions[i] >> Gun.Rotation + ZOffset;
					}
					else
					{
						tryPlace = Location + VehicleBase.ExitPositions[i] >> Rotation;
					}
				}
			}
			else
			{
				tryPlace = VehicleBase.ExitPositions[i];
			}
			if (bRelativeExitPos)
			{
				if (VehicleBase != nullptr)
				{
					if (VehicleBase.Trace(HitLocation, HitNormal, tryPlace, VehicleBase.Location + ZOffset, false, Extent) != nullptr)
					{
					}
				}
				else
				{
			else
			{
				if (Trace(HitLocation, HitNormal, tryPlace, Location + ZOffset, false, Extent) != nullptr)
				{
				}
			}
				}
			else
			{
				if (!Driver.SetLocation(tryPlace))
				{
				}
				return true;
			}
			}
		}
	}
	else
	{
		for (i = 0; i < ExitPositions.Num(); i++)
		{
			if (bRelativeExitPos)
			{
				if (VehicleBase != nullptr)
				{
					tryPlace = VehicleBase.Location + ExitPositions[i] >> VehicleBase.Rotation + ZOffset;
				}
				else
				{
					if (Gun != nullptr)
					{
						tryPlace = Gun.Location + ExitPositions[i] >> Gun.Rotation + ZOffset;
					}
					else
					{
						tryPlace = Location + ExitPositions[i] >> Rotation;
					}
				}
			}
			else
			{
				tryPlace = ExitPositions[i];
			}
			if (bRelativeExitPos)
			{
				if (VehicleBase != nullptr)
				{
					if (VehicleBase.Trace(HitLocation, HitNormal, tryPlace, VehicleBase.Location + ZOffset, false, Extent) != nullptr)
					{
					}
				}
				else
				{
			else
			{
				if (Trace(HitLocation, HitNormal, tryPlace, Location + ZOffset, false, Extent) != nullptr)
				{
				}
			}
				}
			else
			{
				if (!Driver.SetLocation(tryPlace))
				{
				}
				return true;
			}
			}
		}
	}
	*/
	return false;
}

void AVehiclePosition::GetDriverAttachmentBone(AActor* &AttachActor, FName &DriverAttachmentBone)
{
	/*
	AttachActor = VehicleBase;
	DriverAttachmentBone = DriverBone;
	return;
	*/
}

void AVehiclePosition::DetachDriver(APawn* p)
{
	/*
	if (Gun != nullptr && p.AttachmentBone != "None")
	{
		Gun.DetachFromBone(p);
	}
	DetachDriver(p);
	*/
}

void AVehiclePosition::UpdateRocketAcceleration(float DeltaTime, float YawChange, float PitchChange)
{
}

void AVehiclePosition::SetTeamNum(uint8 t)
{
	uint8 Temp = 0;
	Temp = Team;
	PrevTeam = t;
	Team = t;
	if (Temp != t)
	{
		TeamChanged();
	}
}

void AVehiclePosition::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
	APlayerController* PC = nullptr;
	AController* C = nullptr;
	APawn* OldDriver = nullptr;
	/*
	if (bDeleteMe || Level.bLevelChange)
	{
		return;
	}
	if (Level.Game.PreventDeath(this, Killer, DamageType, HitLocation))
	{
		Health = FMath::Max(Health, 1);
		return;
	}
	Health = FMath::Min(0, Health);
	if (Controller != nullptr)
	{
		C = Controller;
		C.WasKilledBy(Killer);
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
				if (Driver != nullptr)
				{
					OldDriver = Driver;
					KDriverLeave(true);
					OldDriver.Died(Killer, DamageType, HitLocation, HitDir, Bone);
				}
			}
		}
		else
		{
			C.Destroy();
		}
	}
	else
	{
		Level.Game.Killed(Killer, Cast<AController>(GetOwner()), this, DamageType);
	}
	if (Killer != nullptr)
	{
		TriggerEvent(Event, this, Killer.Pawn);
	}
	else
	{
		TriggerEvent(Event, this, None);
	}
	if (IsHumanControlled())
	{
		Cast<APlayerController>(Controller).ForceDeathUpdate();
	}
	*/
}

/*
void AVehiclePosition::TakeDamage(int32 Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (bHasOwnHealth)
	{
		TakeDamage(Damage, EventInstigator, HitLocation, Momentum, DamageType);
	}
	else
	{
		if (Driver != nullptr)
		{
			Driver.TakeDamage(Damage, EventInstigator, HitLocation, Momentum, DamageType);
			if (VehicleBase == nullptr)
			{
				Health = Driver.Health;
			}
		}
	}
}
*/
bool AVehiclePosition::CanLean()
{
	return true;
}

void AVehiclePosition::LeanLeft(bool bFullLeft)
{
	//VehicleBase.ServerChangePosition(false, Driver);
}

void AVehiclePosition::LeanRight(bool bFullRight)
{
	//VehicleBase.ServerChangePosition(true, Driver);
}

int32 AVehiclePosition::LimitPitch(int32 Pitch)
{
	if ((VehicleBase == nullptr) || (Gun == nullptr))
	{
		//return Super::LimitPitch(Pitch);
	}
	return Gun->LimitPitch(Pitch, VehicleBase->GetActorRotation(),0);
}

bool AVehiclePosition::TeamLink(int32 TeamNum)
{
	if ((VehicleBase != nullptr) && (!bHasOwnHealth))
	{
		return VehicleBase->TeamLink(TeamNum);
	}
	//return Super::TeamLink(TeamNum);
	return false;    //FAKE   /ELiZ
}

void AVehiclePosition::DrawHUD(UCanvas* Canvas)
{
	APlayerController* PC = nullptr;
	FVector CameraLocation = FVector(0,0,0);
	FRotator CameraRotation = FRotator(0,0,0);
	AActor* ViewActor = nullptr;
	/*
	if (IsLocallyControlled() && CrosshairTexture != nullptr && Gun != nullptr && Gun.bCorrectAim)
	{
		Canvas.DrawColor = CrossHairColor;
		Canvas.DrawColor.A = 255;
		Canvas.Style = 6;
		Canvas.SetPos(Canvas.SizeX * 0.5 - CrosshairX, Canvas.SizeY * 0.5 - CrosshairY);
		Canvas.DrawTile(CrosshairTexture, CrosshairX * 2, CrosshairY * 2, 0, 0, CrosshairTexture.USize, CrosshairTexture.VSize);
	}
	PC = Cast<APlayerController>(Controller);
	if (bDrawGunOverlay && PC != nullptr && !PC.bBehindView && GunOverlay != nullptr)
	{
		GunOverlay.RenderOverlays(Canvas, false);
	}
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

void AVehiclePosition::PostNetReceive()
{
	if (VehicleBase != nullptr && PositionsIndex != -1)
	{
		//bNetNotify = false;
		if (PositionsIndex < VehicleBase->Positions.Num())
		{
			VehicleBase->Positions[PositionsIndex] = this;
		}
	}
}

void AVehiclePosition::NotifyControllerOutOfBounds(int32 Seconds)
{
	/*
	if (Controller != nullptr)
	{
		Cast<APlayerController>(Controller).myHUD.DisplayCenteredMessage(1.1, "You have left the combat zone!", "You have" @ Seconds @ "seconds to return...");
	}
	*/
}

void AVehiclePosition::StaticPrecache(ALevelInfo* L)
{
	if (GetDefault<AVehiclePosition>()->GunClass != nullptr)
	{
		GetDefault<AVehiclePosition>()->GunClass->StaticPrecache(L);
	}
}
