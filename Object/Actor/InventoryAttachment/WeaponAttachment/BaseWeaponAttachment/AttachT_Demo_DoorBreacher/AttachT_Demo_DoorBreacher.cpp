// All the original content belonged to the US Army


#include "AttachT_Demo_DoorBreacher.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_Demo_DoorBreacher/AttachT_Pipe_Bomb/AttachT_Pipe_Bomb.h"

AAttachT_Demo_DoorBreacher::AAttachT_Demo_DoorBreacher()
{
	bAttachMILES      = false;
	//EnemyAttachmentClass = class'AGP_Inventory.AttachT_Pipe_Bomb'
	//EnemyAttachmentClass = AInventoryAttachment*(AAttachT_Pipe_Bomb);
	//EnemyAttachmentClass = LoadObject<class AInventoryAttachment>(NULL, TEXT("AAttachT_Pipe_Bomb"), NULL, LOAD_None, NULL);
	EnemyAttachmentClass = AAttachT_Pipe_Bomb::StaticClass();
	StaticMesh        = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_door_breacher.wpn2_door_breacher"), NULL, LOAD_None, NULL);
	RelativeRotation  = FRotator(0, 0, 90);
}