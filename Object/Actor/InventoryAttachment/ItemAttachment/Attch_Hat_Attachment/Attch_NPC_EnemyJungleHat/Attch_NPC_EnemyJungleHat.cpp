// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_NPC_EnemyJungleHat/Attch_NPC_EnemyJungleHat.h"

AAttch_NPC_EnemyJungleHat::AAttch_NPC_EnemyJungleHat()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_junglehat.m_atta_enemynpc_junglehat"), NULL, LOAD_None, NULL);
}
