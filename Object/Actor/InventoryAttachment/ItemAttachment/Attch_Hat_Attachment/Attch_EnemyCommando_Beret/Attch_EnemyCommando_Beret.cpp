// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_EnemyCommando_Beret/Attch_EnemyCommando_Beret.h"

AAttch_EnemyCommando_Beret::AAttch_EnemyCommando_Beret()
{
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_beret.m_atta_enemynpc_beret'"), NULL, LOAD_None, NULL);
}

void AAttch_EnemyCommando_Beret::PostBeginPlay()
{
	//Super::PostBeginPlay();
}
