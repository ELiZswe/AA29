// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerRF/HMMWV_RunningBoardPassengerRF.h"

AHMMWV_RunningBoardPassengerRF::AHMMWV_RunningBoardPassengerRF()
{
	DoorAnimChannel = 3;
	DoorAnimBone = "B_Door_RF";
	//AnimManagerClass = class'AGP_Vehicles.HMMWVRunningBoardRightAnimManager';
	//SeatBeltOnMesh = class'None';
	//SeatBeltOffMesh = class'None';
	DriveAnim = "vehhmvpsngridle";
	//SeatbeltSound = class'None';
}


void AHMMWV_RunningBoardPassengerRF::PostBeginPlay()
{
	Super::PostBeginPlay();
	//HMMWVRunningBoardAnimManager(AnimManager).DoorBoneName = DoorAnimBone;
	//HMMWVRunningBoardAnimManager(AnimManager).VehicleDoorAnimChannel = DoorAnimChannel;
}