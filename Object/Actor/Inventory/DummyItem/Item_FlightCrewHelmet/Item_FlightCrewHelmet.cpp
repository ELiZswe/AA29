// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/DummyItem/Item_FlightCrewHelmet/Item_FlightCrewHelmet.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_FlightCrewHelmet/Attch_FlightCrewHelmet.h"

AItem_FlightCrewHelmet::AItem_FlightCrewHelmet()
{
	AttachmentClass = { AAttch_FlightCrewHelmet::StaticClass() };
}
