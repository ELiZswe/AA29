// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Jungle/Hat_Jungle.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_JungleHat/Attch_JungleHat.h"

AHat_Jungle::AHat_Jungle()
{
	AttachmentClass = { AAttch_JungleHat::StaticClass() };
}
