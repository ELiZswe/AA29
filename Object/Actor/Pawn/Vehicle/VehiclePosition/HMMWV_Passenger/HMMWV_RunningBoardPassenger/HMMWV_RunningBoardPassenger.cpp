// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassenger.h"

AHMMWV_RunningBoardPassenger::AHMMWV_RunningBoardPassenger()
{

}


void AHMMWV_RunningBoardPassenger::SetDriverHiddenAttachments()
{
}

void AHMMWV_RunningBoardPassenger::SetOldPCRotation(APawn* User)
{
	//OldPCRotation = User.GetViewRotation();
}

void AHMMWV_RunningBoardPassenger::ClientKDriverEnter(APlayerController* PC)
{
	//PC.bIgnoreSetTargetRotation = true;
	//ClientKDriverEnter(PC);
}
