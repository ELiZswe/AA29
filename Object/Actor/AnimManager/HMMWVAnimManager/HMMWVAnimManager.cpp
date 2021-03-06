// All the original content belonged to the US Army

#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVAnimManager.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner.h"

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
	if ((Cast<ACROWS_HMMWV>(Vehicle) != nullptr) && Cast<ACROWS_HMMWV>(Vehicle).bHitIgnition)
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
	if ((Vehicle != nullptr) && Vehicle->IsA(ACROWS_HMMWV::StaticClass()))
	{
		Cast<ACROWS_HMMWV>(Vehicle).bCanSteerAnim=true;
	}
	Pawn.LoopAnim(ActionIdle);
	if (IsInState(NewState))
	{
		Sleep(0);
	}
	if ((Vehicle != nullptr) && Vehicle->IsA(ACROWS_HMMWV::StaticClass()))
	{
		Cast<ACROWS_HMMWV>(Vehicle).bCanSteerAnim=false;
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
			Pawn.iAlpha=int(((float(254) * (1 - ((GetWorld()->GetTimeSeconds() - DeathFadeStartTime) / DeathFadeOutTime))) + 1));
		}
	}
Begin:
	if (Pawn == nullptr)
	{
		Sleep(0);
	}
	if (((GetWorld()->GetNetMode() == NM_Client) && (Cast<ACROWS_Gunner>(Vehicle) != nullptr)) && CROWS_Gunner(Vehicle).bInCROWS)
	{
		Cast<ACROWS_Gunner>(Vehicle).ClientFinishCrows();
		Cast<ACROWS_Gunner>(Vehicle).bInCROWS=false;
	}
	Pawn.bPhysicsAnimUpdate=false;
	Pawn.bWaitForAnim=false;
	Pawn.StopAnimating(true);
	bBusyAnimating=true;
	TempPC=Cast<APlayerController>(Vehicle.Controller);
	if (Cast<APlayerController>(Vehicle.Controller) != nullptr)
	{
		Cast<APlayerController>(Vehicle.Controller).LockPlayer(true,true);
	}
	Pawn.PlayAnim(DriverDie);
	Sleep(Pawn.GetAnimDuration(DriverDie));
	Pawn.LoopAnim(DriverDead);
	DeathFadeStartTime=GetWorld()->GetTimeSeconds();
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
	Super::BindToPawn(p);
	//Pawn->AnimManager = this;
	SetOwner(p);
}

void AHMMWVAnimManager::ReleasePawn()
{
	if (bDelayStateChange)
	{
		bLeaving = true;
		return;
	}
	/*
	if (Pawn->AnimManager == this)
	{
		Pawn->AnimManager = nullptr;
	}
	*/
	bBusyAnimating = false;
	Super::ReleasePawn();
	SetOwner(Vehicle);
}

bool AHMMWVAnimManager::DoTransition(AVehicle* EntryVehicle)
{
	APawn* OldPawn = nullptr;
	AVehicle* OldVehicle = nullptr;
	AController* OldController = nullptr;
	if ((GetNetMode() != ENetMode::NM_Client) && (EntryVehicle->Driver == nullptr))
	{
		OldPawn = Pawn;
		OldController = Vehicle->Controller;
		OldVehicle = Vehicle;
		Vehicle->ClearDriverHiddenAttachments();
		OldController->UnPossess();
		Vehicle->Driver = nullptr;
		Vehicle->bReservedOccupation = false;
		ReleasePawn();
		//Cast<APlayerController>(OldController)->bDontClearLevel = true;
		OldController->Possess(EntryVehicle);
		OldPawn->SetOwner(EntryVehicle);
		EntryVehicle->Driver = OldPawn;
		EntryVehicle->AnimManager->BindToPawn(OldPawn);
		EntryVehicle->SetDriverHiddenAttachments();
		if ((EntryVehicle->EventLab != nullptr) && (OldController != nullptr))
		{
			//EntryVehicle->EventLab->ActorNotify(EntryVehicle, 25, OldController);
		}
		return true;
	}
	return false;
}

bool AHMMWVAnimManager::CanPlayDeathAnim()
{
	return true;
}

void AHMMWVAnimManager::PlayIdleAnim()
{
	NetChangeState("PawnDrivingVehicle");
}

void AHMMWVAnimManager::PlayActionAnim()
{
	NetChangeState("PawnVehicleAction");
}

void AHMMWVAnimManager::PlayDeathAnim()
{
	NetChangeState("PawnDead");
}
