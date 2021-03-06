// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_FlightCrewHelmetBH/Attch_FlightCrewHelmetBH.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAttch_FlightCrewHelmetBH::AAttch_FlightCrewHelmetBH()
{
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/M_BlkHawk_Helmet.M_BlkHawk_Helmet'"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/M_BlkHawk_Helmet.M_BlkHawk_Helmet'"), NULL, LOAD_None, NULL);
}

FName AAttch_FlightCrewHelmetBH::GetAttachBoneFor(AInventory* Inv)
{
	return AttachBone;
}
