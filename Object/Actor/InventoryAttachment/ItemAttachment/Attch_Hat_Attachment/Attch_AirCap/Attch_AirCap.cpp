// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_AirCap/Attch_AirCap.h"

AAttch_AirCap::AAttch_AirCap()
{
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-air_cap.m-air_cap'"), NULL, LOAD_None, NULL);
}

void AAttch_AirCap::PostBeginPlay()
{
	//SetRelativeLocation(FVector(0, 0.2, 0));
}
