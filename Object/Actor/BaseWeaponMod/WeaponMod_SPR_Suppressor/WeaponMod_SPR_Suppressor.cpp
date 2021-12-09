// All the original content belonged to the US Army


#include "WeaponMod_SPR_Suppressor.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Virtual_SPR_Suppressor/WeaponMod_Virtual_SPR_Suppressor.h"

AWeaponMod_SPR_Suppressor::AWeaponMod_SPR_Suppressor()
{
	bSuppressorMod     = true;
	//ValidSlot(5) = 1
	EnemyModClass      = AWeaponMod_Virtual_SPR_Suppressor::StaticClass();
	DrawType           = EDrawType::DT_Mesh;
	Mesh               = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/spr_suppressor.spr_suppressor"), NULL, LOAD_None, NULL);
}