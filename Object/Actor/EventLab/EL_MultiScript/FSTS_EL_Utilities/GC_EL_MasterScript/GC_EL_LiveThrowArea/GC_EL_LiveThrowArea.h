// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"
#include "GC_EL_LiveThrowArea.generated.h"

class AFSTS_WeaponPickup;

UCLASS()
class AA29_API AGC_EL_LiveThrowArea : public AGC_EL_MasterScript
{
	GENERATED_BODY()
public:
	AGC_EL_LiveThrowArea();

	UPROPERTY()						bool bLooseGrenadeOMG;										//var bool bLooseGrenadeOMG;
	UPROPERTY()						bool bDisableIdleTimers;									//var bool bDisableIdleTimers;
	UPROPERTY()						bool bDisableThrowTimers;									//var bool bDisableThrowTimers;
	UPROPERTY()						bool bCrouchedInTime;										//var bool bCrouchedInTime;
	UPROPERTY()						bool bThrowTooShort;										//var bool bThrowTooShort;
	UPROPERTY()						bool bThrowIsAuthorized;									//var bool bThrowIsAuthorized;
	UPROPERTY()						AActor* LiveThrowPosition;									//var Actor LiveThrowPosition;
	UPROPERTY()						AFSTS_WeaponPickup* GrenadePickup;							//var FSTS_WeaponPickup GrenadePickup;
};
