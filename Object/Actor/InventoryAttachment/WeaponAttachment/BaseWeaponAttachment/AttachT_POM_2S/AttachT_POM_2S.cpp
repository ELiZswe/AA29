// All the original content belonged to the US Army


#include "AttachT_POM_2S.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_PDM_Munition/AttachT_PDM_Munition.h"

AAttachT_POM_2S::AAttachT_POM_2S()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttachT_PDM_Munition::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_uipom2s_3P_closed.wpn2_uipom2s_3P_closed"), NULL, LOAD_None, NULL);
	RelativeRotation      = FRotator(-98.23974609375f, -90, 0);
}