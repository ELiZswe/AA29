// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_SargeHat/Attch_SargeHat.h"

AAttch_SargeHat::AAttch_SargeHat()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-drill/m-sarge_hat.m-sarge_hat"), NULL, LOAD_None, NULL);
}
