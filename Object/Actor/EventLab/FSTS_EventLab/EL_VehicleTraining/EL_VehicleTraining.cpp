// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/Controller/AGP_VehicleBot/AGP_VehicleBot.h"
#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/AGP_VehicleFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"

AEL_VehicleTraining::AEL_VehicleTraining()
{
	InitialStateName = "'";
	DriverPosition = 1;
	PassengerPosition = 2;
	ActionHintString1 = "Press the <action> key";
	ActionHintString3 = "Press the <action> key";
}

//const VehicleTag = 'DriveMe';
//const DrillSgtTag = 'Frank';
//const DrillSgtTriggerTag = 'DrillSgtTrigger';

void AEL_VehicleTraining::PlayLSMessage(int32 Slot)
{
	/*
	if (Slot >= 0)
	{
		if (bDebug)
		{
			if (Slot < LipSyncDebugs.Num())
			{
				PlayTip(ReplaceCommandString(LipSyncDebugs[Slot].Line1), ReplaceCommandString(LipSyncDebugs[Slot].Line2), LipSyncDebugs[Slot].Duration);
			}
		}
		else
		{
			if (Slot < LipSyncs.Num())
			{
				PlayLSAnim(LipSyncs[Slot].AnimName, TargetIDs[LipSyncs[Slot].TargetID]);
			}
		}
	}
	*/
}

void AEL_VehicleTraining::PostInit()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		SearchActor.EventLab = this;
	}
	Super::PostInit();
	*/
}

void AEL_VehicleTraining::PostPostInit()
{
	Super::PostPostInit();
	//Controller->EventLab = this;
	//Player->EventLab = this;
	AssignSgt();
	AssignVehicle();
	//TargetIDs.Num() = 2;
	//TargetIDs[0] = Sgt->Pawn;
}

void AEL_VehicleTraining::AssignSgt()
{
	APawn* sgtPawn = nullptr;
	/*
	ForEach AllActors(Class'Pawn', sgtPawn, 'Frank')
	{
		GOTO JL0019;
	JL0019:
	}
	if (sgtPawn != nullptr)
	{
		Sgt = Spawn(Class'AAGP_Vehicle*Bot');
		Sgt.Possess(sgtPawn);
		Sgt.SetEventLab(this);
	}
	*/
}

void AEL_VehicleTraining::AssignVehicle()
{
	/*
	ForEach AllActors(Class'AAGP_Vehicle*', Vehicle, 'DriveMe')
	{
		GOTO JL0019;
	JL0019:
	}
	*/
}

bool AEL_VehicleTraining::AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms)
{
	/*
	int32 i = 0;
	Log("AGP_Vehicle_Spawned called", 'VehicleTraining');
	NewVehicle.EventLab = this;
	for (i = 0; i < NewVehicle.Positions.Num(); i++)
	{
		NewVehicle.Positions[i].EventLab = this;
		if (NewVehicle.Positions[i].Gun != nullptr)
		{
			NewVehicle.Positions[i].Gun.EventLab = this;
		}
	}
	for (i = 0; i < NewVehicle.VehicleWeapons.Num(); i++)
	{
		NewVehicle.VehicleWeapons[i].EventLab = this;
	}
	if (NewVehicle.Tag == 'DriveMe')
	{
		Vehicle = NewVehicle;
	}
	*/
	return true;
}

bool AEL_VehicleTraining::AGP_Vehicle_Entered(AAGP_Vehicle* EntryVehicle, AActor* aController, FString Parms)
{
	//Log("AGP_Vehicle_Entered called with Vehicle" @ FString::FromInt(EntryVehicle) @ "controller" @ FString::FromInt(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::AGP_Vehicle_Exited(AAGP_Vehicle* ExitVehicle, AActor* aController, FString Parms)
{
	//Log("AGP_Vehicle_Exited called with Vehicle" @ FString::FromInt(ExitVehicle) @ "controller" @ FString::FromInt(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::VehiclePosition_Entered(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	//Log("VehiclePosition_Entered called with Vehicle" @ FString::FromInt(Position) @ "controller" @ FString::FromInt(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::VehiclePosition_Exited(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	//Log("VehiclePosition_Exited called with Vehicle" @ FString::FromInt(Position) @ "controller" @ FString::FromInt(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::VehicleWeapon_Fire(AVehicleWeapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	//Log("VehicleWeapon_Fire called with weapon" @ FString::FromInt(NotifyActor) @ "and Instigator" @ FString::FromInt(aInstigator), 'VehicleTraining');
	return true;
}
