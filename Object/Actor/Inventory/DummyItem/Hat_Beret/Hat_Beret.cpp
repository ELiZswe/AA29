// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Beret/Hat_Beret.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Beret/Attch_Beret.h"

AHat_Beret::AHat_Beret()
{
	AttachmentClass = { AAttch_Beret::StaticClass() };
}
