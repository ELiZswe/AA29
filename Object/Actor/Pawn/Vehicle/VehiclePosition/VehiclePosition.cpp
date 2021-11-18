// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"

AVehiclePosition::AVehiclePosition()
{
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
	/*
	if (VehicleBase != None)
	{
		return VehicleBase.GetVehicleNumber();
	}
	else
	{
		return -1;
	}
	*/

	return -1;    //FAKE   /ELiZ
}

int32 AVehiclePosition::GetVehiclePositionIndex(AVehicle* VehiclePosition)
{
	/*
	if (VehicleBase != None)
	{
		return VehicleBase.GetVehiclePositionIndex(VehiclePosition);
	}
	else
	{
		return -1;
	}
	*/

	return -1;    //FAKE   /ELiZ
}

void AVehiclePosition::AttachFlag(AActor* FlagActor)
{
	/*
	if (VehicleBase != None)
	{
		VehicleBase.AttachFlag(FlagActor);
	}
	else
	{
		AttachFlag(FlagActor);
	}
	*/
}

void AVehiclePosition::GetMoveTargetFor(APawn* p)
{
	/*
	if (VehicleBase != None)
	{
		Return VehicleBase;
	}
	return this;
	*/
}

bool AVehiclePosition::HasWeapon()
{
	//return Gun != nullptr;
	return false;    //FAKE   /ELiZ
}

void AVehiclePosition::GetAimTarget()
{
	/*
	if (VehicleBase != None)
	{
		Return VehicleBase;
	}
	return this;
	*/
}

bool AVehiclePosition::CanAttack(AActor* Other)
{
	/*
	if (Gun != None)
	{
		Return Gun.CanAttack(Other);
	}
	*/
	return false;
}

bool AVehiclePosition::TooCloseToAttack(AActor* Other)
{
	int32 NeededPitch=0;
	/*
	if (Gun == None || VSize(Location - Other.Location) > 2500)
	{
		return false;
	}
	NeededPitch = Other.Location - Gun.WeaponFireLocation.Pitch;
	NeededPitch = NeededPitch & 65535;
	Return LimitPitch(NeededPitch) == NeededPitch;
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
		if (Gun != None)
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

int32 AVehiclePosition::RefireRate()
{
	/*
	if (Gun != None)
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			Return Gun.AIInfo[1].RefireRate;
		}
		else
		{
			Return Gun.AIInfo[0].RefireRate;
		}
	}
	*/
	return 0;
}

bool AVehiclePosition::IsFiring()
{
	//Return Gun != None && bWeaponisFiring || bWeaponisAltFiring && bHasAltFire;
	return false;    //FAKE    /ELiZ
}

bool AVehiclePosition::NeedToTurn(FVector targ)
{
	//Return !Gun != None && Gun.bCorrectAim;
	return false;    //FAKE    /ELiZ
}

bool AVehiclePosition::FireOnRelease()
{
	/*
	if (Gun != None)
	{
		if (bWeaponisAltFiring && bHasAltFire)
		{
			Return Gun.AIInfo[1].bFireOnRelease;
		}
		else
		{
			Return Gun.AIInfo[0].bFireOnRelease;
		}
	}
	*/
	return false;
}

bool AVehiclePosition::IndependentVehicle()
{
	return false;
}

void AVehiclePosition::ToggleZoom()
{
	/*
	if (Gun != None)
	{
		Gun.ToggleZoom();
	}
	*/
}
/*
void AVehiclePosition::DisplayDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	DisplayDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.DrawText("VehiclePosition ----- " $ DebugInfo);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText(DebugInfo);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.SetDrawColor(0, 0, 255);
	Canvas.DrawText("-- Gun: " $ Gun);
	if (Gun != None)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Gun.DisplayDebug(Canvas, YL, YPos);
	}
	Canvas.SetPos(4, YPos);
	DebugInfo = "";
}
*/
void AVehiclePosition::PostBeginPlay()
{
	BeginPlay();
}

void AVehiclePosition::PostNetBeginPlay()
{
	/*
	local bool OldCollideActors;
	local bool OldBlockActors;
	PostNetBeginPlay();
	if (bCollideActors)
	{
		OldCollideActors = bCollideActors;
		OldBlockActors = bBlockActors;
		GetBoneCoords('None');
		SetCollision(False, False);
		SetCollision(OldCollideActors, OldBlockActors);
	}
	TeamChanged();
	if (PawnShadow != None)
	{
		PawnShadow.Destroy();
		PawnShadow = None;
	}
	if (Shadow != None)
	{
		Shadow.Destroy();
		Shadow = None;
	}
	if (Role < 4)
	{
		bClientInitComplete = true;
		Return;
	}
	if (Role == 4 && GunClass != None)
	{
		Gun = Spawn(GunClass, Self, , Location);
		if (Gun != None)
		{
			Gun.SetOwner(Self);
			PitchUpLimit = Gun.PitchUpLimit;
			PitchDownLimit = Gun.PitchDownLimit;
		}
		else
		{
			if (GunClass != None)
			{
				DebugLog(DEBUG_Vehicle, Self $ " gun was not spawned with GunClass " $ GunClass);
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
		if (!bClientInitComplete || VehicleBase == None || PositionsIndex == -1)
		{
			return false;
		}
		if (GunClass != None)
		{
			if (Gun == None)
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
	/*
	TeamChanged();
	if (Gun != None)
	{
		Gun.SetTeam(Team);
	}
	*/
}

AAGP_Vehicle* AVehiclePosition::GetVehicleBase()
{
	return VehicleBase;
}

void AVehiclePosition::AttachToVehicle(AAGP_Vehicle* VehiclePawn, FName WeaponBone)
{
	/*
	if (Level.NetMode != 3)
	{
		VehicleBase = VehiclePawn;
		if (Gun != None)
		{
			VehicleBase.AttachToBone(Gun, WeaponBone);
			Gun.SetBase(VehicleBase);
		}
	}
	*/
}

FVector AVehiclePosition::RotatorAlign(FRotator A, FRotator B)
{
	
	FVector tempvector= FVector(0,0,0);
	/*
	A = Normalize(A);
	tempvector = Vector(A);
	tempvector = tempvector >> B;
	*/
	return tempvector;
	
}

void AVehiclePosition::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Quat CarQuat;
	local Object.Quat LookQuat;
	local Object.Quat ResultQuat;
	local FVector X;
	local FVector Y;
	local FVector Z;
	local FVector VehicleZ;
	local FVector CamViewOffsetWorld;
	local float CamViewOffsetZAmount;
	local Object.Coords CamBoneCoords;
	if (Driver != None)
	{
		Driver.bOwnerNoSee = true;
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = Self;
	CameraRotation = Rotation;
	if (bPCRelativeFPRotation && bLockFirstPersonView == False)
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
	if (CameraBone != 'None' && Gun != None)
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
		VehicleZ = vect(0 0 1) >> VehicleBase.Rotation;
		CamViewOffsetZAmount = CamViewOffsetWorld Dot VehicleZ;
		CameraLocation -= CamViewOffsetZAmount * VehicleZ;
	}
	CameraRotation = Normalize(CameraRotation + PC.ShakeRot);
	CameraLocation = CameraLocation + PC.ShakeOffset.X * X + PC.ShakeOffset.Y * Y + PC.ShakeOffset.Z * Z;
	*/
}

void AVehiclePosition::GetCameraLocationStart()
{
	/*
	if (VehicleBase != None && Gun != None)
	{
		Return VehicleBase.GetBoneCoords(Gun.AttachmentBone).Origin;
	}
	else
	{
		if (VehicleBase != None)
		{
			Return VehicleBase.Location;
		}
		else
		{
			Return GetCameraLocationStart();
		}
	}
	*/
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
		VehicleCeaseFire(False);
	}
	*/
}

void AVehiclePosition::SetInstantFire(bool bInstant)
{
	/*
	if (Gun == None)
	{
		Return;
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
	if (Gun != None && PlayerController(Controller) != None)
	{
		Gun.ClientStartFire(Controller, False);
	}
	*/
}

void AVehiclePosition::AltFire(float F)
{
	/*
	AltFire(F);
	if (!bWeaponisFiring && Gun != None && PlayerController(Controller) != None)
	{
		Gun.ClientStartFire(Controller, True);
	}
	*/
}

void AVehiclePosition::ClientVehicleCeaseFire(bool bWasAltFire)
{
	/*
	ClientVehicleCeaseFire(bWasAltFire);
	if (Gun != None)
	{
		Gun.ClientStopFire(Controller, bWasAltFire);
		if (!bWasAltFire && bWeaponisAltFiring)
		{
			Gun.ClientStartFire(Controller, True);
		}
	}
	*/
}

void AVehiclePosition::VehicleCeaseFire(bool bWasAltFire)
{
	/*
	VehicleCeaseFire(bWasAltFire);
	if (Gun != None)
	{
		Gun.CeaseFire(Controller);
	}
	*/
}

bool AVehiclePosition::TryToDrive(APawn* p)
{
	/*
	local Pawn OldPawn;
	DebugLog(DEBUG_Vehicle, "VehiclePosition::TryToDrive start");
	if (VehicleBase != None)
	{
		if (VehicleBase.NeedsFlip())
		{
			VehicleBase.Flip(Vector(p.Rotation), 1);
			return false;
		}
	}
	if (Driver != None && HumanController(Controller) == None && HumanController(p.Controller) != None)
	{
		OldPawn = Driver;
		KDriverLeave(True);
		OldPawn.Destroy();
	}
	return Super::TryToDrive(p);
	*/
	return false;   //FAKE    /ELiZ
}

void AVehiclePosition::KDriverEnter(APawn* p)
{
	/*
	local FRotator NewRotation;
	DebugLog(DEBUG_Vehicle, "VehiclePosition::KDriverEnter start");
	KDriverEnter(p);
	if (VehicleBase != None && VehicleBase.bTeamLocked && VehicleBase.bEnterringUnlocks)
	{
		VehicleBase.bTeamLocked = false;
	}
	if (!bHasOwnHealth && VehicleBase == None)
	{
		Health = Driver.Health;
		HealthMax = Driver.HealthMax;
	}
	NewRotation = Controller.Rotation;
	NewRotation.Pitch = LimitPitch(NewRotation.Pitch);
	SetRotation(NewRotation);
	Driver.bSetPCRotOnPossess = false;
	if (Gun != None && Gun.bActive)
	{
		Gun.NetPriority = 1.5;
		Gun.NetUpdateFrequency = 10;
	}
	*/
}

bool AVehiclePosition::KDriverLeave(bool bForceLeave)
{
	/*
	local Controller C;
	local AGP.AGP_APawn* p;
	DebugLog(DEBUG_Vehicle, "VehiclePosition::KDriverLeave");
	C = Controller;
	if (KDriverLeave(bForceLeave) || bForceLeave)
	{
		bWeaponisFiring = false;
		if (!bHasOwnHealth && VehicleBase == None)
		{
			HealthMax = Default.HealthMax;
			Health = HealthMax;
		}
		if (C != None)
		{
			if (C.Pawn != None)
			{
				C.Pawn.bSetPCRotOnPossess = C.Pawn.Default.bSetPCRotOnPossess;
			}
			p = AGP_Pawn(C.Pawn);
			if (p != None && VehicleBase.OutOfBounds > 0)
			{
				p.TimeOutOfBounds = VehicleBase.TimeOutOfBounds;
				p.OutOfBounds = VehicleBase.OutOfBounds;
			}
		}
		if (Gun != None)
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
		DebugLog(DEBUG_Vehicle, "Cannot leave " $ Self);
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
	/*
	local FRotator NewRotation;
	ClientKDriverEnter(PC);
	NewRotation = PC.Rotation;
	NewRotation.Pitch = LimitPitch(NewRotation.Pitch);
	SetRotation(NewRotation);
	if (Level.NetMode != 1)
	{
		SpawnFPVehicleWeaponOverlay(PC);
	}
	*/
}

void AVehiclePosition::ClientKDriverLeave(APlayerController* PC)
{
	/*
	if (Gun != None)
	{
		if (bWeaponisFiring)
		{
			Gun.ClientStopFire(PC, False);
		}
		if (bWeaponisAltFiring)
		{
			Gun.ClientStopFire(PC, True);
		}
	}
	if (GunOverlay != None)
	{
		GunOverlay.Destroy();
	}
	ClientKDriverLeave(PC);
	*/
}

void AVehiclePosition::SpawnFPVehicleWeaponOverlay(APlayerController* PC)
{
	/*
	if (GunOverlayClass != None && GunOverlay == None && Gun != None)
	{
		GunOverlay = Spawn(GunOverlayClass, PC);
	}
	if (GunOverlay != None)
	{
		GunOverlay.Weapon = Gun;
	}
	*/
}

void AVehiclePosition::DrivingStatusChanged()
{
	/*
	DrivingStatusChanged();
	if (VehicleBase != None)
	{
		SetBase(VehicleBase);
	}
	*/
}

bool AVehiclePosition::PlaceExitingDriver()
{
	/*
	local int32 i;
	local FVector tryPlace;
	local FVector Extent;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector ZOffset;
	Extent = Driver.Default.CollisionRadius * vect(1 1 0);
	Extent.Z = Driver.Default.CollisionHeight;
	ZOffset = Driver.Default.CollisionHeight * vect(0 0 0.5);
	if (VehicleBase != None && VSize(VehicleBase.Velocity) > 100)
	{
		tryPlace = Normal(VehicleBase.Velocity Cross vect(0 0 1)) * VehicleBase.CollisionRadius * 1.25;
		if (FRand() < 0.5)
		{
			tryPlace *= -1;
		}
		if (VehicleBase.Trace(HitLocation, HitNormal, VehicleBase.Location + tryPlace + ZOffset, VehicleBase.Location + ZOffset, False, Extent) == None && Driver.SetLocation(VehicleBase.Location + tryPlace + ZOffset) || VehicleBase.Trace(HitLocation, HitNormal, VehicleBase.Location - tryPlace + ZOffset, VehicleBase.Location + ZOffset, False, Extent) == None && Driver.SetLocation(VehicleBase.Location - tryPlace + ZOffset))
		{
			return true;
		}
	}
	if (VehicleBase != None)
	{
		for (i = 0; i < VehicleBase.ExitPositions.Length; i++)
		{
			if (bRelativeExitPos)
			{
				if (VehicleBase != None)
				{
					tryPlace = VehicleBase.Location + VehicleBase.ExitPositions[i] >> VehicleBase.Rotation + ZOffset;
				}
				else
				{
					if (Gun != None)
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
				if (VehicleBase != None)
				{
					if (VehicleBase.Trace(HitLocation, HitNormal, tryPlace, VehicleBase.Location + ZOffset, False, Extent) != None)
					{
					}
				}
				else
				{
			else
			{
				if (Trace(HitLocation, HitNormal, tryPlace, Location + ZOffset, False, Extent) != None)
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
		for (i = 0; i < ExitPositions.Length; i++)
		{
			if (bRelativeExitPos)
			{
				if (VehicleBase != None)
				{
					tryPlace = VehicleBase.Location + ExitPositions[i] >> VehicleBase.Rotation + ZOffset;
				}
				else
				{
					if (Gun != None)
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
				if (VehicleBase != None)
				{
					if (VehicleBase.Trace(HitLocation, HitNormal, tryPlace, VehicleBase.Location + ZOffset, False, Extent) != None)
					{
					}
				}
				else
				{
			else
			{
				if (Trace(HitLocation, HitNormal, tryPlace, Location + ZOffset, False, Extent) != None)
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
	Return;
	*/
}

void AVehiclePosition::DetachDriver(APawn* p)
{
	/*
	if (Gun != None && p.AttachmentBone != 'None')
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
	/*
	local byte Temp;
	Temp = Team;
	PrevTeam = t;
	Team = t;
	if (Temp != t)
	{
		TeamChanged();
	}
	*/
}

void AVehiclePosition::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
	/*
	local APlayerController* PC;
	local Controller C;
	local Pawn OldDriver;
	if (bDeleteMe || Level.bLevelChange)
	{
		Return;
	}
	if (Level.Game.PreventDeath(Self, Killer, DamageType, HitLocation))
	{
		Health = Max(Health, 1);
		Return;
	}
	Health = Min(0, Health);
	if (Controller != None)
	{
		C = Controller;
		C.WasKilledBy(Killer);
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
				if (Driver != None)
				{
					OldDriver = Driver;
					KDriverLeave(True);
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
		Level.Game.Killed(Killer, Controller(Owner), Self, DamageType);
	}
	if (Killer != None)
	{
		TriggerEvent(Event, Self, Killer.Pawn);
	}
	else
	{
		TriggerEvent(Event, Self, None);
	}
	if (IsHumanControlled())
	{
		PlayerController(Controller).ForceDeathUpdate();
	}
	*/
}

/*
void AVehiclePosition::TakeDamage(int32 Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (bHasOwnHealth)
	{
		TakeDamage(Damage, EventInstigator, HitLocation, Momentum, DamageType);
	}
	else
	{
		if (Driver != None)
		{
			Driver.TakeDamage(Damage, EventInstigator, HitLocation, Momentum, DamageType);
			if (VehicleBase == None)
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
	//VehicleBase.ServerChangePosition(False, Driver);
}

void AVehiclePosition::LeanRight(bool bFullRight)
{
	//VehicleBase.ServerChangePosition(True, Driver);
}

void AVehiclePosition::LimitPitch(int32 Pitch)
{
	/*
	if (VehicleBase == None || Gun == None)
	{
		Return LimitPitch(Pitch);
	}
	Return Gun.LimitPitch(Pitch, VehicleBase.Rotation);
	*/
}

void AVehiclePosition::TeamLink(int32 TeamNum)
{
	/*
	if (VehicleBase != None && !bHasOwnHealth)
	{
		Return VehicleBase.TeamLink(TeamNum);
	}
	Return TeamLink(TeamNum);
	*/
}

void AVehiclePosition::DrawHUD(UCanvas* Canvas)
{
	/*
	local APlayerController* PC;
	local FVector CameraLocation;
	local FRotator CameraRotation;
	local Actor ViewActor;
	if (IsLocallyControlled() && CrosshairTexture != None && Gun != None && Gun.bCorrectAim)
	{
		Canvas.DrawColor = CrossHairColor;
		Canvas.DrawColor.A = 255;
		Canvas.Style = 6;
		Canvas.SetPos(Canvas.SizeX * 0.5 - CrosshairX, Canvas.SizeY * 0.5 - CrosshairY);
		Canvas.DrawTile(CrosshairTexture, CrosshairX * 2, CrosshairY * 2, 0, 0, CrosshairTexture.USize, CrosshairTexture.VSize);
	}
	PC = PlayerController(Controller);
	if (bDrawGunOverlay && PC != None && !PC.bBehindView && GunOverlay != None)
	{
		GunOverlay.RenderOverlays(Canvas, False);
	}
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

void AVehiclePosition::PostNetReceive()
{
	/*
	if (VehicleBase != None && PositionsIndex != -1)
	{
		bNetNotify = false;
		if (PositionsIndex < VehicleBase.Positions.Length)
		{
			VehicleBase.Positions[PositionsIndex] = Self;
		}
	}
	*/
}

void AVehiclePosition::NotifyControllerOutOfBounds(int32 Seconds)
{
	/*
	if (Controller != None)
	{
		PlayerController(Controller).myHUD.DisplayCenteredMessage(1.1, "You have left the combat zone!", "You have" @ Seconds @ "seconds to return...");
	}
	*/
}
/*
void AVehiclePosition::StaticPrecache(LevelInfo L)
{
	if (Default.GunClass != None)
	{
		Default.GunClass.StaticPrecache(L);
	}
}
*/