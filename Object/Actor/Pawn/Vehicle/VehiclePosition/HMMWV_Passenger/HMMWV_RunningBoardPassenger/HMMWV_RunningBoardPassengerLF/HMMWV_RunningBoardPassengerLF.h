// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassenger.h"
#include "HMMWV_RunningBoardPassengerLF.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHMMWV_RunningBoardPassengerLF : public AHMMWV_RunningBoardPassenger
{
	GENERATED_BODY()
public:
	AHMMWV_RunningBoardPassengerLF();

	UPROPERTY()						FName DoorAnimBone;						//var name DoorAnimBone;
	UPROPERTY()						int32 DoorAnimChannel;					//var int DoorAnimChannel;

	void PostBeginPlay();
};
