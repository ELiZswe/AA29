// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Green_Beret/Hat_Green_Beret.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Green_Beret/Attch_Green_Beret.h"

AHat_Green_Beret::AHat_Green_Beret()
{
	AttachmentClass = { AAttch_Green_Beret::StaticClass() };
}
