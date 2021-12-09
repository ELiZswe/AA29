// All the original content belonged to the US Army


#include "AttachW_M870_Shotgun.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter\Shell_762mm_Emitter\Shell_762mm_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M24MuzzleFlash/M24MuzzleFlash.h"


AAttachW_M870_Shotgun::AAttachW_M870_Shotgun()
{
	_cShellEmitterClass				= AShell_762mm_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= -30;
	_ShellDirInfo.PitchMaxDeviation	= 10;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 135;
	_ShellDirInfo.YawMaxDeviation	= 15;
	_ShellDirInfo.YawFalloff		= 1;
	_ShellDirInfo.bRoll				= 0;
	_ShellDirInfo.RollMean			= 0;
	_ShellDirInfo.RollMaxDeviation	= 0;
	_ShellDirInfo.RollFalloff		= 0;
	_ShellDirInfo.SpeedMean			= 100;
	_ShellDirInfo.SpeedMaxDeviation	= 20;
	_ShellDirInfo.SpeedFalloff		= 1;
	_ShellDirInfo.Base				= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset			= FVector(3, 0, -3);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "Box08";
	_ShellOffset3P.VOffset			= FVector(0, 1, -5);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_bDelayShellEject				= true;
	_cMuzzleFlashClass				= AM24MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(45, 0, -42);
	_MuzzleOffset.ROffset			= FRotator(6.4984130859375, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	EnemyAttachmentClass			= AAttachW_M870_Shotgun::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m870_shorty_3p.m870_shorty_3p"), NULL, LOAD_None, NULL);
}