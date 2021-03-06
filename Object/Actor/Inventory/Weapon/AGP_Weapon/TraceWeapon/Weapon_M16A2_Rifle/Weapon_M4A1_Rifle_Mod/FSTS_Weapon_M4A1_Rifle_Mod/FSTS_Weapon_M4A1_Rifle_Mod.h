// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "FSTS_Weapon_M4A1_Rifle_Mod.generated.h"

UCLASS()
class AFSTS_Weapon_M4A1_Rifle_Mod : public AWeapon_M4A1_Rifle_Mod
{
	GENERATED_BODY()
public:
	AFSTS_Weapon_M4A1_Rifle_Mod();

	
	UPROPERTY()		bool bSpawnMILES;						//var bool bSpawnMILES;
	UPROPERTY()		bool bInitializeWeaponDown;				//var bool bInitializeWeaponDown;

	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	virtual void TweenDown() override;
	void SetupClientWeapon();

};
