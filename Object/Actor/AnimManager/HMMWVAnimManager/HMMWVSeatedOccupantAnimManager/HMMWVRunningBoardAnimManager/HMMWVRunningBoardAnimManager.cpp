// All the original content belonged to the US Army

#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVRunningBoardAnimManager/HMMWVRunningBoardAnimManager.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

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
		Vehicle.Controller.SetRotation(rot(0,0,0));
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	if (HumanController(Vehicle.Controller) != nullptr)
	{
		HumanController(Vehicle.Controller).LockPlayer(true,true);
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
	if ((VehiclePosition(Vehicle) != nullptr) && (VehiclePosition(Vehicle).VehicleBase != nullptr))
	{
		VehiclePosition(Vehicle).VehicleBase.AnimBlendParams(VehicleDoorAnimChannel,1,0,0,DoorBoneName);
		VehiclePosition(Vehicle).VehicleBase.PlayAnim(VehicleDoorEnter,1,0,VehicleDoorAnimChannel);
	}
	Sleep(Pawn.GetAnimDuration(TransitionFromRunningBoard));
	if (HumanController(Vehicle.Controller) != nullptr)
	{
		HumanController(Vehicle.Controller).LockPlayer(false,false);
	}
	FinishVehicleTransition();
	if (Role < 4)
	{
		DestVehicle.AttachDriver(Pawn);
		Pawn.PlayAnim(HMMWVAnimManager(DestVehicle.AnimManager).DrivingIdle,0);
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
	OldController=PlayerController(Vehicle.Controller);
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
	LastTime=Level.TimeSeconds;
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
	if ((VehiclePosition(Vehicle) != nullptr) && (VehiclePosition(Vehicle).VehicleBase != nullptr))
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
	/*
	local Vehicle OldDestVehicle;
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

/*
void AHMMWVRunningBoardAnimManager::ClientBeginEnterVehicle(APawn* User, AVehicle* BaseVehicle)
{
	local Actor ViewActor;
	local Object.Vector ViewLocation;
	local Object.Rotator ViewRotation;
	PlayerController(User.Controller).PlayerCalcView(ViewActor, ViewLocation, ViewRotation);
	HumanController(User.Controller).LastViewLocation = ViewLocation - BaseVehicle.Location;
	HumanController(User.Controller).LastViewRotation = ViewRotation;
	User.Controller.bIgnoreSetTargetRotation = true;
}
*/
/*
void AHMMWVRunningBoardAnimManager::ServerBeginEnterVehicle(APawn* User, AVehicle* EntryVehicle, AVehicle* EntryBoard)
{
	User.Controller.bIgnoreSetTargetRotation = true;
	if (!EntryVehicle.bReservedOccupation && !EntryBoard.bReservedOccupation)
	{
		EntryBoard.KDriverEnter(User);
		EntryVehicle.bReservedOccupation = true;
		EntryBoard.bReservedOccupation = true;
		DestVehicle = EntryVehicle;
		PlayVehicleEnterAnim();
		return;
	}
	else
	{
		User.Controller.bIgnoreSetTargetRotation = false;
		return;
	}
}
*/
void AHMMWVRunningBoardAnimManager::FinishPawnLeave()
{
	/*
	local bool bRemoteControlled;
	local Object.Vector OldPawnLocation;
	local Object.Vector DriverExitPos;
	local Pawn OldPawn;
	local Object.Vector DriverExitVelocity;
	local Actor ViewActor;
	local Object.Vector ViewLocation;
	local Object.Rotator ViewRotation;
	local AGP_WheeledCraft BaseVehicle;
	DriverExitPos = Pawn.GetBoneCoords('Pelvis').Origin;
	DriverExitVelocity = DriverExitPos - LastPawnLocation / Level.TimeSeconds - LastTime;
	OldPawnLocation = Pawn.Location;
	Vehicle.SpecialCalcFirstPersonView(OldController, ViewActor, ViewLocation, ViewRotation);
	OldController.bIgnoreSetTargetRotation = true;
	Pawn.bCollideWorld = true;
	Pawn.SetCollision(True, True);
	Pawn.PlayAnim(RunningBoardExitFinal, 0);
	if (!Pawn.SetLocation(DriverExitPos))
	{
		bDestGetOff = false;
		Pawn.SetCollision(False, False);
		Pawn.SetLocation(OldPawnLocation);
		Vehicle.AttachDriver(Pawn);
		OldController.bIgnoreSetTargetRotation = true;
		PlayIdleAnim();
		BackupController = OldController;
		Timer();
		return;
	}
	BaseVehicle = AGP_WheeledCraft(VehiclePosition(Vehicle).VehicleBase);
	if (BaseVehicle != nullptr && VSize(BaseVehicle.Velocity) > 10)
	{
		AGP_Pawn(Pawn).VehicleExitMPH = AGP_WheeledCraft(VehiclePosition(Vehicle).VehicleBase).CarMPH;
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
	if (Vehicle(OldController.Pawn) != nullptr && Vehicle(OldController.Pawn).Driver != nullptr)
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
	SetTimer(1E-06, False);
	Vehicle.bRemoteControlled = bRemoteControlled;
	OldPawn.SetBase(None);
	OldPawn.StopDriving(Vehicle);
	if (Level.NetMode == 0 || Role < 4)
	{
		OldPawn.SetRotation(ViewRotation);
		OldController.SetRotation(ViewRotation);
	}
	OldPawn.Velocity = DriverExitVelocity;
	*/
}

void AHMMWVRunningBoardAnimManager::Timer()
{
	/*
	if (BackupController != nullptr)
	{
		if (Role == 4)
		{
			BackupController.Pawn.SetCollision(True, True, True);
			BackupController.GotoState('PlayerWalking');
		}
		BackupController.bIgnoreSetTargetRotation = false;
	}
	Vehicle.Driver = nullptr;
	bLockLeavingState = false;
	*/
}

void AHMMWVRunningBoardAnimManager::SetExitRotation()
{
	/*
	local Actor ViewActor;
	local Object.Vector ViewLocation;
	local Object.Rotator ViewRotation;
	Vehicle.SpecialCalcFirstPersonView(PlayerController(Vehicle.Controller), ViewActor, ViewLocation, ViewRotation);
	ServerSetExitRotation(ViewRotation);
	*/
}

void AHMMWVRunningBoardAnimManager::ServerSetExitRotation(FRotator Rotation)
{
	ExitRotation = Rotation;
}
