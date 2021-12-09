// All the original content belonged to the US Army


#include "Attch_NPC_EnemyBackpack.h"

AAttch_NPC_EnemyBackpack::AAttch_NPC_EnemyBackpack()
{
	AttachBone          = "RuckSack";
	//	DisableOtherAttachment(0) = Attch_MedicRuck
	EnemyStaticMesh     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_backpack.m_atta_enemynpc_backpack"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_backpack.m_atta_enemynpc_backpack"), NULL, LOAD_None, NULL);
}
