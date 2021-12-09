// All the original content belonged to the US Army


#include "Item_RuckSackChute.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_RuckSackChute/Attch_RuckSackChute.h"

AItem_RuckSackChute::AItem_RuckSackChute()
{
	AttachmentClass = { AAttch_RuckSackChute::StaticClass() };
}