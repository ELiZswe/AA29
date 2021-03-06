// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_PSO/WeaponMod_PSO.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Acog4x/WeaponMod_Acog4x.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_PSO_AK74su/ScopeW_PSO_AK74su.h"

AWeaponMod_PSO::AWeaponMod_PSO()
{
	ScopeClass			= AScopeW_PSO_AK74su::StaticClass();
	ExclusiveModsList	= {
							AWeaponMod_Reflex::StaticClass()
						};
	ValidSlot			= { 1 };
	EnemyModClass		= AWeaponMod_Acog4x::StaticClass();
	mFov				= 10;
	mZoomAnimOffset		= FVector(-6, -51982, 173);
	bUseModZoomOffset	= true;
	DrawType			= EDrawType::DT_Mesh;
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/PSO.PSO'"), NULL, LOAD_None, NULL);
}
