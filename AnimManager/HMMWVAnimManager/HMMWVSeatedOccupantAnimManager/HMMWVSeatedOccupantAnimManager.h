// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AnimManager/HMMWVAnimManager/HMMWVAnimManager.h"
#include "HMMWVSeatedOccupantAnimManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHMMWVSeatedOccupantAnimManager : public AHMMWVAnimManager
{
	GENERATED_BODY()
public:
	AHMMWVSeatedOccupantAnimManager();

	UPROPERTY()										FName TransitionToSideSeat;							//var name TransitionToSideSeat;
	UPROPERTY()										FName TransitionFromCenter;							//var name TransitionFromCenter;
	UPROPERTY()										FName TransitionToCenter;							//var name TransitionToCenter;

	//void PlayVehicleTransitionToCenterAnim(AVehicle* Destination)
	void PlayVehicleTransitionToSeatAnim();
	void PlayVehicleExitToRunningBoardAnim();
	void FinishExitToRunningBoardAnim();
	//void PlayVehicleTransitionToSideSeatAnim(AVehicle* Destination);
	void PlayIdleAnimFromCenter();
	void FinishTransitionToCenter();
	void FinishTransitionToSideSeat();

};
