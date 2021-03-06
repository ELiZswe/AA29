// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M583_Flare/Throw_M583_Flare.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M583_Flare/PickupT_M583_Flare.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M583_Flare/AttachT_M583_Flare.h"

AThrow_M583_Flare::AThrow_M583_Flare()
{
	BoomSound			= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M83SmokeBang.WeaponsUS_Grenades_M83SmokeBang"), NULL, LOAD_None, NULL);
	//cExplosionEmitter = nullptr
	//cExplosionDecal	= nullptr
	InvGrenadeIndex		= 1;
	_bCanBeMiles		= true;
	PickupClass			= APickupT_M583_Flare::StaticClass();
	AttachmentClass		= { AAttachT_M583_Flare::StaticClass() };
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m203_flare_Mat.hud_ammo_m203_flare_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "M583 Flare Grenade";
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M83smoke_1P.M83smoke_1P'"), NULL, LOAD_None, NULL);
}
