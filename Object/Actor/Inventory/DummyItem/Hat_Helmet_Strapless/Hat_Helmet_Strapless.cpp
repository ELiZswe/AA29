// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Helmet_Strapless/Hat_Helmet_Strapless.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Helmet/Attch_Helmet_Strapless/Attch_Helmet_Strapless.h"

AHat_Helmet_Strapless::AHat_Helmet_Strapless()
{
	AttachmentClass = { AAttch_Helmet_Strapless::StaticClass() };
}
