// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Turban/Hat_Turban.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Turban/Attch_Turban.h"

AHat_Turban::AHat_Turban()
{
	AttachmentClass = { AAttch_Turban::StaticClass() };
}
