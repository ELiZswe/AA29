// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_NPC_EnemyBeanie/Attch_NPC_EnemyBeanie.h"

AAttch_NPC_EnemyBeanie::AAttch_NPC_EnemyBeanie()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_beanie.m_atta_enemynpc_beanie"), NULL, LOAD_None, NULL);
}
