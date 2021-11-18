// All the original content belonged to the US Army


#include "Attch_Beret_Amerine.h"

AAttch_Beret_Amerine::AAttch_Beret_Amerine()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_beret_rh_amerine.m_atta_us-soldier_beret_rh_amerine"), NULL, LOAD_None, NULL);
}