// All the original content belonged to the US Army


#include "AttachW_MosinNagant_Sniper.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M24_Sniper/AttachW_M24_Sniper.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_762x54mm_Emitter/Shell_762x54mm_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M24MuzzleFlash/M24MuzzleFlash.h"

AAttachW_MosinNagant_Sniper::AAttachW_MosinNagant_Sniper()
{
	_cShellEmitterClass				= AShell_762x54mm_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= 65;
	_ShellDirInfo.PitchMaxDeviation	= 5;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 90;
	_ShellDirInfo.YawMaxDeviation	= 5;
	_ShellDirInfo.YawFalloff		= 1;
	_ShellDirInfo.bRoll				= 0;
	_ShellDirInfo.RollMean			= 0;
	_ShellDirInfo.RollMaxDeviation	= 0;
	_ShellDirInfo.RollFalloff		= 0;
	_ShellDirInfo.SpeedMean			= 100;
	_ShellDirInfo.SpeedMaxDeviation	= 30;
	_ShellDirInfo.SpeedFalloff		= 1;
	_ShellDirInfo.Base				= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset			= FVector(3, 0, -6);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "Box08";
	_ShellOffset3P.VOffset			= FVector(0, 1, -4);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_bDelayShellEject				= true;
	_cMuzzleFlashClass				= AM24MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(4, 0, -44);
	_MuzzleOffset.ROffset			= FRotator(6.4984130859375, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	EnemyAttachmentClass			= AAttachW_M24_Sniper::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-mosin_nagant_sniper_rifle_3p.m-mosin_nagant_sniper_rifle_3p"), NULL, LOAD_None, NULL);
}