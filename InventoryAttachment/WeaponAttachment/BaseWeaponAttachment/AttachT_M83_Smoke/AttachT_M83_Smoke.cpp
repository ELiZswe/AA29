// All the original content belonged to the US Army


#include "AttachT_M83_Smoke.h"


AAttachT_M83_Smoke::AAttachT_M83_Smoke()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttachT_M83_Smoke::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m83_smoke_3p.m-m83_smoke_3p"), NULL, LOAD_None, NULL);
	RelativeLocation      = FVector( 6, 0,-22);
	RelativeRotation      = FRotator(-27.4658203125f, -90, 0);
}