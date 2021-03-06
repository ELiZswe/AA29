// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Javelin/Ammo_Javelin.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_Javelin/Proj_Javelin.h"

AAmmo_Javelin::AAmmo_Javelin()
{
	Damage				= 90;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount			= 1;
	bInstantHit			= false;
	ProjectileClass		= AProj_Javelin::StaticClass();
	MyDamageType		= UProjectileDamageLargeArms::StaticClass();
	_bLarge				= false;
	fWeight				= 0.1;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_javelin_Mat.hud_ammo_javelin_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "1 Round for the Javelin";
}
