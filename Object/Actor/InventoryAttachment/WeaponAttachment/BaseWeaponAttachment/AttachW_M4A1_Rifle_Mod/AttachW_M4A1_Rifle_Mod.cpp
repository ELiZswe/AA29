// All the original content belonged to the US Army


#include "AttachW_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_AK74su_Rifle/AttachW_AK74su_Rifle.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_556mm_Emitter/Shell_556mm_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_40mm_Emitter/Shell_40mm_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash/M16A2MuzzleFlash.h"

AAttachW_M4A1_Rifle_Mod::AAttachW_M4A1_Rifle_Mod()
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
	_cAuxShellEmitterClass			= AShell_40mm_Emitter::StaticClass();
	_AuxShellOffset1P.VOffset		= FVector(2, -18, 5);
	_AuxShellOffset1P.ROffset		= FRotator(0, 0, 0);
	_AuxShellOffset1P.nBone			= "AuxAmmo01";
	_AuxShellOffset3P.VOffset		= FVector(-5, 0, -8);
	_AuxShellOffset3P.ROffset		= FRotator(0, 0, 180);
	_AuxShellOffset3P.nBone			= "WeaponBone";
	_bAuxDelayShellEject			= true;
	_cMuzzleFlashClass				= AM16A2MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(0, 0, 0);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 0);
	_MuzzleOffset.nBone				= "Muzzle";
	EnemyAttachmentClass			= AAttachW_AK74su_Rifle::StaticClass();
	DrawType						= EDrawType::DT_Mesh;
	Mesh							= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/m4a1_3P.m4a1_3P"), NULL, LOAD_None, NULL);
}