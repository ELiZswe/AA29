// All the original content belonged to the US Army


#include "AttachW_T62_Coax.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Shell_127mm_Emitter/Shell_127mm_Emitter.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash/AK47MuzzleFlash.h"


AAttachW_T62_Coax::AAttachW_T62_Coax()
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
	_cMuzzleFlashClass				= AAK47MuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(200, 0, 0);
	_MuzzleOffset.ROffset			= FRotator(-90, -90, 90);
	_MuzzleOffset.nBone				= "WeaponBone";
	SupportedStaticMesh				= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Vehicles/T-62/m_vehi_T_62_coax_gun.m_vehi_T_62_coax_gun"), NULL, LOAD_None, NULL);
	EnemyAttachmentClass			= AAttachW_T62_Coax::StaticClass();
	StaticMesh						= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Vehicles/T-62/m_vehi_T_62_coax_gun.m_vehi_T_62_coax_gun"), NULL, LOAD_None, NULL);
}


void AAttachW_T62_Coax::SpawnMILESAttachments()
{
}
void AAttachW_T62_Coax::AttachToMe(AInventoryAttachment* att)
{
}
void AAttachW_T62_Coax::AdjustAttachmentFor(AInventory* Inv)
{
}
void AAttachW_T62_Coax::PostBeginPlay()
{
	/*
	PostBeginPlay();
	SetRelativeLocation(vect(-295 0 - 25));
	SetRelativeRotation(rot(32768 - 32768 - 16384));
	*/
}
void AAttachW_T62_Coax::SpawnMuzzleFlashEmitters()
{
	/*
	local Actor AttachTo;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		Return;
	}
	if (_MuzzleFlashEmitter == None && _cMuzzleFlashClass != None)
	{
		_MuzzleFlashEmitter = Spawn(_cMuzzleFlashClass, GetSource());
		_MuzzleFlashEmitter.bRenderAttachmentSeperately = true;
		Vehicle(GetSource()).GetActiveWeaponSystem().AttachToBone(_MuzzleFlashEmitter, 'Muzzle_Bone');
		_MuzzleFlashEmitter.SetRelativeLocation(vect(-214 - 4 - 25));
		_MuzzleFlashEmitter.SetRelativeRotation(rot(0 0 - 32768) + Vehicle(GetSource()).GetActiveWeaponSystem().Rotation);
	}
	if (_AuxMuzzleFlashEmitter == None && _cAuxMuzzleFlashClass != None)
	{
		_AuxMuzzleFlashEmitter = Spawn(_cAuxMuzzleFlashClass, GetSource());
		_AuxMuzzleFlashEmitter.bRenderAttachmentSeperately = true;
		AttachTo.AttachToBoneOffset(_AuxMuzzleFlashEmitter, _AuxMuzzleOffset);
	}
	*/
}
