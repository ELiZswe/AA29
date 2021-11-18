// All the original content belonged to the US Army


#include "AttachW_M82_Sniper.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_SVD_Sniper/AttachW_SVD_Sniper.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_127mm_Emitter/Shell_127mm_Emitter.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/M82MuzzleFlash/M82MuzzleFlash.h"

AAttachW_M82_Sniper::AAttachW_M82_Sniper()
{
	
	_cShellEmitterClass				= AShell_127mm_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= 45;
	_ShellDirInfo.PitchMaxDeviation	= 10;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 120;
	_ShellDirInfo.YawMaxDeviation	= 10;
	_ShellDirInfo.YawFalloff		= 1;
	_ShellDirInfo.bRoll				= 0;
	_ShellDirInfo.RollMean			= 0;
	_ShellDirInfo.RollMaxDeviation	= 0;
	_ShellDirInfo.RollFalloff		= 0;
	_ShellDirInfo.SpeedMean			= 100;
	_ShellDirInfo.SpeedMaxDeviation	= 20;
	_ShellDirInfo.SpeedFalloff		= 1;
	_ShellDirInfo.Base				= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset			= FVector(11, -18, -10);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "Box07";
	_ShellOffset3P.VOffset			= FVector(1, 1, -3);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_cMuzzleFlashClass				= AM82MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(-5, 0, -50);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	SupportedStaticMesh				= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m82a1_sup_3p.m-m82a1_sup_3p"), NULL, LOAD_None, NULL);
	EnemyAttachmentClass			= AAttachW_SVD_Sniper::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m82a1_3p.m-m82a1_3p"), NULL, LOAD_None, NULL);
}