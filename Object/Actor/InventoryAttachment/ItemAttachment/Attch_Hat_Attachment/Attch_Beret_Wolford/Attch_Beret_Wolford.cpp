// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Beret_Wolford/Attch_Beret_Wolford.h"

AAttch_Beret_Wolford::AAttch_Beret_Wolford()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_beret_rh_wolford.m_atta_us-soldier_beret_rh_wolford"), NULL, LOAD_None, NULL);
}
