// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_SF_Cap/Attch_SF_Cap.h"

AAttch_SF_Cap::AAttch_SF_Cap()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-SF_instructor_cap.m-SF_instructor_cap"), NULL, LOAD_None, NULL);
}
