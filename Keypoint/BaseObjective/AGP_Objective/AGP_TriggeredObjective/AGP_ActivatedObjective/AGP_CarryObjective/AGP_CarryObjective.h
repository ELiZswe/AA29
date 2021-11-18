// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ActivatedObjective.h"
#include "AGP_CarryObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_CarryObjective : public AAGP_ActivatedObjective
{
	GENERATED_BODY()
public:
	AAGP_CarryObjective(const FObjectInitializer& objectInitializer);
	
	
	UPROPERTY()										bool bObjectiveInPlay;											//var bool bObjectiveInPlay;
	UPROPERTY()										bool bWaitingFirstPickup;										//var bool bWaitingFirstPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ECompassVisibilityDropped CompassVisibilityWhenDropped;			//var() ECompassVisibilityDropped CompassVisibilityWhenDropped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ECompassVisibilityCarried CompassVisibilityWhenCarried;			//var() ECompassVisibilityCarried CompassVisibilityWhenCarried;


	void Reset();
	uint8 GetPickupTeamOwner();
	bool NoPickupsInsideFor(APawn* User);
	virtual bool IsEnabled() override;
	bool CarryableInPlay();
	bool UsedBy(APawn* User);
	void CarryObjectiveUsed(APawn* User);
	bool CanAccomplish(APawn* User);
	void DetermineCarriedCompassVisbility(APawn* ObjCarrier, bool bDropped);
	bool IsOnCompass(AController* ctrlRequesting);
	void AccomplishObjective(APawn* _Instigator, AController* Killer);
	void GiveInventoryPickup(APawn* _Instigator);
	bool CheckAllowedPickupTeam(APawn* User);

};
