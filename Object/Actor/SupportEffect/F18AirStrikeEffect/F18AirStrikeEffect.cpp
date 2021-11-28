// All the original content belonged to the US Army


#include "AA29/Object/Actor/SupportEffect/F18AirStrikeEffect/F18AirStrikeEffect.h"

AF18AirStrikeEffect::AF18AirStrikeEffect()
{
	//StrikeProjectileClass = class'AGP_Inventory.Proj_MaverickMissile';
}


/*
State Drop
{
	simulated Function Tick(float dt)
	{
		float Delta = 0;
		Delta = FMin(((Level.TimeSeconds - StartTime) / DropTime),1);
	}
	simulated Function Timer()
	{
		local AGP_Effects.BaseContactProjector Impact;
		local AGP_Effects.BaseContactEmitter Explosion;
		Impact = Spawn(Class'AGP_Effects.de_bt_MaverickMissileImpact',,,(HitLocation + vect(0,0,100)),rot(0,16384,0));
		Impact.RemoteRole = ROLE_None;
		Explosion = Spawn(Class'AGP_Effects.em_bt_MaverickMissileExplosion',,,(HitLocation + vect(0,0,100)),rot(0,16384,0));
		Explosion.RemoteRole = ROLE_None;
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
