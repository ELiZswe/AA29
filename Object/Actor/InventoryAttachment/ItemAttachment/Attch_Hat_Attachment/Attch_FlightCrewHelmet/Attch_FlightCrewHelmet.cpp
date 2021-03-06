// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_FlightCrewHelmet/Attch_FlightCrewHelmet.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAttch_FlightCrewHelmet::AAttch_FlightCrewHelmet()
{
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_helmet.m_flightcrew_helmet'"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_helmet.m_flightcrew_helmet'"), NULL, LOAD_None, NULL);
}

FName AAttch_FlightCrewHelmet::GetAttachBoneFor(AInventory* Inv)
{
	return AttachBone;
}
