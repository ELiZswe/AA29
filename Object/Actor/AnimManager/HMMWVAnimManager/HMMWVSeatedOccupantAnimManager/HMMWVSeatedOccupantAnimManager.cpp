// All the original content belonged to the US Army

#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVSeatedOccupantAnimManager.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AHMMWVSeatedOccupantAnimManager::AHMMWVSeatedOccupantAnimManager()
{
	TransitionToCenter = "DrvrToTrans";
	TransitionFromCenter = "TransToDrvr";
	TransitionToSideSeat = "LtSeatToRtSeat";
	DrivingIdle = "IdleSeated";
	DriverDie = "DieSeated";
	DriverDead = "DeadSeated";
}

/*
simulated State PawnTransitionToCenter
{
Begin:
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	bBusyAnimating=true;
	Pawn.PlayAnim(TransitionToCenter);
	Sleep(Pawn.GetAnimDuration(TransitionToCenter));
	FinishTransitionToCenter();
	if (Role < 4)
	{
		DestVehicle.AttachDriver(Pawn);
		Pawn.PlayAnim(HMMWVSeatedOccupantAnimManager(DestVehicle.AnimManager).TransitionFromCenter,0);
	}
}
*/

/*
simulated State PawnTransitionToRunningBoard
{
Begin:
	FinishExitToRunningBoardAnim();
}
*/

/*
simulated State PawnDriveVehicleTransition
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
	bBusyAnimating=false;
	if ((CROWS_HMMWV(Vehicle) != nullptr) && CROWS_HMMWV(Vehicle).bHitIgnition)
	{
		PlayActionAnim();
	}
	Pawn.LoopAnim(DrivingIdle);
	Sleep(Pawn.GetAnimDuration(DrivingIdle));
}
*/

/*
simulated State PawnTransitionFromCenter
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
	Pawn.PlayAnim(TransitionFromCenter);
	Sleep(Pawn.GetAnimDuration(TransitionFromCenter));
	CROWS_HMMWV(Vehicle.GetVehicleBase()).bTransitioningCenter=false;
	PlayIdleAnim();
	if (Role < 4)
	{
		GotoState("PawnDrivingVehicle");
	}
}
*/

/*
simulated State PawnTransitionToSideSeat
{
Begin:
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	bBusyAnimating=true;
	Pawn.PlayAnim(TransitionToSideSeat);
	Sleep(Pawn.GetAnimDuration(TransitionToSideSeat));
	FinishTransitionToSideSeat();
	if (Role < 4)
	{
		DestVehicle.AttachDriver(Pawn);
		if (DestVehicle.AnimManager != nullptr)
		{
			Pawn.PlayAnim(HMMWVSeatedOccupantAnimManager(DestVehicle.AnimManager).DrivingIdle,0);
		}
	}
}
*/

/*
void AHMMWVSeatedOccupantAnimManager::PlayVehicleTransitionToCenterAnim(AVehicle* Destination)
{
	DestVehicle = Destination;
	//NetChangeState('PawnTransitionToCenter');
}
*/

void AHMMWVSeatedOccupantAnimManager::PlayVehicleTransitionToSeatAnim()
{
	//NetChangeState('PawnTransitionFromCenter');
}
void AHMMWVSeatedOccupantAnimManager::PlayVehicleExitToRunningBoardAnim()
{
	//NetChangeState('PawnTransitionToRunningBoard');
}
void AHMMWVSeatedOccupantAnimManager::FinishExitToRunningBoardAnim()
{
	/*
	local Vehicle OldDestVehicle;
	local Vehicle OldVehicle;
	if (DestVehicle.bReservedOccupation)
	{
		PlayIdleAnim();
	}
	Vehicle.ServerRemoveSeatbelt();
	DestVehicle.bReservedOccupation = true;
	OldDestVehicle = DestVehicle;
	OldVehicle = Vehicle;
	if (OldDestVehicle != nullptr && DoTransition(DestVehicle))
	{
		HMMWVRunningBoardAnimManager(OldDestVehicle.AnimManager).bDestGetOff = true;
		HMMWVRunningBoardAnimManager(OldDestVehicle.AnimManager).DestVehicle = OldVehicle;
		HMMWVRunningBoardAnimManager(OldDestVehicle.AnimManager).DoTransitionToRunningBoardAnim();
	}
	*/
}

/*
void AHMMWVSeatedOccupantAnimManager::PlayVehicleTransitionToSideSeatAnim(AVehicle* Destination)
{
	DestVehicle = Destination;
	//NetChangeState('PawnTransitionToSideSeat');
}
*/

void AHMMWVSeatedOccupantAnimManager::PlayIdleAnimFromCenter()
{
	//NetChangeState('PawnDriveVehicleTransition');
}
void AHMMWVSeatedOccupantAnimManager::FinishTransitionToCenter()
{
	/*
	local Vehicle OldDestination;
	OldDestination = DestVehicle;
	if (OldDestination != nullptr && DoTransition(OldDestination))
	{
		HMMWVSeatedOccupantAnimManager(OldDestination.AnimManager).PlayVehicleTransitionToSeatAnim();
	}
	*/
}

void AHMMWVSeatedOccupantAnimManager::FinishTransitionToSideSeat()
{
	/*
	local Vehicle OldDestination;
	OldDestination = DestVehicle;
	if (OldDestination != nullptr && DoTransition(OldDestination))
	{
		HMMWVSeatedOccupantAnimManager(OldDestination.AnimManager).PlayIdleAnimFromCenter();
	}
	*/
}
