// All the original content belonged to the US Army


#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVRunningBoardAnimManager/HMMWVRunningBoardAnimManager.h"

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
State PawnEnteringVehicle
{
}
State FinishEnterVehicle
{
}
State PawnLeavingVehicle
{
}
State BeginTransitionFromSeat
{
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
	if (!bDestGetOff && DestVehicle != None && DestVehicle.Driver == None)
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
	if (DestVehicle.Driver == None)
	{
		OldDestVehicle = DestVehicle;
		if (DestVehicle != None && DoTransition(DestVehicle))
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
		Return;
	}
	else
	{
		User.Controller.bIgnoreSetTargetRotation = False;
		Return;
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
		bDestGetOff = False;
		Pawn.SetCollision(False, False);
		Pawn.SetLocation(OldPawnLocation);
		Vehicle.AttachDriver(Pawn);
		OldController.bIgnoreSetTargetRotation = true;
		PlayIdleAnim();
		BackupController = OldController;
		Timer();
		Return;
	}
	BaseVehicle = AGP_WheeledCraft(VehiclePosition(Vehicle).VehicleBase);
	if (BaseVehicle != None && VSize(BaseVehicle.Velocity) > 10)
	{
		AGP_Pawn(Pawn).VehicleExitMPH = AGP_WheeledCraft(VehiclePosition(Vehicle).VehicleBase).CarMPH;
	}
	bRemoteControlled = Vehicle.bRemoteControlled;
	Vehicle.bRemoteControlled = true;
	OldPawn = Pawn;
	Vehicle.ClearDriverHiddenAttachments();
	if (OldController.Pawn != None)
	{
		OldController.SetLocation(OldController.Pawn.Location);
		OldController.Pawn.RemoteRole = 2;
		OldController.Pawn.UnPossessed();
		OldController.CleanOutSavedMoves();
	}
	OldController.Pawn = None;
	DestVehicle.bReservedOccupation = False;
	Vehicle.bReservedOccupation = False;
	ReleasePawn();
	OldController.bDontClearLevel = true;
	if (OldController.PlayerReplicationInfo.bOnlySpectator)
	{
		BackupController = OldController;
		Timer();
		Return;
	}
	OldController.ResetFOV();
	OldPawn.PossessedBy(OldController);
	OldController.Pawn = OldPawn;
	OldController.Pawn.bStasis = False;
	OldController.ResetTimeMargin();
	OldController.CleanOutSavedMoves();
	if (Vehicle(OldController.Pawn) != None && Vehicle(OldController.Pawn).Driver != None)
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
	if (BackupController != None)
	{
		if (Role == 4)
		{
			BackupController.Pawn.SetCollision(True, True, True);
			BackupController.GotoState('PlayerWalking');
		}
		BackupController.bIgnoreSetTargetRotation = False;
	}
	Vehicle.Driver = None;
	bLockLeavingState = False;
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