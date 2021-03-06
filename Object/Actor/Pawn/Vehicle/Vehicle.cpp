// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/AIMarker/AIMarker.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/SVehicleFactory/SVehicleFactory.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/VehicleReplicationInfo.h"
#include "AA29/Object/DamageType/Crushed/Crushed.h"
#include "AA29/Object/DamageType/DamRanOver/DamRanOver.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

// Sets default values
AVehicle::AVehicle()
{
	SpawnOverlay.SetNum(2);
	TransEffects.SetNum(2);
 	// Set this APawn* to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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
	//RanOverDamageType = ADamRanOver::StaticClass();
	//CrushedDamageType = ACrushed::StaticClass();
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
	ValidJavelinTarget = 1;
}

/*
State UnDeployed
{
	Function VehicleFire(bool bWasAltFire)
	{
		Global.C(bWasAltFire);
	}
	Function VehicleCeaseFire(bool bWasAltFire)
	{
		Global.iRand(bWasAltFire);
	}
}
*/

/*
State Deployed
{
	Function VehicleFire(bool bWasAltFire)
	{
		Global.C(bWasAltFire);
	}
	Function VehicleCeaseFire(bool bWasAltFire)
	{
		Global.iRand(bWasAltFire);
	}
}
*/


void AVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}


void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

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

float AVehicle::UAVGetRadioStrength()
{
	return 0;
}

void AVehicle::StartSmokeGenerator()
{
}

void AVehicle::StopSmokeGenerator()
{
}

AActor* AVehicle::GetActiveWeaponSystem()
{
	return nullptr;     //FAKE  /ELiZ
}

AActor* AVehicle::GetPosition(int32 iPosition)
{
	return nullptr;     //FAKE  /ELiZ
}

FRotator AVehicle::GetWeaponAim()
{
	return FRotator(0,0,0);     //FAKE  /ELiZ
}

bool AVehicle::VehicleDisabled()
{
	return false;     //FAKE  /ELiZ
}

void AVehicle::SetDriverHiddenAttachments()
{
}

void AVehicle::ClearDriverHiddenAttachments()
{
	int32 i = 0;
	if (Driver != nullptr)
	{
		for (i = 0; i < 24; i++)
		{
			//Driver->HiddenAttachmentClasses[i] = nullptr;
		}
	}
}

void AVehicle::PreBeginPlay()
{
	/*
	if (!Level.Game.bAllowVehicles && !bDeleteMe)
	{
		Destroy();
		return;
	}
	Super::PreBeginPlay();
	*/
}

void AVehicle::PlayerChangedTeam()
{
	if (Driver != nullptr)
	{
		//Driver->KilledBy(Driver);
	}
	else
	{
		PlayerChangedTeam();
	}
}

int32 AVehicle::GetVehicleNumber()
{
	return VehicleNumber;
}

int32 AVehicle::GetVehiclePositionIndex(AVehicle* VehiclePosition)
{
	return -1;
}

int32 AVehicle::GetMyPositionIndex()
{
	return GetVehiclePositionIndex(this);
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
	if (Driver != nullptr)
	{
		//Driver->KilledBy(Driver);
	}
	else
	{
		//KilledBy(this);
	}
}

void AVehicle::MatchEnding()
{
	//Super::MatchEnding();
	if (Driver != nullptr)
	{
		//KDriverLeave(true);
	}
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
	if (VehicleReplicationInfoClass != nullptr)
	{
		//VehicleReplicationInfo = Spawn(VehicleReplicationInfoClass, this);
		VehicleReplicationInfo->SetVehicle(this);
		VehicleReplicationInfo->SetVehicleNumber(VehicleNumber);
	}
}

void AVehicle::PostBeginPlay()
{
	AController* NewController = nullptr;
	/*
	Super::PostBeginPlay();
	if (bDeleteMe)
	{
		return;
	}
	if (bVehicleShadows && bDrawVehicleShadow && GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		VehicleShadow = Spawn('ShadowProjector', this, "None", Location);
		VehicleShadow.ShadowActor = this;
		VehicleShadow.LightDirection = Normal(FVector(1 1 6));
		VehicleShadow.LightDistance = 1200;
		VehicleShadow.MaxTraceDistance = ShadowMaxTraceDist;
		VehicleShadow.CullDistance = ShadowCullDistance;
		VehicleShadow.InitShadow();
	}
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		if (bAutoTurret && Controller == nullptr && AutoTurretControllerClass != nullptr)
		{
			NewController = Spawn(AutoTurretControllerClass);
			if (NewController != nullptr)
			{
				NewController.Possess(this);
			}
		}
		if (!bAutoTurret && !bNonHumanControl && IndependentVehicle())
		{
			Level.Game.RegisterVehicle(this);
		}
		CreateVRI();
	}
	OldTeam = Team;
	PrevTeam = Team;
	*/
}

void AVehicle::SetInitialState()
{
	//Super::SetInitialState();
	//Disable("Tick");
}

bool AVehicle::StronglyRecommended(AActor* S, int32 TeamIndex, AActor* Objective)
{
	return bKeyVehicle;
}

float AVehicle::BotDesireability(AActor* S, int32 TeamIndex, AActor* Objective)
{
	bool bSameTeam = false;
	APlayerController* p = nullptr;
	bSameTeam = GetTeamNum() == TeamIndex;
	if (bSameTeam)
	{
		if (GetWorld()->GetTimeSeconds() < TeamUseTime)
		{
			return 0;
		}
		if (!bKeyVehicle && GetWorld()->GetTimeSeconds() < PlayerStartTime)
		{
			/*
			p = Level->GetLocalPlayerController();
			if (p == nullptr || p->Pawn != nullptr && Cast<AVehicle>(p->Pawn) == nullptr)
			{
				return 0;
			}
			*/
		}
	}
	/*
	if (!bKeyVehicle && !bStationary && GetWorld()->GetTimeSeconds() < VehicleLostTime)
	{
		return 0;
	}
	else
	{
		if (Health <= 0 || Occupied() || bTeamLocked && !bSameTeam)
		{
			return 0;
		}
	}
	*/
	if (bKeyVehicle)
	{
		return 100;
	}
	return MaxDesireability * 0.5 + MaxDesireability * 0.5 * Health / HealthMax;
}

void AVehicle::Destroyed()
{
	AVehicle* V = nullptr;
	AVehicle* Prev = nullptr;
	if (ParentFactory != nullptr)
	{
		ParentFactory->VehicleDestroyed(this);
	}
	if (VehicleShadow != nullptr)
	{
		//VehicleShadow->Destroy();
	}
	/*
	if (bAutoTurret && Controller != nullptr && ClassIsChildOf(Controller.Class, AutoTurretControllerClass) && !Controller.bDeleteMe)
	{
		Controller.Destroy();
		Controller = nullptr;
	}
	if (Driver != nullptr)
	{
		Destroyed_HandleDriver();
	}
	if (Level.Game != nullptr)
	{
		if (Level.Game.VehicleList == this)
		{
			Level.Game.VehicleList = NextVehicle;
		}
		else
		{
			Prev = Level.Game.VehicleList;
			if (Prev != nullptr)
			{
				V = Level.Game.VehicleList.NextVehicle;
				if (V != nullptr)
				{
					if (V == this)
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
	if (VehicleReplicationInfo != nullptr)
	{
		VehicleReplicationInfo.Destroy();
	}
	*/
	Super::Destroyed();
}

void AVehicle::Destroyed_HandleDriver()
{
	APawn* OldDriver = nullptr;
	/*
	Driver.LastRenderTime = LastRenderTime;
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		if (Driver != nullptr && !bRemoteControlled && !bEjectDriver && !bDrawDriverInTP && Driver.Health > 0)
		{
			OldDriver = Driver;
			Driver = nullptr;
			OldDriver.DrivenVehicle = nullptr;
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
					Driver.StopDriving(this);
					Driver.DrivenVehicle = this;
				}
				Driver.TearOffMomentum = Velocity * 0.25;
				Driver.Died(Controller, 'DamRanOver', Driver.Location);
			}
		}
	}
	else
	{
		if (Driver.DrivenVehicle == this)
		{
			Driver.StopDriving(this);
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
	FVector CamLookAt = FVector(0,0,0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector OffsetVector = FVector(0, 0, 0);
	AActor* HitActor = nullptr;
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	if (Driver != nullptr && bDrawDriverInTP)
	{
		Driver->bOwnerNoSee = false;
	}
	if (DesiredTPCamDistance < TPCamDistance)
	{
		TPCamDistance = FMax(DesiredTPCamDistance, TPCamDistance - CameraSpeed * GetWorld()->GetTimeSeconds() - LastCameraCalcTime);
	}
	else
	{
		if (DesiredTPCamDistance > TPCamDistance)
		{
			TPCamDistance = FMin(DesiredTPCamDistance, TPCamDistance + CameraSpeed * GetWorld()->GetTimeSeconds() - LastCameraCalcTime);
		}
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = this;
	CamLookAt = GetCameraLocationStart() + TPCamLookat >> Rotation + TPCamWorldOffset;
	OffsetVector = FVector(0,0,0);
	OffsetVector.X = -1 * TPCamDistance;
	CameraLocation = CamLookAt + OffsetVector >> PC.Rotation;
	HitActor = Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, true, FVector(40 40 40));
	if (HitActor != nullptr && HitActor.bWorldGeometry || HitActor == GetVehicleBase() || Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, false, FVector(40 40 40)) != nullptr)
	{
		CameraLocation = HitLocation;
	}
	CameraRotation = Normalize(PC.Rotation + PC.ShakeRot);
	CameraLocation = CameraLocation + PC.ShakeOffset.X * X + PC.ShakeOffset.Y * Y + PC.ShakeOffset.Z * Z;
	*/
}

void AVehicle::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	FQuat CarQuat = FQuat(0,0,0,0);
	FQuat LookQuat = FQuat(0, 0, 0, 0);
	FQuat ResultQuat = FQuat(0, 0, 0, 0);
	FVector VehicleZ = FVector(0,0,0);
	FVector CamViewOffsetWorld = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	float CamViewOffsetZAmount = 0;
	/*
	if (Driver != nullptr)
	{
		Driver.bOwnerNoSee = true;
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = this;
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
		VehicleZ = FVector(0 0 1) >> Rotation;
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
	APlayerController* PC = nullptr;
	PC = Cast<APlayerController>(Controller);
	if (PC == nullptr || PC.ViewTarget != Self)
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
	LastCameraCalcTime = GetWorld()->GetTimeSeconds();
	*/
	return true;
}

bool AVehicle::SpectatorSpecialCalcView(APlayerController* Viewer, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	FRotator DummyRotation = FRotator(0,0,0);
	/*
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
	LastCameraCalcTime = GetWorld()->GetTimeSeconds();
	Viewer.SetLocation(CameraLocation);
	*/
	return true;
}

AVehicle* AVehicle::FindEntryVehicle(APawn* p)
{
	/*
	if (Cast<AAIController>(p.Controller) != nullptr)
	{
		return this;
	}
	if (VSize(p.Location - Location + EntryPosition >> Rotation) < EntryRadius)
	{
		return this;
	}
	*/
	return nullptr;
}

bool AVehicle::TryToDrive(APawn* p)
{
	/*
	if (p.bIsCrouched || bNonHumanControl || p.Controller == nullptr || Driver != nullptr || p.DrivenVehicle != nullptr || !p.Controller.bIsPlayer && !p.Controller->IsA(ANPCBaseController::StaticClass()) || p->IsA(AVehicle::StaticClass()) || Health <= 0)
	{
		return false;
	}
	if (!Level.Game.CanEnterVehicle(this, p))
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
	return false;    //FAKE   /ELiZ
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
	APlayerController* PC = nullptr;
	if (bAutoTurret && Controller != nullptr && ClassIsChildOf(Controller.Class, AutoTurretControllerClass) && !Controller.bDeleteMe)
	{
		Controller.Destroy();
		Controller = nullptr;
	}
	PossessedBy(C);
	if (C.GetTeamNum() != Team)
	{
		if (Team != 255 && PlayerController(C) != nullptr)
		{
			if (StolenAnnouncement != "None")
			{
				Cast<APlayerController>(C).PlayRewardAnnouncement(StolenAnnouncement, 1);
			}
			if (StolenSound != nullptr)
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
	ThrottleTime = GetWorld()->GetTimeSeconds();
	bSpawnProtected = false;
	PC = Cast<APlayerController>(C);
	if (PC != nullptr)
	{
		ClientKDriverEnter(PC);
	}
	if (ParentFactory != nullptr && !bAutoTurret || !ClassIsChildOf(C.Class, AutoTurretControllerClass))
	{
		ParentFactory.VehiclePossessed(this);
	}
	if (VehicleReplicationInfo != nullptr && PlayerController(C) != nullptr)
	{
		VehicleReplicationInfo.PlayerEntered(Cast<APlayerController>(C), GetMyPositionIndex());
	}
	*/
}

void AVehicle::UnPossessed()
{
	APlayerController* PC = nullptr;
	AController* NewController = nullptr;
	bool bWasPlayer = false;
	StopWeaponFiring();
	/*
	PC = Cast<APlayerController>(Controller);
	if (PC != nullptr)
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
	NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	NetUpdateFrequency = 8;
	if (VehicleReplicationInfo != nullptr && PC != nullptr)
	{
		VehicleReplicationInfo.PlayerLeft(PC);
	}
	UnPossessed();
	if (ParentFactory != nullptr && !bAutoTurret || Controller == nullptr || !ClassIsChildOf(Controller.Class, AutoTurretControllerClass))
	{
		ParentFactory.VehicleUnPossessed(this);
	}
	if (Health > 0 && !bDeleteMe)
	{
		if (bWasPlayer && bAutoTurret && AutoTurretControllerClass != nullptr)
		{
			Controller = nullptr;
			NewController = Spawn(AutoTurretControllerClass);
			if (NewController != nullptr)
			{
				NewController.Possess(this);
			}
		}
	}
	*/
}
void AVehicle::KDriverEnter(APawn* p)
{
	/*
	AController* C = nullptr;
	bDriving = true;
	StuckCount = 0;
	if (!bRelativeExitPos)
	{
		PlayerEnterredRotation = p.Rotation;
		ExitPositions[0] = p.Location + FVector(0 0 16);
	}
	if (p.Controller != nullptr)
	{
		C = p.Controller;
	}
	if (C == nullptr)
	{
		return;
	}
	if (C != nullptr && C.PlayerReplicationInfo != nullptr)
	{
		if (!bCanCarryFlag && C.PlayerReplicationInfo.HasFlag != nullptr)
		{
			p.DropFlag();
		}
	}
	Driver = p;
	Driver.StartDriving(this);
	if (C != nullptr)
	{
		C.bVehicleTransition = true;
		C.UnPossess();
	}
	Driver.SetOwner(this);
	if (C != nullptr)
	{
		if (C->IsA(APlayerController::StaticClass()))
		{
			Cast<APlayerController>(C).SimplePossess(this);
		}
		else
		{
			C.Possess(this);
		}
		C.bVehicleTransition = false;
	}
	DrivingStatusChanged();
	if (C != nullptr && PlayerController(C) != nullptr)
	{
		VehicleLostTime = 0;
	}
	if (PlayerReplicationInfo != nullptr)
	{
		AttachFlag(PlayerReplicationInfo.HasFlag);
	}
	if (C != nullptr && C->IsA(APlayerController::StaticClass()))
	{
		Cast<APlayerController>(C).LockPlayer(false, false);
	}
	Level.Game.DriverEnteredVehicle(this, p);
	if (EventLab != nullptr && C != nullptr)
	{
		EventLab.ActorNotify(this, 25, C);
	}
	SetDriverHiddenAttachments();
	*/
}

void AVehicle::AttachFlag(AActor* FlagActor)
{
	/*
	if (!bDriverHoldsFlag && FlagActor != nullptr)
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
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	bool havePlaced = false;
	/*
	if (!bForceLeave && !Level.Game.CanLeaveVehicle(this, Driver))
	{
		return false;
	}
	if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.HasFlag != nullptr)
	{
		Driver.HoldFlag(PlayerReplicationInfo.HasFlag);
	}
	if (Controller == nullptr)
	{
		return false;
	}
	if (Driver != nullptr && !bRemoteControlled || bHideRemoteDriver)
	{
		Driver.bHardAttach = false;
		Driver.bCollideWorld = true;
		Driver.SetCollisionSize(Driver.Default.CollisionRadius, Driver.Default.CollisionHeight);
		Driver.SetCollision(true, true);
		havePlaced = PlaceExitingDriver();
		if (!havePlaced && !bForceLeave)
		{
			Driver.bHardAttach = true;
			Driver.bCollideWorld = false;
			Driver.SetCollision(false, false);
			return false;
		}
	}
	bDriving = false;
	C = Controller;
	if (C.RouteGoal == this)
	{
		C.RouteGoal = nullptr;
	}
	if (C.MoveTarget == this)
	{
		C.MoveTarget = nullptr;
	}
	C.bVehicleTransition = true;
	Controller.UnPossess();
	if (Driver != nullptr && Driver.Health > 0)
	{
		Driver.SetOwner(C);
		C.Possess(Driver);
		PC = Cast<APlayerController>(C);
		if (PC != nullptr)
		{
			PC.ClientSetViewTarget(Driver);
		}
		Driver.StopDriving(this);
	}
	C.bVehicleTransition = false;
	Cast<APlayerController>(C).LockPlayer(false, false);
	if (C == Controller)
	{
		Controller = nullptr;
	}
	Level.Game.DriverLeftVehicle(this, Driver);
	ServerRemoveSeatbelt();
	bReservedOccupation = false;
	ClearDriverHiddenAttachments();
	Driver = nullptr;
	DriverLeft();
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 26, C);
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
	FRotator SpringCenter = FRotator(0,0,0);
	float Pitch = 0;
	float Roll = 0;
	APlayerController* PC = nullptr;
	/*
	PC = Cast<APlayerController>(Controller);
	if (PC != nullptr)
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
		PC.SetRotation(FRotator(0 0 0));
	}
	TPCamDistance = Default.TPCamDistance;
	DesiredTPCamDistance = TPCamDistance;
	if (!PC.bBehindView)
	{
		ActivateOverlay(true);
	}
	if (PC.bEnableGUIForceFeedback && PC.bForceFeedbackSupported && Viewport(PC.Player) != nullptr)
	{
		if (CenterSpringRangePitch > 0 && CenterSpringRangeRoll > 0)
		{
			UpdateTiltForceFeedback();
		}
		PC.ClientPlayForceFeedback(CenterSpringForce);
	}
	if (Driver != nullptr)
	{
		Driver.AmbientSound = nullptr;
		if (Driver.Weapon != nullptr)
		{
			Driver.Weapon.AmbientSound = nullptr;
		}
	}
	*/
}

void AVehicle::ClientClearController()
{
	//ActivateOverlay(false);
}

void AVehicle::ClientKDriverLeave(APlayerController* PC)
{
	/*
	if (Driver != nullptr)
	{
		Driver.bOwnerNoSee = Driver.Default.bOwnerNoSee;
	}
	if (PC.bEnableGUIForceFeedback)
	{
		PC.StopForceFeedback(CenterSpringForce);
	}
	bWeaponisFiring = false;
	bWeaponisAltFiring = false;
	ActivateOverlay(false);
	*/
}

void AVehicle::ActivateOverlay(bool bActive)
{
	/*
	if (bActive)
	{
		if (HUDOverlayClass != nullptr && HudOverlay == nullptr)
		{
			HudOverlay = Spawn(HUDOverlayClass);
		}
	}
	else
	{
		if (HudOverlay != nullptr)
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
	FName DriverAttachmentBone = "";
	AActor* AttachActor = nullptr;
	FVector fPosOffset = FVector(0,0,0);
	FRotator fRotOffset = FRotator(0,0,0);
	/*
	DebugLog(DEBUG_Vehicle, "Attaching APawn* " + p + " to vehicle " + Self);
	if (p == nullptr)
	{
		return;
	}
	GetDriverAttachmentBone(AttachActor, DriverAttachmentBone);
	if (DriverAttachmentBone == "None")
	{
		return;
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
	int32 i = 0;
	int32 j = 0;
	FVector tryPlace = FVector(0, 0, 0);
	FVector Extent = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector ZOffset = FVector(0, 0, 0);
	FVector RandomSphereLoc = FVector(0,0,0);
	/*
	Extent = Driver.Default.CollisionRadius * FVector(1 1 0);
	Extent.Z = Driver.Default.CollisionHeight;
	ZOffset = Driver.Default.CollisionHeight * FVector(0 0 1);
	if (VSize(Velocity) > 100)
	{
		tryPlace = Normal(Velocity Cross FVector(0 0 1)) * CollisionRadius + Driver.Default.CollisionRadius * 1.25;
		if (FMath::FRand() < 0.5)
		{
			tryPlace *= -1;
		}
		if (Trace(HitLocation, HitNormal, Location + tryPlace + ZOffset, Location + ZOffset, false, Extent) == nullptr && Driver.SetLocation(Location + tryPlace + ZOffset) || Trace(HitLocation, HitNormal, Location - tryPlace + ZOffset, Location + ZOffset, false, Extent) == nullptr && Driver.SetLocation(Location - tryPlace + ZOffset))
		{
			return true;
		}
	}
	if (!bRelativeExitPos)
	{
		for (i = 0; i < ExitPositions.Num(); i++)
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
					RandomSphereLoc = VRand() * 200 * FMax(FMath::FRand(), 0.5);
					RandomSphereLoc.Z = Extent.Z * FMath::FRand();
					if (Trace(HitLocation, HitNormal, tryPlace + RandomSphereLoc, tryPlace, false, Extent) == nullptr)
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
	for (i = 0; i < ExitPositions.Num(); i++)
	{
		if (ExitPositions[0].Z != 0)
		{
			ZOffset = FVector(0 0 1) * ExitPositions[0].Z;
		}
		else
		{
			ZOffset = Driver.Default.CollisionHeight * FVector(0 0 2);
		}
		tryPlace = Location + ExitPositions[i] - ZOffset >> Rotation + ZOffset;
		if (Trace(HitLocation, HitNormal, tryPlace, Location + ZOffset, false, Extent) != nullptr)
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

APawn* AVehicle::CheckForHeadShot(FVector loc, FVector ray, float AdditionalScale)
{
	return nullptr;
}

bool AVehicle::TakeRadiusDamage(float DamageAmount, APawn* instigatedBy, FVector ExplosionLocation, float Momentum, UaDamageType* ExplosionDamageType, float DamageRadius)
{
	return false;
}

/*
void AVehicle::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMAterialInstance HitMaterial)
{
	int32 ActualDamage = 0;
	AController* Killer = nullptr;
	if (bSpawnProtected && instigatedBy != nullptr && instigatedBy != Self)
	{
		return;
	}
	NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	if (DamageType != nullptr)
	{
		if (instigatedBy == nullptr || instigatedBy.Controller == nullptr && DamageType.Default.bDelayedDamage && DelayedDamageInstigatorController != nullptr)
		{
			instigatedBy = DelayedDamageInstigatorController.Pawn;
		}
		Damage *= DamageType.Default.VehicleDamageScaling;
		Momentum *= DamageType.Default.VehicleMomentumScaling * MomentumMult;
		if (bShowDamageOverlay && DamageType.Default.DamageOverlayMaterial != nullptr && Damage > 0)
		{
			SetOverlayMaterial(DamageType.Default.DamageOverlayMaterial, DamageType.Default.DamageOverlayTime, false);
		}
	}
	if (bRemoteControlled && Driver != nullptr)
	{
		ActualDamage = Damage;
		if (Weapon != nullptr)
		{
			Weapon.AdjustPlayerDamage(ActualDamage, instigatedBy, HitLocation, Momentum, DamageType);
		}
		if (instigatedBy != nullptr && instigatedBy.HasUDamage())
		{
			ActualDamage *= 2;
		}
		ActualDamage = Level.Game.ReduceDamage(ActualDamage, this, instigatedBy, HitLocation, Momentum, DamageType);
		if (Health - ActualDamage <= 0)
		{
			KDriverLeave(false);
		}
	}
	if (Physics != 13)
	{
		TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType);
		return;
	}
	if (Weapon != nullptr)
	{
		Weapon.AdjustPlayerDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType);
	}
	if (instigatedBy != nullptr && instigatedBy.HasUDamage())
	{
		Damage *= 2;
	}
	ActualDamage = Level.Game.ReduceDamage(Damage, this, instigatedBy, HitLocation, Momentum, DamageType);
	Health -= ActualDamage;
	PlayHit(ActualDamage, instigatedBy, HitLocation, DamageType, Momentum);
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
		if (Killer == nullptr && DamageType != nullptr && DamageType.Default.bDelayedDamage)
		{
			Killer = DelayedDamageInstigatorController;
		}
		Died(Killer, DamageType, HitLocation);
	}
	else
	{
		if (Controller != nullptr)
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
	if (Cast<APlayerController>(Healer) != nullptr)
	{
		PlayerStartTime = GetWorld()->GetTimeSeconds() + 3;
	}
	if (Health <= 0 || Health >= HealthMax || Amount <= 0 || Healer == nullptr || !TeamLink(Healer.GetTeamNum()))
	{
		return false;
	}
	Health = FMath::Min(Health + Amount * LinkHealMult, HealthMax);
	NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	*/
	return true;
}

void AVehicle::DriverRadiusDamage(float DamageAmount, float DamageRadius, AController* EventInstigator, UaDamageType* DamageType, float Momentum, FVector HitLocation)
{
	float damageScale = 0;
	float dist = 0;
	FVector Dir = FVector(0,0,0);
	/*
	if (EventInstigator == nullptr || Driver == nullptr || Driver.bCollideActors || bRemoteControlled)
	{
		return;
	}
	Dir = Driver.Location - HitLocation;
	dist = FMax(1, VSize(Dir));
	Dir = Dir / dist;
	damageScale = 1 - FMax(0, dist - Driver.CollisionRadius / DamageRadius);
	if (damageScale <= 0)
	{
		return;
	}
	Driver.SetDelayedDamageInstigatorController(EventInstigator);
	Driver.TakeDamage(damageScale * DamageAmount, EventInstigator.Pawn, Driver.Location - 0.5 * Driver.CollisionHeight + Driver.CollisionRadius * Dir, damageScale * Momentum * Dir, DamageType);
	*/
}

void AVehicle::DriverDied()
{
	/*
	AController* C = nullptr;
	Level.Game.DiscardInventory(Driver);
	if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.HasFlag != nullptr)
	{
		PlayerReplicationInfo.HasFlag.Drop(0.5 * Velocity);
	}
	if (Driver == nullptr)
	{
		return;
	}
	C = Controller;
	Driver.StopDriving(this);
	Driver.Controller = C;
	Driver.DrivenVehicle = this;
	if (Controller == nullptr)
	{
		return;
	}
	if (Cast<APlayerController>(Controller) != nullptr)
	{
		Controller.SetLocation(Location);
		Cast<APlayerController>(Controller).SetViewTarget(Driver);
		Cast<APlayerController>(Controller).ClientSetViewTarget(Driver);
	}
	Controller.UnPossess();
	if (Controller == C)
	{
		Controller = nullptr;
	}
	C.Pawn = Driver;
	Driver.SetOwner(C);
	bCollideWorld = false;
	Driver.SetLocation(Driver.Location + FVector(0 0 1) * 20);
	bCollideWorld = true;
	Level.Game.DriverLeftVehicle(this, Driver);
	Driver = nullptr;
	bDriving = false;
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	*/
}

void AVehicle::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
	/*
	APlayerController* PC = nullptr;
	AController* C = nullptr;
	if (bDeleteMe || Level.bLevelChange)
	{
		return;
	}
	if (Physics != 13)
	{
		Died(Killer, DamageType, HitLocation);
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
		Level.Game.Killed(Killer, C, this, DamageType);
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
		if (!C.bIsPlayer && !C.bDeleteMe)
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
	APawn* OldPawn = nullptr;
	FVector EjectVel = FVector(0,0,0);
	OldPawn = Driver;
	KDriverLeave(true);
	if (OldPawn == nullptr)
	{
		return;
	}
	/*
	EjectVel = VRand();
	EjectVel.Z = 0;
	EjectVel = Normal(EjectVel) * 0.2 + FVector(0 0 1) * EjectMomentum;
	OldPawn->Velocity = EjectVel;
	OldPawn->SpawnTime = GetWorld()->GetTimeSeconds();
	OldPawn->PlayTeleportEffect(false, false);
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
	//VehicleFire(false);
	//bWeaponisFiring = true;
}

void AVehicle::AltFire( float F)
{
	//VehicleFire(true);
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
		ClientVehicleCeaseFire(false);
		bWeaponisFiring = false;
		bResult = true;
	}
	if (bWeaponisAltFiring)
	{
		ClientVehicleCeaseFire(true);
		bWeaponisAltFiring = false;
		bResult = true;
	}
	*/
	return bResult;
}

void AVehicle::UpdateEyeHeight(float DeltaTime)
{
	/*
	AController* C = nullptr;
	if ((Controller != nullptr) && Controller->IsA(APlayerController::StaticClass()))
	{
		Controller.AdjustView(DeltaTime);
	}
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if (C->IsA(APlayerController::StaticClass()) && (Cast<APlayerController>(C).ViewTarget == this))
		{
			return;
		}
	}
	bUpdateEyeheight=false;
	EyeHeight=BaseEyeHeight;
	*/
}

void AVehicle::FaceRotation(FRotator NewRotation, float DeltaTime)
{
}

void AVehicle::SetAnimAction(FName NewAction)
{
	/*
	if (bDrawDriverInTP && Driver != nullptr)
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
	FVector Momentum = FVector(0,0,0);
	float Speed = 0;
	/*
	if (Cast<APawn>(Other) == nullptr || Vehicle(Other) != nullptr || Other == Instigator || Other.Role != 4)
	{
		return;
	}
	Speed = VSize(Velocity);
	if (Speed > MinRunOverSpeed)
	{
		Momentum = Velocity * 0.25 * Other.Mass;
		if (Controller != nullptr && Controller.SameTeamAs(Cast<APawn>(Other).Controller))
		{
			Momentum += Speed * 0.25 * Other.Mass * Normal(Velocity Cross FVector(0 0 1));
		}
		if (RanOverSound != nullptr)
		{
			PlaySound(RanOverSound, , TransientSoundVolume * 2.5);
		}
		Other.TakeDamage(Speed * 0.075, this, Other->GetActorLocation(), Momentum, RanOverDamageType, , Controller);
	}
	*/
}

bool AVehicle::EncroachingOn(AActor* Other)
{
	/*
	if (Other == nullptr || Other == Instigator || Other.Role != 4 || !Other.bCollideActors && !Other.bBlockActors || VSize(Velocity) < 10)
	{
		return false;
	}
	if (Cast<APawn>(Other) != nullptr && !Pawn(Other).IsHumanControlled() && Vehicle(Other) == nullptr)
	{
		Other.TakeDamage(200, Instigator, Other->GetActorLocation(), Velocity * Other.Mass, CrushedDamageType);
		return false;
	}
	*/

	return false;    //FAKE   /ELiZ
}

bool AVehicle::FindValidTaunt(FName &Sequence)
{
	if (!bDrawDriverInTP || Driver == nullptr)
	{
		return false;
	}
	//return Driver->FindValidTaunt(Sequence);
	return false;     //FAKE   /EliZ
}

bool AVehicle::CheckTauntValid(FName Sequence)
{
	if (!bDrawDriverInTP || Driver == nullptr)
	{
		return false;
	}
	//return Driver.CheckTauntValid(Sequence);
	return false;     //FAKE   /EliZ
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

AVehicle* AVehicle::OpenPositionFor(APawn* p)
{
	if (Controller == nullptr)
	{
		return this;
	}
	return nullptr;
}

bool AVehicle::IndependentVehicle()
{
	return true;
}

AActor* AVehicle::GetBestEntry(APawn* p)
{
	return this;
}

AVehicle* AVehicle::GetMoveTargetFor(APawn* p)
{
	return this;
}

void AVehicle::DrivingStatusChanged()
{
	/*
	APlayerController* PC = nullptr;
	PC = Level.GetLocalPlayerController();
	if (bDriving && PC != nullptr && PC.ViewTarget == nullptr || !PC.ViewTarget.IsJoinedTo(this))
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
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0,0,0);
	AActor* EntryActor = nullptr;
	/*
	TakeDamage(WaterDamage * DeltaTime, this, FVector(0,0,0), FVector(0,0,0), VehicleDrowningDamType);
	if (GetWorld()->GetTimeSeconds() - SplashTime > 0.3 && PhysicsVolume.PawnEntryActor != nullptr && !Level.bDropDetail && Level.DetailMode != 0 && EffectIsRelevant(Location, False) && VSize(Velocity) > 300)
	{
		SplashTime = GetWorld()->GetTimeSeconds();
		if (!PhysicsVolume.TraceThisActor(HitLocation, HitNormal, Location - CollisionHeight * FVector(0 0 1), Location + CollisionHeight * FVector(0 0 1)))
		{
			EntryActor = Spawn(PhysicsVolume.PawnEntryActor, this, , HitLocation, FRotator(16384 0 0));
		}
	}
	*/
}

void AVehicle::LockOnWarning()
{
	ULocalMessage* LockOnClass = nullptr;
	/*
	LockOnClass = class<LocalMessage>(DynamicLoadObject(LockOnClassString, Class'Class'));
	Cast<APlayerController>(Controller).ReceiveLocalizedMessage(LockOnClass, 12);
	LastLockWarningTime = GetWorld()->GetTimeSeconds();
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
	AActor* A = nullptr;
	AActor* TransEffect = nullptr;
	/*
	if (GetTeam() == nullptr || GetTeam().TeamIndex == 0)
	{
		TransEffect = class<Actor>(DynamicLoadObject(TransEffects[0], Class'Class'));
	}
	else
	{
		TransEffect = class<Actor>(DynamicLoadObject(TransEffects[1], Class'Class'));
	}
	if (TransEffect != nullptr)
	{
		A = Spawn(TransEffect, , , Location + CollisionHeight * FVector(0 0 0.75));
	}
	if (A != nullptr)
	{
		A.SetBase(this);
	}
	PlayTeleportEffect(bOut, bSound);
	*/
}

void AVehicle::PlayDying(UaDamageType* DamageType, FVector HitLoc, FVector HitDir, FBoneInfo Bone)
{
}

int32 AVehicle::GetTeamNum()
{
	/*
	if (Role == 4 && Team == 255 && Controller != nullptr)
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

void AVehicle::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float &YL, float &YPos)
{
	/*
	DisplayDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.DrawText("Steering " + Steering + " throttle " + Throttle + " rise " + Rise);
	if (Driver != nullptr)
	{
		YPos += YL;
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.SetDrawColor(0, 0, 255);
		Canvas.DrawText("--- DRIVER");
		Canvas.SetPos(4, YPos);
		Driver.DisplayDebug(Canvas, YL, YPos);
	}
	*/
}

void AVehicle::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	float XL = 0;
	/*
	Canvas.StrLen("TEST", XL, YL);
	YPos = YPos + YL;
	Canvas.Style = 1;
	Canvas.SetDrawColor(255, 0, 0);
	*/
}

AActor* AVehicle::ShootSpecial(AActor* A)
{
	AController* OldController = nullptr;
	/*
	if (!Controller.bCanDoSpecial || Weapon == nullptr)
	{
		return nullptr;
	}
	Controller = OldController;
	if (KDriverLeave(false) && OldController.Pawn != nullptr)
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
	APlayerController* PC = nullptr;
	if (Level.Pauser != nullptr)
	{
		return;
	}
	PC = Cast<APlayerController>(Controller);
	if (PC == nullptr)
	{
		return;
	}
	if (!PC.bBehindView)
	{
		PC.BehindView(true);
		DesiredTPCamDistance = TPCamDistRange.Min;
		TPCamDistance = DesiredTPCamDistance;
	}
	else
	{
		DesiredTPCamDistance = FMath::Min(DesiredTPCamDistance + 100, TPCamDistRange.Max);
	}
	Default.TPCamDistance = DesiredTPCamDistance;
	StaticSaveConfig();
	*/
}

void AVehicle::PrevWeapon()
{
	/*
	APlayerController* PC = nullptr;
	if (Level.Pauser != nullptr)
	{
		return;
	}
	PC = Cast<APlayerController>(Controller);
	if (PC == nullptr || !PC.bBehindView)
	{
		return;
	}
	if (DesiredTPCamDistance ~= TPCamDistRange.Min)
	{
		PC.BehindView(false);
	}
	else
	{
		DesiredTPCamDistance = FMath::Max(DesiredTPCamDistance - 100, TPCamDistRange.Min);
		Default.TPCamDistance = DesiredTPCamDistance;
		StaticSaveConfig();
	}
	*/
}

bool AVehicle::TeamLink(int32 TeamNum)
{
	return LinkHealMult > 0 && Team == TeamNum && Health > 0;
}

bool AVehicle::NeedsFlip()
{
	FVector worldUp = FVector(0, 0, 0);;
	FVector gravUp = FVector(0,0,0);
	float GravMag = 0;
	/*
	GravMag = VSize(PhysicsVolume.Gravity);
	if (GravMag < 0.1)
	{
		gravUp = FVector(0 0 1);
	}
	else
	{
		gravUp = -1 * PhysicsVolume.Gravity / GravMag;
	}
	worldUp = FVector(0 0 1) >> Rotation;
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

float AVehicle::ChargeBar()
{
	return 0;    //FAKE   /ELiZ
}

void AVehicle::ClientPlayForceFeedback(FString EffectName)
{
	/*
	APlayerController* PC = nullptr;
	PC = Cast<APlayerController>(Controller);
	if (PC != nullptr && PC.bEnableGUIForceFeedback)
	{
		PC.ClientPlayForceFeedback(EffectName);
	}
	*/
}

void AVehicle::StopForceFeedback(FString EffectName)
{
	/*
	APlayerController* PC = nullptr;
	PC = Cast<APlayerController>(Controller);
	if (PC != nullptr && PC.bEnableGUIForceFeedback)
	{
		PC.StopForceFeedback(EffectName);
	}
	*/
}

void AVehicle::ServerPlayHorn(int32 HornIndex)
{
	/*
	if (GetWorld()->GetTimeSeconds() - LastHornTime > 0.25 && HornIndex >= 0 && HornIndex < HornSounds.Num())
	{
		PlaySound(HornSounds[HornIndex], , 3.5 * TransientSoundVolume, , 800);
		LastHornTime = GetWorld()->GetTimeSeconds();
	}
	*/
}

int32 AVehicle::NumPassengers()
{
	/*
	if (Driver != nullptr)
	{
		return 1;
	}
	*/
	return 0;
}

APawn* AVehicle::GetInstigator()
{
	return this;
}

AaAIController* AVehicle::GetBotPassenger()
{
	return Cast<AaAIController>(Controller);
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
		return 1;
	}
	*/
	return 0;
}

void AVehicle::StaticPrecache(ALevelInfo* L)
{
}

int32 AVehicle::GetSpree()
{
	if (Driver != nullptr)
	{
		//return Driver->GetSpree();
	}
	return 0;
}

void AVehicle::IncrementSpree()
{
	/*
	if (Driver != nullptr)
	{
		Driver.IncrementSpree();
	}
	*/
}

void AVehicle::ToggleVehicleView()
{
	/*
	APlayerController* PC = nullptr;
	PC = Cast<APlayerController>(Controller);
	if (PC != nullptr)
	{
		PC.BehindView(!PC.bBehindView);
		POVChanged(PC, true);
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
		if (Driver != nullptr)
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
			ActivateOverlay(false);
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
		if (Driver != nullptr)
		{
			Driver.bOwnerNoSee = true;
		}
		if (bDriving && PC == Controller)
		{
			ActivateOverlay(true);
		}
	}
	*/
}

void AVehicle::PlayTakeHit(FVector HitLocation, int32 Damage, UaDamageType* DamageType)
{
	int32 SoundNum = 0;
	/*
	if (IndependentVehicle() && DamageType.Default.bBulletHit && BulletSounds.Num() > 0)
	{
		SoundNum = Rand(BulletSounds.Num());
		if (Controller != nullptr && Controller == Level.GetLocalPlayerController())
		{
			PlayOwnedSound(BulletSounds[SoundNum], 0, 2, false, 400);
		}
		else
		{
			PlayOwnedSound(BulletSounds[SoundNum], 0, 2, false, 100);
		}
	}
	*/
}

TArray<AVehicle*> AVehicle::GetTurrets()
{
	return {};    //FAKE   /ELiZ
}

void AVehicle::CheckSuperBerserk()
{
}

bool AVehicle::VerifyLock(AActor* Aggressor, AActor* &NewTarget)
{
	return true;
}

AActor* AVehicle::AlternateTarget()
{
	return nullptr;
}

void AVehicle::ShouldTargetMissile(AProjectile* p)
{
	AaAIController* C = nullptr;
	C = Cast<AaAIController>(Controller);
	/*
	if (C != nullptr && C.Skill >= 5 && C.Enemy == nullptr || !C.LineOfSightTo(C.Enemy))
	{
		ShootMissile(p);
	}
	*/
}

void AVehicle::ShootMissile(AProjectile* p)
{
	//Controller->Focus = p;
	//Controller->FireWeaponAt(p);
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
	if (bWearingSeatbelt != true)
	{
		PlaySound(SeatbeltSound, 0, 1);
	}
	bWearingSeatbelt = true;
	*/
}

void AVehicle::ServerRemoveSeatbelt()
{
	/*
	if (bWearingSeatbelt != false)
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
