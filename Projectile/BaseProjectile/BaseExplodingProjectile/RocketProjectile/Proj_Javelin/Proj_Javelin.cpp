// All the original content belonged to the US Army


#include "Proj_Javelin.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/RocketExplosionDamage/RocketJavelinDamage/RocketJavelinDamage.h"
#include "AA29/DamageType/AGP_DamageType\RocketFragDamage\JavelinFragDamage.h"
#include "AA29/DamageType/AGP_DamageType\RocketImpact\JavelinImpactDamage.h"

AProj_Javelin::AProj_Javelin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cJavPuff = class'AGP_Armory.JavMissilePuff'
	MaxHeightTop          = 12000;
	MaxHeightDir          = 2250;
	MinHeightTop          = 4500;
	MinHeightDir          = 900;
	HeightTopSteep        = 1500;
	HeightDirSteep        = 300;
	LongArmingTimeRange.Min = 30.0f;
	LongArmingTimeRange.Max = 30.0f;
	RocketTrailOffset     = FVector(0, 0, -32);
	InitialSpeed          = 1125;
	AccelRate             = 0.95;
	PropellantDuration    = 30;
	ArmingTimeRange.Min   = 1.0f;
	ArmingTimeRange.Max   = 1.0f;
	ImpactDamageType      = UJavelinImpactDamage::StaticClass();
	FragDamageType        = UJavelinFragDamage::StaticClass();
	//ExplosionEmitter = class'AGP_Armory.em_bt_Javelinexplosion'
	ExplosionSoundRadius  = 10000;
	//cTrailEmitterClass = class'AGP_Armory.JavMissileSmoke'
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Missile_Explosion.S_Armo_Javelin_Missile_Explosion"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_Javelin::StaticClass();
	Speed                 = 1125;
	MaxSpeed              = 4000;
	Damage                = 100;
	MyDamageType          = URocketJavelinDamage::StaticClass();
	//ExplosionDecal = class'AGP_Armory.de_bt_javimpact'
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/missile.missile"), NULL, LOAD_None, NULL);
	//Physics             = 2;
	NetPriority           = 3;
	LifeSpan              = 30;
	DrawScale             = 1.13;
}