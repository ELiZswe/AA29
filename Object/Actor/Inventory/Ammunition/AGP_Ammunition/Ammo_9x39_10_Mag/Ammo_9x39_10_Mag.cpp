// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x39_10_Mag/Ammo_9x39_10_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm_Vintorez.h"

AAmmo_9x39_10_Mag::AAmmo_9x39_10_Mag()
{
	Damage			= 45;
	MaxAmmo			= 10;
	AmmoAmount		= 10;
	MyDamageType	= UProjectileDamage762mm_Vintorez::StaticClass();
	_bLarge			= false;
	fWeight			= 0.5;
	IconMaterial	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_vss_Mat.hud_ammo_vss_Mat'"), NULL, LOAD_None, NULL);
	ItemName		= FString("Vintorez 10-shot magazine");
}
