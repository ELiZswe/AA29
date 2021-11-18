// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Inventory.h"

#include "AA29/AA29.h"
#include "AA29/DamageType/aDamageType.h"
#include "Weapon.generated.h"

/**
 * 
 */



UCLASS()
class AA29_API AWeapon : public AInventory
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AWeapon();

	UPROPERTY()																bool bGuerrillaWeapon;						//var bool bGuerrillaWeapon;
	UPROPERTY()																bool bIsRuined;								//var bool bIsRuined;
	UPROPERTY()																bool bIsJammed;								//var bool bIsJammed;
	UPROPERTY()																bool bMisFireOnRapid;						//var bool bMisFireOnRapid;
	UPROPERTY()																bool bMisFire;								//var bool bMisFire;
	UPROPERTY()																bool _bTossNotThrow;						//var bool _bTossNotThrow;
	UPROPERTY()																bool bIsSupported;							//var bool bIsSupported;
	UPROPERTY()																bool bCanSupport;							//var bool bCanSupport;
	UPROPERTY()																bool bMuzzleFlashParticles;					//var bool bMuzzleFlashParticles;
	UPROPERTY()																bool bDrawMuzzleFlash;						//var bool bDrawMuzzleFlash;
	UPROPERTY()																bool bSetFlashTime;							//var bool bSetFlashTime;
	UPROPERTY()																bool bMuzzleFlash;							//var bool bMuzzleFlash;
	UPROPERTY()																bool bAutoFire;								//var bool bAutoFire;
	UPROPERTY()																bool bForceAltFire;							//var bool bForceAltFire;
	UPROPERTY()																bool bForceFire;							//var bool bForceFire;
	UPROPERTY()																bool bSteadyToggle;							//var bool bSteadyToggle;
	UPROPERTY()																bool bDebugging;							//var bool bDebugging;
	UPROPERTY()																bool bSniping;								//var bool bSniping;			
	UPROPERTY()																bool bMeleeWeapon;							//var bool bMeleeWeapon;
	UPROPERTY()																bool bHasBackBlast;							//var bool bHasBackBlast;
	UPROPERTY()																bool bLongTargetTrace;						//var bool bLongTargetTrace;
	UPROPERTY()																bool bSpectated;							//var bool bSpectated;
	UPROPERTY()																bool bForceReload;							//var bool bForceReload;
	UPROPERTY()																bool bRapidFire;							//var bool bRapidFire;	
	UPROPERTY()																bool bCanThrow;								//var bool bCanThrow;
	UPROPERTY()																bool bChangeWeapon;							//var bool bChangeWeapon;
	UPROPERTY()																bool bWeaponUp;								//var bool bWeaponUp;
	UPROPERTY()																bool bPointing;								//var bool bPointing;
	UPROPERTY()																ENewAuxMode NewAuxMode;						//var ENewAuxMode NewAuxMode;
	UPROPERTY()																RateofFire eROF;							//var RateofFire 
	UPROPERTY()																EWeaponType weaponType;						//var EWeaponType weaponType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								EWeaponClientState ClientState;				//var () EWeaponClientState ClientState;
	UPROPERTY()																int32 AutoSwitchPriority;					//var int AutoSwitchPriority;
	UPROPERTY()																int32 iNextMisFire;							//var int iNextMisFire;
	UPROPERTY()																int32 iMisFire;								//var int iMisFire;
	UPROPERTY()																int32 AuxPickupAmmoCount;					//var int AuxPickupAmmoCount;
	UPROPERTY()																int32 PickupAmmoCount;						//var int PickupAmmoCount;
	UPROPERTY()																float ShakeTime;							//var float ShakeTime;
	UPROPERTY()																float ShakeMag;								//var float ShakeMag;
	UPROPERTY()																float StopFiringTime;						//var float StopFiringTime;
	UPROPERTY()																float WallTraceDist;						//var float WallTraceDist;
	UPROPERTY()																float fZoomAnimTime;						//var float fZoomAnimTime;
	UPROPERTY()																float fZoomAnimFOV;							//var float fZoomAnimFOV;
	UPROPERTY()																float FireAdjust;							//var float FireAdjust;
	UPROPERTY()																float MuzzleFlashScale;						//var float MuzzleFlashScale;
	UPROPERTY()																float FlashTime;							//var float FlashTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzleFlash)		float MuzzleFlashSize;						//var (MuzzleFlash) float MuzzleFlashSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzleFlash)		float FlashLength;							//var (MuzzleFlash) float FlashLength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzleFlash)		float FlashOffsetX;							//var (MuzzleFlash) float FlashOffsetX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzleFlash)		float FlashOffsetY;							//var (MuzzleFlash) float FlashOffsetY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzleFlash)		float MuzzleScale;							//var (MuzzleFlash) float MuzzleScale;
	UPROPERTY()																float DisplayFOV;							//var float DisplayFOV;
	UPROPERTY()																float MaxRange;								//var float MaxRange;
	UPROPERTY()																float TraceDist;							//var float TraceDist;
	UPROPERTY()																float CurrentRating;						//var float CurrentRating;
	UPROPERTY()																float AIRating;								//var float AIRating;
	UPROPERTY()																float aimerror;								//var float aimerror;
	UPROPERTY()																float BackBlastDamage;						//var float BackBlastDamage;
	UPROPERTY()																float BackBlastCone;						//var float BackBlastCone;	
	UPROPERTY()																float BackBlastRadius;						//var float BackBlastRadius;
	UPROPERTY()																float TraceAccuracy;						//var float TraceAccuracy;
	UPROPERTY()																TArray<uint8> _AuxAmmoClips;				//var byte _AuxAmmoClips;
	UPROPERTY()																TArray<uint8> _AmmoClips;					//var byte _AmmoClips;
	UPROPERTY()																uint8 AuxAmmoMagCount;						//var byte AuxAmmoMagCount;
	UPROPERTY()																uint8 FlashCount;							//var byte FlashCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								uint8 Priority;								//var () config byte Priority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								uint8 ExchangeFireModes;					//var () config byte ExchangeFireModes;
	UPROPERTY()																uint8 AmmoMagCount;							//var byte AuxAmmoMagCount;
	UPROPERTY()																uint8 ReloadCount;							//var byte ReloadCount;
	UPROPERTY()																FVector vZoomAnimOffset;					//var FVector vZoomAnimOffset;
	UPROPERTY()																FVector BackFireOffset;						//var FVector BackFireOffset;
	UPROPERTY()																FVector ShakeSpeed;							//var FVector ShakeSpeed;
	UPROPERTY()																FVector ShakeVert;							//var FVector ShakeVert;
	UPROPERTY()																FVector FireOffset;							//var FVector FireOffset;
	UPROPERTY()																FRotator rSupportedLimit;					//var Object.Rotator rSupportedLimit;
	UPROPERTY()																FRotator AdjustedAim;						//var Object.Rotator AdjustedAim;
	UPROPERTY()																FString LeftHandedMesh;						//var string LeftHandedMesh;
	UPROPERTY()																FString WeaponDescription;					//var localized string WeaponDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString MessageNoAmmo;						//var () localized string MessageNoAmmo;
	UPROPERTY()																FName ReloadProne3PAnim;					//var name ReloadProne3PAnim;
	UPROPERTY()																FName ReloadStanding3PAnim;					//var name ReloadStanding3PAnim;
	UPROPERTY()																FColor NameColor;							//var Object.Color NameColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								USoundBase* SelectSound;					//var () Sound SelectSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								USoundBase* FireSound;						//var () Sound FireSound;
	UPROPERTY()																UTexture2D* tSupportIcon;					//var Texture tSupportIcon;
	UPROPERTY()																UTexture2D* MuzzleFlashTexture;				//var Texture MuzzleFlashTexture;
	UPROPERTY()																UTexture2D* MFTexture;						//var Texture MFTexture;
	UPROPERTY()																UTexture2D* CrossHair;						//var Texture CrossHair;
	UPROPERTY()																TSubclassOf<class AProjectile> _Projectile;	//var Projectile _Projectile;
	UPROPERTY()																class AAmmunition* AmmoType;				//var class<Ammunition> AmmoType;					// Inventory Ammo being used.
	UPROPERTY()																TSubclassOf<class AAmmunition> AmmoName;	//var class<Ammunition> AmmoName;					// Type of ammo used.
	UPROPERTY()																AAmmunition* AuxAmmoType;					//var travel Ammunition AuxAmmoType;		
	UPROPERTY()																TSubclassOf<class AAmmunition> AuxAmmoName;	//var class<Ammunition> AuxAmmoName;
	UPROPERTY()																UStaticMesh* MuzzleFlashMesh;				//var Mesh MuzzleFlashMesh;
	UPROPERTY()																FRotationRandomizer _AccuracyDirInfo;		//var Object.RotationRandomizer _AccuracyDirInfo;
	UPROPERTY()																FRotationRandomizer _ZoomDirInfo;			//var Object.RotationRandomizer _ZoomDirInfo;
	//UPROPERTY()															UStaticMesh* MuzzleFlashMesh;				//var Mesh MuzzleFlashMesh;
	UPROPERTY()																ERenderStyle MuzzleFlashStyle;				//var Actor.ERenderStyle MuzzleFlashStyle;
	
	//var() EWeaponClientState ClientState;
	//var Powerups Affector;						var Powerups Affector;



	void CanCombatRoll(bool bActual);
	virtual bool CanSprint();
	virtual bool IsBusy();
	bool CanUseWeapon(int DesiredAction);
	bool IsTempBusy();
	bool IsCrawling();
	bool ShouldDrawCrosshair();
	void ClientBringUp();
	void ClientPutDown();
	void OwnerRecieved();
	void DiscardShell();
	bool ShouldDoDelayedEject();
	void UpdateCurrentAmmoRounds(bool bRoundInBreech);
	void SetAltFireNotified(bool bNotify);
	bool IsAltFireNotified();
	void SetFastMove(bool fast);
	void SetSupported(bool newSupported);
	void SetGuerrillaWeapon(bool newGuerrillaWeap);
	void FailedSupported();
	UFUNCTION()		bool IsSupported();
	void CalcZoomWander();
	void GetSupportIcon();
	void StartCrawling();
	void StopCrawling();
	bool IsSuppressed();
	void ToggleSuppressor();
	void ToggleLeftRail();
	void ToggleRightRail();
	bool ShouldBreatheCycle();
	bool IsZoomed();
	float GetZoomMultiplier();
	void CycleZoom();
	void ToggleZoom();
	void ForceUnzoom(bool bForce);
	virtual void Zoom();
	virtual void UnZoom();
	void ScopeAdjust(bool Vertical, bool increase);
	void ZeroScope();
	virtual void FixJam();
	void ServerFixJam();
	virtual void ChangeFireMode();
	void ServerChangeFireMode();
	virtual void Reload();
	bool ShouldRenderWeapon();
	float GetSoundDampening();
	void GuardWeapon();
	void TempLowerWeapon(bool bActive);
	void ClientTempLowerWeapon( bool bActive);
	void TempRaiseWeapon();
	void GetUpperBodyReadyAnim();
	bool CheckJavelinTube();
	void NV();
	void SetbTubeAttached(bool Tube);
	bool CanLean();
	void AdjustAmmoRound();
	float RangedAttackTime();
	bool RecommendRangedAttack();
	bool SplashDamage();
	float GetDamageRadius();
	bool FocusOnLeader(bool bLeaderFiring);
	float RefireRate();
	bool RecommendSplashDamage();
	void FireHack(uint8 Mode);
	void IsFiring();
	void AdjustPlayerDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType);
	void IncrementFlashCount();
	void ForceReload();
	void ServerForceReload();
	void ClientForceReload();
	//void DisplayDebug(UCanvas* Canvas, float YL, float YPos);
	void AttachToBack();
	void TravelPostAccept();
	void SetAITarget(AActor* t);
	//void Destroyed();
	void GiveTo(APawn* Other, APickup* Pickup);
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
	void DrawCrossHair(UCanvas* Canvas);
	void DrawMuzzleFlash(UCanvas* Canvas);
	void CanAttack(AActor* Other);
	float AmmoStatus();
	bool HasAmmo();
	bool SplashJump();
	float GetRating();
	float RateSelf();
	float GetAIRating();
	float SuggestAttackStyle();
	float SuggestDefenseStyle();
	void ClientWeaponEvent(FName EventType);
	void HandlePickupQuery(APickup* Item);
	void SetHand(float hand);
	void GetViewAxes(FVector XAxis, FVector YAxis, FVector ZAxis);
	void WeaponChange(uint8 F, bool bSilent);
	void PrevWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon);
	void NextWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon);
	void AnimEnd(int32 Channel);
	void GiveAmmo(APawn* Other);
	void SwitchPriority();
	void ClientWeaponSet(bool bOptionalSet);
	void RecommendWeapon(float rating);
	void DropFrom(FVector StartLocation,  bool bAttach);
	bool RepeatFire();
	void ServerStopFiring();
	void ServerRapidFire();
	void ServerFire( bool bNoAdjustAim,  bool bRapid,  bool bBreatheBonus);
	virtual void Fire(float Value);
	void NPC_Fire(float Value, APawn* Enemy);
	void LocalFire();
	void ServerAltFire();
	virtual void AltFire(float Value);
	virtual void PlayFiring();
	void GetFireStart(FVector X, FVector Y, FVector Z);
	void ProjectileFire();
	void NPC_ProjectileFire();
	void TraceFire(float Accuracy, float YOffset, float ZOffset);
	void NeedsToReload();
	void BotFire(bool bFinished,  FName FiringMode);
	bool IsIdle();
	void Finish();
	void SwitchToWeaponWithAmmo();
	void CauseAltFire();
	void ClientFinish();
	void CheckAnimating();
	void ImmediateStopFire();
	virtual void BringUp();
	virtual bool PutDown();
	virtual void TweenDown();
	virtual void PlayReloading();
	virtual void PlaySelect();
	void PlayPostSelect();
	virtual void PlayIdleAnim();
	TSubclassOf<class AAmmunition> GetCurrentAmmoName();
	AAmmunition* GetCurrentAmmoType();
	void SetCurrentAmmoType(AAmmunition* newAmmoType);
	void SetCurrentAmmoName(AAmmunition* newAmmoName);
	void NotifyAddAmmo(AAmmunition* NewAmmo);
	void NotifyDeleteAmmo(AAmmunition* OldAmmo);
	virtual void RecountAmmo();
	virtual int32 GetClipCount(uint8 clip,  bool bAuxAmmo);
	virtual bool CheckForNoReload();
	uint8 GetBestClip();
	void ReloadClip(uint8 newclip);
	bool ShowProjectileView();
	void ProjectileCalcView(AActor* ViewActor, FVector CameraLocation, FRotator CameraRotation);
};
