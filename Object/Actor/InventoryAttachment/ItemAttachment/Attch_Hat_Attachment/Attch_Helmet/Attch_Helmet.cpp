// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Helmet/Attch_Helmet.h"

AAttch_Helmet::AAttch_Helmet()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_michhelmet1a.m_atta_us-soldier_michhelmet1a"), NULL, LOAD_None, NULL);
}
