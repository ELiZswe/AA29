// All the original content belonged to the US Army


#include "Attch_NPC_CivilianSunglasses.h"

AAttch_NPC_CivilianSunglasses::AAttch_NPC_CivilianSunglasses()
{
	AttachBone = "BN_HeadEnd";
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_AttachmentsNPC/Civilian/m_atta_civilian_sunglasses.m_atta_civilian_sunglasses"), NULL, LOAD_None, NULL);
}