// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_FlightCrewHelmet/Attch_FlightCrewHelmet.h"

AAttch_FlightCrewHelmet::AAttch_FlightCrewHelmet()
{
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_helmet.m_flightcrew_helmet"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_helmet.m_flightcrew_helmet"), NULL, LOAD_None, NULL);
}
