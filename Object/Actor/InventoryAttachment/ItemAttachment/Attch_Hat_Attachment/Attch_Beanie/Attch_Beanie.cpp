// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Beanie/Attch_Beanie.h"

AAttch_Beanie::AAttch_Beanie()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-beanie_blk_cap.m-beanie_blk_cap"), NULL, LOAD_None, NULL);
}
