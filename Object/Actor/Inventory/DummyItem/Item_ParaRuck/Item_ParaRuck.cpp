// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Item_ParaRuck/Item_ParaRuck.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_ParaRuck/Attch_ParaRuck.h"

AItem_ParaRuck::AItem_ParaRuck()
{
	AttachmentClass = { AAttch_ParaRuck::StaticClass() };
}
