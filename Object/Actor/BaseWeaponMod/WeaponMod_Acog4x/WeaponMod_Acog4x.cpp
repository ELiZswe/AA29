// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Acog4x/WeaponMod_Acog4x.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_PSO/WeaponMod_PSO.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_ACOG_4X/ScopeW_ACOG_4X.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"

AWeaponMod_Acog4x::AWeaponMod_Acog4x()
{
	ScopeClass			= AScopeW_ACOG_4X::StaticClass();
	ModImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_acog4x_black_Mat.mod_acog4x_black_Mat'"), NULL, LOAD_None, NULL);
	ModImageOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_acog_Mat.m4mod_acog_Mat'"), NULL, LOAD_None, NULL);
	//ExclusiveModsList(0) = AWeaponMod_Reflex::StaticClass()
	ValidSlot			= { 1 };
	EnemyModClass		= AWeaponMod_PSO::StaticClass();
	modname				= "Acog 4X";
	//ModScopeScriptedTexture = ScriptedTexture'T_AA2_Skins.Scopes.ScriptedScope'
	mFov				= 10;
	mZoomAnimOffset		= FVector(-15, -51, 1141);
	bUseModZoomOffset	= true;
	DrawType			= EDrawType::DT_Mesh;
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/Acog4x.Acog4x"), NULL, LOAD_None, NULL);
}
