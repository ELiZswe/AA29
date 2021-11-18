// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "Javelin_LF_CLU.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AJavelin_LF_CLU : public AWEAPON_Javelin
{
	GENERATED_BODY()
public:
	AJavelin_LF_CLU();

	
	UPROPERTY()		bool bTotalLock;			//var bool bTotalLock;
	UPROPERTY()		bool bCanReload;			//var bool bCanReload;
	UPROPERTY()		bool bCanZoom;				//var bool bCanZoom;
	UPROPERTY()		bool bCanDrop;				//var bool bCanDrop;
	UPROPERTY()		bool bCanFire;				//var bool bCanFire;


	bool CanUseWeapon(int32 DesiredAction);
	virtual void Fire(float Value) override;
	void Spawn_J_Target();
	void IsJavelin();

};
