// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_ReserveChute/Attch_ReserveChute.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAttch_ReserveChute::AAttch_ReserveChute()
{
	AttachBone = "spine01";
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_reserve_chute.m_reserve_chute'"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_reserve_chute.m_reserve_chute'"), NULL, LOAD_None, NULL);
	bOrientOnSlope = true;
	//bReplicateInstigator = true;
	//bCollideActors = true;
	//bCollideWorld = true;
}

FName AAttch_ReserveChute::GetAttachBoneFor(AInventory* Inv)
{
	return "spine01";
}
