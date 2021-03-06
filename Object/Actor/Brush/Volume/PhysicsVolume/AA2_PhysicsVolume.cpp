// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "AA29/Object/I3DL2Listener/I3DL2Listener.h"

AAA2_PhysicsVolume::AAA2_PhysicsVolume()
{
	Gravity = FVector(0, 0, -1500);
	GroundFriction = 8;
	TerminalVelocity = 1000000;
	FluidFriction = 0.3;
	//bDamagesVehicles = true;
	//KBuoyancy = 1;
	//fParaGravFactor = 1;
	//fParaWindFactor = 1;
	bAlwaysRelevant = true;
	//bOnlyDirtyReplication = true;
	NetUpdateFrequency = 0.1;
}
