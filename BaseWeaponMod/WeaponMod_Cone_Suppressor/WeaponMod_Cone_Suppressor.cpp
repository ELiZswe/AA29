// All the original content belonged to the US Army


#include "WeaponMod_Cone_Suppressor.h"

AWeaponMod_Cone_Suppressor::AWeaponMod_Cone_Suppressor()
{
	//ValidSlot(5) = 1
	//EnemyModClass = AWeaponMod_Virtual_ConeSuppressor::StaticClass();
	DrawType  = EDrawType::DT_Mesh;
	Mesh      = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/cone_flash_suppressor.cone_flash_suppressor"), NULL, LOAD_None, NULL);
}