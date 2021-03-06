// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_UpdateCurrentAmmo/AnimNotify_UpdateCurrentAmmo.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

UAnimNotify_UpdateCurrentAmmo::UAnimNotify_UpdateCurrentAmmo()
{

}

void UAnimNotify_UpdateCurrentAmmo::Notify(AActor* aOwner)
{
	if (aOwner->IsA(AWeapon::StaticClass()))
	{
		Cast<AWeapon>(aOwner)->UpdateCurrentAmmoRounds(bRoundInBreech);
	}
}
