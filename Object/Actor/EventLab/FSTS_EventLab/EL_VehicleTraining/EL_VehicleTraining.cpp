// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining.h"

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
			if (Slot < LipSyncDebugs.Length)
			{
				PlayTip(ReplaceCommandString(LipSyncDebugs[Slot].Line1), ReplaceCommandString(LipSyncDebugs[Slot].Line2), LipSyncDebugs[Slot].Duration);
			}
		}
		else
		{
			if (Slot < LipSyncs.Length)
			{
				PlayLSAnim(LipSyncs[Slot].AnimName, TargetIDs[LipSyncs[Slot].TargetID]);
			}
		}
	}
	*/
}

void AEL_VehicleTraining::PostInit()
{
	/*
	local AActor* SearchActor;
	ForEach AllActors(Class'Actor', SearchActor)
	{
		SearchActor.EventLab = Self;
	}
	Super::PostInit();
	*/
}

void AEL_VehicleTraining::PostPostInit()
{
	/*
	Super::PostPostInit();
	Controller.EventLab = Self;
	Player.EventLab = Self;
	AssignSgt();
	AssignVehicle();
	TargetIDs.Length = 2;
	TargetIDs[0] = Sgt.Pawn;
	*/
}

void AEL_VehicleTraining::AssignSgt()
{
	/*
	local Pawn sgtPawn;
	ForEach AllActors(Class'Pawn', sgtPawn, 'Frank')
	{
		GOTO JL0019;
	JL0019:
	}
	if (sgtPawn != None)
	{
		Sgt = Spawn(Class'AAGP_Vehicle*Bot');
		Sgt.Possess(sgtPawn);
		Sgt.SetEventLab(Self);
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
	NewVehicle.EventLab = Self;
	for (i = 0; i < NewVehicle.Positions.Length; i++)
	{
		NewVehicle.Positions[i].EventLab = Self;
		if (NewVehicle.Positions[i].Gun != None)
		{
			NewVehicle.Positions[i].Gun.EventLab = Self;
		}
	}
	for (i = 0; i < NewVehicle.VehicleWeapons.Length; i++)
	{
		NewVehicle.VehicleWeapons[i].EventLab = Self;
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
	//Log("AGP_Vehicle_Entered called with Vehicle" @ string(EntryVehicle) @ "controller" @ string(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::AGP_Vehicle_Exited(AAGP_Vehicle* ExitVehicle, AActor* aController, FString Parms)
{
	//Log("AGP_Vehicle_Exited called with Vehicle" @ string(ExitVehicle) @ "controller" @ string(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::VehiclePosition_Entered(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	//Log("VehiclePosition_Entered called with Vehicle" @ string(Position) @ "controller" @ string(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::VehiclePosition_Exited(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	//Log("VehiclePosition_Exited called with Vehicle" @ string(Position) @ "controller" @ string(aController), 'VehicleTraining');
	return true;
}

bool AEL_VehicleTraining::VehicleWeapon_Fire(AVehicleWeapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	//Log("VehicleWeapon_Fire called with weapon" @ string(NotifyActor) @ "and Instigator" @ string(aInstigator), 'VehicleTraining');
	return true;
}
