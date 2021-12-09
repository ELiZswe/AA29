// All the original content belonged to the US Army


#include "Attch_Helmet_Strapless.h"

AAttch_Helmet_Strapless::AAttch_Helmet_Strapless()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_helmet_ds.m_atta_us-soldier_helmet_ds"), NULL, LOAD_None, NULL);
}