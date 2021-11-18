// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "WEAPON_Javelin.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWEAPON_Javelin : public ARocketWeapon
{
	GENERATED_BODY()
public:
	AWEAPON_Javelin();
	
	UPROPERTY()										float fpTimeReloadNextAllowed;		//var float fpTimeReloadNextAllowed;
	UPROPERTY()										uint8 CurrentJRA;					//var byte CurrentJRA;
	UPROPERTY()										bool bWasZoomed;					//var bool bWasZoomed;
	UPROPERTY()										bool bUseNV;						//var bool bUseNV;
	UPROPERTY()										USoundBase* TopAttackSound;			//var Sound TopAttackSound;
	UPROPERTY()										USoundBase* DirectAttackSound;		//var Sound DirectAttackSound;
	UPROPERTY()										USoundBase* CLU_Fan;				//var Sound CLU_Fan;
	UPROPERTY()										USoundBase* UnZoomSound;			//var Sound UnZoomSound;
	UPROPERTY()										USoundBase* ZoomSound;				//var Sound ZoomSound;
	UPROPERTY()										USoundBase* LockFail;				//var Sound LockFail;
	UPROPERTY()										USoundBase* UnloadEmpty;			//var Sound UnloadEmpty;
	UPROPERTY()										USoundBase* UnloadFull;				//var Sound UnloadFull;
	UPROPERTY()										USoundBase* MissileBitError;		//var Sound MissileBitError;
	UPROPERTY()										USoundBase* LockedOnSound;			//var Sound LockedOnSound;
	UPROPERTY()										USoundBase* LockTone;				//var Sound LockTone;
	UPROPERTY()										USoundBase* SeekOff;				//var Sound SeekOff;
	UPROPERTY()										USoundBase* SeekOn;					//var Sound SeekOn;
	UPROPERTY()										USoundBase* ChangeViewMode;			//var Sound ChangeViewMode;
	UPROPERTY()										USoundBase* NV_Sound;				//var Sound NV_Sound;
	//UPROPERTY()									AAttch_CLUpack* CLUpack;		//var Attch_CLUpack CLUpack;
	UPROPERTY()										float MisFireChance;				//var float MisFireChance;
	UPROPERTY()										float old_total_count;				//var float old_total_count;
	UPROPERTY()										float accuracy_count;				//var float accuracy_count;
	UPROPERTY()										float total_count;					//var float total_count;
	UPROPERTY()										float LockOn_Time;					//var float LockOn_Time;
	UPROPERTY()										float acc_check;					//var float acc_check;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MinRangeTop;					//var(Javelin) int MinRangeTop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MinRangeDirect;				//var(Javelin) int MinRangeDirect;
	UPROPERTY()										FName ReloadTubeEmpty;				//var name ReloadTubeEmpty;
	UPROPERTY()										FVector NewHomingLocation;			//var FVector NewHomingLocation;
	UPROPERTY()										FVector HitLocation;				//var FVector HitLocation;
	//UPROPERTY()									AJav_Target* J_Target;			//var Jav_Target J_Target;
	//UPROPERTY()									AScopeW_Javelin* myscope;		//var ScopeW_Javelin myscope;
	UPROPERTY()										AActor* HomingTarget;				//var Actor HomingTarget;
	UPROPERTY()										bool bWas9x;						//var bool bWas9x;
	UPROPERTY()										bool bNVWasOn;						//var bool bNVWasOn;
	UPROPERTY()										bool bForceMisfire;					//var bool bForceMisfire;
	UPROPERTY()										bool bTooClose;						//var bool bTooClose;
	UPROPERTY()										bool bDisableNV;					//var bool bDisableNV;
	UPROPERTY()										bool bCanMisFire;					//var bool bCanMisFire;
	UPROPERTY()										bool bWantsToSwap;					//var bool bWantsToSwap;
	UPROPERTY()										bool bTargetIsVisible;				//var bool bTargetIsVisible;
	UPROPERTY()										bool bAttachingTube;				//var bool bAttachingTube;
	UPROPERTY()										bool bTubeAttached;					//var bool bTubeAttached;
	UPROPERTY()										bool bSeekOn;						//var bool bSeekOn;
	UPROPERTY()										bool bDirectFire;					//var bool bDirectFire;
	UPROPERTY()										bool bIsActive;						//var bool bIsActive;
	UPROPERTY()										bool bLockedOn;						//var bool bLockedOn;

	//void DisplayDebug(UCanvas* Canvas, float YL, float YPos);
	void SpawnTubePickup();
	void DropFrom(FVector StartLocation, bool bAttach);
	virtual bool CheckForNoReload() override;
	virtual void PlayReloading() override;
	void ShouldDoDelayedEject();
	void SetbTubeAttached(bool Tube);
	virtual void Reload() override;
	void Set_bAttachingTube();
	void ReloadClip(uint8 newclip);
	void SpawnTube();
	void NPC_Fire(float Value, APawn* Enemy);
	void NPC_ProjectileFire();
	void ClientAdjustAmmoRound(bool bRemove);
	void AdjustAmmoRound();
	//void StaticPrecache (LevelInfo L);
	void IsJavelin();
	virtual void TweenDown() override;
	virtual void PlaySelect() override;
	void JavelinPlaySound(USoundBase* SoundName);
	void JavelinStopSound(USoundBase* SoundName);
	void PostBeginPlay();
	void CanLean();
	void GiveTo(APawn* Other, APickup* Pickup);
	void MaybeSwapBinocs();
	void SwapWeapons();
	void GetSwapContainer();
	void Destroyed();
	void SpawnAndAttachScope();
	bool CanUseWeapon(int32 DesiredAction);
	void FixSynch();
	void SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial);
	void GetBreatheMultiplier();
	virtual bool CanSprint() override;
	bool CheckJavelinTube();
	virtual void FixJam() override;
	void ClientSetUpCLUPack(bool bSetUp);
	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
	virtual void Fire(float Value) override;
	void ProjectileFire();
	void ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus);
	void CheckTarget();
	void FailedSupported();
	void FireMode();
	void Target_Lock();
	void CancelLock(bool KeepSeekOn);
	void Spawn_J_Target();
	void CheckDistance(AActor* Target);
	void JavTrace();
	void SetSeekViewMode();
	virtual void AltFire(float Value) override;
	void Toggle_bLockedOn();
	void GetJ_Target();
	void GetHomingTarget();
	bool GetbTooClose();
	void SetHomingTarget(AActor* Target);
	void RememberViewMode();
	void SetPreviousViewMode();
	void NV();
	void ToggleZoom();
	virtual void Zoom() override;
	virtual void UnZoom() override;
	void ToggleVision(bool TurnOn);
	void CycleZoom();
	bool GetbIsActive();
	bool GetbSeekOn();
	bool GetbDirectFire();
	bool GetbLockedOn();
	void SetbIsActive(bool _bIsActive);
	void Toggle_bIsActive(bool TurnOn);
	void Set_NV();
	bool ShouldDrawCrosshair();
	void TrackLength(UCanvas* Canvas, int32 Direction, FVector TargetLocation);
	void SimTrace(FVector TraceVec);
	void SetScopeVar();
	void RunAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop);
	void ServerJamit();
	void ServerUnJamit();
	void ShowProjectileView();
	void ProjectileCalcView(AActor* ViewActor, FVector CameraLocation, FRotator CameraRotation);

};
