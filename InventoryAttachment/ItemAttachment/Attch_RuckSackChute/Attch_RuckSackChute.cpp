// All the original content belonged to the US Army


#include "Attch_RuckSackChute.h"

AAttch_RuckSackChute::AAttch_RuckSackChute()
{
	AttachBone          = "Pelvis";
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_rucksack_parachute.m_rucksack_parachute"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_rucksack_parachute.m_rucksack_parachute"), NULL, LOAD_None, NULL);
	bOrientOnSlope      = true;
	//bReplicateInstigator = true;
	//bCollideActors = true;
	//bCollideWorld = true;
}