// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_NPC_EnemyJungleHat_Black/Attch_NPC_EnemyJungleHat_Black.h"

AAttch_NPC_EnemyJungleHat_Black::AAttch_NPC_EnemyJungleHat_Black()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_junglehat_b.m_atta_enemynpc_junglehat_b"), NULL, LOAD_None, NULL);
}
