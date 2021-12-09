// All the original content belonged to the US Army


#include "AttachW_MP5_Rifle.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_9x39_Emitter/Shell_9x39_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_9mm_BS1_Emitter/Shell_9mm_BS1_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AK74suMuzzleFlash/AK74suMuzzleFlash.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M4A1_Rifle_Mod/AttachW_M4A1_Rifle_Mod.h"

AAttachW_MP5_Rifle::AAttachW_MP5_Rifle()
{
	_cShellEmitterClass					= AShell_9x39_Emitter::StaticClass();
	_ShellDirInfo.MeanDirection			= FVector(0, 0, 0);
	_ShellDirInfo.bPitch				= 1;
	_ShellDirInfo.PitchMean				= 25;
	_ShellDirInfo.PitchMaxDeviation		= 10;
	_ShellDirInfo.PitchFalloff			= 1;
	_ShellDirInfo.bYaw					= 1;
	_ShellDirInfo.YawMean				= 95;
	_ShellDirInfo.YawMaxDeviation		= 10;
	_ShellDirInfo.YawFalloff			= 1;
	_ShellDirInfo.bRoll					= 0;
	_ShellDirInfo.RollMean				= 0;
	_ShellDirInfo.RollMaxDeviation		= 0;
	_ShellDirInfo.RollFalloff			= 0;
	_ShellDirInfo.SpeedMean				= 500;
	_ShellDirInfo.SpeedMaxDeviation		= 200;
	_ShellDirInfo.SpeedFalloff			= 1;
	_ShellDirInfo.Base					= FRotator(0, 0, 0);
	_ShellOffset1P.VOffset				= FVector(-10, 5, 3);
	_ShellOffset1P.ROffset				= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone				= "Shell";
	_ShellOffset3P.VOffset				= FVector(0, 1, -5);
	_ShellOffset3P.ROffset				= FRotator(0, 0, 180);
	_ShellOffset3P.nBone				= "WeaponBone";
	_cAuxShellEmitterClass				= AShell_9mm_BS1_Emitter::StaticClass();
	_AuxShellDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AuxShellDirInfo.bPitch				= 1;
	_AuxShellDirInfo.PitchMean			= 25;
	_AuxShellDirInfo.PitchMaxDeviation	= 10;
	_AuxShellDirInfo.PitchFalloff		= 1;
	_AuxShellDirInfo.bYaw				= 1;
	_AuxShellDirInfo.YawMean			= 95;
	_AuxShellDirInfo.YawMaxDeviation	= 10;
	_AuxShellDirInfo.YawFalloff			= 1;
	_AuxShellDirInfo.bRoll				= 0;
	_AuxShellDirInfo.RollMean			= 0;
	_AuxShellDirInfo.RollMaxDeviation	= 0;
	_AuxShellDirInfo.RollFalloff		= 0;
	_AuxShellDirInfo.SpeedMean			= 100;
	_AuxShellDirInfo.SpeedMaxDeviation	= 15;
	_AuxShellDirInfo.SpeedFalloff		= 1;
	_AuxShellDirInfo.Base				= FRotator(0, 0, 0);
	_AuxShellOffset1P.VOffset			= FVector(0, 0, 0);
	_AuxShellOffset1P.ROffset			= FRotator(0, 0, 0);
	_AuxShellOffset1P.nBone				= "AuxBolt";
	_AuxShellOffset3P.VOffset			= FVector(-5, 0, -8);
	_AuxShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_AuxShellOffset3P.nBone				= "WeaponBone";
	_bAuxDelayShellEject				= true;
	_cMuzzleFlashClass					= AAK74suMuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset				= FVector(-2, 0, -20);
	_MuzzleOffset.ROffset				= FRotator(0, 0, 90);
	_MuzzleOffset.nBone					= "WeaponBone";
	EnemyAttachmentClass				= AAttachW_M4A1_Rifle_Mod::StaticClass();
	StaticMesh							= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2_wpn_mp5sd6_3p.m2_wpn_mp5sd6_3p"), NULL, LOAD_None, NULL);
}


void AAttachW_MP5_Rifle::AttachmentAnimation()
{
	//AttachmentAnimation();
	//Self.SetRelativeLocation(vect(0 0 - 1));
}