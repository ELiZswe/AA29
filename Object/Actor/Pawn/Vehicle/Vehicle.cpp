// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

// Sets default values
AVehicle::AVehicle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bVehicleShadows = true;
	bDrawVehicleShadow = true;
	bRelativeExitPos = true;
	TurnInPlaceThreshold = 0.9;
	bZeroPCRotOnEntry = true;
	bPCRelativeFPRotation = true;
	bAllowViewChange = true;
	bAdjustDriversHead = true;
	bDesiredBehindView = true;
	bDriverHoldsFlag = true;
	bCanCarryFlag = true;
	Team = 255;
	OldTeam = 255;
	PrevTeam = 255;
	EjectMomentum = 1000;
	DriveAnim = "Vehicle_Driving";
	bPlayDrivingAnimations = true;
	ExitPositions = { FVector(0, 0, 0) };
	EntryRadius = 100;
	TPCamDistance = 600;
	CenterSpringForce = "SpringONSHoverBike";
	CenterSpringRangePitch = 2000;
	CenterSpringRangeRoll = 2000;
	TPCamLookat = FVector(-100, 0, 100);
	CameraSpeed = 500;
	//TPCamDistRange = Min = Min = 50 Max = Max = 1500;
	MaxViewYaw = 16000;
	MaxViewPitch = 16000;
	ShadowMaxTraceDist = 350;
	ShadowCullDistance = 1500;
	MomentumMult = 4;
	DriverDamageMult = 1;
	LockWarningInterval = 1.5;
	VehiclePositionString = "in a vehicle";
	VehicleNameString = "Vehicle";
	//RanOverDamageType = class'Engine.DamRanOver';
	//CrushedDamageType = class'Engine.Crushed';
	LinkHealMult = 0.35;
	MaxDesireability = 0.5;
	ObjectiveGetOutDist = 1000;
	VehicleNumber = -1;
	//bCanBeBaseForPawns = true;
	//bDontPossess = true;
	//bUseCompressedPosition = false;
	//SightRadius = 15000;
	//WalkingPct = 1;
	//CrouchedPct = 1;
	//LandMovementState = "PlayerDriving";
	//NetUpdateFrequency = 4;
	//NetPriority = 1;
	//NV_AmbientGlow = 254;
	//CollisionRadius = 120;
	//ValidJavelinTarget = 1;

}

// Called when the game starts or when spawned
void AVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



/*
State UnDeployed
{
	Function VehicleCeaseFire(bool bWasAltFire)
	{
		Global.iRand(bWasAltFire);
	}
	Function VehicleFire(bool bWasAltFire)
	{
		Global.C(bWasAltFire);
	}
}
State Deployed
{
	Function VehicleCeaseFire(bool bWasAltFire)
	{
		Global.iRand(bWasAltFire);
	}
	Function VehicleFire(bool bWasAltFire)
	{
		Global.C(bWasAltFire);
	}
}
*/


void AVehicle::SpawnSmokeGenerator(float fpSmokeLengthSeconds)
{
}
void AVehicle::SpawnDestructionEffects()
{
}
void AVehicle::HelicopterEngineSmoke(bool bEnable)
{
}
void AVehicle::HelicopterRotorSmoke(bool bEnable)
{
}
void AVehicle::HelicopterCockpitSmoke(bool bEnable)
{
}
void AVehicle::HelicopterForceRotorMaxToIdleSpeed()
{
}
void AVehicle::HelicopterRestoreRotorMaxSpeed()
{
}
void AVehicle::UAVTakeOff()
{
}
void AVehicle::UAVTurnLeft()
{
}
void AVehicle::UAVTurnRight()
{
}
void AVehicle::UAVSetThrottle(float fpThrottle)
{
}
void AVehicle::UAVSetAileron(float fpAngle)
{
}
void AVehicle::UAVSetElevator(float fpElevatorSetting)
{
}

void AVehicle::UAVMoveElevator(float fpElevatorIncrement)
{
}

void AVehicle::UAVSetRudder(float fpRudderSetting)
{
}

void AVehicle::UAVMoveRudder(float fpRudderIncrement)
{
}

void AVehicle::UAVSetVerticalVelocity(float fpVelocity)
{
}

void AVehicle::UAVSetHorizontalVelocity(float fpVelocity)
{
}

void AVehicle::UAVGear(bool bGearUp)
{
}

void AVehicle::UAVLand()
{
}

void AVehicle::UAVEnableAutoPilot(bool bEnable)
{
}

int32 AVehicle::UAVGetRadioStrength()
{
	return 0;
}

void AVehicle::StartSmokeGenerator()
{
}

void AVehicle::StopSmokeGenerator()
{
}

void AVehicle::GetActiveWeaponSystem()
{
}

void AVehicle::GetPosition(int32 iPosition)
{
}

void AVehicle::GetWeaponAim()
{
}

void AVehicle::VehicleDisabled()
{
}

void AVehicle::SetDriverHiddenAttachments()
{
}

void AVehicle::ClearDriverHiddenAttachments()
{
	/*
	local int32 i;
	if (Driver != None)
	{
		for (i = 0; i < 24; i++)
		{
			Driver.HiddenAttachmentClasses[i] = None;
		}
	}
	*/
}

void AVehicle::PreBeginPlay()
{
	/*
	if (!Level.Game.bAllowVehicles && !bDeleteMe)
	{
		Destroy();
		Return;
	}
	Super::PreBeginPlay();
	*/
}

void AVehicle::PlayerChangedTeam()
{
	/*
	if (Driver != None)
	{
		Driver.KilledBy(Driver);
	}
	else
	{
		PlayerChangedTeam();
	}
	*/
}

int32 AVehicle::GetVehicleNumber()
{
	return VehicleNumber;
}

int32 AVehicle::GetVehiclePositionIndex(AVehicle* VehiclePosition)
{
	return -1;
}

void AVehicle::GetMyPositionIndex()
{
	//Return GetVehiclePositionIndex(Self);
}

void AVehicle::SetBaseEyeheight()
{
	//BaseEyeHeight = Default.BaseEyeHeight;
	//EyeHeight = BaseEyeHeight;
}

FString AVehicle::GetVehiclePositionString()
{
	return VehiclePositionString;
}

void AVehicle::Suicide()
{
	/*
	if (Driver != None)
	{
		Driver.KilledBy(Driver);
	}
	else
	{
		KilledBy(Self);
	}
	*/
}


void AVehicle::MatchEnding()
{
	/*
	Super::MatchEnding();
	if (Driver != None)
	{
		KDriverLeave(True);
	}
	*/
}

bool AVehicle::CheatWalk()
{
	return false;
}

bool AVehicle::CheatGhost()
{
	return false;
}

bool AVehicle::CheatFly()
{
	return false;
}

void AVehicle::CreateVRI()
{
	/*
	if (VehicleReplicationInfoClass != None)
	{
		VehicleReplicationInfo = Spawn(VehicleReplicationInfoClass, Self);
		VehicleReplicationInfo.SetVehicle(Self);
		VehicleReplicationInfo.SetVehicleNumber(VehicleNumber);
	}
	*/
}
void AVehicle::PostBeginPlay()
{
	/*
	local Controller NewController;
	PostBeginPlay();
	if (bDeleteMe)
	{
		Return;
	}
	if (bVehicleShadows && bDrawVehicleShadow && Level.NetMode != 1)
	{
		VehicleShadow = Spawn('ShadowProjector', Self, 'None', Location);
		VehicleShadow.ShadowActor = Self;
		VehicleShadow.LightDirection = Normal(vect(1 1 6));
		VehicleShadow.LightDistance = 1200;
		VehicleShadow.MaxTraceDistance = ShadowMaxTraceDist;
		VehicleShadow.CullDistance = ShadowCullDistance;
		VehicleShadow.InitShadow();
	}
	if (Role == 4)
	{
		if (bAutoTurret && Controller == None && AutoTurretControllerClass != None)
		{
			NewController = Spawn(AutoTurretControllerClass);
			if (NewController != None)
			{
				NewController.Possess(Self);
			}
		}
		if (!bAutoTurret && !bNonHumanControl && IndependentVehicle())
		{
			Level.Game.RegisterVehicle(Self);
		}
		CreateVRI();
	}
	OldTeam = Team;
	PrevTeam = Team;
	*/
}

void AVehicle::SetInitialState()
{
	//SetInitialState();
	//Disable('Tick');
}

bool AVehicle::StronglyRecommended(AActor* S, int32 TeamIndex, AActor* Objective)
{
	return bKeyVehicle;
}

void AVehicle::BotDesireability(AActor* S, int32 TeamIndex, AActor* Objective)
{
	/*
	local bool bSameTeam;
	local PlayerController p;
	bSameTeam = GetTeamNum() == TeamIndex;
	if (bSameTeam)
	{
		if (Level.TimeSeconds < TeamUseTime)
		{
			Return 0;
		}
		if (!bKeyVehicle && Level.TimeSeconds < PlayerStartTime)
		{
			p = Level.GetLocalPlayerController();
			if (p == None || p.Pawn != None && Vehicle(p.Pawn) == None)
			{
				Return 0;
			}
		}
	}
	if (!bKeyVehicle && !bStationary && Level.TimeSeconds < VehicleLostTime)
	{
		Return 0;
	}
	else
	{
		if (Health <= 0 || Occupied() || bTeamLocked && !bSameTeam)
		{
			Return 0;
		}
	}
	if (bKeyVehicle)
	{
		Return 100;
	}
	Return MaxDesireability * 0.5 + MaxDesireability * 0.5 * Health / HealthMax;
	*/
}

void AVehicle::Destroyed()
{
	/*
	local Vehicle V;
	local Vehicle Prev;
	if (ParentFactory != None)
	{
		ParentFactory.VehicleDestroyed(Self);
	}
	if (VehicleShadow != None)
	{
		VehicleShadow.Destroy();
	}
	if (bAutoTurret && Controller != None && ClassIsChildOf(Controller.Class, AutoTurretControllerClass) && !Controller.bDeleteMe)
	{
		Controller.Destroy();
		Controller = None;
	}
	if (Driver != None)
	{
		Destroyed_HandleDriver();
	}
	if (Level.Game != None)
	{
		if (Level.Game.VehicleList == Self)
		{
			Level.Game.VehicleList = NextVehicle;
		}
		else
		{
			Prev = Level.Game.VehicleList;
			if (Prev != None)
			{
				V = Level.Game.VehicleList.NextVehicle;
				if (V != None)
				{
					if (V == Self)
					{
						Prev.NextVehicle = NextVehicle;
					}
					else
					{
				else
				{
					Prev = V;
				}
				V = V.NextVehicle;
					}
				}
			}
		}
	}
	if (VehicleReplicationInfo != None)
	{
		VehicleReplicationInfo.Destroy();
	}
	*/
	Super::Destroyed();
}

void AVehicle::Destroyed_HandleDriver()
{
	/*
	local Pawn OldDriver;
	Driver.LastRenderTime = LastRenderTime;
	if (Role == 4)
	{
		if (Driver != None && !bRemoteControlled && !bEjectDriver && !bDrawDriverInTP && Driver.Health > 0)
		{
			OldDriver = Driver;
			Driver = None;
			OldDriver.DrivenVehicle = None;
			if (!OldDriver.bDeleteMe)
			{
				OldDriver.Destroy();
			}
		}
		else
		{
			if (!bRemoteControlled && !bEjectDriver)
			{
				if (!bDrawDriverInTP && PlaceExitingDriver())
				{
					Driver.StopDriving(Self);
					Driver.DrivenVehicle = Self;
				}
				Driver.TearOffMomentum = Velocity * 0.25;
				Driver.Died(Controller, 'DamRanOver', Driver.Location);
			}
		}
	}
	else
	{
		if (Driver.DrivenVehicle == Self)
		{
			Driver.StopDriving(Self);
		}
	}
	*/
}

FVector AVehicle::GetCameraLocationStart()
{
	return GetActorLocation();
}

void AVehicle::SpecialCalcBehindView(APlayerController* PC, AActor* ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local FVector CamLookAt;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector OffsetVector;
	local Actor HitActor;
	local FVector X;
	local FVector Y;
	local FVector Z;
	if (Driver != None && bDrawDriverInTP)
	{
		Driver.bOwnerNoSee = false;
	}
	if (DesiredTPCamDistance < TPCamDistance)
	{
		TPCamDistance = FMax(DesiredTPCamDistance, TPCamDistance - CameraSpeed * Level.TimeSeconds - LastCameraCalcTime);
	}
	else
	{
		if (DesiredTPCamDistance > TPCamDistance)
		{
			TPCamDistance = FMin(DesiredTPCamDistance, TPCamDistance + CameraSpeed * Level.TimeSeconds - LastCameraCalcTime);
		}
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = Self;
	CamLookAt = GetCameraLocationStart() + TPCamLookat >> Rotation + TPCamWorldOffset;
	OffsetVector = vect(0 0 0);
	OffsetVector.X = -1 * TPCamDistance;
	CameraLocation = CamLookAt + OffsetVector >> PC.Rotation;
	HitActor = Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, True, vect(40 40 40));
	if (HitActor != None && HitActor.bWorldGeometry || HitActor == GetVehicleBase() || Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, False, vect(40 40 40)) != None)
	{
		CameraLocation = HitLocation;
	}
	CameraRotation = Normalize(PC.Rotation + PC.ShakeRot);
	CameraLocation = CameraLocation + PC.ShakeOffset.X * X + PC.ShakeOffset.Y * Y + PC.ShakeOffset.Z * Z;
	*/
}

void AVehicle::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Quat CarQuat;
	local Object.Quat LookQuat;
	local Object.Quat ResultQuat;
	local FVector VehicleZ;
	local FVector CamViewOffsetWorld;
	local FVector X;
	local FVector Y;
	local FVector Z;
	local float CamViewOffsetZAmount;
	if (Driver != None)
	{
		Driver.bOwnerNoSee = true;
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = Self;
	if (bPCRelativeFPRotation)
	{
		CarQuat = QuatFromRotator(Rotation);
		CameraRotation = Normalize(PC.Rotation);
		LookQuat = QuatFromRotator(CameraRotation);
		ResultQuat = QuatProduct(LookQuat, CarQuat);
		CameraRotation = QuatToRotator(ResultQuat);
	}
	else
	{
		CameraRotation = PC.Rotation;
	}
	CamViewOffsetWorld = FPCamViewOffset >> CameraRotation;
	CameraLocation = GetCameraLocationStart() + FPCamPos >> Rotation + CamViewOffsetWorld;
	if (bFPNoZFromCameraPitch)
	{
		VehicleZ = vect(0 0 1) >> Rotation;
		CamViewOffsetZAmount = CamViewOffsetWorld Dot VehicleZ;
		CameraLocation -= CamViewOffsetZAmount * VehicleZ;
	}
	CameraRotation = Normalize(CameraRotation + PC.ShakeRot);
	CameraLocation = CameraLocation + PC.ShakeOffset.X * X + PC.ShakeOffset.Y * Y + PC.ShakeOffset.Z * Z;
	*/
}

void AVehicle::SpecialSetFirstPersonViewRotation(APlayerController* PC, FRotator CameraRotation)
{
}

bool AVehicle::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC == None || PC.ViewTarget != Self)
	{
		return false;
	}
	if (PC.bBehindView)
	{
		SpecialCalcBehindView(PC, ViewActor, CameraLocation, CameraRotation);
	}
	else
	{
		SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
	}
	LastCameraCalcTime = Level.TimeSeconds;
	*/
	return true;
}

bool AVehicle::SpectatorSpecialCalcView(APlayerController* Viewer, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local FRotator DummyRotation;
	if (Viewer.ViewTarget != Self)
	{
		return false;
	}
	if (Viewer.bBehindView)
	{
		DesiredTPCamDistance = TPCamDistRange.Max - TPCamDistRange.Min * Viewer.CameraDist / Viewer.CameraDistRange.Max + TPCamDistRange.Min;
		SpecialCalcBehindView(Viewer, ViewActor, CameraLocation, CameraRotation);
	}
	else
	{
		SpecialCalcFirstPersonView(Viewer, ViewActor, CameraLocation, DummyRotation);
	}
	LastCameraCalcTime = Level.TimeSeconds;
	Viewer.SetLocation(CameraLocation);
	*/
	return true;
}

void AVehicle::FindEntryVehicle(APawn* p)
{
	/*
	if (AIController(p.Controller) != None)
	{
		return this;
	}
	if (VSize(p.Location - Location + EntryPosition >> Rotation) < EntryRadius)
	{
		return this;
	}
	return nullptr;
	*/
}

void AVehicle::TryToDrive(APawn* p)
{
	/*
	if (p.bIsCrouched || bNonHumanControl || p.Controller == None || Driver != None || p.DrivenVehicle != None || !p.Controller.bIsPlayer && !p.Controller.IsA('NPCBaseController') || p.IsA('Vehicle') || Health <= 0)
	{
		return false;
	}
	if (!Level.Game.CanEnterVehicle(Self, p))
	{
		return false;
	}
	if (!bTeamLocked || p.GetTeamNum() == Team)
	{
		if (bEnterringUnlocks && bTeamLocked)
		{
			bTeamLocked = false;
		}
		KDriverEnter(p);
		return true;
	}
	else
	{
		VehicleLocked(p);
		return false;
	}
	*/
}

void AVehicle::VehicleLocked(APawn* p)
{
}

void AVehicle::CannotAimAtEnemy()
{
}

void AVehicle::PossessedBy(AController* C)
{
	/*
	local PlayerController PC;
	if (bAutoTurret && Controller != None && ClassIsChildOf(Controller.Class, AutoTurretControllerClass) && !Controller.bDeleteMe)
	{
		Controller.Destroy();
		Controller = None;
	}
	PossessedBy(C);
	if (C.GetTeamNum() != Team)
	{
		if (Team != 255 && PlayerController(C) != None)
		{
			if (StolenAnnouncement != 'None')
			{
				PlayerController(C).PlayRewardAnnouncement(StolenAnnouncement, 1);
			}
			if (StolenSound != None)
			{
				PlaySound(StolenSound, , 2.5 * TransientSoundVolume, , 400);
			}
		}
		if (C.GetTeamNum() != 255)
		{
			SetTeamNum(C.GetTeamNum());
		}
	}
	NetPriority = 3;
	NetUpdateFrequency = 100;
	ThrottleTime = Level.TimeSeconds;
	bSpawnProtected = false;
	PC = PlayerController(C);
	if (PC != None)
	{
		ClientKDriverEnter(PC);
	}
	if (ParentFactory != None && !bAutoTurret || !ClassIsChildOf(C.Class, AutoTurretControllerClass))
	{
		ParentFactory.VehiclePossessed(Self);
	}
	if (VehicleReplicationInfo != None && PlayerController(C) != None)
	{
		VehicleReplicationInfo.PlayerEntered(PlayerController(C), GetMyPositionIndex());
	}
	*/
}

void AVehicle::UnPossessed()
{
	/*
	local PlayerController PC;
	local Controller NewController;
	local bool bWasPlayer;
	StopWeaponFiring();
	PC = PlayerController(Controller);
	if (PC != None)
	{
		bWasPlayer = true;
		ClientKDriverLeave(PC);
		if (bPCRelativeFPRotation && !PC.bBehindView)
		{
			FixPCRotation(PC);
		}
	}
	else
	{
		ClientClearController();
	}
	NetPriority = Default.NetPriority;
	NetUpdateTime = Level.TimeSeconds - 1;
	NetUpdateFrequency = 8;
	if (VehicleReplicationInfo != None && PC != None)
	{
		VehicleReplicationInfo.PlayerLeft(PC);
	}
	UnPossessed();
	if (ParentFactory != None && !bAutoTurret || Controller == None || !ClassIsChildOf(Controller.Class, AutoTurretControllerClass))
	{
		ParentFactory.VehicleUnPossessed(Self);
	}
	if (Health > 0 && !bDeleteMe)
	{
		if (bWasPlayer && bAutoTurret && AutoTurretControllerClass != None)
		{
			Controller = None;
			NewController = Spawn(AutoTurretControllerClass);
			if (NewController != None)
			{
				NewController.Possess(Self);
			}
		}
	}
	*/
}
void AVehicle::KDriverEnter(APawn* p)
{
	/*
	local Controller C;
	bDriving = true;
	StuckCount = 0;
	if (!bRelativeExitPos)
	{
		PlayerEnterredRotation = p.Rotation;
		ExitPositions[0] = p.Location + vect(0 0 16);
	}
	if (p.Controller != None)
	{
		C = p.Controller;
	}
	if (C == None)
	{
		Return;
	}
	if (C != None && C.PlayerReplicationInfo != None)
	{
		if (!bCanCarryFlag && C.PlayerReplicationInfo.HasFlag != None)
		{
			p.DropFlag();
		}
	}
	Driver = p;
	Driver.StartDriving(Self);
	if (C != None)
	{
		C.bVehicleTransition = true;
		C.UnPossess();
	}
	Driver.SetOwner(Self);
	if (C != None)
	{
		if (C.IsA('PlayerController'))
		{
			PlayerController(C).SimplePossess(Self);
		}
		else
		{
			C.Possess(Self);
		}
		C.bVehicleTransition = false;
	}
	DrivingStatusChanged();
	if (C != None && PlayerController(C) != None)
	{
		VehicleLostTime = 0;
	}
	if (PlayerReplicationInfo != None)
	{
		AttachFlag(PlayerReplicationInfo.HasFlag);
	}
	if (C != None && C.IsA('PlayerController'))
	{
		PlayerController(C).LockPlayer(False, False);
	}
	Level.Game.DriverEnteredVehicle(Self, p);
	if (EventLab != None && C != None)
	{
		EventLab.ActorNotify(Self, 25, C);
	}
	SetDriverHiddenAttachments();
	*/
}

void AVehicle::AttachFlag(AActor* FlagActor)
{
	/*
	if (!bDriverHoldsFlag && FlagActor != None)
	{
		AttachToBone(FlagActor, FlagBone);
		FlagActor.SetRelativeRotation(FlagRotation);
		FlagActor.SetRelativeLocation(FlagOffset);
	}
	*/
}

void AVehicle::SetWheelsScale(float NewScale)
{
	WheelsScale = NewScale;
}

bool AVehicle::KDriverLeave(bool bForceLeave)
{
	/*
	local Controller C;
	local PlayerController PC;
	local bool havePlaced;
	if (!bForceLeave && !Level.Game.CanLeaveVehicle(Self, Driver))
	{
		return false;
	}
	if (PlayerReplicationInfo != None && PlayerReplicationInfo.HasFlag != None)
	{
		Driver.HoldFlag(PlayerReplicationInfo.HasFlag);
	}
	if (Controller == None)
	{
		return false;
	}
	if (Driver != None && !bRemoteControlled || bHideRemoteDriver)
	{
		Driver.bHardAttach = false;
		Driver.bCollideWorld = true;
		Driver.SetCollisionSize(Driver.Default.CollisionRadius, Driver.Default.CollisionHeight);
		Driver.SetCollision(True, True);
		havePlaced = PlaceExitingDriver();
		if (!havePlaced && !bForceLeave)
		{
			Driver.bHardAttach = true;
			Driver.bCollideWorld = false;
			Driver.SetCollision(False, False);
			return false;
		}
	}
	bDriving = false;
	C = Controller;
	if (C.RouteGoal == Self)
	{
		C.RouteGoal = None;
	}
	if (C.MoveTarget == Self)
	{
		C.MoveTarget = None;
	}
	C.bVehicleTransition = true;
	Controller.UnPossess();
	if (Driver != None && Driver.Health > 0)
	{
		Driver.SetOwner(C);
		C.Possess(Driver);
		PC = PlayerController(C);
		if (PC != None)
		{
			PC.ClientSetViewTarget(Driver);
		}
		Driver.StopDriving(Self);
	}
	C.bVehicleTransition = false;
	PlayerController(C).LockPlayer(False, False);
	if (C == Controller)
	{
		Controller = None;
	}
	Level.Game.DriverLeftVehicle(Self, Driver);
	ServerRemoveSeatbelt();
	bReservedOccupation = false;
	ClearDriverHiddenAttachments();
	Driver = None;
	DriverLeft();
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 26, C);
	}
	*/
	return true;
}

void AVehicle::DriverLeft()
{
	DrivingStatusChanged();
}

void AVehicle::UpdateTiltForceFeedback()
{
	/*
	local FRotator SpringCenter;
	local float Pitch;
	local float Roll;
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC != None)
	{
		SpringCenter = Rotation;
		Pitch = Clamp(SpringCenter.Pitch, -CenterSpringRangePitch, CenterSpringRangePitch);
		Roll = Clamp(SpringCenter.Roll, -CenterSpringRangeRoll, CenterSpringRangeRoll);
		Pitch /= CenterSpringRangePitch;
		Roll /= CenterSpringRangeRoll;
		PC.ChangeSpringFeedbackEffect(CenterSpringForce, Roll, Pitch);
	}
	*/
}

void AVehicle::ClientKDriverEnter(APlayerController* PC)
{
	/*
	if (bZeroPCRotOnEntry)
	{
		PC.SetRotation(rot(0 0 0));
	}
	TPCamDistance = Default.TPCamDistance;
	DesiredTPCamDistance = TPCamDistance;
	if (!PC.bBehindView)
	{
		ActivateOverlay(True);
	}
	if (PC.bEnableGUIForceFeedback && PC.bForceFeedbackSupported && Viewport(PC.Player) != None)
	{
		if (CenterSpringRangePitch > 0 && CenterSpringRangeRoll > 0)
		{
			UpdateTiltForceFeedback();
		}
		PC.ClientPlayForceFeedback(CenterSpringForce);
	}
	if (Driver != None)
	{
		Driver.AmbientSound = None;
		if (Driver.Weapon != None)
		{
			Driver.Weapon.AmbientSound = None;
		}
	}
	*/
}

void AVehicle::ClientClearController()
{
	//ActivateOverlay(False);
}

void AVehicle::ClientKDriverLeave(APlayerController* PC)
{
	/*
	if (Driver != None)
	{
		Driver.bOwnerNoSee = Driver.Default.bOwnerNoSee;
	}
	if (PC.bEnableGUIForceFeedback)
	{
		PC.StopForceFeedback(CenterSpringForce);
	}
	bWeaponisFiring = false;
	bWeaponisAltFiring = false;
	ActivateOverlay(False);
	*/
}

void AVehicle::ActivateOverlay(bool bActive)
{
	/*
	if (bActive)
	{
		if (HUDOverlayClass != None && HudOverlay == None)
		{
			HudOverlay = Spawn(HUDOverlayClass);
		}
	}
	else
	{
		if (HudOverlay != None)
		{
			HudOverlay.Destroy();
		}
	}
	*/
}

void AVehicle::FixPCRotation(APlayerController* PC)
{
	//PC.SetRotation(Vector(PC.Rotation) >> Rotation);
}

void AVehicle::GetDriverAttachmentBone(AActor* &AttachActor, FName &DriverAttachmentBone)
{
	AttachActor = this;
	DriverAttachmentBone = DriverBone;
}

void AVehicle::GetOffsets(FVector &oPosOffset, FRotator &oRotOffset)
{
	oPosOffset = DriverPosOffset;
	oRotOffset = DriverRotOffset;
}

void AVehicle::AttachDriver(APawn* p)
{
	/*
	local name DriverAttachmentBone;
	local Actor AttachActor;
	local FVector fPosOffset;
	local FRotator fRotOffset;
	DebugLog(DEBUG_Vehicle, "Attaching Pawn " $ p $ " to vehicle " $ Self);
	if (p == None)
	{
		Return;
	}
	GetDriverAttachmentBone(AttachActor, DriverAttachmentBone);
	if (DriverAttachmentBone == 'None')
	{
		Return;
	}
	GetOffsets(fPosOffset, fRotOffset);
	p.PrePivot.Z = 0;
	p.SetPhysics(0);
	AttachActor.AttachToBone(p, DriverAttachmentBone);
	p.SetRelativeLocation(fPosOffset);
	p.SetRelativeRotation(fRotOffset);
	*/
}

void AVehicle::DetachDriver(APawn* p)
{
	//p.PrePivot = p.Default.PrePivot;
}

bool AVehicle::PlaceExitingDriver()
{
	/*
	local int32 i;
	local int32 j;
	local FVector tryPlace;
	local FVector Extent;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector ZOffset;
	local FVector RandomSphereLoc;
	Extent = Driver.Default.CollisionRadius * vect(1 1 0);
	Extent.Z = Driver.Default.CollisionHeight;
	ZOffset = Driver.Default.CollisionHeight * vect(0 0 1);
	if (VSize(Velocity) > 100)
	{
		tryPlace = Normal(Velocity Cross vect(0 0 1)) * CollisionRadius + Driver.Default.CollisionRadius * 1.25;
		if (FRand() < 0.5)
		{
			tryPlace *= -1;
		}
		if (Trace(HitLocation, HitNormal, Location + tryPlace + ZOffset, Location + ZOffset, False, Extent) == None && Driver.SetLocation(Location + tryPlace + ZOffset) || Trace(HitLocation, HitNormal, Location - tryPlace + ZOffset, Location + ZOffset, False, Extent) == None && Driver.SetLocation(Location - tryPlace + ZOffset))
		{
			return true;
		}
	}
	if (!bRelativeExitPos)
	{
		for (i = 0; i < ExitPositions.Length; i++)
		{
			tryPlace = ExitPositions[i];
			if (Driver.SetLocation(tryPlace))
			{
				return true;
			}
			else
			{
				for (j = 0; j < 10; j++)
				{
					RandomSphereLoc = VRand() * 200 * FMax(FRand(), 0.5);
					RandomSphereLoc.Z = Extent.Z * FRand();
					if (Trace(HitLocation, HitNormal, tryPlace + RandomSphereLoc, tryPlace, False, Extent) == None)
					{
						if (Driver.SetLocation(tryPlace + RandomSphereLoc))
						{
							return true;
						}
					}
					else
					{
						if (Driver.SetLocation(HitLocation))
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	for (i = 0; i < ExitPositions.Length; i++)
	{
		if (ExitPositions[0].Z != 0)
		{
			ZOffset = vect(0 0 1) * ExitPositions[0].Z;
		}
		else
		{
			ZOffset = Driver.Default.CollisionHeight * vect(0 0 2);
		}
		tryPlace = Location + ExitPositions[i] - ZOffset >> Rotation + ZOffset;
		if (Trace(HitLocation, HitNormal, tryPlace, Location + ZOffset, False, Extent) != None)
		{
		}
		if (!Driver.SetLocation(tryPlace))
		{
		}
		return true;
	}
	*/
	return false;
}

void AVehicle::CheckForHeadShot(FVector loc, FVector ray, float AdditionalScale)
{
	//return nullptr;
}
bool AVehicle::TakeRadiusDamage(float DamageAmount, APawn* instigatedBy, FVector ExplosionLocation, float Momentum, UaDamageType* ExplosionDamageType, float DamageRadius)
{
	return false;
}

/*
void AVehicle::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMAterialInstance HitMaterial)
{
	local int32 ActualDamage;
	local Controller Killer;
	if (bSpawnProtected && instigatedBy != None && instigatedBy != Self)
	{
		Return;
	}
	NetUpdateTime = Level.TimeSeconds - 1;
	if (DamageType != None)
	{
		if (instigatedBy == None || instigatedBy.Controller == None && DamageType.Default.bDelayedDamage && DelayedDamageInstigatorController != None)
		{
			instigatedBy = DelayedDamageInstigatorController.Pawn;
		}
		Damage *= DamageType.Default.VehicleDamageScaling;
		Momentum *= DamageType.Default.VehicleMomentumScaling * MomentumMult;
		if (bShowDamageOverlay && DamageType.Default.DamageOverlayMaterial != None && Damage > 0)
		{
			SetOverlayMaterial(DamageType.Default.DamageOverlayMaterial, DamageType.Default.DamageOverlayTime, False);
		}
	}
	if (bRemoteControlled && Driver != None)
	{
		ActualDamage = Damage;
		if (Weapon != None)
		{
			Weapon.AdjustPlayerDamage(ActualDamage, instigatedBy, HitLocation, Momentum, DamageType);
		}
		if (instigatedBy != None && instigatedBy.HasUDamage())
		{
			ActualDamage *= 2;
		}
		ActualDamage = Level.Game.ReduceDamage(ActualDamage, Self, instigatedBy, HitLocation, Momentum, DamageType);
		if (Health - ActualDamage <= 0)
		{
			KDriverLeave(False);
		}
	}
	if (Physics != 13)
	{
		TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType);
		Return;
	}
	if (Weapon != None)
	{
		Weapon.AdjustPlayerDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType);
	}
	if (instigatedBy != None && instigatedBy.HasUDamage())
	{
		Damage *= 2;
	}
	ActualDamage = Level.Game.ReduceDamage(Damage, Self, instigatedBy, HitLocation, Momentum, DamageType);
	Health -= ActualDamage;
	PlayHit(ActualDamage, instigatedBy, HitLocation, DamageType, Momentum);
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
		if (Killer == None && DamageType != None && DamageType.Default.bDelayedDamage)
		{
			Killer = DelayedDamageInstigatorController;
		}
		Died(Killer, DamageType, HitLocation);
	}
	else
	{
		if (Controller != None)
		{
			Controller.NotifyTakeHit(instigatedBy, HitLocation, ActualDamage, DamageType, Momentum);
		}
	}
	MakeNoise(1);
	if (!bDeleteMe)
	{
		if (Location.Z > Level.StallZ)
		{
			Momentum.Z = FMin(Momentum.Z, 0);
		}
		KAddImpulse(Momentum, HitLocation);
	}
}
*/

bool AVehicle::HealDamage(int32 Amount, AController* Healer, UaDamageType* DamageType)
{
	/*
	if (PlayerController(Healer) != None)
	{
		PlayerStartTime = Level.TimeSeconds + 3;
	}
	if (Health <= 0 || Health >= HealthMax || Amount <= 0 || Healer == None || !TeamLink(Healer.GetTeamNum()))
	{
		return false;
	}
	Health = Min(Health + Amount * LinkHealMult, HealthMax);
	NetUpdateTime = Level.TimeSeconds - 1;
	*/
	return true;
}

void AVehicle::DriverRadiusDamage(float DamageAmount, float DamageRadius, AController* EventInstigator, UaDamageType* DamageType, float Momentum, FVector HitLocation)
{
	/*
	local float damageScale;
	local float dist;
	local FVector Dir;
	if (EventInstigator == None || Driver == None || Driver.bCollideActors || bRemoteControlled)
	{
		Return;
	}
	Dir = Driver.Location - HitLocation;
	dist = FMax(1, VSize(Dir));
	Dir = Dir / dist;
	damageScale = 1 - FMax(0, dist - Driver.CollisionRadius / DamageRadius);
	if (damageScale <= 0)
	{
		Return;
	}
	Driver.SetDelayedDamageInstigatorController(EventInstigator);
	Driver.TakeDamage(damageScale * DamageAmount, EventInstigator.Pawn, Driver.Location - 0.5 * Driver.CollisionHeight + Driver.CollisionRadius * Dir, damageScale * Momentum * Dir, DamageType);
	*/
}

void AVehicle::DriverDied()
{
	/*
	local Controller C;
	Level.Game.DiscardInventory(Driver);
	if (PlayerReplicationInfo != None && PlayerReplicationInfo.HasFlag != None)
	{
		PlayerReplicationInfo.HasFlag.Drop(0.5 * Velocity);
	}
	if (Driver == None)
	{
		Return;
	}
	C = Controller;
	Driver.StopDriving(Self);
	Driver.Controller = C;
	Driver.DrivenVehicle = Self;
	if (Controller == None)
	{
		Return;
	}
	if (PlayerController(Controller) != None)
	{
		Controller.SetLocation(Location);
		PlayerController(Controller).SetViewTarget(Driver);
		PlayerController(Controller).ClientSetViewTarget(Driver);
	}
	Controller.UnPossess();
	if (Controller == C)
	{
		Controller = None;
	}
	C.Pawn = Driver;
	Driver.SetOwner(C);
	bCollideWorld = false;
	Driver.SetLocation(Driver.Location + vect(0 0 1) * 20);
	bCollideWorld = true;
	Level.Game.DriverLeftVehicle(Self, Driver);
	Driver = None;
	bDriving = false;
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	*/
}

void AVehicle::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
	/*
	local PlayerController PC;
	local Controller C;
	if (bDeleteMe || Level.bLevelChange)
	{
		Return;
	}
	if (Physics != 13)
	{
		Died(Killer, DamageType, HitLocation);
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
		Level.Game.Killed(Killer, C, Self, DamageType);
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
		if (!C.bIsPlayer && !C.bDeleteMe)
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
	if (!bDeleteMe)
	{
		Destroy();
	}
	*/
}

void AVehicle::AdjustDriverDamage(int32 &Damage, APawn* instigatedBy, FVector HitLocation, FVector &Momentum, UaDamageType* DamageType)
{
	/*
	if (InGodMode())
	{
		Damage = 0;
	}
	else
	{
		Damage *= DriverDamageMult;
	}
	*/
}

void AVehicle::EjectDriver()
{
	/*
	local Pawn OldPawn;
	local FVector EjectVel;
	OldPawn = Driver;
	KDriverLeave(True);
	if (OldPawn == None)
	{
		Return;
	}
	EjectVel = VRand();
	EjectVel.Z = 0;
	EjectVel = Normal(EjectVel) * 0.2 + vect(0 0 1) * EjectMomentum;
	OldPawn.Velocity = EjectVel;
	OldPawn.SpawnTime = Level.TimeSeconds;
	OldPawn.PlayTeleportEffect(False, False);
	*/
}

bool AVehicle::UsedBy(APawn* User)
{
	if (Driver != nullptr)
	{
		return false;
	}
	TryToDrive(User);
	return true;
}

bool AVehicle::PanelUsedBy(APawn* User, int32 Id)
{
	return false;
}

void AVehicle::Fire(float F)
{
	//VehicleFire(False);
	//bWeaponisFiring = true;
}

void AVehicle::AltFire( float F)
{
	//VehicleFire(True);
	//bWeaponisAltFiring = true;
}

void AVehicle::ClientVehicleCeaseFire(bool bWasAltFire)
{
	if (bWasAltFire)
	{
		bWeaponisAltFiring = false;
	}
	else
	{
		bWeaponisFiring = false;
	}
	VehicleCeaseFire(bWasAltFire);
}

void AVehicle::VehicleFire(bool bWasAltFire)
{
	if (bWasAltFire)
	{
		bWeaponisAltFiring = true;
	}
	else
	{
		bWeaponisFiring = true;
	}
}

void AVehicle::VehicleCeaseFire(bool bWasAltFire)
{
	if (bWasAltFire)
	{
		bWeaponisAltFiring = false;
	}
	else
	{
		bWeaponisFiring = false;
	}
}

bool AVehicle::StopWeaponFiring()
{
	bool bResult=false;
	/*
	if (bWeaponisFiring)
	{
		ClientVehicleCeaseFire(False);
		bWeaponisFiring = false;
		bResult = true;
	}
	if (bWeaponisAltFiring)
	{
		ClientVehicleCeaseFire(True);
		bWeaponisAltFiring = false;
		bResult = true;
	}
	*/
	return bResult;
}

void AVehicle::UpdateEyeHeight(float DeltaTime)
{
	/*
	local Controller C;
	if (Controller != None && Controller.IsA('PlayerController'))
	{
		Controller.AdjustView(DeltaTime);
	}
	C = Level.ControllerList;
	if (C != None)
	{
		if (C.IsA('PlayerController') && PlayerController(C).ViewTarget == Self)
		{
			Return;
		}
		C = C.nextController;
	}
	bUpdateEyeheight = false;
	EyeHeight = BaseEyeHeight;
	*/
}

void AVehicle::FaceRotation(FRotator NewRotation, float DeltaTime)
{
}

void AVehicle::SetAnimAction(FName NewAction)
{
	/*
	if (bDrawDriverInTP && Driver != None)
	{
		Driver.SetAnimAction(NewAction);
	}
	*/
}

void AVehicle::EncroachedBy(AActor* Other)
{
}

void AVehicle::RanInto(AActor* Other)
{
	/*
	local FVector Momentum;
	local float Speed;
	if (Pawn(Other) == None || Vehicle(Other) != None || Other == Instigator || Other.Role != 4)
	{
		Return;
	}
	Speed = VSize(Velocity);
	if (Speed > MinRunOverSpeed)
	{
		Momentum = Velocity * 0.25 * Other.Mass;
		if (Controller != None && Controller.SameTeamAs(Pawn(Other).Controller))
		{
			Momentum += Speed * 0.25 * Other.Mass * Normal(Velocity Cross vect(0 0 1));
		}
		if (RanOverSound != None)
		{
			PlaySound(RanOverSound, , TransientSoundVolume * 2.5);
		}
		Other.TakeDamage(Speed * 0.075, Self, Other.Location, Momentum, RanOverDamageType, , Controller);
	}
	*/
}

bool AVehicle::EncroachingOn(AActor* Other)
{
	/*
	if (Other == None || Other == Instigator || Other.Role != 4 || !Other.bCollideActors && !Other.bBlockActors || VSize(Velocity) < 10)
	{
		return false;
	}
	if (Pawn(Other) != None && !Pawn(Other).IsHumanControlled() && Vehicle(Other) == None)
	{
		Other.TakeDamage(200, Instigator, Other.Location, Velocity * Other.Mass, CrushedDamageType);
		return false;
	}
	*/

	return false;    //FAKE   /ELiZ
}

void AVehicle::FindValidTaunt(FName &Sequence)
{
	/*
	if (!bDrawDriverInTP || Driver == None)
	{
		return false;
	}
	Return Driver.FindValidTaunt(Sequence);
	*/
}

void AVehicle::CheckTauntValid(FName Sequence)
{
	/*
	if (!bDrawDriverInTP || Driver == None)
	{
		return false;
	}
	Return Driver.CheckTauntValid(Sequence);
	*/
}

bool AVehicle::Occupied()
{
	return GetController() != nullptr;
}

float AVehicle::ReservationCostMultiplier()
{
	return 1;
}

float AVehicle::NewReservationCostMultiplier(APawn* p)
{
	return ReservationCostMultiplier();
}

bool AVehicle::ChangedReservation(APawn* p)
{
	return false;
}

bool AVehicle::SpokenFor(AController* C)
{
	return false;
}

void AVehicle::SetReservation(AController* C)
{
}

void AVehicle::OpenPositionFor(APawn* p)
{
	/*
	if (Controller == None)
	{
		return this;
	}
	return nullptr;
	*/
}

bool AVehicle::IndependentVehicle()
{
	return true;
}

void AVehicle::GetBestEntry(APawn* p)
{
	//return this;
}

void AVehicle::GetMoveTargetFor(APawn* p)
{
	//return this;
}

void AVehicle::DrivingStatusChanged()
{
	/*
	local PlayerController PC;
	PC = Level.GetLocalPlayerController();
	if (bDriving && PC != None && PC.ViewTarget == None || !PC.ViewTarget.IsJoinedTo(Self))
	{
		bDropDetail = Level.bDropDetail || Level.DetailMode == 0;
	}
	else
	{
		bDropDetail = false;
	}
	if (bDriving)
	{
		Enable('Tick');
	}
	else
	{
		Disable('Tick');
	}
	*/
}

void AVehicle::TakeWaterDamage(float DeltaTime)
{
	/*
	local FVector HitLocation;
	local FVector HitNormal;
	local Actor EntryActor;
	TakeDamage(WaterDamage * DeltaTime, Self, vect(0 0 0), vect(0 0 0), VehicleDrowningDamType);
	if (Level.TimeSeconds - SplashTime > 0.3 && PhysicsVolume.PawnEntryActor != None && !Level.bDropDetail && Level.DetailMode != 0 && EffectIsRelevant(Location, False) && VSize(Velocity) > 300)
	{
		SplashTime = Level.TimeSeconds;
		if (!PhysicsVolume.TraceThisActor(HitLocation, HitNormal, Location - CollisionHeight * vect(0 0 1), Location + CollisionHeight * vect(0 0 1)))
		{
			EntryActor = Spawn(PhysicsVolume.PawnEntryActor, Self, , HitLocation, rot(16384 0 0));
		}
	}
	*/
}

void AVehicle::LockOnWarning()
{
	/*
	local class<LocalMessage>  LockOnClass;
	LockOnClass = class<LocalMessage>(DynamicLoadObject(LockOnClassString, Class'Class'));
	PlayerController(Controller).ReceiveLocalizedMessage(LockOnClass, 12);
	LastLockWarningTime = Level.TimeSeconds;
	*/
}

bool AVehicle::PointOfView()
{
	/*
	if (!bAllowViewChange)
	{
		return true;
	}
	return Default.bDesiredBehindView;
	*/
	return false;    //FAKE   /ELiZ
}

void AVehicle::PlayTeleportEffect(bool bOut, bool bSound)
{
	/*
	local Actor A;
	local class<Actor>  TransEffect;
	if (GetTeam() == None || GetTeam().TeamIndex == 0)
	{
		TransEffect = class<Actor>(DynamicLoadObject(TransEffects[0], Class'Class'));
	}
	else
	{
		TransEffect = class<Actor>(DynamicLoadObject(TransEffects[1], Class'Class'));
	}
	if (TransEffect != None)
	{
		A = Spawn(TransEffect, , , Location + CollisionHeight * vect(0 0 0.75));
	}
	if (A != None)
	{
		A.SetBase(Self);
	}
	PlayTeleportEffect(bOut, bSound);
	*/
}

void AVehicle::PlayDying(UaDamageType* DamageType, FVector HitLoc, FVector HitDir, FBoneInfo Bone)
{
}

uint8 AVehicle::GetTeamNum()
{
	/*
	if (Role == 4 && Team == 255 && Controller != None)
	{
		SetTeamNum(Controller.GetTeamNum());
	}
	*/
	return Team;
}

void AVehicle::NotifyEnemyLockedOn()
{
	bEnemyLockedOn = true;
}

void AVehicle::IncomingMissile(AProjectile* p)
{
}

void AVehicle::NotifyEnemyLostLock()
{
	bEnemyLockedOn = false;
}

void AVehicle::SetTeamNum(uint8 t)
{
	PrevTeam = Team;
	Team = t;
	if (PrevTeam != Team)
	{
		TeamChanged();
	}
}

void AVehicle::TeamChanged()
{
}

/*
void AVehicle::DisplayDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	DisplayDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.DrawText("Steering " $ Steering $ " throttle " $ Throttle $ " rise " $ Rise);
	if (Driver != None)
	{
		YPos += YL;
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.SetDrawColor(0, 0, 255);
		Canvas.DrawText("--- DRIVER");
		Canvas.SetPos(4, YPos);
		Driver.DisplayDebug(Canvas, YL, YPos);
	}
}
*/

void AVehicle::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	/*
	local float XL;
	Canvas.StrLen("TEST", XL, YL);
	YPos = YPos + YL;
	Canvas.Style = 1;
	Canvas.SetDrawColor(255, 0, 0);
	*/
}

AActor* AVehicle::ShootSpecial(AActor* A)
{
	/*
	local Controller OldController;
	if (!Controller.bCanDoSpecial || Weapon == None)
	{
		return nullptr;
	}
	Controller = OldController;
	if (KDriverLeave(False) && OldController.Pawn != None)
	{
		OldController.Pawn.SetRotation(A.Location - OldController.Pawn.Location);
		OldController.Focus = A;
		OldController.FireWeaponAt(A);
	}
	*/
	return A;
}

void AVehicle::Stalled()
{
}

void AVehicle::UnStalled()
{
}

void AVehicle::NextWeapon()
{
	/*
	local PlayerController PC;
	if (Level.Pauser != None)
	{
		Return;
	}
	PC = PlayerController(Controller);
	if (PC == None)
	{
		Return;
	}
	if (!PC.bBehindView)
	{
		PC.BehindView(True);
		DesiredTPCamDistance = TPCamDistRange.Min;
		TPCamDistance = DesiredTPCamDistance;
	}
	else
	{
		DesiredTPCamDistance = Min(DesiredTPCamDistance + 100, TPCamDistRange.Max);
	}
	Default.TPCamDistance = DesiredTPCamDistance;
	StaticSaveConfig();
	*/
}

void AVehicle::PrevWeapon()
{
	/*
	local PlayerController PC;
	if (Level.Pauser != None)
	{
		Return;
	}
	PC = PlayerController(Controller);
	if (PC == None || !PC.bBehindView)
	{
		Return;
	}
	if (DesiredTPCamDistance ~= TPCamDistRange.Min)
	{
		PC.BehindView(False);
	}
	else
	{
		DesiredTPCamDistance = Max(DesiredTPCamDistance - 100, TPCamDistRange.Min);
		Default.TPCamDistance = DesiredTPCamDistance;
		StaticSaveConfig();
	}
	*/
}

void AVehicle::TeamLink(int32 TeamNum)
{
	//Return LinkHealMult > 0 && Team == TeamNum && Health > 0;
}

bool AVehicle::NeedsFlip()
{
	/*
	local FVector worldUp;
	local FVector gravUp;
	local float GravMag;
	GravMag = VSize(PhysicsVolume.Gravity);
	if (GravMag < 0.1)
	{
		gravUp = vect(0 0 1);
	}
	else
	{
		gravUp = -1 * PhysicsVolume.Gravity / GravMag;
	}
	worldUp = vect(0 0 1) >> Rotation;
	if (worldUp Dot gravUp < -0.5)
	{
		return true;
	}
	*/
	return false;
}

void AVehicle::Flip(FVector HitNormal, float ForceScale)
{
}

void AVehicle::ChargeBar()
{
}

void AVehicle::ClientPlayForceFeedback(FString EffectName)
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC != None && PC.bEnableGUIForceFeedback)
	{
		PC.ClientPlayForceFeedback(EffectName);
	}
	*/
}

void AVehicle::StopForceFeedback(FString EffectName)
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC != None && PC.bEnableGUIForceFeedback)
	{
		PC.StopForceFeedback(EffectName);
	}
	*/
}

void AVehicle::ServerPlayHorn(int32 HornIndex)
{
	/*
	if (Level.TimeSeconds - LastHornTime > 0.25 && HornIndex >= 0 && HornIndex < HornSounds.Length)
	{
		PlaySound(HornSounds[HornIndex], , 3.5 * TransientSoundVolume, , 800);
		LastHornTime = Level.TimeSeconds;
	}
	*/
}

int32 AVehicle::NumPassengers()
{
	/*
	if (Driver != None)
	{
		Return 1;
	}
	*/
	return 0;
}

void AVehicle::GetInstigator()
{
	//return this;
}

void AVehicle::GetBotPassenger()
{
	//return AIController(Controller);
}

bool AVehicle::IsVehicleEmpty()
{
	return Driver == nullptr;
}

bool AVehicle::HasOccupiedTurret()
{
	return false;
}

float AVehicle::AdjustedStrength()
{
	/*
	if (bStationary && bDefensive)
	{
		Return 1;
	}
	*/
	return 0;
}
/*
void AVehicle::StaticPrecache(LevelInfo L)
{
}
*/
float AVehicle::GetSpree()
{
	/*
	if (Driver != None)
	{
		Return Driver.GetSpree();
	}
	*/
	return 0;
}

void AVehicle::IncrementSpree()
{
	/*
	if (Driver != None)
	{
		Driver.IncrementSpree();
	}
	*/
}

void AVehicle::ToggleVehicleView()
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC != None)
	{
		PC.BehindView(!PC.bBehindView);
		POVChanged(PC, True);
	}
	*/
}

void AVehicle::POVChanged(APlayerController* PC, bool bBehindViewChanged)
{
	/*
	if (PC.bBehindView)
	{
		if (bBehindViewChanged && bPCRelativeFPRotation)
		{
			PC.SetRotation(Vector(PC.Rotation) >> Rotation);
		}
		bOwnerNoSee = false;
		if (Driver != None)
		{
			if (bDrawDriverInTP)
			{
				Driver.bOwnerNoSee = false;
			}
			else
			{
				Driver.bOwnerNoSee = true;
			}
		}
		if (PC == Controller)
		{
			ActivateOverlay(False);
		}
	}
	else
	{
		if (bPCRelativeFPRotation)
		{
			PC.SetRotation(Vector(PC.Rotation) << Rotation);
		}
		if (bDrawMeshInFP)
		{
			bOwnerNoSee = false;
		}
		else
		{
			bOwnerNoSee = true;
		}
		if (Driver != None)
		{
			Driver.bOwnerNoSee = true;
		}
		if (bDriving && PC == Controller)
		{
			ActivateOverlay(True);
		}
	}
	*/
}

void AVehicle::PlayTakeHit(FVector HitLocation, int32 Damage, UaDamageType* DamageType)
{
	/*
	local int32 SoundNum;
	if (IndependentVehicle() && DamageType.Default.bBulletHit && BulletSounds.Length > 0)
	{
		SoundNum = Rand(BulletSounds.Length);
		if (Controller != None && Controller == Level.GetLocalPlayerController())
		{
			PlayOwnedSound(BulletSounds[SoundNum], 0, 2, False, 400);
		}
		else
		{
			PlayOwnedSound(BulletSounds[SoundNum], 0, 2, False, 100);
		}
	}
	*/
}

void AVehicle::GetTurrets()
{
}

void AVehicle::CheckSuperBerserk()
{
}

bool AVehicle::VerifyLock(AActor* Aggressor, AActor* &NewTarget)
{
	return true;
}

void AVehicle::AlternateTarget()
{
	//return nullptr;
}

void AVehicle::ShouldTargetMissile(AProjectile* p)
{
	/*
	local AIController C;
	C = AIController(Controller);
	if (C != None && C.Skill >= 5 && C.Enemy == None || !C.LineOfSightTo(C.Enemy))
	{
		ShootMissile(p);
	}
	*/
}

void AVehicle::ShootMissile(AProjectile* p)
{
	/*
	Controller.Focus = p;
	Controller.FireWeaponAt(p);
	*/
}

bool AVehicle::ImportantVehicle()
{
	return false;
}

bool AVehicle::IsArtillery()
{
	return false;
}

void AVehicle::ServerSetSeatbelt()
{
	/*
	if (bWearingSeatbelt != True)
	{
		PlaySound(SeatbeltSound, 0, 1);
	}
	bWearingSeatbelt = true;
	*/
}

void AVehicle::ServerRemoveSeatbelt()
{
	/*
	if (bWearingSeatbelt != False)
	{
		PlaySound(SeatbeltSound, 0, 1);
	}
	bWearingSeatbelt = false;
	*/
}

void AVehicle::SetSeatbelt()
{
	ServerSetSeatbelt();
}

void AVehicle::GetDamageModifier(int32 BodyPanelID, UaDamageType* DamageType, int32 Damage)
{
}

void AVehicle::NotifyVehiclePanelDamaged(int32 PanelID, int32 DamageLevel)
{
}

void AVehicle::NotifyVehiclePanelDestroyed(int32 PanelID)
{
}