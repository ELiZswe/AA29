// All the original content belonged to the US Army

#include "AA29/Object/Actor/SupportEffect/F18AirStrikeEffect/F18AirStrikeEffect.h"
#include "AA29/Object/Actor/Projector/BaseContactProjector/de_bt_MissileImpact/de_bt_MaverickMissileImpact/de_bt_MaverickMissileImpact.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_MissileExplosion/em_bt_MaverickMissileExplosion/em_bt_MaverickMissileExplosion.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/MissileProjectile/Proj_MaverickMissile/Proj_MaverickMissile.h"

AF18AirStrikeEffect::AF18AirStrikeEffect()
{
	//StrikeProjectileClass = AProj_MaverickMissile::StaticClass();
}

/*
State Drop
{
	simulated Function Tick(float dt)
	{
		float Delta = 0;
		Delta=FMin(((GetWorld()->GetTimeSeconds() - StartTime) / DropTime),1);
	}
	simulated Function Timer()
	{
		AGP_Effects.BaseContactProjector* Impact = nullptr;
		AGP_Effects.BaseContactEmitter* Explosion = nullptr;
		Impact=Spawn(Ade_bt_MaverickMissileImpact::StaticClass(),,,(HitLocation + FVector(0,0,100)),FRotator(0,16384,0));
		Impact.RemoteRole=ROLE_None;
		Explosion=Spawn(Aem_bt_MaverickMissileExplosion::StaticClass(),,,(HitLocation + FVector(0,0,100)),FRotator(0,16384,0));
		Explosion.RemoteRole=ROLE_None;
		Super::Timer();
	}
}
*/

void AF18AirStrikeEffect::SpawnEffects()
{
	/*
	StrikeProjectile = Spawn(StrikeProjectileClass, , , Location, Rotation);
	Super::SpawnEffects();
	*/
}
