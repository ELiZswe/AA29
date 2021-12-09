// All the original content belonged to the US Army


#include "Item_FlightCrewPara.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_FlightCrewPara/Attch_FlightCrewPara.h"

AItem_FlightCrewPara::AItem_FlightCrewPara()
{
	AttachmentClass = { AAttch_FlightCrewPara::StaticClass() };
}