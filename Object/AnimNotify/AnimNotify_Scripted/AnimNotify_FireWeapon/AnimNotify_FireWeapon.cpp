// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_FireWeapon/AnimNotify_FireWeapon.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"

UAnimNotify_FireWeapon::UAnimNotify_FireWeapon()
{

}

void UAnimNotify_FireWeapon::Notify(AActor* Owner)
{
	/*
	Cast<APawn>(Owner)->bIgnorePlayFiring = true;
	Cast<AWeaponAttachment>(Cast<APawn>(Owner)->Weapon.ThirdPersonActor).ThirdPersonEffects();
	if (Cast<APawn>(Owner)->Weapon.FireSound != nullptr)
	{
		Cast<APawn>(Owner)->Weapon.PlaySound(Cast<APawn>(Owner)->Weapon.FireSound, 0, 1);
	}
	*/
}
