// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_Passenger.h"
#include "HMMWV_RunningBoardPassenger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHMMWV_RunningBoardPassenger : public AHMMWV_Passenger
{
	GENERATED_BODY()
public:
	AHMMWV_RunningBoardPassenger();

	UPROPERTY()						FRotator				OldPCRotation;					//var Object.Rotator OldPCRotation;

	void SetDriverHiddenAttachments();
	void SetOldPCRotation(APawn* User);
	void ClientKDriverEnter(APlayerController* PC);

};
