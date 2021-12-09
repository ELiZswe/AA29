// All the original content belonged to the US Army


#include "AttachW_Vintorez_Sniper.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_SPR_Sniper/AttachW_SPR_Sniper.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_9x39_Emitter/Shell_9x39_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/VSSSuppressorMuzzleFlash/VSSSuppressorMuzzleFlash.h"

AAttachW_Vintorez_Sniper::AAttachW_Vintorez_Sniper()
{
	_cShellEmitterClass				= AShell_9x39_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= 25;
	_ShellDirInfo.PitchMaxDeviation	= 10;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 95;
	_ShellDirInfo.YawMaxDeviation	= 10;
	_ShellDirInfo.YawFalloff		= 1;
	_ShellDirInfo.bRoll				= 0;
	_ShellDirInfo.RollMean			= 0;
	_ShellDirInfo.RollMaxDeviation	= 0;
	_ShellDirInfo.RollFalloff		= 0;
	_ShellDirInfo.SpeedMean			= 500;
	_ShellDirInfo.SpeedMaxDeviation	= 200;
	_ShellDirInfo.SpeedFalloff		= 1;
	_ShellDirInfo.Base				= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset			= FVector(0, 0, -10);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "Shell";
	_ShellOffset3P.VOffset			= FVector(0, 0, 0);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 0);
	_ShellOffset3P.nBone			= "Shell";
	_cMuzzleFlashClass				= AVSSSuppressorMuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(0, 0, 0);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 0);
	_MuzzleOffset.nBone				= "Muzzle";
	EnemyAttachmentClass			= AAttachW_SPR_Sniper::StaticClass();
	DrawType						= EDrawType::DT_Mesh;
	Mesh							= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/vss_3P.vss_3P"), NULL, LOAD_None, NULL);
}