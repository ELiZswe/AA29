// All the original content belonged to the US Army


#include "Attch_Beret_Rieman.h"

AAttch_Beret_Rieman::AAttch_Beret_Rieman()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_beret_rh_rieman.m_atta_us-soldier_beret_rh_rieman"), NULL, LOAD_None, NULL);
}