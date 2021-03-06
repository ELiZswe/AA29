// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_NPC_RPG7_Rocket/AttachW_NPC_RPG7_Rocket.h"
#include "AA29/Object/Actor/Base3pAmmoRound/Base3pAmmoRound.h"

AAttachW_NPC_RPG7_Rocket::AAttachW_NPC_RPG7_Rocket()
{
	EnemyAttachmentClass = AAttachW_NPC_RPG7_Rocket::StaticClass();
	//bNetInitialRotation = true
}

void AAttachW_NPC_RPG7_Rocket::PreBeginPlay()
{
	Super::PreBeginPlay();
}

void AAttachW_NPC_RPG7_Rocket::AttachmentAnimation()
{
	Super::AttachmentAnimation();
	if (AmmoRound3P == nullptr)
	{
		return;
	}
	AmmoRound3P->ShowRound(false);
	if (IsAnimState(16))
	{
		//SetTimer(0.25, false);
	}
	else
	{
		AmmoRound3P->ShowRound(false);
	}
}

void AAttachW_NPC_RPG7_Rocket::Timer()
{
	AmmoRound3P->ShowRound(true);
}

