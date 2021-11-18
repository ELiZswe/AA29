// All the original content belonged to the US Army


#include "Attch_EnemyCommando_Helmet.h"

AAttch_EnemyCommando_Helmet::AAttch_EnemyCommando_Helmet()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_helmet.m_atta_enemynpc_helmet"), NULL, LOAD_None, NULL);
}