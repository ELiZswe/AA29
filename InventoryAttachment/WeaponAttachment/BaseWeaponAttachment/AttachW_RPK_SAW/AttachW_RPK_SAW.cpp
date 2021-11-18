// All the original content belonged to the US Army


#include "AttachW_RPK_SAW.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M249_SAW/AttachW_M249_SAW.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_762mm_Emitter/Shell_762mm_Emitter.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash/AK47MuzzleFlash.h"

AAttachW_RPK_SAW::AAttachW_RPK_SAW()
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
	_ShellOffset1P.VOffset			= FVector(7, -18, -8);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "M16-MagRound";
	_ShellOffset3P.VOffset			= FVector(0, 1, -6);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_cMuzzleFlashClass				= AAK47MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(0, 0, -36);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	SupportedStaticMesh				= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-rpk_sup_3p.m-rpk_sup_3p"), NULL, LOAD_None, NULL);
	EnemyAttachmentClass			= AAttachW_M249_SAW::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-rpk_3p.m-rpk_3p"), NULL, LOAD_None, NULL);
}