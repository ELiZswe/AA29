// All the original content belonged to the US Army


#include "Attch_ParaRuck.h"

AAttch_ParaRuck::AAttch_ParaRuck()
{
	AttachBone          = "RuckSack";
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_watchcap_b.m_atta_enemynpc_watchcap_b"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/EnemyNPC/m_atta_enemynpc_watchcap_b.m_atta_enemynpc_watchcap_b"), NULL, LOAD_None, NULL);
	bOrientOnSlope      = true;
	//bReplicateInstigator = true;
	//bCollideActors = true;
	//bCollideWorld = true;
}