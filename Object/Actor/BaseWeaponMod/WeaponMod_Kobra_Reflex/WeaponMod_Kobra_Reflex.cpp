// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Kobra_Reflex/WeaponMod_Kobra_Reflex.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_ACOG_Reflex/ScopeW_ACOG_Reflex.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_PSO/WeaponMod_PSO.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"

AWeaponMod_Kobra_Reflex::AWeaponMod_Kobra_Reflex()
{
	ScopeClass			= AScopeW_ACOG_Reflex::StaticClass();
	ExclusiveModsList	= {
							AWeaponMod_PSO::StaticClass()
						};
	//ValidSlot(1) = 1
	EnemyModClass		= AWeaponMod_Reflex::StaticClass();
	mZoomAnimOffset		= FVector(-79, -4365, 15);
	bUseModZoomOffset	= true;
	DrawType			= EDrawType::DT_Mesh;
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/kobra.kobra"), NULL, LOAD_None, NULL);
}
