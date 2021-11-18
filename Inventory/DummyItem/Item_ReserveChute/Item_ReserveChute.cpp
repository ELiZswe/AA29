// All the original content belonged to the US Army


#include "Item_ReserveChute.h"
#include "AA29/InventoryAttachment/ItemAttachment/Attch_ReserveChute/Attch_ReserveChute.h"

AItem_ReserveChute::AItem_ReserveChute()
{
	AttachmentClass = { AAttch_ReserveChute::StaticClass() };
}