// All the original content belonged to the US Army


#include "AGP_ObjectiveInventory.h"
#include "AA29/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "AA29/InventoryAttachment/ItemAttachment/AGP_ObjectiveAttachment/AGP_ObjectiveAttachment.h"


AAGP_ObjectiveInventory::AAGP_ObjectiveInventory()
{
	PickupClass			= AAGP_ObjectivePickup::StaticClass();
	bUseAttachment		= true;
	AttachmentClass		= { AAGP_ObjectiveAttachment::StaticClass() };
}


void AAGP_ObjectiveInventory::setObjective()
{

}
void AAGP_ObjectiveInventory::DropFrom()
{

}
void AAGP_ObjectiveInventory::InitFor()
{

}
void AAGP_ObjectiveInventory::SetPlacedPickup()
{

}
void AAGP_ObjectiveInventory::AttachToPawn()
{

}
void AAGP_ObjectiveInventory::GetSwapContainer()
{

}
