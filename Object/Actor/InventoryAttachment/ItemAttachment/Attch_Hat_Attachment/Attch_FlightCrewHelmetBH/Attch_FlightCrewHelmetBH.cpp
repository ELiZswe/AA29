// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_FlightCrewHelmetBH/Attch_FlightCrewHelmetBH.h"

AAttch_FlightCrewHelmetBH::AAttch_FlightCrewHelmetBH()
{
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/M_BlkHawk_Helmet.M_BlkHawk_Helmet"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/M_BlkHawk_Helmet.M_BlkHawk_Helmet"), NULL, LOAD_None, NULL);
}
