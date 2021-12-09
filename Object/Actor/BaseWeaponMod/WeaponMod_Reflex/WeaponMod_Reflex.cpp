// All the original content belonged to the US Army


#include "WeaponMod_Reflex.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_ACOG_Reflex/ScopeW_ACOG_Reflex.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Acog4x/WeaponMod_Acog4x.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Anpvs10_Sight/WeaponMod_Anpvs10_Sight.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod_AuxWeapon/WeaponMod_M203_Gren/WeaponMod_M203_Gren.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_M68_AimPoint/WeaponMod_M68_AimPoint.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod_AuxWeapon/WeaponMod_Flare_Gren/WeaponMod_Flare_Gren.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Kobra_Reflex/WeaponMod_Kobra_Reflex.h"

AWeaponMod_Reflex::AWeaponMod_Reflex()
{
	ScopeClass           = AScopeW_ACOG_Reflex::StaticClass();
	ModImage             = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_reflex_black.mod_reflex_black"), NULL, LOAD_None, NULL);
	ModImageOverlay      = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_reflex.m4mod_reflex"), NULL, LOAD_None, NULL);
	ExclusiveModsList = {
		AWeaponMod_Acog4x::StaticClass(),
		AWeaponMod_Anpvs10_Sight::StaticClass(),
		AWeaponMod_M203_Gren::StaticClass(),
		AWeaponMod_M68_AimPoint::StaticClass(),
		AWeaponMod_Flare_Gren::StaticClass()
	};
		//ValidSlot(1) = 1
	EnemyModClass        = AWeaponMod_Kobra_Reflex::StaticClass();
	modname              = "Acog Reflex";
	//ModScopeScriptedTexture = ScriptedTexture'T_AA2_Skins.Scopes.ScriptedScope'
	mFov                 = 10;
	//ModScopeTexSize(0) = 512
	//ModScopeTexSize(1) = 256
	//ModScopeTexSize(2) = 128
	//ModScopeTexSize(3) = 64
	mZoomAnimOffset      = FVector(-10, -4155, 1215);
	bUseModZoomOffset    = true;
	bCanSwapLense        = true;
	StandardLensTexture  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Skins/us_mods/skn2_us_mods_acog_reflex_lens_base.skn2_us_mods_acog_reflex_lens_base"), NULL, LOAD_None, NULL);
	//ScriptedLensTexture  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Skins/Scopes/ScriptedReflex.ScriptedReflex"), NULL, LOAD_None, NULL);
	DrawType             = EDrawType::DT_Mesh;
	Mesh                 = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/AcogReflex.AcogReflex"), NULL, LOAD_None, NULL);
}