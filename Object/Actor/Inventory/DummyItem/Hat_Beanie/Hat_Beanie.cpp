// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Beanie/Hat_Beanie.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment\Attch_Hat_Attachment\Attch_Beanie\Attch_Beanie.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Beanie/Attch_Beanie.h"

AHat_Beanie::AHat_Beanie()
{
	AttachmentClass = { AAttch_Beanie::StaticClass() };
}
