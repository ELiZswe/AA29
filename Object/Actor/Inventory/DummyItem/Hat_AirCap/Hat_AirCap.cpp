// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_AirCap/Hat_AirCap.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_AirCap/Attch_AirCap.h"

AHat_AirCap::AHat_AirCap()
{
	AttachmentClass = { AAttch_AirCap::StaticClass() };
}
