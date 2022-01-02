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
simulated State PawnDrivingVehicle
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
simulated State PawnVehicleAction
{
Begin:
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	bDelayStateChange=true;
	bBusyAnimating=true;
	Pawn.PlayAnim(ActionTransition);
	Sleep(Pawn.GetAnimDuration(ActionTransition));
	bBusyAnimating=false;
	if ((Vehicle != nullptr) && Vehicle.IsA("CROWS_HMMWV"))
	{
		CROWS_HMMWV(Vehicle).bCanSteerAnim=true;
	}
	Pawn.LoopAnim(ActionIdle);
	if (IsInState(NewState))
	{
		Sleep(0);
	}
	if ((Vehicle != nullptr) && Vehicle.IsA("CROWS_HMMWV"))
	{
		CROWS_HMMWV(Vehicle).bCanSteerAnim=false;
	}
	bBusyAnimating=true;
	Pawn.PlayAnim(ActionTransitionReverse);
	Sleep(Pawn.GetAnimDuration(ActionTransitionReverse));
	bBusyAnimating=false;
	bDelayStateChange=false;
	if (bLeaving)
	{
		bLeaving=false;
		ReleasePawn();
	}
	GotoState(NewState);
}
*/

/*
simulated State PawnDead
{
	simulated Function Tick(float DeltaTime)
	{
		if (Pawn != nullptr)
		{
			Pawn.iAlpha=int(((float(254) * (1 - ((Level.TimeSeconds - DeathFadeStartTime) / DeathFadeOutTime))) + 1));
		}
	}
Begin:
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	if (((Level.NetMode == NM_Client) && (CROWS_Gunner(Vehicle) != nullptr)) && CROWS_Gunner(Vehicle).bInCROWS)
	{
		CROWS_Gunner(Vehicle).ClientFinishCrows();
		CROWS_Gunner(Vehicle).bInCROWS=false;
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	bBusyAnimating=true;
	TempPC=PlayerController(Vehicle.Controller);
	if (PlayerController(Vehicle.Controller) != nullptr)
	{
		PlayerController(Vehicle.Controller).LockPlayer(true,true);
	}
	Pawn.PlayAnim(DriverDie);
	Sleep(Pawn.GetAnimDuration(DriverDie));
	Pawn.LoopAnim(DriverDead);
	DeathFadeStartTime=Level.TimeSeconds;
	Enable("Tick");
	Sleep(DeathFadeOutTime);
	Disable("Tick");
	TempPawn=Pawn;
	Vehicle.KDriverLeave(true);
	TempPawn.iAlpha=1;
	TempPawn.bHidden=true;
	TempPawn.Destroy();
	Vehicle.bReservedOccupation=false;
	if (DestVehicle != nullptr)
	{
		DestVehicle.bReservedOccupation=false;
	}
	TempPC.GotoState("Spectating");
	TempPC=nullptr;
	TempPawn=nullptr;
	bBusyAnimating=false;
	NewState="None";
	GotoState("None");
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
		Pawn.AnimManager = nullptr;
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
	if (Level.NetMode != 3 && EntryVehicle.Driver == nullptr)
	{
		OldPawn = Pawn;
		OldController = Vehicle.Controller;
		OldVehicle = Vehicle;
		Vehicle.ClearDriverHiddenAttachments();
		OldController.UnPossess();
		Vehicle.Driver = nullptr;
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
		return true;
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
