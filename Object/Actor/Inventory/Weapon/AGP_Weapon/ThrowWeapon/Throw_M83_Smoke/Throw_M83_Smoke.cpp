// All the original content belonged to the US Army


#include "Throw_M83_Smoke.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M83_Smoke/AttachT_M83_Smoke.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M83_Smoke/PickupT_M83_Smoke.h"

AThrow_M83_Smoke::AThrow_M83_Smoke()
{
	BoomSound        = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M83SmokeBang.WeaponsUS_Grenades_M83SmokeBang"), NULL, LOAD_None, NULL);
	//cExplosionEmitter = class'None'
	//cExplosionDecal = class'None'
	//cSmokeEmitter = AM83SmokeEmitter::StaticClass();
	InvGrenadeIndex  = 1;
	_bCanBeMiles     = true;
	PickupClass      = APickupT_M83_Smoke::StaticClass();
	AttachmentClass  = { AAttachT_M83_Smoke::StaticClass() };
	IconMaterial     = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_smoke_01.hud_gren_smoke_01"), NULL, LOAD_None, NULL);
	ItemName         = "M83 White Smoke Grenade";
	Mesh             = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M83smoke_1P.M83smoke_1P"), NULL, LOAD_None, NULL);
}