// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_RPK_SAW/Weapon_RPK_SAW.h"
#include "Weapon_T62_Coax.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_T62_Coax : public AWeapon_RPK_SAW
{
	GENERATED_BODY()
public:
	AWeapon_T62_Coax();

	void ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus);
	void TraceFire(float Accuracy, float YOffset, float ZOffset);
	void DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth);
	void IncrementFlashCount();

};
