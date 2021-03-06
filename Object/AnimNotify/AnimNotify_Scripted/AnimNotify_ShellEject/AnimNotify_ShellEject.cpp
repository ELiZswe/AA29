// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_ShellEject/AnimNotify_ShellEject.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/BaseShellEmitter.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"

UAnimNotify_ShellEject::UAnimNotify_ShellEject()
{

}

void UAnimNotify_ShellEject::Notify(AActor* Owner)
{
	ABaseShellEmitter* SE = nullptr;
	AHumanController* HC = nullptr;
	if (Owner->IsA(AAGP_Weapon::StaticClass()))
	{
		HC = Cast<AHumanController>(Owner->GetInstigator()->Controller);
		if (HC == nullptr || HC->bNoClientSideEffects)
		{
			return;
		}
		SE = Cast<ABaseWeaponAttachment>(Cast<AAGP_Weapon>(Owner)->ThirdPersonActor)->GetShellEmitter();
		SE->AnimControlledEject();
	}
}
