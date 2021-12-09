// All the original content belonged to the US Army


#include "AttachT_RGD5_Frag.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M67_Frag/AttachT_M67_Frag.h"

AAttachT_RGD5_Frag::AAttachT_RGD5_Frag()
{
	EnemyAttachmentClass  = AAttachT_M67_Frag::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-rgd-5_3p.m-rgd-5_3p"), NULL, LOAD_None, NULL);
	RelativeLocation      = FVector(0, 2, 5);
	RelativeRotation      = FRotator(-98.23974609375f, -90, 0);
}