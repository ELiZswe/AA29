// All the original content belonged to the US Army


#include "Ammo_9x39_10_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm_Vintorez.h"

AAmmo_9x39_10_Mag::AAmmo_9x39_10_Mag()
{
	Damage        = 45;
	MaxAmmo       = 10;
	AmmoAmount    = 10;
	MyDamageType  = UProjectileDamage762mm_Vintorez::StaticClass();
	_bLarge       = false;
	fWeight       = 0.5;
	IconMaterial  = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_vss.hud_ammo_vss"), NULL, LOAD_None, NULL);
	ItemName      = FString("Vintorez 10-shot magazine");
}