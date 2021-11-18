// All the original content belonged to the US Army


#include "WeaponMod_VariX_Scope.h"
#include "AA29/BaseWeaponMod/WeaponMod_Vintorez_Scope/WeaponMod_Vintorez_Scope.h"
#include "AA29/BaseScope/ScopeW_M24_Sniper.h"

AWeaponMod_VariX_Scope::AWeaponMod_VariX_Scope()
{
	ScopeClass      = AScopeW_M24_Sniper::StaticClass();
	//ValidSlot = 1;
	EnemyModClass   = AWeaponMod_Vintorez_Scope::StaticClass();
	DrawType        = EDrawType::DT_Mesh;
	Mesh            = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/vari_x_iii_m3_scope.vari_x_iii_m3_scope"), NULL, LOAD_None, NULL);
}