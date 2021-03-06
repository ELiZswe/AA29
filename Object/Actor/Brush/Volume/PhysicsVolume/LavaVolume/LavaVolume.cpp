// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LavaVolume/LavaVolume.h"
#include "AA29/Object/DamageType/Burned/Burned.h"

ALavaVolume::ALavaVolume()
{
	DamagePerSec = 40;
	//DamageType = ABurned::StaticClass();
	FluidFriction = 4;
	ViewFog = FVector(0.585938, 0.195312, 0.078125);
	bPainCausing = true;
	bDestructive = true;
	bNoInventory = true;
	bWaterVolume = true;
	//LocationName = "in lava";
	//bObsolete = true;
}
