// All the original content belonged to the US Army


#include "RocketProjectile.h"
#include "AA29/Projectile/BaseProjectile\BaseExplodingProjectile\RocketProjectile\Proj_AT4_Explosive\Proj_AT4_Explosive.h"
#include "AA29/DamageType/AGP_DamageType\RocketFragDamage\RocketFragDamage.h"
#include "AA29/DamageType/AGP_DamageType\RocketImpact\RocketImpact.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/RocketExplosionDamage/RocketExplosionDamage.h"

ARocketProjectile::ARocketProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	InitialSpeed          = 1800;
	AccelRate             = 1.25;
	AccelDuration         = 0.01;
	PropellantDuration    = 1.5;
	RandomScaleFactor     = 300;
	SpeedJacked           = 1500;
	RandomMinTime         = 0.2;
	RandomMaxTime         = 1;
	JackedDuration        = 0.01;
	ArmingTimeRange.Min   = 0.25f;
	ArmingTimeRange.Max   = 0.25f;
	ImpactDamage          = 100;
	ImpactDamageType      = URocketImpact::StaticClass();
	FragDamageType        = URocketFragDamage::StaticClass();
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Explosions/PlainExplosions/Explosion3.Explosion3"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_AT4_Explosive::StaticClass();
	Speed                 = 5000;
	MaxSpeed              = 5000;
	Damage                = 150;
	DamageRadius          = 1312.335938;
	MyDamageType          = URocketExplosionDamage::StaticClass();
	LightType             = ELightType::LT_Steady;
	LightEffect           = ELightEffect::LE_NonIncidence;
	LightHue              = 22;
	LightSaturation       = 177;
	LightBrightness       = 150;
	LightRadius           = 22;
	bDynamicLight         = true;
	//bUpdateSimulatedPosition = true;
	//Physics = 6;
	AmbientGlow           = 255;
	//bRotateToDesired = true;
}