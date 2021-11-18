// All the original content belonged to the US Army


#include "WeaponMod_PBS4_Suppressor.h"
#include "AA29/BaseWeaponMod/WeaponMod_M4qd_Suppressor/WeaponMod_M4qd_Suppressor.h"

AWeaponMod_PBS4_Suppressor::AWeaponMod_PBS4_Suppressor()
{
	bSuppressorMod  = true;
	//ValidSlot(5) = 1
	EnemyModClass   = AWeaponMod_M4qd_Suppressor::StaticClass();
	DrawType        = EDrawType::DT_Mesh;
	Mesh            = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/pbs4_suppressor.pbs4_suppressor"), NULL, LOAD_None, NULL);
}