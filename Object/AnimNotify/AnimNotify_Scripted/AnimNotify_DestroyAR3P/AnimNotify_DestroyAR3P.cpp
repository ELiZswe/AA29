// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_DestroyAR3P/AnimNotify_DestroyAR3P.h"

UAnimNotify_DestroyAR3P::UAnimNotify_DestroyAR3P()
{

}

void UAnimNotify_DestroyAR3P::Notify(AActor* Owner)
{
	/*
	if (Cast<APawn>(GetOwner())->Weapon != nullptr && Pawn(GetOwner())->Controller.Level.IsServer())
	{
		WeaponAttachment(Cast<APawn>(GetOwner())->Weapon.ThirdPersonActor).DestroyAR3P();
	}
	*/
}
