// All the original content belonged to the US Army


#include "Proj_Mk19G.h"
#include "AA29/DamageType/CROWS_Mk19Damage/CROWS_Mk19Damage.h"

AProj_Mk19G::AProj_Mk19G(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ArmingTimeRange.Min   = 0.16f;
	ArmingTimeRange.Max   = 0.16f;
	ImpactDamage          = 125;
	ImpactDamageType      = UCROWS_Mk19Damage::StaticClass();
	//ExplosionEmitter = Class'AGP_Effects.em_bt_mk19grenexplosion'
	ExplosionSoundRadius  = 4000;
//		\\DamageClasses =
//		bNoPassDamageToVehicle = 296
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/MK19/s_arm_mk19_impact_explosion.s_arm_mk19_impact_explosion"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_Mk19G::StaticClass();
	Speed                 = 6000;
	Damage                = 125;
	DamageRadius          = 890;
	MomentumTransfer      = 5000;
	MyDamageType          = UCROWS_Mk19Damage::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
	DrawScale             = 1;
	CollisionRadius       = 1;
	CollisionHeight       = 1;
}
