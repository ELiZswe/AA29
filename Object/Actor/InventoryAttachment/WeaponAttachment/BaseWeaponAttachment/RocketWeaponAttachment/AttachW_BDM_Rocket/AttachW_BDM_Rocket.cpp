// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_BDM_Rocket/AttachW_BDM_Rocket.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_PG7VR_Rocket/AttachW_PG7VR_Rocket.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BDMMuzzleFlash/BDMMuzzleFlash.h"

AAttachW_BDM_Rocket::AAttachW_BDM_Rocket()
{
	_cMuzzleFlashClass		= ABDMMuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset	= FVector(45, 0, -42);
	_MuzzleOffset.ROffset	= FRotator(6.4984130859375, 0, 90);
	_MuzzleOffset.nBone		= "WeaponBone";
	EnemyAttachmentClass	= AAttachW_PG7VR_Rocket::StaticClass();
	DrawType				= EDrawType::DT_Mesh;
	Mesh					= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/at4_3P.at4_3P"), NULL, LOAD_None, NULL);
}
