// All the original content belonged to the US Army

#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_JavelinGrow/AnimNotify_JavelinGrow.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_Javelin/AttachW_Javelin.h"

UAnimNotify_JavelinGrow::UAnimNotify_JavelinGrow()
{

}

void UAnimNotify_JavelinGrow::Notify(AActor* Owner)
{
	/*
	if (Owner->IsA(APawn::StaticClass()) && Pawn(GetOwner())->Weapon.ThirdPersonActor->isA(AAttachW_Javelin::StaticClass()))
	{
		Cast<APawn>(GetOwner())->Weapon.ThirdPersonActor.GotoState('Growing', 'Begin');
	}
	*/
}
