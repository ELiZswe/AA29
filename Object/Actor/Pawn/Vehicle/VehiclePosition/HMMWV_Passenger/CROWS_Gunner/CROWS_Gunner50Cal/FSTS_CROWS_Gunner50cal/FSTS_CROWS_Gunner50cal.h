// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner50Cal/CROWS_Gunner50Cal.h"
#include "FSTS_CROWS_Gunner50cal.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_CROWS_Gunner50cal : public ACROWS_Gunner50Cal
{
	GENERATED_BODY()
public:
	AFSTS_CROWS_Gunner50cal();

	UPROPERTY()						bool bSafety;									//var bool bSafety;
	UPROPERTY()						bool bHasZoomed;								//var bool bHasZoomed;
	UPROPERTY()						bool bHasLased;									//var bool bHasLased;

	void DoLase();
	void ZoomIn();
	void ZoomOut();
	void ServerActivateCrows();
	void Fire(float F);
	void AltFire(float F);
};
