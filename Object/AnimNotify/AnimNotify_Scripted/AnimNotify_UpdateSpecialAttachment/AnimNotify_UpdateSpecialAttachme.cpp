// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_UpdateSpecialAttachment/AnimNotify_UpdateSpecialAttachme.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

UAnimNotify_UpdateSpecialAttachme::UAnimNotify_UpdateSpecialAttachme()
{

}

void UAnimNotify_UpdateSpecialAttachme::Notify(AActor* Owner)
{
	/*
	if (Owner->IsA(AAGP_Weapon::StaticClass()))
	{
		Cast<AAGP_Weapon>(GetOwner())->UpdateSpecialAttachment(bAttachmentVisible);
	}
	*/
}
