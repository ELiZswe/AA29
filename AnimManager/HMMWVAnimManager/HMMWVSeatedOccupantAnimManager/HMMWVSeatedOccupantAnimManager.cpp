// All the original content belonged to the US Army


#include "AA29/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVSeatedOccupantAnimManager.h"

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
State PawnTransitionToCenter
{
}
State PawnTransitionToRunningBoard
{
}
State PawnDriveVehicleTransition
{
}
State PawnTransitionFromCenter
{
}
State PawnTransitionToSideSeat
{
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
	if (OldDestVehicle != None && DoTransition(DestVehicle))
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
	if (OldDestination != None && DoTransition(OldDestination))
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
	if (OldDestination != None && DoTransition(OldDestination))
	{
		HMMWVSeatedOccupantAnimManager(OldDestination.AnimManager).PlayIdleAnimFromCenter();
	}
	*/
}