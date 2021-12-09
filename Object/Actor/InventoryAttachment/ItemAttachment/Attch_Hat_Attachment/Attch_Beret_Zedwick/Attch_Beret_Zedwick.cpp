// All the original content belonged to the US Army


#include "Attch_Beret_Zedwick.h"

AAttch_Beret_Zedwick::AAttch_Beret_Zedwick()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_beret_rh_zedwick.m_atta_us-soldier_beret_rh_zedwick"), NULL, LOAD_None, NULL);
}