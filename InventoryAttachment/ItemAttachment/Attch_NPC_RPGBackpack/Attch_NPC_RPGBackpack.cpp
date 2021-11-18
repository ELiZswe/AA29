// All the original content belonged to the US Army


#include "Attch_NPC_RPGBackpack.h"

AAttch_NPC_RPGBackpack::AAttch_NPC_RPGBackpack()
{
	AttachBone          = "RuckSack";
		//DisableOtherAttachment = { Attch_MedicRuck };
	EnemyStaticMesh     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/op-DesOp/m-opfor_rpg_pack.m-opfor_rpg_pack"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/op-DesOp/m-opfor_rpg_pack.m-opfor_rpg_pack"), NULL, LOAD_None, NULL);
}