// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_DesertCap/Hat_DesertCap.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_DesertCap/Attch_DesertCap.h"

AHat_DesertCap::AHat_DesertCap()
{
	AttachmentClass = { AAttch_DesertCap::StaticClass() };
}
