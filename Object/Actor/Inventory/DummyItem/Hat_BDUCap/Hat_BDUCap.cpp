// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_BDUCap/Hat_BDUCap.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment\Attch_Hat_Attachment\Attch_BDUCap\Attch_BDUCap.h"

AHat_BDUCap::AHat_BDUCap()
{
	AttachmentClass = { AAttch_BDUCap::StaticClass() };
}
