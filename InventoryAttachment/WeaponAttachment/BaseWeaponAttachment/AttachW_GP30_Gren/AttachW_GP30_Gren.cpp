// All the original content belonged to the US Army


#include "AttachW_GP30_Gren.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M203_Gren/AttachW_M203_Gren.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_762mm_Emitter/Shell_762mm_Emitter.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash/AK47MuzzleFlash.h"

AAttachW_GP30_Gren::AAttachW_GP30_Gren()
{
	_cShellEmitterClass				= AShell_762mm_Emitter::StaticClass();
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
	_ShellOffset1P.VOffset			= FVector(7, -10, 8);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "M16-MagRound";
	_ShellOffset3P.VOffset			= FVector(2, 1, -6);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_cMuzzleFlashClass				= AAK47MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(0, 0, -34);
	_MuzzleOffset.ROffset			= FRotator(1.0986328125, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	EnemyAttachmentClass			= AAttachW_M203_Gren::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-ak74_gp30_40mm_3p.m-ak74_gp30_40mm_3p"), NULL, LOAD_None, NULL);
}