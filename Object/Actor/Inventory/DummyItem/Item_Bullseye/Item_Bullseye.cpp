// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Item_Bullseye/Item_Bullseye.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Bullseye/Attch_Bullseye.h"

AItem_Bullseye::AItem_Bullseye()
{
	AttachmentClass = { AAttch_Bullseye::StaticClass() };
}

