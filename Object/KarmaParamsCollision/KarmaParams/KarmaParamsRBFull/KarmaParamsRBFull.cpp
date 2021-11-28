// All the original content belonged to the US Army


#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"

UKarmaParamsRBFull::UKarmaParamsRBFull()
{
	KInertiaTensor.SetNum(7);
	KInertiaTensor[0] = 0.4;
	KInertiaTensor[3] = 0.4;
	KInertiaTensor[5] = 0.4;
}
