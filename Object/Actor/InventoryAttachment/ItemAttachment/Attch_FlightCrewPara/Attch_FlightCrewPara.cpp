// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_FlightCrewPara/Attch_FlightCrewPara.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAttch_FlightCrewPara::AAttch_FlightCrewPara()
{
	AttachBone = "RuckSack";
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_parachute.m_flightcrew_parachute'"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_parachute.m_flightcrew_parachute'"), NULL, LOAD_None, NULL);
}

FName AAttch_FlightCrewPara::GetAttachBoneFor(AInventory* Inv)
{
	return "RuckSack";
}
