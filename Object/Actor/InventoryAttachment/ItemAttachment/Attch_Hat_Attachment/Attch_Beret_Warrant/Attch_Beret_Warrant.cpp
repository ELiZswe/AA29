// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Beret_Warrant/Attch_Beret_Warrant.h"

AAttch_Beret_Warrant::AAttch_Beret_Warrant()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-green_beret_warrent.m-green_beret_warrent"), NULL, LOAD_None, NULL);
}
