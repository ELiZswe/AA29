// All the original content belonged to the US Army


#include "Proj_60mmMortar.h"
#include "AA29/DamageType/AGP_DamageType\FragDamage\Mortar_60mm_FragDamage.h"
#include "AA29/DamageType/AGP_DamageType\RocketImpact\Mortar_60mm_ImpactDamage.h"
#include "AA29/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_60mmMortar\Proj_60mmMortar.h"
#include "AA29/DamageType/ArtilleryDamage/MortarDamage/MortarDamage.h"

AProj_60mmMortar::AProj_60mmMortar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImpactDamage          = 250;
	ImpactDamageType      = UMortar_60mm_ImpactDamage::StaticClass();
	FragDamageType        = UMortar_60mm_FragDamage::StaticClass();
	//ExplosionEmitter = Class'AGP_Effects.em_bt_PG7Bexplosion'
//		\\DamageClasses =
//		AGP = 200
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/60mm_Mortar/s_arm_mortar_impact_explosion.s_arm_mortar_impact_explosion"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_60mmMortar::StaticClass();
	Speed                 = 5000;
	MaxSpeed              = 5500;
	DamageRadius          = 750;
	MyDamageType          = UMortarDamage::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/wpn2_shells_usmortar.wpn2_shells_usmortar"), NULL, LOAD_None, NULL);
	Rotation              = FRotator (0, 0, 90);
	DrawScale3D           = FVector(4, 4, 4);
}