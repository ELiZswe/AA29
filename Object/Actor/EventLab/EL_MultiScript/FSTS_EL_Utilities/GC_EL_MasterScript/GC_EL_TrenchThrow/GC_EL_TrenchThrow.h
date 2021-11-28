// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"
#include "GC_EL_TrenchThrow.generated.h"

/**
 * 
 */
class AFSTS_WeaponPickup;
class AVolume;

UCLASS()
class AA29_API AGC_EL_TrenchThrow : public AGC_EL_MasterScript
{
	GENERATED_BODY()
public:
	AGC_EL_TrenchThrow();

	UPROPERTY()						int32 MissedThrows;											//var int MissedThrows;
	UPROPERTY()						AVolume* Target;											//var Volume Target;
	UPROPERTY()						AActor* ThrowPosition;											//var Actor ThrowPosition;
	UPROPERTY()						AFSTS_WeaponPickup* GrenadePickup;											//var FSTS_WeaponPickup GrenadePickup;
};
