// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"
#include "GC_EL_FightingPositionThrow.generated.h"

class AFSTS_WeaponPickup;

UCLASS()
class AA29_API AGC_EL_FightingPositionThrow : public AGC_EL_MasterScript
{
	GENERATED_BODY()
public:
	AGC_EL_FightingPositionThrow();

	UPROPERTY()						int32 MissedThrows;							//var int MissedThrows;
	UPROPERTY()						AActor* target2;							//var Actor target2;
	UPROPERTY()						AActor* Target1;							//var Actor Target1;
	UPROPERTY()						AActor* ThrowPosition;						//var Actor ThrowPosition;
	UPROPERTY()						AFSTS_WeaponPickup* GrenadePickup;			//var FSTS_WeaponPickup GrenadePickup;

	void Reset();
	void DoReferenceLinking();
};
