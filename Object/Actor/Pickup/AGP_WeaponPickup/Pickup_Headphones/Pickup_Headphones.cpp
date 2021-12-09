// All the original content belonged to the US Army


#include "Pickup_Headphones.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/item_headphones/item_headphones.h"

APickup_Headphones::APickup_Headphones()
{
	InventoryType	= Aitem_headphones::StaticClass();
	PickupMessage	= FString("You got headphones");
	DrawType		= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Equipment/headphones/eqp2_headphones_resting.eqp2_headphones_resting"), NULL, LOAD_None, NULL));
}