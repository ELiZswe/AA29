// All the original content belonged to the US Army


#include "WeaponMod_Vintorez_Scope.h"
#include "AA29/BaseWeaponMod/WeaponMod_VariX_Scope/WeaponMod_VariX_Scope.h"
#include "AA29/BaseScope/ScopeW_PSO_Vintorez.h"

AWeaponMod_Vintorez_Scope::AWeaponMod_Vintorez_Scope()
{
	ScopeClass         = AScopeW_PSO_Vintorez::StaticClass();
	//ValidSlot = 1;
	EnemyModClass      = AWeaponMod_VariX_Scope::StaticClass();
	mFov               = 10;
	mZoomAnimOffset    = FVector(-5, -64, 5);
	bUseModZoomOffset  = true;
	DrawType           = EDrawType::DT_Mesh;
	Mesh               = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/PSO.PSO"), NULL, LOAD_None, NULL);
}