// All the original content belonged to the US Army


#include "AttachW_AT4_Rocket.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_RPG7_Rocket.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AT4MuzzleFlash/AT4MuzzleFlash.h"

AAttachW_AT4_Rocket::AAttachW_AT4_Rocket()
{
	
	_cMuzzleFlashClass		= AAT4MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset	= FVector(45, 0, -42);
	_MuzzleOffset.ROffset	= FRotator(6.4984130859375, 0, 90);
	_MuzzleOffset.nBone		= "WeaponBone";
	EnemyAttachmentClass	= AAttachW_RPG7_Rocket::StaticClass();
	DrawType				= EDrawType::DT_Mesh;
	Mesh					= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/at4_3P.at4_3P"), NULL, LOAD_None, NULL);
}