// All the original content belonged to the US Army


#include "AttachT_PDM_Munition.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_POM_2S/AttachT_POM_2S.h"

AAttachT_PDM_Munition::AAttachT_PDM_Munition()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttachT_POM_2S::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pdm_3p_inhand.wpn2_pdm_3p_inhand"), NULL, LOAD_None, NULL);
	RelativeRotation      = FRotator(-98.23974609375f, -90, 0);
}