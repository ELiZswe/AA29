// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_FlightCrewHelmetBH/Attch_FlightCrewHelmetBHRedCross/Attch_FlightCrewHelmetBHRedCross.h"

AAttch_FlightCrewHelmetBHRedCross::AAttch_FlightCrewHelmetBHRedCross()
{
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_blkhawk_helmet_redcross.m_blkhawk_helmet_redcross"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_blkhawk_helmet_redcross.m_blkhawk_helmet_redcross"), NULL, LOAD_None, NULL);
}
