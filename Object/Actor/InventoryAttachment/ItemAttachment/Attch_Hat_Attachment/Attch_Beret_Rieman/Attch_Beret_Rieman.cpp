// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Beret_Rieman/Attch_Beret_Rieman.h"

AAttch_Beret_Rieman::AAttch_Beret_Rieman()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_beret_rh_rieman.m_atta_us-soldier_beret_rh_rieman"), NULL, LOAD_None, NULL);
}
