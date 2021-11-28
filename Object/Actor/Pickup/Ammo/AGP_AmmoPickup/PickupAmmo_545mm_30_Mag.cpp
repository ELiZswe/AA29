// All the original content belonged to the US Army


#include "PickupAmmo_545mm_30_Mag.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_545mm_30_Mag/Ammo_545mm_30_Mag.h"

APickupAmmo_545mm_30_Mag::APickupAmmo_545mm_30_Mag()
{
	AmmoAmount     = 30;
	InventoryType  = AAmmo_545mm_30_Mag::StaticClass();
	PickupMessage  = "You got an AK-74 banana clip.";
	DrawScale      = 2;
	//Mesh = VertMesh'AGP_Inventory.mag55630pick'

	Skins = {
			  Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/AGP_Inventory/Skins/mag55630T_Mat.mag55630T_Mat'")))
	};
}