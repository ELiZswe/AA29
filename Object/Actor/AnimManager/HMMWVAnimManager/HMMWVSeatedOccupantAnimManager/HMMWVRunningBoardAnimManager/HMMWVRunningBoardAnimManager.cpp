// All the original content belonged to the US Army

#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVRunningBoardAnimManager/HMMWVRunningBoardAnimManager.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVAnimManager.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"

AHMMWVRunningBoardAnimManager::AHMMWVRunningBoardAnimManager()
{
	DoorBoneName = "B_Door_LF";
	VehicleDoorEnter = "EnterHmmwv";
	VehicleDoorExit = "EnterHmmwv";
	RunningBoardEnter = "RunningBrdOnLt";
	RunningBoardExit = "RunningBrdOffLt";
	RunningBoardExitFinal = "RunFwLgJmpLand";
	TransitionFromRunningBoard = "EnterLt";
	TransitionToRunningBoard = "ExitLt";
	JumpOut = 10;
	DrivingIdle = "IdleRunningBrdLt";
}

/*
simulated State PawnEnteringVehicle
{
Begin:
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	if (Vehicle == nullptr)
	{
		Sleep(0);
	}
	Vehicle.AttachDriver(Pawn);
	if (Vehicle.Controller != nullptr)
	{
		Vehicle.Controller.SetRotation(FRotator(0,0,0));
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	if (Cast<AHumanController>(Vehicle.Controller) != nullptr)
	{
		Cast<AHumanController>(Vehicle.Controller).LockPlayer(true,true);
	}
	bBusyAnimating=true;
	Pawn.PlayAnim(RunningBoardEnter);
	Sleep(Pawn.GetAnimDuration(RunningBoardEnter));
	PlayIdleAnim();
	if (Role < 4)
	{
		GotoState("FinishEnterVehicle");
	}
}
*/

/*
simulated State FinishEnterVehicle
{
Begin:
	if (Role < 4)
	{
		EnableStateChange(false);
	}
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	Pawn.PlayAnim(TransitionFromRunningBoard);
	if ((Cast<AVehiclePosition>(Vehicle) != nullptr) && (Cast<AVehiclePosition>(Vehicle).VehicleBase != nullptr))
	{
		VehiclePosition(Vehicle).VehicleBase.AnimBlendParams(VehicleDoorAnimChannel,1,0,0,DoorBoneName);
		VehiclePosition(Vehicle).VehicleBase.PlayAnim(VehicleDoorEnter,1,0,VehicleDoorAnimChannel);
	}
	Sleep(Pawn.GetAnimDuration(TransitionFromRunningBoard));
	if (Cast<AHumanController>(Vehicle.Controller) != nullptr)
	{
		Cast<AHumanController>(Vehicle.Controller).LockPlayer(false,false);
	}
	FinishVehicleTransition();
	if (Role < 4)
	{
		DestVehicle.AttachDriver(Pawn);
		Pawn.PlayAnim(Cast<AHMMWVAnimManager>(DestVehicle.AnimManager).DrivingIdle,0);
	}
	if (Role < 4)
	{
		EnableStateChange(true);
	}
}
*/

/*
simulated State PawnLeavingVehicle
{
Begin:
	if (Role < 4)
	{
		EnableStateChange(false);
	}
	bLockLeavingState=true;
	BackupPawn=Pawn;
	OldController=Cast<APlayerController>(Vehicle.Controller);
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	Pawn.PlayAnim(RunningBoardExit);
	Sleep(Pawn.GetAnimDuration(RunningBoardExit));
	LastPawnLocation=Pawn.GetBoneCoords("Pelvis").Origin;
	LastTime=GetWorld()->GetTimeSeconds();
	Sleep(0);
	Pawn=BackupPawn;
	FinishPawnLeave();
	if (bLockLeavingState)
	{
		Sleep(0);
	}
	if (Role < 4)
	{
		EnableStateChange(true);
	}
}
*/

/*
simulated State BeginTransitionFromSeat
{
Begin:
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	if (Vehicle == nullptr)
	{
		Sleep(0);
	}
	Vehicle.AttachDriver(Pawn);
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	bBusyAnimating=true;
	Pawn.PlayAnim(TransitionToRunningBoard);
	if ((Cast<AVehiclePosition>(Vehicle) != nullptr) && (Cast<AVehiclePosition>(Vehicle).VehicleBase != nullptr))
	{
		VehiclePosition(Vehicle).VehicleBase.AnimBlendParams(VehicleDoorAnimChannel,1,0,0,DoorBoneName);
		VehiclePosition(Vehicle).VehicleBase.PlayAnim(VehicleDoorExit,1,0,VehicleDoorAnimChannel);
	}
	Sleep(Pawn.GetAnimDuration(TransitionToRunningBoard));
	PlayIdleAnim();
	if (Role < 4)
	{
		GotoState("PawnLeavingVehicle");
	}
}
*/

void AHMMWVRunningBoardAnimManager::ReleasePawn()
{
	//DestVehicle = nullptr;
	bDestGetOff = false;
	Super::ReleasePawn();
}

void AHMMWVRunningBoardAnimManager::PlayVehicleEnterAnim()
{
	//NetChangeState('PawnEnteringVehicle');
}

void AHMMWVRunningBoardAnimManager::PlayIdleAnim()
{
	/*
	if (!bDestGetOff && DestVehicle != nullptr && DestVehicle.Driver == nullptr)
	{
		NetChangeState('FinishEnterVehicle');
	}
	else
	{
		NetChangeState('PawnLeavingVehicle');
	}
	*/
}

void AHMMWVRunningBoardAnimManager::FinishVehicleTransition()
{
	AVehicle* OldDestVehicle = nullptr;
	/*
	if (DestVehicle.Driver == nullptr)
	{
		OldDestVehicle = DestVehicle;
		if (DestVehicle != nullptr && DoTransition(DestVehicle))
		{
			HMMWVAnimManager(OldDestVehicle.AnimManager).PlayIdleAnim();
		}
	}
	else
	{
		NetChangeState('FinishEnterVehicle');
	}
	return;
	*/
}

void AHMMWVRunningBoardAnimManager::DoTransitionToRunningBoardAnim()
{
	//NetChangeState('BeginTransitionFromSeat');
}

void AHMMWVRunningBoardAnimManager::ClientBeginEnterVehicle(APawn* User, AVehicle* BaseVehicle)
{
	AActor* ViewActor = nullptr;
	FVector ViewLocation = FVector(0,0,0);
	FRotator ViewRotation = FRotator(0,0,0);
	//PlayerController(User->Controller)->PlayerCalcView(ViewActor, ViewLocation, ViewRotation);
	Cast<AHumanController>(User->Controller)->LastViewLocation = ViewLocation - BaseVehicle->GetActorLocation();
	Cast<AHumanController>(User->Controller)->LastViewRotation = ViewRotation;
	//User->Controller->bIgnoreSetTargetRotation = true;
}

void AHMMWVRunningBoardAnimManager::ServerBeginEnterVehicle(APawn* User, AVehicle* EntryVehicle, AVehicle* EntryBoard)
{
	//User->Controller->bIgnoreSetTargetRotation = true;
	if (!EntryVehicle->bReservedOccupation && !EntryBoard->bReservedOccupation)
	{
		EntryBoard->KDriverEnter(User);
		EntryVehicle->bReservedOccupation = true;
		EntryBoard->bReservedOccupation = true;
		DestVehicle = EntryVehicle;
		PlayVehicleEnterAnim();
		return;
	}
	else
	{
		//User->Controller->bIgnoreSetTargetRotation = false;
		return;
	}
}

void AHMMWVRunningBoardAnimManager::FinishPawnLeave()
{
	bool bRemoteControlled = false;
	FVector OldPawnLocation = FVector(0,0,0);
	FVector DriverExitPos = FVector(0,0,0);
	APawn* OldPawn = nullptr;
	FVector DriverExitVelocity;
	AActor* ViewActor = nullptr;
	FVector ViewLocation = FVector(0,0,0);
	FRotator ViewRotation = FRotator(0,0,0);
	AAGP_WheeledCraft* BaseVehicle = nullptr;
	/*
	DriverExitPos = Pawn.GetBoneCoords('Pelvis').Origin;
	DriverExitVelocity = DriverExitPos - LastPawnLocation / GetWorld()->GetTimeSeconds() - LastTime;
	OldPawnLocation = Pawn.Location;
	Vehicle.SpecialCalcFirstPersonView(OldController, ViewActor, ViewLocation, ViewRotation);
	OldController.bIgnoreSetTargetRotation = true;
	Pawn.bCollideWorld = true;
	Pawn.SetCollision(true, true);
	Pawn.PlayAnim(RunningBoardExitFinal, 0);
	if (!Pawn.SetLocation(DriverExitPos))
	{
		bDestGetOff = false;
		Pawn.SetCollision(false, false);
		Pawn.SetLocation(OldPawnLocation);
		Vehicle.AttachDriver(Pawn);
		OldController.bIgnoreSetTargetRotation = true;
		PlayIdleAnim();
		BackupController = OldController;
		Timer();
		return;
	}
	BaseVehicle = AGP_WheeledCraft(Cast<AVehiclePosition>(Vehicle).VehicleBase);
	if (BaseVehicle != nullptr && VSize(BaseVehicle.Velocity) > 10)
	{
		Cast<AAGP_Pawn>(Pawn)->VehicleExitMPH = AGP_WheeledCraft(Cast<AVehiclePosition>(Vehicle).VehicleBase).CarMPH;
	}
	bRemoteControlled = Vehicle.bRemoteControlled;
	Vehicle.bRemoteControlled = true;
	OldPawn = Pawn;
	Vehicle.ClearDriverHiddenAttachments();
	if (OldController.Pawn != nullptr)
	{
		OldController.SetLocation(OldController.Pawn.Location);
		OldController.Pawn.RemoteRole = 2;
		OldController.Pawn.UnPossessed();
		OldController.CleanOutSavedMoves();
	}
	OldController.Pawn = nullptr;
	DestVehicle.bReservedOccupation = false;
	Vehicle.bReservedOccupation = false;
	ReleasePawn();
	OldController.bDontClearLevel = true;
	if (OldController.PlayerReplicationInfo.bOnlySpectator)
	{
		BackupController = OldController;
		Timer();
		return;
	}
	OldController.ResetFOV();
	OldPawn.PossessedBy(OldController);
	OldController.Pawn = OldPawn;
	OldController.Pawn.bStasis = false;
	OldController.ResetTimeMargin();
	OldController.CleanOutSavedMoves();
	if (Cast<AVehicle>(OldController.Pawn) != nullptr && Vehicle(OldController.Pawn).Driver != nullptr)
	{
		OldController.PlayerReplicationInfo.bIsFemale = Vehicle(OldController.Pawn).Driver.bIsFemale;
	}
	else
	{
		OldController.PlayerReplicationInfo.bIsFemale = OldController.Pawn.bIsFemale;
	}
	OldController.ServerSetHandedness(OldController.Handedness);
	OldController.ServerSetAutoTaunt(OldController.bAutoTaunt);
	OldController.SetViewTarget(OldPawn);
	OldPawn.SetPhysics(2);
	BackupController = OldController;
	SetTimer(1E-06, false);
	Vehicle.bRemoteControlled = bRemoteControlled;
	OldPawn.SetBase(nullptr);
	OldPawn.StopDriving(Vehicle);
	if (GetWorld()->GetNetMode() == 0 || Role < 4)
	{
		OldPawn.SetRotation(ViewRotation);
		OldController.SetRotation(ViewRotation);
	}
	OldPawn.Velocity = DriverExitVelocity;
	*/
}

void AHMMWVRunningBoardAnimManager::Timer()
{
	if (BackupController != nullptr)
	{
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			//BackupController->Pawn->SetCollision(true, true, true);
			//BackupController->GotoState('PlayerWalking');
		}
		//BackupController->bIgnoreSetTargetRotation = false;
	}
	Vehicle->Driver = nullptr;
	bLockLeavingState = false;
}

void AHMMWVRunningBoardAnimManager::SetExitRotation()
{
	AActor* ViewActor = nullptr;
	FVector ViewLocation = FVector(0,0,0);
	FRotator ViewRotation = FRotator(0,0,0);
	Vehicle->SpecialCalcFirstPersonView(Cast<APlayerController>(Vehicle->Controller), ViewActor, ViewLocation, ViewRotation);
	ServerSetExitRotation(ViewRotation);
}

void AHMMWVRunningBoardAnimManager::ServerSetExitRotation(FRotator Rotation)
{
	ExitRotation = Rotation;
}
