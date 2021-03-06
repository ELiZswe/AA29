// All the original content belonged to the US Army

#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVSeatedOccupantAnimManager.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVRunningBoardAnimManager/HMMWVRunningBoardAnimManager.h"

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
		Pawn.PlayAnim(Cast<AHMMWVSeatedOccupantAnimManager>(DestVehicle.AnimManager).TransitionFromCenter,0);
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
	if ((Cast<ACROWS_HMMWV>(Vehicle) != nullptr) && Cast<ACROWS_HMMWV>(Vehicle).bHitIgnition)
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
	Cast<ACROWS_HMMWV>(Vehicle.GetVehicleBase()).bTransitioningCenter=false;
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
			Pawn.PlayAnim(Cast<AHMMWVSeatedOccupantAnimManager>(DestVehicle.AnimManager).DrivingIdle,0);
		}
	}
}
*/

void AHMMWVSeatedOccupantAnimManager::PlayVehicleTransitionToCenterAnim(AVehicle* Destination)
{
	DestVehicle = Destination;
	//NetChangeState('PawnTransitionToCenter');
}

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
	AVehicle* OldDestVehicle = nullptr;
	AVehicle* OldVehicle;
	if (DestVehicle->bReservedOccupation)
	{
		PlayIdleAnim();
	}
	Vehicle->ServerRemoveSeatbelt();
	DestVehicle->bReservedOccupation = true;
	OldDestVehicle = DestVehicle;
	OldVehicle = Vehicle;
	if (OldDestVehicle != nullptr && DoTransition(DestVehicle))
	{
		Cast<AHMMWVRunningBoardAnimManager>(OldDestVehicle->AnimManager)->bDestGetOff = true;
		Cast<AHMMWVRunningBoardAnimManager>(OldDestVehicle->AnimManager)->DestVehicle = OldVehicle;
		Cast<AHMMWVRunningBoardAnimManager>(OldDestVehicle->AnimManager)->DoTransitionToRunningBoardAnim();
	}
}

void AHMMWVSeatedOccupantAnimManager::PlayVehicleTransitionToSideSeatAnim(AVehicle* Destination)
{
	DestVehicle = Destination;
	//NetChangeState('PawnTransitionToSideSeat');
}

void AHMMWVSeatedOccupantAnimManager::PlayIdleAnimFromCenter()
{
	//NetChangeState('PawnDriveVehicleTransition');
}

void AHMMWVSeatedOccupantAnimManager::FinishTransitionToCenter()
{
	AVehicle* OldDestination = nullptr;
	OldDestination = DestVehicle;
	if (OldDestination != nullptr && DoTransition(OldDestination))
	{
		Cast<AHMMWVSeatedOccupantAnimManager>(OldDestination->AnimManager)->PlayVehicleTransitionToSeatAnim();
	}
}

void AHMMWVSeatedOccupantAnimManager::FinishTransitionToSideSeat()
{
	AVehicle* OldDestination = nullptr;
	OldDestination = DestVehicle;
	if (OldDestination != nullptr && DoTransition(OldDestination))
	{
		Cast<AHMMWVSeatedOccupantAnimManager>(OldDestination->AnimManager)->PlayIdleAnimFromCenter();
	}
}
