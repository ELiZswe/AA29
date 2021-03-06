// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_AltFire/AnimNotify_AltFire.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

UAnimNotify_AltFire::UAnimNotify_AltFire()
{

}

void UAnimNotify_AltFire::Notify(AActor* Owner)
{
	AWeapon* W = nullptr;
	if (Owner->IsA(AWeapon::StaticClass()))
	{
		W = Cast<AWeapon>(Owner);
		W->SetAltFireNotified(true);
		W->AltFire(inputvalue);
	}
}
