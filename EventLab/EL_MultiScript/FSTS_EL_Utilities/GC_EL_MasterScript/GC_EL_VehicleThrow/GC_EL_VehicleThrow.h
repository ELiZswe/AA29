// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"
#include "GC_EL_VehicleThrow.generated.h"


class AFSTS_WeaponPickup;

UCLASS()
class AA29_API AGC_EL_VehicleThrow : public AGC_EL_MasterScript
{
	GENERATED_BODY()
public:
	AGC_EL_VehicleThrow();

	UPROPERTY()						int32 MissedThrows;										//var int MissedThrows;
	UPROPERTY()						AVolume* Target;										//var Volume Target;
	UPROPERTY()						AActor* ThrowPosition;									//var Actor ThrowPosition;
	UPROPERTY()						AFSTS_WeaponPickup* GrenadePickup;						//var FSTS_WeaponPickup GrenadePickup;
};
