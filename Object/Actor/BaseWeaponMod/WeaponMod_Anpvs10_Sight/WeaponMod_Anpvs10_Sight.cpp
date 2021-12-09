// All the original content belonged to the US Army


#include "WeaponMod_Anpvs10_Sight.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_ACOG_4X/ScopeW_ACOG_4X.h"

AWeaponMod_Anpvs10_Sight::AWeaponMod_Anpvs10_Sight()
{
	ScopeClass			= AScopeW_ACOG_4X::StaticClass();
	ExclusiveModsList	= {
							AWeaponMod_Reflex::StaticClass()
						};
	ValidSlot			= 1;
	DrawType			= EDrawType::DT_Mesh;
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/anpvs10.anpvs10"), NULL, LOAD_None, NULL);
}