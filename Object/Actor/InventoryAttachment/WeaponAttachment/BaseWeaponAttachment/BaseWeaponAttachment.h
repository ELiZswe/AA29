// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "AA29/AA29.h"
#include "BaseWeaponAttachment.generated.h"

class AInventoryAttachment;
class ABase3pAmmoRound;
class AHumanController;
class AAGP_Weapon;
class ABaseMuzzleFlashEmitter;

UCLASS()
class AA29_API ABaseWeaponAttachment : public AWeaponAttachment
{
	GENERATED_BODY()
public:
	ABaseWeaponAttachment();

	
	UPROPERTY()		FName PrnFullReloadAnim;											//var name PrnFullReloadAnim;
	UPROPERTY()		FName PrnEmptyReloadAnim;											//var name PrnEmptyReloadAnim;
	UPROPERTY()		FName FullReloadAnim;												//var name FullReloadAnim;
	UPROPERTY()		FName EmptyReloadAnim;												//var name EmptyReloadAnim;
	UPROPERTY()		FName FixJamAnim;													//var name FixJamAnim;
	UPROPERTY()		FName IdleEmptyAnim;												//var name IdleEmptyAnim;
	UPROPERTY()		FName FireLastAnim;													//var name FireLastAnim;
	UPROPERTY()		FName FireAnim;														//var name FireAnim;
	UPROPERTY()		FName IdleAnim;														//var name IdleAnim;
	UPROPERTY()		FName PawnPrnReloadAnimation;										//var name PawnPrnReloadAnimation;
	UPROPERTY()		FName PawnStdReloadAnimation;										//var name PawnStdReloadAnimation;
	UPROPERTY()		bool bHasAttachmentReload;											//var bool bHasAttachmentReload;
	UPROPERTY()		bool bCurrentlySelectedAttachment;									//var bool bCurrentlySelectedAttachment;
	UPROPERTY()		bool bAttachMILES;													//var bool bAttachMILES;
	UPROPERTY()		bool _bAuxDelayShellEject;											//var bool _bAuxDelayShellEject;
	UPROPERTY()		bool _bDelayShellEject;												//var bool _bDelayShellEject;
	UPROPERTY()		FVector _WeaponOffset3P;											//var FVector _WeaponOffset3P;
	UPROPERTY()		UStaticMesh* NormalStaticMesh;										//var StaticMesh NormalStaticMesh;
	UPROPERTY()		UStaticMesh* SupportedStaticMesh;									//var StaticMesh SupportedStaticMesh;
	UPROPERTY()		ABase3pAmmoRound* AmmoRound3P;										//var Base3pAmmoRound AmmoRound3P;
	//UPROPERTY()	ALaserProjector* LaserSight;										//var LaserProjector LaserSight;
	//UPROPERTY()	AAttachmentHandler* AttachHandler;									//var AttachmentHandler AttachHandler;
	UPROPERTY()		AInventoryAttachment* BlankPlug;									//var InventoryAttachment BlankPlug;
	UPROPERTY()		AInventoryAttachment* MILESBox;										//var InventoryAttachment MILESBox;
	UPROPERTY()		FBoneOffset _AuxMuzzleOffset;										//var Object.BoneOffset _AuxMuzzleOffset;
	UPROPERTY()		FBoneOffset _MuzzleOffset;											//var Object.BoneOffset _MuzzleOffset;
	UPROPERTY()		TSubclassOf<ABaseMuzzleFlashEmitter> _AuxMuzzleFlashEmitter;		//var AGP_Effects.BaseMuzzleFlashEmitter _AuxMuzzleFlashEmitter;
	UPROPERTY()		TSubclassOf<ABaseMuzzleFlashEmitter> _cAuxMuzzleFlashClass;			//var class<AGP_Effects.BaseMuzzleFlashEmitter> _cAuxMuzzleFlashClass;
	UPROPERTY()		TSubclassOf<ABaseMuzzleFlashEmitter> _MuzzleFlashEmitter;			//var AGP_Effects.BaseMuzzleFlashEmitter _MuzzleFlashEmitter;
	UPROPERTY()		TSubclassOf<ABaseMuzzleFlashEmitter> _cMuzzleFlashClass;			//var class<AGP_Effects.BaseMuzzleFlashEmitter> _cMuzzleFlashClass;
	UPROPERTY()		FBoneOffset _AuxShellOffset3P;										//var Object.BoneOffset _AuxShellOffset3P;
	UPROPERTY()		FBoneOffset _AuxShellOffset1P;										//var Object.BoneOffset _AuxShellOffset1P;
	UPROPERTY()		FRotationRandomizer _AuxShellDirInfo;								//var Object.RotationRandomizer _AuxShellDirInfo;
	UPROPERTY()		FBoneOffset _ShellOffset3P;											//var Object.BoneOffset _ShellOffset3P;
	UPROPERTY()		FBoneOffset _ShellOffset1P;											//var Object.BoneOffset _ShellOffset1P;
	UPROPERTY()		FRotationRandomizer _ShellDirInfo;									//var Object.RotationRandomizer _ShellDirInfo;
	UPROPERTY()		TSubclassOf<class ABaseShellEmitter> _AuxShellEmitter;				//var AGP_Effects.BaseShellEmitter _AuxShellEmitter;
	UPROPERTY()		TSubclassOf<class ABaseShellEmitter> _ShellEmitter;					//var AGP_Effects.BaseShellEmitter _ShellEmitter;
	UPROPERTY()		TSubclassOf<class ABaseShellEmitter> _cAuxShellEmitterClass;		//var class<AGP_Effects.BaseShellEmitter> _cAuxShellEmitterClass;
	UPROPERTY()		TSubclassOf<class ABaseShellEmitter> _cShellEmitterClass;			//var class<AGP_Effects.BaseShellEmitter> _cShellEmitterClass;



	bool GetbIsDetaching();
	void SetbIsDetaching(bool Detach);
	void PreBeginPlay();
	void InitializeShellEmitter();
	void GetStaticMesh(bool bFriendly);
	void GetMesh(bool bFriendly);
	void NotifyNewMesh(bool bFriendly);
	void SetupForClass(ABaseWeaponAttachment* NewClass);
	void GetPawnReloadAnimation();
	void PlayAttachmentReload(int32 SpecialReload);
	void GetSource();
	bool CanHaveMILES();
	void SetLaser();
	void NotifyWeaponAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop);
	void NotifyBaseChange();
	void AdjustAttachmentFor(AInventory* Inv);
	uint8 AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv);
	void IsAnimState(uint8 test_byte);
	void IsNotUS(APawn* p);
	void AttachmentAnimation();
	void GetSuppressor();
	void SpawnModAttachments(AAGP_Weapon* W);
	void SpawnMILESAttachments();
	void AttachToMe(AInventoryAttachment* att);
	void Destroyed();
	void CleanUp();
	void InitFor(AInventory* i);
	void GetShellEmitter();
	void GetDelayShellEject();
	void SpawnShellEmitters();
	void SpawnMuzzleFlashEmitters();
	void GetMuzzleFlashEmitter();
	void DoDelayedShell();
	void ThirdPersonEffects();
	void ThirdPersonEffectsEject(AHumanController* HC);
	void ThirdPersonEffectsMuzzleFlash(AHumanController* HC);
	void ShouldDoTraceEffects();
	void ThirdPersonTrace();
	void DoEffectTrace(AActor* TraceFrom, FVector StartTrace, int32 end_trace, bool bDoExit);
	void BulletExitTrace(AActor* TraceFrom, FVector StartTrace, FVector EndTrace);
	void GetBulletImpactType(int32 trace_index);
	void SetBulletImpactType(int32 trace_index, EBulletImpactType new_type);
	void DoBulletEffect(AActor* HitActor, UTexture2D* HitMaterial, FVector HitLocation, FVector HitNormal, EBulletImpactType BType);

};
