// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_VliFlashLight/WeaponMod_VliFlashLight.h"

// Sets default values
AWeaponMod_VliFlashLight::AWeaponMod_VliFlashLight()
{
	//ValidSlot(2) = 1
	//ValidSlot(3) = 1
	// DrawType = 2
	Mesh        = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/vliflashlight.vliflashlight"), NULL, LOAD_None, NULL);
}
