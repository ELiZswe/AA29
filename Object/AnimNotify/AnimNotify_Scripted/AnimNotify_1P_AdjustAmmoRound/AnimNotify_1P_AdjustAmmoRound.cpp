// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_1P_AdjustAmmoRound/AnimNotify_1P_AdjustAmmoRound.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

UAnimNotify_1P_AdjustAmmoRound::UAnimNotify_1P_AdjustAmmoRound()
{

}

void UAnimNotify_1P_AdjustAmmoRound::Notify(AActor* Owner)
{
	if (Cast<AWeapon>(Owner) != nullptr)
	{
		Cast<AWeapon>(Owner)->AdjustAmmoRound();
	}
}
