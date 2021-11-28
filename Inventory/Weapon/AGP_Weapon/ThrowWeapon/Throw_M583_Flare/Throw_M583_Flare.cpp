// All the original content belonged to the US Army


#include "Throw_M583_Flare.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M583_Flare/PickupT_M583_Flare.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M583_Flare/AttachT_M583_Flare.h"

AThrow_M583_Flare::AThrow_M583_Flare()
{
	BoomSound        = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M83SmokeBang.WeaponsUS_Grenades_M83SmokeBang"), NULL, LOAD_None, NULL);
		//cExplosionEmitter = class'None'
		//cExplosionDecal = class'None'
	InvGrenadeIndex  = 1;
	_bCanBeMiles     = true;
	PickupClass      = APickupT_M583_Flare::StaticClass();
	AttachmentClass  = { AAttachT_M583_Flare::StaticClass() };
	IconMaterial     = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m203_flare.hud_ammo_m203_flare"), NULL, LOAD_None, NULL);
	ItemName         = "M583 Flare Grenade";
	Mesh             = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M83smoke_1P.M83smoke_1P"), NULL, LOAD_None, NULL);
}
