// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Helmet/Hat_Helmet.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Helmet/Attch_Helmet.h"

AHat_Helmet::AHat_Helmet()
{
	AttachmentClass = { AAttch_Helmet::StaticClass() };
}
