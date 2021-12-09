// All the original content belonged to the US Army


#include "AttachT_M84_Stun.h"


AAttachT_M84_Stun::AAttachT_M84_Stun()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttachT_M84_Stun::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-flashbang_3p.m-flashbang_3p"), NULL, LOAD_None, NULL);
	RelativeLocation      = FVector(6, 0, -22);
	RelativeRotation      = FRotator(-27.4658203125f, -90, 0);
}