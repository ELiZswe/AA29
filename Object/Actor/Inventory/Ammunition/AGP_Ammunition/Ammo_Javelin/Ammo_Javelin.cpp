// All the original content belonged to the US Army


#include "Ammo_Javelin.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_Javelin/Proj_Javelin.h"
AAmmo_Javelin::AAmmo_Javelin()
{
	Damage            = 90;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_Javelin::StaticClass();
	MyDamageType      = UProjectileDamageLargeArms::StaticClass();
	_bLarge           = false;
	fWeight           = 0.1;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_javelin.hud_ammo_javelin"), NULL, LOAD_None, NULL);
	ItemName          = FString("1 Round for the Javelin");
}