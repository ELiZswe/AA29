// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag\Ammo_556mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"

APickupAmmo_556mm_30_Mag::APickupAmmo_556mm_30_Mag()
{
	AmmoAmount     = 30;
	InventoryType  = AAmmo_556mm_30_Mag::StaticClass();
	PickupMessage  = "You got an M16 rifle magazine.";
	//Mesh = VertMesh'AGP_Inventory.mag55630pick'
	DrawScale      = 2;
	Skins = {
			Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/AGP_Inventory/Skins/mag55630T_Mat.mag55630T_Mat'")))
	};
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m16a2-clip.m16a2-clip'"), NULL, LOAD_None, NULL));

}
