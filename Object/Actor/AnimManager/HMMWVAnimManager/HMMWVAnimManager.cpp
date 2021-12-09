// All the original content belonged to the US Army


#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVAnimManager.h"

AHMMWVAnimManager::AHMMWVAnimManager()
{
	CameraBone = "CameraBone";
	DeathFadeOutTime = 1.25;
	//bHidden = true;
	//RemoteRole = 2;
	//bNetNotify = true;
}
/*
State PawnDrivingVehicle
{
}
State PawnVehicleAction
{
}
State PawnDead
{
	simulated Function Tick(float DeltaTime)
	{
		if (Pawn != None)
		{
			Pawn.iAlpha = 254 * 1 - Level.TimeSeconds - DeathFadeStartTime / DeathFadeOutTime + 1;
		}
	}
}
*/

void AHMMWVAnimManager::BindToPawn(APawn* p)
{
	/*
	BindToPawn(p);
	Pawn.AnimManager = Self;
	SetOwner(p);
	*/
}

void AHMMWVAnimManager::ReleasePawn()
{
	/*
	if (bDelayStateChange)
	{
		bLeaving = true;
		Return;
	}
	if (Pawn.AnimManager == Self)
	{
		Pawn.AnimManager = None;
	}
	bBusyAnimating = False;
	ReleasePawn();
	SetOwner(Vehicle);
	*/
}

/*
bool AHMMWVAnimManager::DoTransition(AVehicle* EntryVehicle)
{
	local Pawn OldPawn;
	local Vehicle OldVehicle;
	local Controller OldController;
	if (Level.NetMode != 3 && EntryVehicle.Driver == None)
	{
		OldPawn = Pawn;
		OldController = Vehicle.Controller;
		OldVehicle = Vehicle;
		Vehicle.ClearDriverHiddenAttachments();
		OldController.UnPossess();
		Vehicle.Driver = None;
		Vehicle.bReservedOccupation = False;
		ReleasePawn();
		PlayerController(OldController).bDontClearLevel = true;
		OldController.Possess(EntryVehicle);
		OldPawn.SetOwner(EntryVehicle);
		EntryVehicle.Driver = OldPawn;
		EntryVehicle.AnimManager.BindToPawn(OldPawn);
		EntryVehicle.SetDriverHiddenAttachments();
		if (EntryVehicle.EventLab != None && OldController != None)
		{
			EntryVehicle.EventLab.ActorNotify(EntryVehicle, 25, OldController);
		}
		Return True;
	}
	return false;
}
*/

bool AHMMWVAnimManager::CanPlayDeathAnim()
{
	return true;
}

void AHMMWVAnimManager::PlayIdleAnim()
{
	//NetChangeState('PawnDrivingVehicle');
}

void AHMMWVAnimManager::PlayActionAnim()
{
	//NetChangeState('PawnVehicleAction');
}

void AHMMWVAnimManager::PlayDeathAnim()
{
	//NetChangeState('PawnDead');
}