// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerRB/HMMWV_RunningBoardPassengerRB.h"

AHMMWV_RunningBoardPassengerRB::AHMMWV_RunningBoardPassengerRB()
{
	DoorAnimChannel = 3;
	DoorAnimBone = "B_Door_RB";
	//AnimManagerClass = class'AGP_Vehicles.HMMWVRunningBoardRightAnimManager';
	//SeatBeltOnMesh = class'None';
	//SeatBeltOffMesh = class'None';
	DriveAnim = "vehhmvpsngridle";
	//SeatbeltSound = class'None';
}




void AHMMWV_RunningBoardPassengerRB::PostBeginPlay()
{
	Super::PostBeginPlay();
	//HMMWVRunningBoardAnimManager(AnimManager).DoorBoneName = DoorAnimBone;
	//HMMWVRunningBoardAnimManager(AnimManager).VehicleDoorAnimChannel = DoorAnimChannel;
}