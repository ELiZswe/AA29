// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Item_PencilSkilCraft/Item_PencilSkilCraft.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_PencilSkilCraft/Attch_PencilSkilCraft.h"

AItem_PencilSkilCraft::AItem_PencilSkilCraft()
{
	AttachmentClass = { AAttch_PencilSkilCraft::StaticClass() };
}
