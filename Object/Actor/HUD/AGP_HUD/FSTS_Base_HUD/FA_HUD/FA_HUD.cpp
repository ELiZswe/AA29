// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/AGP_HUD/FSTS_Base_HUD/FA_HUD/FA_HUD.h"

AFA_HUD::AFA_HUD(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}

void AFA_HUD::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
	//Level.AddPrecacheMaterial(Texture'T_AA2_UI.HUD.hud_crosshair_10a');
}
