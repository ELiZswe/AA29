// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_BDUCap_sgt/Attch_BDUCap_sgt.h"

AAttch_BDUCap_sgt::AAttch_BDUCap_sgt()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-sgt_bdu_cap.m-sgt_bdu_cap"), NULL, LOAD_None, NULL);
}
