// All the original content belonged to the US Army


#include "AA29/Object/Actor/KActor/KConstraint/KCarWheelJoint/KCarWheelJoint.h"

AKCarWheelJoint::AKCarWheelJoint()
{
	KProportionalGap = 8200;
	KMaxSteerTorque = 1000;
	KMaxSteerSpeed = 2600;
	bKSteeringLocked = true;
	KMaxSpeed = 1310700;
	KSuspLowLimit = -1;
	KSuspHighLimit = 1;
	KSuspStiffness = 50;
	KSuspDamping = 5;
	//bNoDelete = false;
}
