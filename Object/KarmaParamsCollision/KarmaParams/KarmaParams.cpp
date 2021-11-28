// All the original content belonged to the US Army


#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParams.h"

UKarmaParams::UKarmaParams()
{
	//PointerProperty* KAng3 = NewObject<PointerProperty>(PointerProperty::StaticClass());
	//PointerProperty* KTriList = NewObject<PointerProperty>(PointerProperty::StaticClass());
	KMass = 1;
	KLinearDamping = 0.2;
	KAngularDamping = 0.2;
	KActorGravScale = 1;
	KVelDropBelowThreshold = 1000000;
	KMaxSpeed = 2500;
	KMaxAngularSpeed = 10;
	bHighDetailOnly = true;
	bClientOnly = true;
	bDestroyOnSimError = true;
	StayUprightStiffness = 50;
}
