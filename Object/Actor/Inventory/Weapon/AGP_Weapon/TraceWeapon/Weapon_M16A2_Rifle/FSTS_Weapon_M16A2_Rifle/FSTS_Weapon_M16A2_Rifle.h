// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "FSTS_Weapon_M16A2_Rifle.generated.h"

class ABaseWeaponAttachment;
UCLASS()
class AFSTS_Weapon_M16A2_Rifle : public AWeapon_M16A2_Rifle
{
	GENERATED_BODY()
public:
	AFSTS_Weapon_M16A2_Rifle();
	
	UPROPERTY()		bool bInitializeWeaponDown;				//var bool bInitializeWeaponDown;

	void DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	virtual void TweenDown() override;
	int32 DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth);
	void SetupClientWeapon();
};
