// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/AGP_Ammunition.h"

AAGP_Ammunition::AAGP_Ammunition()
{
	Damage             = 30;
	MomentumTransfer   = 2000;
	//_cTracerClass = Class'AGP.BaseTracer'
	_iTracerCount      = -1;
	bInstantHit        = true;
	bVirtualInventory  = true;
}
