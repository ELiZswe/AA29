// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Sarge/Hat_Sarge.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_SargeHat/Attch_SargeHat.h"

AHat_Sarge::AHat_Sarge()
{
	AttachmentClass = { AAttch_SargeHat::StaticClass() };
}
