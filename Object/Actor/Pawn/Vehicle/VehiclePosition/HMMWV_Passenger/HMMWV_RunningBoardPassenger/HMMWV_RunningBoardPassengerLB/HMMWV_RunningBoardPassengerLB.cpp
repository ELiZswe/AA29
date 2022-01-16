// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerLB/HMMWV_RunningBoardPassengerLB.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVRunningBoardAnimManager/HMMWVRunningBoardAnimManager.h"

AHMMWV_RunningBoardPassengerLB::AHMMWV_RunningBoardPassengerLB()
{
	DoorAnimChannel = 2;
	DoorAnimBone = "B_Door_LB";
	//AnimManagerClass = AHMMWVRunningBoardAnimManager::StaticClass();
	//SeatBeltOnMesh = nullptr;
	//SeatBeltOffMesh = nullptr;
	DriveAnim = "vehhmvpsngridle";
	//SeatbeltSound = nullptr;
}

void AHMMWV_RunningBoardPassengerLB::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	HMMWVRunningBoardAnimManager(AnimManager).DoorBoneName = DoorAnimBone;
	HMMWVRunningBoardAnimManager(AnimManager).VehicleDoorAnimChannel = DoorAnimChannel;
	*/
}
