// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerLF/HMMWV_RunningBoardPassengerLF.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVRunningBoardAnimManager/HMMWVRunningBoardAnimManager.h"

AHMMWV_RunningBoardPassengerLF::AHMMWV_RunningBoardPassengerLF()
{
	DoorAnimChannel = 1;
	DoorAnimBone = "B_Door_LF";
	//AnimManagerClass = AHMMWVRunningBoardAnimManager::StaticClass();
	//SeatBeltOnMesh = nullptr;
	//SeatBeltOffMesh = nullptr;
	//DriveAnim = "vehhmvpsngridle";
	//SeatbeltSound = nullptr;
}

void AHMMWV_RunningBoardPassengerLF::PostBeginPlay()
{
	Super::PostBeginPlay();
	//HMMWVRunningBoardAnimManager(AnimManager).DoorBoneName = DoorAnimBone;
	//HMMWVRunningBoardAnimManager(AnimManager).VehicleDoorAnimChannel = DoorAnimChannel;
}
