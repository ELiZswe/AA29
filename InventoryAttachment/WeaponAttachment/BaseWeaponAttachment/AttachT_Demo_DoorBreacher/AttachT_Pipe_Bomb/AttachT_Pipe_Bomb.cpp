// All the original content belonged to the US Army


#include "AttachT_Pipe_Bomb.h"


AAttachT_Pipe_Bomb::AAttachT_Pipe_Bomb()
{
	EnemyAttachmentClass   = AAttachT_Demo_DoorBreacher::StaticClass();
	StaticMesh             = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pipebomb_3p.wpn2_pipebomb_3p"), NULL, LOAD_None, NULL);
	RelativeRotation       = FRotator(180, 90, -90);
}