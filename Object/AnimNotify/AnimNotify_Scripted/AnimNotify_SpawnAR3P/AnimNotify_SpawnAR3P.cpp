// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_SpawnAR3P/AnimNotify_SpawnAR3P.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"

UAnimNotify_SpawnAR3P::UAnimNotify_SpawnAR3P()
{

}

void UAnimNotify_SpawnAR3P::Notify(AActor* Owner)
{
	/*
	if (Cast<APawn>(Owner)->Weapon != nullptr && Pawn(Owner)->Controller->Level->IsServer())
	{
		Cast<AWeaponAttachment>(Cast<APawn>(Owner)->Weapon->ThirdPersonActor)->SpawnAndAttachAR3P();
	}
	*/
}
