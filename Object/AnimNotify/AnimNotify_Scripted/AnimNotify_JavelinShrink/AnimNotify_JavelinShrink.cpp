// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_JavelinShrink/AnimNotify_JavelinShrink.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_Javelin/AttachW_Javelin.h"

UAnimNotify_JavelinShrink::UAnimNotify_JavelinShrink()
{

}

void UAnimNotify_JavelinShrink::Notify(AActor* Owner)
{
	/*
	if (Owner->IsA(APawn::StaticClass()) && Pawn(GetOwner())->Weapon.ThirdPersonActor->IsA(AAttachW_Javelin::StaticClass()))
	{
		Cast<APawn>(GetOwner())->Weapon.ThirdPersonActor.GotoState('Shrinking', 'Begin');
	}
	*/
}
