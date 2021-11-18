// All the original content belonged to the US Army


#include "AttachT_M67_Frag.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_RGD5_Frag/AttachT_RGD5_Frag.h"

AAttachT_M67_Frag::AAttachT_M67_Frag()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttachT_RGD5_Frag::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m67_3p.m-m67_3p"), NULL, LOAD_None, NULL);
	RelativeRotation      = FRotator(-98.23974609375f, -90, 0);
}