// All the original content belonged to the US Army


#include "AA29/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVCrowsAnimManager/HMMWVCrowsAnimManager.h"

AHMMWVCrowsAnimManager::AHMMWVCrowsAnimManager()
{
	TransitionToCenter = "CrowsToTrans";
	TransitionFromCenter = "TransToCrows";
	ActionTransition = "StartCROWS";
	ActionTransitionReverse = "EndCrows";
	ActionIdle = "IdleCROWS";
}