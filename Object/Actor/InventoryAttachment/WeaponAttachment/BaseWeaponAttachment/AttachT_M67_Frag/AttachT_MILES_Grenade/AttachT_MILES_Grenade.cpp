// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M67_Frag/AttachT_MILES_Grenade/AttachT_MILES_Grenade.h"

AAttachT_MILES_Grenade::AAttachT_MILES_Grenade()
{
	EnemyAttachmentClass  = AAttachT_MILES_Grenade::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-miles_m67_thrown_3p.m-miles_m67_thrown_3p"), NULL, LOAD_None, NULL);
}
