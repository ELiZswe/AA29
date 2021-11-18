// All the original content belonged to the US Army


#include "Proj_BMP_Auto_Cannon.h"
#include "AA29/DamageType/AGP_DamageType\ProjectileDamage\ProjectileDamageBMPAutoCannon.h"

AProj_BMP_Auto_Cannon::AProj_BMP_Auto_Cannon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImpactDamageType  = UProjectileDamageBMPAutoCannon::StaticClass();
	FragDamageType    = UProjectileDamageBMPAutoCannon::StaticClass();
	MyDamageType      = UProjectileDamageBMPAutoCannon::StaticClass();
}