// All the original content belonged to the US Army


#include "Attch_ReserveChute.h"

AAttch_ReserveChute::AAttch_ReserveChute()
{
	AttachBone          = "spine01";
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_reserve_chute.m_reserve_chute"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_reserve_chute.m_reserve_chute"), NULL, LOAD_None, NULL);
	bOrientOnSlope      = true;
		//bReplicateInstigator = true;
		//bCollideActors = true;
		//bCollideWorld = true;
}