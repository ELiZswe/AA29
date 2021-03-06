// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Demo_DoorBreacher/Demo_Pipe_Bomb/Demo_Pipe_Bomb.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_DoorBreacher_Demo/PickupT_PipeBomb_Demo/PickupT_PipeBomb_Demo.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_Demo_DoorBreacher/AttachT_Pipe_Bomb/AttachT_Pipe_Bomb.h"
#include "AA29/Object/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_grenexplosionB/em_bt_grenexplosionB.h"

ADemo_Pipe_Bomb::ADemo_Pipe_Bomb()
{
	fPlacementTraceDistance  = 100;
	DirectionalBlastCone     = 0.65;
	DirectionalBlastDamage   = 140;
	FragDamageType = UFragDamage::StaticClass();
	//	\\DamageClasses =
	//AGP_Inventory = Sound'S_AA2_WeaponsUS.Grenades.WeaponsUS_Grenades_M67explosion1'
	//cExplosionEmitter = Aem_bt_grenexplosionB::StaticClass();
	PickupClass              = APickupT_PipeBomb_Demo::StaticClass();
	AttachmentClass          = { AAttachT_Pipe_Bomb::StaticClass() };
	ItemName                 = "Demolition Pipe Bomb";
}
