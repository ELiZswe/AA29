// All the original content belonged to the US Army


#include "AttachW_SPR_Sniper.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_Vintorez_Sniper/AttachW_Vintorez_Sniper.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_556mm_Emitter/Shell_556mm_Emitter.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash/M16A2MuzzleFlash.h"

AAttachW_SPR_Sniper::AAttachW_SPR_Sniper()
{
	_cShellEmitterClass				= AShell_556mm_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= -10;
	_ShellDirInfo.PitchMaxDeviation	= 5;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 140;
	_ShellDirInfo.YawMaxDeviation	= 5;
	_ShellDirInfo.YawFalloff		= 1;
	_ShellDirInfo.bRoll				= 0;
	_ShellDirInfo.RollMean			= 0;
	_ShellDirInfo.RollMaxDeviation	= 0;
	_ShellDirInfo.RollFalloff		= 0;
	_ShellDirInfo.SpeedMean			= 140;
	_ShellDirInfo.SpeedMaxDeviation	= 20;
	_ShellDirInfo.SpeedFalloff		= 1;
	_ShellDirInfo.Base				= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset			= FVector(-10, 5, 5);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "Shell";
	_ShellOffset3P.VOffset			= FVector(0, 0, 0);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 0);
	_ShellOffset3P.nBone			= "Shell";
	_cMuzzleFlashClass				= AM16A2MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(0, 0, 0);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 0);
	_MuzzleOffset.nBone				= "Muzzle";
	EnemyAttachmentClass			= AAttachW_Vintorez_Sniper::StaticClass();
	DrawType						= EDrawType::DT_Mesh;
	Mesh							= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/spr_3P.spr_3P"), NULL, LOAD_None, NULL);
}