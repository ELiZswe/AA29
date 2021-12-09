// All the original content belonged to the US Army


#include "AttachW_M16A2_Rifle.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_AK47_Rifle/AttachW_AK47_Rifle.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_556mm_Emitter/Shell_556mm_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash/M16A2MuzzleFlash.h"

AAttachW_M16A2_Rifle::AAttachW_M16A2_Rifle()
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
	_ShellOffset1P.VOffset			= FVector(10, 0, -5);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "M16-MagRound";
	_ShellOffset3P.VOffset			= FVector(0, 1, -4);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_cMuzzleFlashClass				= AM16A2MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(-5, 0, -36);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	EnemyAttachmentClass			= AAttachW_AK47_Rifle::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m16a2_3p.m-m16a2_3p"), NULL, LOAD_None, NULL);
}