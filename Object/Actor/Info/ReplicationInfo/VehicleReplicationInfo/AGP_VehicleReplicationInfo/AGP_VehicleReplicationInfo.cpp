// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/AGP_VehicleReplicationInfo/AGP_VehicleReplicationInfo.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/AA2_PlayerState.h"

AAGP_VehicleReplicationInfo::AAGP_VehicleReplicationInfo()
{
	Passengers.SetNum(8);
	StatusUpdateFrequency = 0.2;
	DriverIndex = 7;
	LocationUpdateFrequency = 1;
	RotationUpdateFrequency = 1;
}


static const int32 MAX_PASSENGERS = 8;

/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bVehicleDisabled, bIsPlayerDriveable, Passengers;
}
*/

void AAGP_VehicleReplicationInfo::PostNetBeginPlay()
{
	/*
	SetCustomTimer(StatusUpdateFrequency, true, "UpdateStatus");
	Super::PostNetBeginPlay();
	*/
}

void AAGP_VehicleReplicationInfo::UpdateStatus()
{
	if (MyVehicle != nullptr)
	{
		bVehicleDisabled = MyVehicle->VehicleDisabled();
		bIsPlayerDriveable = (!MyVehicle->bAIDriversOnly);
	}
}

void AAGP_VehicleReplicationInfo::Destroyed()
{
	int32 i = 0;
	Super::Destroyed();
	for (i = 0; i < 8; i++)
	{
		if (Passengers[i] != nullptr)
		{
			Passengers[i]->VehicleReplicationInfo = nullptr;
			Passengers[i] = nullptr;
		}
	}
}

void AAGP_VehicleReplicationInfo::PlayerEntered(APlayerController* PC, int32 PositionIndex)
{
	AHumanController* HC = nullptr;
	HC = Cast<AHumanController>(PC);
	if ((HC == nullptr) || (HC->PlayerReplicationInfo == nullptr))
	{
		return;
	}
	Passengers[PositionIndex] = HC->PlayerReplicationInfo;
	Passengers[PositionIndex]->VehicleReplicationInfo = this;
}

void AAGP_VehicleReplicationInfo::PlayerLeft(APlayerController* PC)
{
	int32 i = 0;
	AHumanController* HC = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	HC = Cast<AHumanController>(PC);
	PRI = HC->PlayerReplicationInfo;
	if ((HC == nullptr) || (HC->PlayerReplicationInfo == nullptr))
	{
		return;
	}
	for (i = 0; i < 8; i++)
	{
		if (Passengers[i] == PRI)
		{
			Passengers[i]->VehicleReplicationInfo = nullptr;
			Passengers[i] = nullptr;
		}
	}
}

bool AAGP_VehicleReplicationInfo::IsPlayerDriveable()
{
	return bIsPlayerDriveable;
}

bool AAGP_VehicleReplicationInfo::IsVehicleDisabled()
{
	return bVehicleDisabled;
}

int32 AAGP_VehicleReplicationInfo::GetPassengerCount()
{
	int32 i = 0;
	int32 PassengerCount = 0;
	PassengerCount = 0;
	for (i = 0; i < 8; i++)
	{
		if (Passengers[i] != nullptr)
		{
			PassengerCount++;
		}
	}
	return PassengerCount;
}

AAA2_PlayerState* AAGP_VehicleReplicationInfo::GetDriver()
{
	return Passengers[DriverIndex];
}

AAA2_PlayerState* AAGP_VehicleReplicationInfo::GetGunner()
{
	return Passengers[GunnerIndex];
}

TArray<AAA2_PlayerState*> AAGP_VehicleReplicationInfo::GetPassengers()
{
	int32 i = 0;
	TArray<AAA2_PlayerState*> ActivePassengers = {};
	for (i = 0; i < 8; i++)
	{
		if (Passengers[i] != nullptr)
		{
			ActivePassengers.Add(Passengers[i]);
		}
	}
	return ActivePassengers;
}
