// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Item_ReserveChute/Item_ReserveChute.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_ReserveChute/Attch_ReserveChute.h"

AItem_ReserveChute::AItem_ReserveChute()
{
	AttachmentClass = { AAttch_ReserveChute::StaticClass() };
}
