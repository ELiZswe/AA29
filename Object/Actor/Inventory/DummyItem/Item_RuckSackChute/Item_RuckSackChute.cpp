// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Item_RuckSackChute/Item_RuckSackChute.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_RuckSackChute/Attch_RuckSackChute.h"

AItem_RuckSackChute::AItem_RuckSackChute()
{
	AttachmentClass = { AAttch_RuckSackChute::StaticClass() };
}
