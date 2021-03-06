// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/SlimeVolume/SlimeVolume.h"
#include "AA29/Object/DamageType/Corroded/Corroded.h"

ASlimeVolume::ASlimeVolume()
{
	DamagePerSec = 40;
	//DamageType = ACorroded::StaticClass();
	FluidFriction = 3;
	ViewFlash = FVector(-0.1172, -0.1172, -0.1172);
	ViewFog = FVector(0.1875, 0.28125, 0.09375);
	bPainCausing = true;
	bDestructive = true;
	bWaterVolume = true;
	//LocationName = "in slime";
	//bObsolete = true;
}
