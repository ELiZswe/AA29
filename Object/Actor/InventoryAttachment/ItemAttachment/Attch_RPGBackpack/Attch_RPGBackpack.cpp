// All the original content belonged to the US Army


#include "Attch_RPGBackpack.h"

AAttch_RPGBackpack::AAttch_RPGBackpack()
{
	AttachBone          = "RuckSack";
	//DisableOtherAttachment(0) = Attch_MedicRuck
	EnemyStaticMesh     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/op-DesOp/m-opfor_rpg_pack.m-opfor_rpg_pack"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-us_rpg_pack.m-us_rpg_pack"), NULL, LOAD_None, NULL);
}