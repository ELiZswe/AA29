// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_BDUCap/Attch_BDUCap.h"

AAttch_BDUCap::AAttch_BDUCap()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-bdu_cap.m-bdu_cap"), NULL, LOAD_None, NULL);
}
