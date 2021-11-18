// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/SniperRifle.h"
#include "Weapon_M24_Sniper.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_M24_Sniper : public ASniperRifle
{
	GENERATED_BODY()
public:
	AWeapon_M24_Sniper();


	UPROPERTY()		FName ReloadEndAnim;					//var name ReloadEndAnim;
	UPROPERTY()		FName ReloadAnim;						//var name ReloadAnim;
	UPROPERTY()		FName ReloadStartAnim;					//var name ReloadStartAnim;
	UPROPERTY()		int32 clientAmmo;						//var int clientAmmo;
	UPROPERTY()		int32 clientClip;						//var int clientClip;
	UPROPERTY()		bool bStopReload;						//var bool bStopReload;
	UPROPERTY()		bool bWorkBolt;							//var bool bWorkBolt;
	UPROPERTY()		bool bRequireRecharge;					//var bool bRequireRecharge;

	virtual void PlayReloading() override;
	bool IsCharged();
	bool MustWorkBolt();
	virtual void Fire(float Value) override;
	void ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus);
	virtual void PlayFiring() override;
	void DiscardShell();
	void ServerStopReload();
	void StopReload();
	int32 GetClipCountAllowed(int32 new_clip, AAmmunition* test_ammo);
	void ReloadBullet();
	virtual bool CheckForNoReload() override;
	void ReloadClip(uint8 newclip);
	virtual int32 GetClipCount(uint8 clip, bool bAuxAmmo) override;
	void GetBestClip();
	void AddClip(AAmmunition* AmmoClass);
	virtual void RecountAmmo() override;
};
