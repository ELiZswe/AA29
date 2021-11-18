// All the original content belonged to the US Army


#include "Item_StaticLineHook.h"
#include "AA29/InventoryAttachment/ItemAttachment/Attch_StaticLineHook/Attch_StaticLineHook.h"

AItem_StaticLineHook::AItem_StaticLineHook()
{
	AttachmentClass = { AAttch_StaticLineHook::StaticClass() };
}