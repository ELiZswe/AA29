// All the original content belonged to the US Army


#include "AttachT_M583_Flare.h"


AAttachT_M583_Flare::AAttachT_M583_Flare()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttachT_M583_Flare::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn_m14th3_incen_3p.wpn_m14th3_incen_3p"), NULL, LOAD_None, NULL);
	RelativeLocation      = FVector(6, 0, -22);
	RelativeRotation      = FRotator(-27.4658203125f, -90, 0);
}