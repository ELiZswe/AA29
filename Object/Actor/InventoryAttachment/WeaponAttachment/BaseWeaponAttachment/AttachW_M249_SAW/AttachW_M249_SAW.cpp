// All the original content belonged to the US Army


#include "AttachW_M249_SAW.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_RPK_SAW/AttachW_RPK_SAW.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_556mm_Emitter/Shell_556mm_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M249MuzzleFlash/M249MuzzleFlash.h"

AAttachW_M249_SAW::AAttachW_M249_SAW()
{
	_cShellEmitterClass				= AShell_556mm_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ShellDirInfo.bPitch			= 1;
	_ShellDirInfo.PitchMean			= 30;
	_ShellDirInfo.PitchMaxDeviation	= 10;
	_ShellDirInfo.PitchFalloff		= 1;
	_ShellDirInfo.bYaw				= 1;
	_ShellDirInfo.YawMean			= 100;
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
	_ShellOffset1P.VOffset			= FVector(11, 7, -7);
	_ShellOffset1P.VOffset			= FVector(-90, 0, 0);
	_ShellOffset1P.nBone			= "M249Charger";
	_ShellOffset3P.VOffset			= FVector(0, 1, -45);
	_ShellOffset3P.VOffset			= FVector(0, 0, 180);
	_ShellOffset3P.nBone			= "WeaponBone";
	_cMuzzleFlashClass				= AM249MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(4, 0, -30);
	_MuzzleOffset.ROffset			= FRotator(4.998779296875, 0, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	SupportedStaticMesh				= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m249_sup_3p.m-m249_sup_3p"), NULL, LOAD_None, NULL);
	EnemyAttachmentClass			= AAttachW_RPK_SAW::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m249_3p.m-m249_3p"), NULL, LOAD_None, NULL);
}