// All the original content belonged to the US Army


#include "AA29/Object/Actor/Keypoint/NPCItemOfInterest/NPCItemOfInterest.h"

ANPCItemOfInterest::ANPCItemOfInterest(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	fpMaxDistanceToNotice = 100;
	fpTimeToWaitHere = 2;
	fpLikelihoodItemWillBeNoticed = 75;
	//bStatic = false;
}