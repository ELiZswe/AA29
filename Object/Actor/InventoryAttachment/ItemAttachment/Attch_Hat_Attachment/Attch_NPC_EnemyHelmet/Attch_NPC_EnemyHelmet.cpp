// All the original content belonged to the US Army


#include "Attch_NPC_EnemyHelmet.h"

AAttch_NPC_EnemyHelmet::AAttch_NPC_EnemyHelmet()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_helmet.m_atta_enemynpc_helmet"), NULL, LOAD_None, NULL);
}