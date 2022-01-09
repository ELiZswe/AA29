// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_MK19Gren/Proj_MK19Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType\ProjectileDamage\ProjectileDamageUS40mmGrenade.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_30Gren\Proj_30Gren.h"

AProj_MK19Gren::AProj_MK19Gren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ArmingTimeRange       = FObjectRange({ 0,0.1 });
	ImpactDamageType      = UProjectileDamageUS40mmGrenade::StaticClass();
	FragDamageType        = UProjectileDamageUS40mmGrenade::StaticClass();
	//ExplosionEmitter = Class'AGP_Effects.em_bt_mk19grenexplosion'
	EnemyProjectileClass  = AProj_30Gren::StaticClass();
	Speed                 = 8000;
	Damage                = 125;
	DamageRadius          = 720;
	MyDamageType          = UProjectileDamageUS40mmGrenade::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
}

void AProj_MK19Gren::Boom(FVector HitLocation, FVector HitNormal)
{
	AController* ctrlIterator = nullptr;
	/*
	Super::Boom(HitLocation, HitNormal);
	if (Level.NetMode == NM_Client)
	{
		return;
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator.IsA("AIController"))
		{
		}
		if ((AIController(ctrlIterator).Pawn != nullptr) && (VSize((AIController(ctrlIterator).Pawn.Location - HitLocation)) < float(1650)))
		{
			if (ctrlIterator.Pawn.LineOfSightTo(this))
			{
				AIController(ctrlIterator).NotifyBuzzedByBullet(Owner);
			}
		}
	}
	*/
}

