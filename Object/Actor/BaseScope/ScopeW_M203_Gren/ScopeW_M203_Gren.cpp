// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseScope/ScopeW_M203_Gren/ScopeW_M203_Gren.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

AScopeW_M203_Gren::AScopeW_M203_Gren()
{
	tAuxZoomOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m203_overlay_sight_Mat.m203_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	aZoomFOV        = { 70.0f };
	tZoomOverlay    = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight_Mat.m16a2_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
}

UMaterialInstance* AScopeW_M203_Gren::GetZoomOverlay()
{
	if (Cast<AAGP_Weapon>(GetOwner())->eROF == ERateofFire::ROF_SingleGren)
	{
		return tAuxZoomOverlay;
	}
	return Super::GetZoomOverlay();
}
