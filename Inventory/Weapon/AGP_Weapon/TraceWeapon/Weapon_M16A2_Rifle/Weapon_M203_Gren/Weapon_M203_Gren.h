// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "Weapon_M203_Gren.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_M203_Gren : public AWeapon_M16A2_Rifle
{
	GENERATED_BODY()
public:
	AWeapon_M203_Gren();

	
	UPROPERTY()		bool bSwitchToGrenade;							//var bool bSwitchToGrenade;
	//UPROPERTY()	bool _SavedMuzzleFlash;							//var AGP_Effects.BaseMuzzleFlashEmitter _SavedMuzzleFlash;
	UPROPERTY()		UTexture2D* MuzzleFlashTextureGrenade;			//var Texture MuzzleFlashTextureGrenade;
	UPROPERTY()		UTexture2D* MuzzleFlashTextureNormal;			//var Texture MuzzleFlashTextureNormal;



	void SetClipCount(uint8 clip, int32 Count, bool bAuxAmmo);
	void Destroyed();
	void BeginPlay();
	virtual bool IsJammed() override;
	void PlayChangeFireMode();
	void ChangeFireModeToGrenade();
	void ClientChangeFireModeToGrenade();
	void ServerChangeFireModeToGrenade();
	void FailedSupported();
	virtual void DoChangeFireMode() override;
	virtual void FixJam() override;
	TSubclassOf<AAmmunition> GetCurrentAmmoName();
	TSubclassOf<AAmmunition> GetAuxAmmoName();
	AAmmunition* GetCurrentAmmoType();
	AAmmunition* GetAuxAmmoType();
	void SetCurrentAmmoType(AAmmunition* newAmmoType);
	void SetCurrentAmmoName(AAmmunition* newAmmoName);
	virtual bool CheckForNoReload() override;
	bool ShouldDoDelayedEject();
	void DiscardShell();
	virtual void PlaySelect() override;
	virtual void PlayIdleAnim() override;
	virtual void SelectGrenadeMode();
	virtual void SelectNormalMode();
	virtual void PlayReloading() override;

};
