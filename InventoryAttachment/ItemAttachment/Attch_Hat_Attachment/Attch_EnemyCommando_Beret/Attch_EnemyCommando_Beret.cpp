// All the original content belonged to the US Army


#include "Attch_EnemyCommando_Beret.h"

AAttch_EnemyCommando_Beret::AAttch_EnemyCommando_Beret()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_beret.m_atta_enemynpc_beret"), NULL, LOAD_None, NULL);
}