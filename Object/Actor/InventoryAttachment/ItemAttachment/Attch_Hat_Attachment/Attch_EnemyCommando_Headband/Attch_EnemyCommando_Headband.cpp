// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_EnemyCommando_Headband/Attch_EnemyCommando_Headband.h"

AAttch_EnemyCommando_Headband::AAttch_EnemyCommando_Headband()
{
	StaticMesh        = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_scarf.m_atta_enemynpc_scarf"), NULL, LOAD_None, NULL);
	RelativeRotation  = FRotator(0, 0, -90);
}
