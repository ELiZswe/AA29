// All the original content belonged to the US Army


#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVRearPassengerAnimManager/HMMWVRearPassengerAnimManager.h"

AHMMWVRearPassengerAnimManager::AHMMWVRearPassengerAnimManager()
{
	TransitionToCenter = "BckPassToTrans";
	TransitionFromCenter = "TransToBckPass";
	TransitionToSideSeat = "RtSeatToLtSeat";
}