// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "Javelin_BST_CLU.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AJavelin_BST_CLU : public AWEAPON_Javelin
{
	GENERATED_BODY()
public:
	AJavelin_BST_CLU();

	
	UPROPERTY()		bool bTotalLock;			//var bool bTotalLock;
	UPROPERTY()		bool bNotifiedJam;			//var bool bNotifiedJam;
	UPROPERTY()		bool bCanFire;				//var bool bCanFire;
	UPROPERTY()		bool bDirectOnly;			//var bool bDirectOnly;
	UPROPERTY()		bool bCanSeek;				//var bool bCanSeek;
	UPROPERTY()		bool bCanCycle;				//var bool bCanCycle;
	UPROPERTY()		bool bCanFixJam;			//var bool bCanFixJam;
	UPROPERTY()		bool bToggled;				//var bool bToggled;
	UPROPERTY()		bool bCanReload;			//var bool bCanReload;
	UPROPERTY()		bool bCanZoom;				//var bool bCanZoom;
	UPROPERTY()		bool bCanDrop;				//var bool bCanDrop;


	bool CanUseWeapon(int32 DesiredAction);
	virtual void FixJam() override;
	void NV();
	void ToggleZoom();
	void CancelLock(bool KeepSeekOn);
	void FireMode();
	void DropFrom(FVector StartLocation, bool bAttach);
	virtual void Fire(float Value) override;
	virtual void AltFire(float Value) override;
	void IsJavelin();

};
