// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_NPC_RPG7_Rocket/AttachW_NPC_RPG7_Rocket.h"

AAttachW_NPC_RPG7_Rocket::AAttachW_NPC_RPG7_Rocket()
{
	EnemyAttachmentClass = AAttachW_NPC_RPG7_Rocket::StaticClass();
	//bNetInitialRotation = True
}

void AAttachW_NPC_RPG7_Rocket::PreBeginPlay()
{
	//PreBeginPlay();
}
void AAttachW_NPC_RPG7_Rocket::AttachmentAnimation()
{
/*
	AttachmentAnimation();
	if (AmmoRound3P == nullptr)
	{
		Return;
	}
	AmmoRound3P.ShowRound(False);
	if (IsAnimState(16))
	{
		SetTimer(0.25, false);
	}
	else
	{
		AmmoRound3P.ShowRound(False);
	}
*/
}
