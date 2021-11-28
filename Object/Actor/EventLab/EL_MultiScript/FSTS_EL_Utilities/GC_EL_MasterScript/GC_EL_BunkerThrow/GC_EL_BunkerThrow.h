// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"
#include "GC_EL_BunkerThrow.generated.h"

class AFSTS_WeaponPickup;
class AVolume;

UCLASS()
class AA29_API AGC_EL_BunkerThrow : public AGC_EL_MasterScript
{
	GENERATED_BODY()
public:
	AGC_EL_BunkerThrow();


	UPROPERTY()						bool bWaitingForStation2_2Finish;					//var bool bWaitingForStation2_2Finish;
	UPROPERTY()						AVolume* BunkerVolume;								//var Volume BunkerVolume;
	UPROPERTY()						int32 MissedThrows;									//var int MissedThrows;
	UPROPERTY()						AActor* ThrowPosition;								//var Actor ThrowPosition;
	UPROPERTY()						AActor* BunkerTarget;								//var Actor BunkerTarget;
	UPROPERTY()						bool bHasGrenades;									//var bool bHasGrenades;
	UPROPERTY()						bool bStationHasBegun;								//var bool bStationHasBegun;
	UPROPERTY()						bool bFirstProneEvent;								//var bool bFirstProneEvent;
	UPROPERTY()						bool bPlayerMustBeProne;							//var bool bPlayerMustBeProne;
	UPROPERTY()						AFSTS_WeaponPickup* GrenadePickup;					//var FSTS_WeaponPickup GrenadePickup;
};
