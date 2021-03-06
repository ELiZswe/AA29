// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_ParaRuck/Attch_ParaRuck.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAttch_ParaRuck::AAttch_ParaRuck()
{
	AttachBone = "RuckSack";
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-parachute.m-parachute'"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-parachute.m-parachute'"), NULL, LOAD_None, NULL);
	bOrientOnSlope = true;
	//bReplicateInstigator = true;
	//bCollideActors = true;
	//bCollideWorld = true;
}

FName AAttch_ParaRuck::GetAttachBoneFor(AInventory* Inv)
{
	return "RuckSack";
}
