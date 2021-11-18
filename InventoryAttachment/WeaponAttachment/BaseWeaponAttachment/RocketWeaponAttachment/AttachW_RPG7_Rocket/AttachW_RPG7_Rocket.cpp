// All the original content belonged to the US Army


#include "AttachW_RPG7_Rocket.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_AT4_Rocket/AttachW_AT4_Rocket.h"
#include "AA29/InventoryAttachment/ItemAttachment/Attch_RPGBackpack/Attch_RPGBackpack.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/RPG7MuzzleFlash/RPG7MuzzleFlash.h"
#include "AA29/Base3pAmmoRound/AmmoRound_3P_RPG7_Rocket.h"

AAttachW_RPG7_Rocket::AAttachW_RPG7_Rocket()
{
	BackpackAttachmentClass		= AAttch_RPGBackpack::StaticClass();
	ThirdPersonAmmoRoundClass	= AAmmoRound_3P_RPG7_Rocket::StaticClass();
	_cMuzzleFlashClass			= ARPG7MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset		= FVector(45, 0, -42);
	_MuzzleOffset.ROffset		= FRotator(0, 6.4984130859375,90);
	_MuzzleOffset.nBone			= "WeaponBone";
	PawnStdReloadAnimation		= FName("StdRPGRld");
	PawnPrnReloadAnimation		= FName("StdRPGRld");
	bHasAttachmentReload		= true;
	IdleAnim					= FName("Full");
	IdleEmptyAnim				= FName("Empty");
	EmptyReloadAnim				= FName("StdRPGRld");
	EnemyAttachmentClass		= AAttachW_AT4_Rocket::StaticClass();
	DrawType					= EDrawType::DT_Mesh;
	Mesh						= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/rpg7_3P.rpg7_3P"), NULL, LOAD_None, NULL);
}