// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Item_StaticLineHook/Item_StaticLineHook.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_StaticLineHook/Attch_StaticLineHook.h"

AItem_StaticLineHook::AItem_StaticLineHook()
{
	AttachmentClass = { AAttch_StaticLineHook::StaticClass() };
}
