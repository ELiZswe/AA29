// All the original content belonged to the US Army


#include "Attch_NPC_EnemyBallCap.h"

AAttch_NPC_EnemyBallCap::AAttch_NPC_EnemyBallCap()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_ballcap.m_atta_enemynpc_ballcap"), NULL, LOAD_None, NULL);
}