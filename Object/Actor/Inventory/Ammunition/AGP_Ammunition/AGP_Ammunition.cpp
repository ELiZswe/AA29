// All the original content belonged to the US Army


#include "AGP_Ammunition.h"


AAGP_Ammunition::AAGP_Ammunition()
{
	Damage             = 30;
	MomentumTransfer   = 2000;
	//_cTracerClass = Class'AGP.BaseTracer'
	_iTracerCount      = -1;
	bInstantHit        = true;
	bVirtualInventory  = true;
}
