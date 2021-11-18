// All the original content belonged to the US Army


#include "WeaponMod_Acog4x.h"
#include "AA29/BaseWeaponMod/WeaponMod_PSO/WeaponMod_PSO.h"
#include "AA29/BaseScope/ScopeW_ACOG_4X.h"

AWeaponMod_Acog4x::AWeaponMod_Acog4x()
{
	ScopeClass			= AScopeW_ACOG_4X::StaticClass();
	ModImage			= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_acog4x_black.mod_acog4x_black"), NULL, LOAD_None, NULL);
	ModImageOverlay		= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_acog.m4mod_acog"), NULL, LOAD_None, NULL);
	//ExclusiveModsList(0) = class'AGP_Inventory.WeaponMod_Reflex'
	ValidSlot			= 1;
	EnemyModClass		= AWeaponMod_PSO::StaticClass();
	modname				= "Acog 4X";
	//ModScopeScriptedTexture = ScriptedTexture'T_AA2_Skins.Scopes.ScriptedScope'
	mFov				= 10;
	mZoomAnimOffset		= FVector(-15, -51, 1141);
	bUseModZoomOffset	= true;
	DrawType			= EDrawType::DT_Mesh;
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/Acog4x.Acog4x"), NULL, LOAD_None, NULL);
}