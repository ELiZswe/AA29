// All the original content belonged to the US Army


#include "AA29/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"

ALadderVolume::ALadderVolume()
{
	ClimbDir = FVector(0, 0, 1);
	bAutoPath = true;
	bStartOn = true;
	bDoTriggerLadder = true;
	//RemoteRole = 2;
}
