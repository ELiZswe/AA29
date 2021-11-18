// All the original content belonged to the US Army


#include "AttachW_SVD_Sniper.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M82_Sniper/AttachW_M82_Sniper.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_127mm_Emitter/Shell_127mm_Emitter.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash/AK47MuzzleFlash.h"

AAttachW_SVD_Sniper::AAttachW_SVD_Sniper()
{
	_cShellEmitterClass				= AShell_127mm_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= 25;
	_ShellDirInfo.PitchMaxDeviation	= 30;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 100;
	_ShellDirInfo.YawMaxDeviation	= 10;
	_ShellDirInfo.YawFalloff		= 1;
	_ShellDirInfo.bRoll				= 0;
	_ShellDirInfo.RollMean			= 0;
	_ShellDirInfo.RollMaxDeviation	= 0;
	_ShellDirInfo.RollFalloff		= 0;
	_ShellDirInfo.SpeedMean			= 250;
	_ShellDirInfo.SpeedMaxDeviation	= 100;
	_ShellDirInfo.SpeedFalloff		= 1;
	_ShellDirInfo.Base				= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset			= FVector(0, -5, -5);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "M16-MagRound";
	_ShellOffset3P.VOffset			= FVector(0, 1, 0);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_cMuzzleFlashClass				= AAK47MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(7, 0, -42);
	_MuzzleOffset.ROffset			= FRotator(1.505126953125, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	EnemyAttachmentClass			= AAttachW_M82_Sniper::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-dragonov_3p.m-dragonov_3p"), NULL, LOAD_None, NULL);
}