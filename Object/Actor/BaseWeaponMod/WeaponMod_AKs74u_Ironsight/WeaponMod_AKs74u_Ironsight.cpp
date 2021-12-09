// All the original content belonged to the US Army


#include "WeaponMod_AKs74u_Ironsight.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Ironsight/WeaponMod_Ironsight.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_M4_Rifle/ScopeW_M4_Rifle.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

AWeaponMod_AKs74u_Ironsight::AWeaponMod_AKs74u_Ironsight()
{
	ScopeClass     = AScopeW_M4_Rifle::StaticClass();
	ValidSlot      = 1;
	EnemyModClass  = AWeaponMod_Ironsight::StaticClass();
	DrawType       = EDrawType::DT_Mesh;
	Mesh           = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/aks74u_ironsight.aks74u_ironsight"), NULL, LOAD_None, NULL);
}


void AWeaponMod_AKs74u_Ironsight::SetupScope()
{
	if (Cast<AAGP_Weapon>(weap)->_cScopeClass == NULL)
	{
		SetupScope();
	}
}