// All the original content belonged to the US Army


#include "WeaponMod_Ironsight.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_M4_Rifle/ScopeW_M4_Rifle.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/BaseWeaponMod//WeaponMod_AKs74u_Ironsight/WeaponMod_AKs74u_Ironsight.h"

AWeaponMod_Ironsight::AWeaponMod_Ironsight()
{
	ScopeClass         = AScopeW_M4_Rifle::StaticClass();
	ModImage           = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_ironsight_black.mod_ironsight_black"), NULL, LOAD_None, NULL);
	ModImageOverlay    = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_ironsights.m4mod_ironsights"), NULL, LOAD_None, NULL);
	//ValidSlot = 1;
	EnemyModClass      = AWeaponMod_AKs74u_Ironsight::StaticClass();
	modname            = "Ironsight";
	DrawType           = EDrawType::DT_Mesh;
	Mesh               = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/CarryingHandle.CarryingHandle"), NULL, LOAD_None, NULL);
}


void AWeaponMod_Ironsight::SetupScope()
{
	if (Cast<AAGP_Weapon>(weap)->_cScopeClass == NULL)
	{
		Super::SetupScope();
	}
}