// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_NPC_EnemyWatchCap/Attch_NPC_EnemyWatchCap.h"
AAttch_NPC_EnemyWatchCap::AAttch_NPC_EnemyWatchCap()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_watchcap.m_atta_enemynpc_watchcap"), NULL, LOAD_None, NULL);
}
