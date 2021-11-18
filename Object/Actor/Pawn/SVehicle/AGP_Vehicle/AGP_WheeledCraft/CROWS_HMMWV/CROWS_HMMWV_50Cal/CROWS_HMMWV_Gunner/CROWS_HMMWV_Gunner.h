// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV_50Cal/CROWS_HMMWV_50Cal.h"
#include "CROWS_HMMWV_Gunner.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACROWS_HMMWV_Gunner : public ACROWS_HMMWV_50Cal
{
	GENERATED_BODY()
public:
	ACROWS_HMMWV_Gunner();

	UPROPERTY()									bool bDoorsLocked;							//var bool bDoorsLocked;
	UPROPERTY()									AActor* LastTouch;							//var Actor LastTouch;


	void AttachBodyPanels();
	bool PanelUsedBy(APawn* User, int32 Id);
	bool TryToDrive(APawn* p);
	void Touch(AActor* Other);

};
