// All the original content belonged to the US Army


#include "AttachW_Makarov_Pistol.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/PistolWeaponAttachment/AttachW_M9_Pistol/AttachW_M9_Pistol.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_9mm_Emitter/Shell_9mm_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M9MuzzleFlash/M9MuzzleFlash.h"

AAttachW_Makarov_Pistol::AAttachW_Makarov_Pistol()
{
	_cShellEmitterClass				= AShell_9mm_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= 40;
	_ShellDirInfo.PitchMaxDeviation	= 5;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 100;
	_ShellDirInfo.YawMaxDeviation	= 5;
	_ShellDirInfo.YawFalloff		= 1;
	_ShellDirInfo.bRoll				= 0;
	_ShellDirInfo.RollMean			= 0;
	_ShellDirInfo.RollMaxDeviation	= 0;
	_ShellDirInfo.RollFalloff		= 0;
	_ShellDirInfo.SpeedMean			= 65;
	_ShellDirInfo.SpeedMaxDeviation	= 5;
	_ShellDirInfo.SpeedFalloff		= 1;
	_ShellDirInfo.Base				= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset			= FVector(0, 0, 0);
	_ShellOffset1P.ROffset			= FRotator(0, 0, 0);
	_ShellOffset1P.nBone			= "Shell";
	_ShellOffset3P.VOffset			= FVector(0, 0, 0);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 0);
	_ShellOffset3P.nBone			= "Shell";
	_cMuzzleFlashClass				= AM9MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(0, 0, 0);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 0);
	_MuzzleOffset.nBone				= "Muzzle";
	EnemyAttachmentClass			= AAttachW_M9_Pistol::StaticClass();
	Mesh							= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/makarov_3p.makarov_3p"), NULL, LOAD_None, NULL);
}