// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV_50Cal/CROWS_HMMWV_50Cal.h"
#include "FSTS_CROWS_Driver_HMMWV.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_CROWS_Driver_HMMWV : public ACROWS_HMMWV_50Cal
{
	GENERATED_BODY()
public:
	AFSTS_CROWS_Driver_HMMWV();

	UPROPERTY()									bool bHasSoundedHorn;						//var bool bHasSoundedHorn;
	UPROPERTY()									bool bHasLookedInMirror;					//var bool bHasLookedInMirror;
	UPROPERTY()									bool bHasChangedSpeed;						//var bool bHasChangedSpeed;
	UPROPERTY()									bool bHasShiftedGears;						//var bool bHasShiftedGears;
	UPROPERTY()									bool bEntryLocked;							//var bool bEntryLocked;

	bool PanelUsedBy(APawn* User, int32 Id);
	bool TryToDrive(APawn* p);
	bool SuperTryToDrive(APawn* p);
	void Touch(AActor* Other);
	void AttachBodyPanels();
	void ShiftDriveGearsUp();
	void ShiftDriveGearsDown();
	void ShiftHiLoGears();
	void LookRearViewLeft();
	void LookRearViewRight();
	void Horn();
	void TakeImpactDamage(float AccelMag);
	void ResetUserFlags();
};
