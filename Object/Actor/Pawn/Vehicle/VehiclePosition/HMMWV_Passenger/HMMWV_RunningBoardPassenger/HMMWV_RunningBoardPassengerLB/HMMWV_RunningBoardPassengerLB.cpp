// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerLB/HMMWV_RunningBoardPassengerLB.h"

AHMMWV_RunningBoardPassengerLB::AHMMWV_RunningBoardPassengerLB()
{
	DoorAnimChannel = 2;
	DoorAnimBone = "B_Door_LB";
	//AnimManagerClass = class'AGP_Vehicles.HMMWVRunningBoardAnimManager';
	//SeatBeltOnMesh = class'None';
	//SeatBeltOffMesh = class'None';
	DriveAnim = "vehhmvpsngridle";
	//SeatbeltSound = class'None';
}

void AHMMWV_RunningBoardPassengerLB::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	HMMWVRunningBoardAnimManager(AnimManager).DoorBoneName = DoorAnimBone;
	HMMWVRunningBoardAnimManager(AnimManager).VehicleDoorAnimChannel = DoorAnimChannel;
	*/
}