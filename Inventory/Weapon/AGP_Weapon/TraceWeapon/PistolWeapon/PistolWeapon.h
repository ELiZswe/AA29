// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "PistolWeapon.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APistolWeapon : public ATraceWeapon
{
	GENERATED_BODY()
public:
	APistolWeapon();
	
	UPROPERTY()		USoundBase* ReloadEmptyHmrBkSound;		//var Sound ReloadEmptyHmrBkSound;
	UPROPERTY()		FName PutAwayLowHFAnim;					//var name PutAwayLowHFAnim;
	UPROPERTY()		FName PutAwayLowEmptyAnim;				//var name PutAwayLowEmptyAnim;
	UPROPERTY()		FName PutAwayLowAnim;					//var name PutAwayLowAnim;
	UPROPERTY()		FName PutAwayEmptyHFAnim;				//var name PutAwayEmptyHFAnim;
	UPROPERTY()		FName PutAwayEmptyAnim;					//var name PutAwayEmptyAnim;
	UPROPERTY()		FName PutAwayAnim;						//var name PutAwayAnim;
	UPROPERTY()		FName GuardIdleHammerFW;				//var name GuardIdleHammerFW;
	UPROPERTY()		FName GuardUpHammerFW;					//var name GuardUpHammerFW;
	UPROPERTY()		FName GuardDownHammerFW;				//var name GuardDownHammerFW;
	UPROPERTY()		FName GuardIdleEmpty;					//var name GuardIdleEmpty;
	UPROPERTY()		FName GuardUpEmpty;						//var name GuardUpEmpty;
	UPROPERTY()		FName GuardDownEmpty;					//var name GuardDownEmpty;
	UPROPERTY()		FName GuardIdle;						//var name GuardIdle;
	UPROPERTY()		FName GuardUp;							//var name GuardUp;
	UPROPERTY()		FName GuardDown;						//var name GuardDown;
	UPROPERTY()		FName CrawlBackEmptyHFAnim;				//var name CrawlBackEmptyHFAnim;
	UPROPERTY()		FName CrawlEmptyHFAnim;					//var name CrawlEmptyHFAnim;
	UPROPERTY()		FName CrawlOutEmptyHFAnim;				//var name CrawlOutEmptyHFAnim;
	UPROPERTY()		FName CrawlInEmptyHFAnim;				//var name CrawlInEmptyHFAnim;
	UPROPERTY()		FName CrawlBackEmptyAnim;				//var name CrawlBackEmptyAnim;
	UPROPERTY()		FName CrawlEmptyAnim;					//var name CrawlEmptyAnim;
	UPROPERTY()		FName CrawlOutEmptyAnim;				//var name CrawlOutEmptyAnim;
	UPROPERTY()		FName CrawlInEmptyAnim;					//var name CrawlInEmptyAnim;
	UPROPERTY()		FName CrawlBackAnim;					//var name CrawlBackAnim;
	UPROPERTY()		FName CrawlAnim;						//var name CrawlAnim;
	UPROPERTY()		FName CrawlOutAnim;						//var name CrawlOutAnim;
	UPROPERTY()		FName CrawlInAnim;						//var name CrawlInAnim;
	UPROPERTY()		FName FireEmptyAnim;					//var name FireEmptyAnim;
	UPROPERTY()		FName FireEmptyFirstAnim;				//var name FireEmptyFirstAnim;
	UPROPERTY()		FName FireLastShotAnim;					//var name FireLastShotAnim;
	UPROPERTY()		FName SelectNewAnim;					//var name SelectNewAnim;
	UPROPERTY()		FName SelectAnim;						//var name SelectAnim;
	UPROPERTY()		FName FixJamAnim;						//var name FixJamAnim;
	UPROPERTY()		FName ReloadEmptyHBAnim;				//var name ReloadEmptyHBAnim;
	UPROPERTY()		FName ReloadEmptyHFAnim;				//var name ReloadEmptyHFAnim;
	UPROPERTY()		FName FullReloadAnim;					//var name FullReloadAnim;
	UPROPERTY()		FName ReloadAnim;						//var name ReloadAnim;
	UPROPERTY()		FName IdleHammerFWAnim;					//var name IdleHammerFWAnim;
	UPROPERTY()		FName IdleEmptyRandomAnim;				//var name IdleEmptyRandomAnim;
	UPROPERTY()		FName IdleEmptyAnim;					//var name IdleEmptyAnim;
	UPROPERTY()		FName IdleAnim;							//var name IdleAnim;
	UPROPERTY()		bool bHammerForward;					//var bool bHammerForward;
	UPROPERTY()		bool bDryFired;							//var bool bDryFired;
	UPROPERTY()		bool bPutAwayEmpty;						//var bool bPutAwayEmpty;
	UPROPERTY()		bool bSlideBack;						//var bool bSlideBack;

	bool CanTraceMore(ABaseWeaponAttachment* BA, int num_traces);
	virtual void AltFire(float Value) override;
	virtual void DoChangeFireMode() override;
	virtual void ChangeFireMode() override;
	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
	void GetSwapContainer();
	bool ShouldUse3dSights();
	void DryFire();
	void PlayDryFire();
	virtual void PlayIdleAnim() override;
	virtual void PlayFiring() override;
	virtual void PlayReloading() override;
	virtual void PlaySelect() override;
	virtual void TweenDown() override;
	void PlayHighCrawlIn();
	void PlayCrawl();
	void PlayHighCrawlOut();

};
