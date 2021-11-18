// All the original content belonged to the US Army


#include "AttachW_M203_Gren.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_GP30_Gren/AttachW_GP30_Gren.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash/M16A2MuzzleFlash.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_40mm_Emitter/Shell_40mm_Emitter.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_556mm_Emitter/Shell_556mm_Emitter.h"

AAttachW_M203_Gren::AAttachW_M203_Gren()
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
	_ShellOffset3P.VOffset			= FVector(125, 1, -225);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_cAuxShellEmitterClass			= AShell_40mm_Emitter::StaticClass();
	_AuxShellOffset1P.VOffset		= FVector(30, 0, -15);
	_AuxShellOffset1P.ROffset		= FRotator(0, 0, 0);
	_AuxShellOffset1P.nBone			= "40mmShell";
	_AuxShellOffset3P.VOffset		= FVector(-5, 0, -8);
	_AuxShellOffset3P.ROffset		= FRotator(0, 0, 180);
	_AuxShellOffset3P.nBone			= "WeaponBone";
	_bAuxDelayShellEject			= true;
	_cMuzzleFlashClass				= AM16A2MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(55, 0, -34);
	_MuzzleOffset.ROffset			= FRotator(7.998046875, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	EnemyAttachmentClass			= AAttachW_GP30_Gren::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m16a2_m203_3p.m-m16a2_m203_3p"), NULL, LOAD_None, NULL);
}