// All the original content belonged to the US Army


#include "AttachT_M14_Incendiary.h"


AAttachT_M14_Incendiary::AAttachT_M14_Incendiary()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttachT_M14_Incendiary::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn_m14th3_incen_3p.wpn_m14th3_incen_3p"), NULL, LOAD_None, NULL);
	RelativeLocation      = FVector(6, 0, -22);
	RelativeRotation      = FRotator(-27.4658203125f, -90, 0);
}