// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerLF/HMMWV_RunningBoardPassengerLF.h"

AHMMWV_RunningBoardPassengerLF::AHMMWV_RunningBoardPassengerLF()
{
	DoorAnimChannel = 1;
	DoorAnimBone = "B_Door_LF";
	//AnimManagerClass = class'AGP_Vehicles.HMMWVRunningBoardAnimManager';
	//SeatBeltOnMesh = class'None';
	//SeatBeltOffMesh = class'None';
	//DriveAnim = "vehhmvpsngridle";
	//SeatbeltSound = class'None';
}

void AHMMWV_RunningBoardPassengerLF::PostBeginPlay()
{
	Super::PostBeginPlay();
	//HMMWVRunningBoardAnimManager(AnimManager).DoorBoneName = DoorAnimBone;
	//HMMWVRunningBoardAnimManager(AnimManager).VehicleDoorAnimChannel = DoorAnimChannel;
}