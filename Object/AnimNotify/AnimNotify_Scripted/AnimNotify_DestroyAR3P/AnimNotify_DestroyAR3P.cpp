// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_DestroyAR3P/AnimNotify_DestroyAR3P.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"

UAnimNotify_DestroyAR3P::UAnimNotify_DestroyAR3P()
{

}

void UAnimNotify_DestroyAR3P::Notify(AActor* Owner)
{
	/*
	if (Cast<APawn>(Owner)->Weapon != nullptr && Cast<APawn>(Owner)->Controller->Level->IsServer())
	{
		Cast<AWeaponAttachment>(Cast<APawn>(Owner)->Weapon->ThirdPersonActor)->DestroyAR3P();
	}
	*/
}
