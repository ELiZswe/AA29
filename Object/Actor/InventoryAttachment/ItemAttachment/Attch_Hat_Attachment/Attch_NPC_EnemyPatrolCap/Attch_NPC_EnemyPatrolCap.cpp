// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_NPC_EnemyPatrolCap/Attch_NPC_EnemyPatrolCap.h"

AAttch_NPC_EnemyPatrolCap::AAttch_NPC_EnemyPatrolCap()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_patrolcap.m_atta_enemynpc_patrolcap"), NULL, LOAD_None, NULL);
}
