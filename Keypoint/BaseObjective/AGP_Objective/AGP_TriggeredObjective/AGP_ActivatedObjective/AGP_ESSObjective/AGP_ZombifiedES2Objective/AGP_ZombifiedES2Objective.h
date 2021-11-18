// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ESSObjective.h"
#include "AGP_ZombifiedES2Objective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ZombifiedES2Objective : public AAGP_ESSObjective
{
	GENERATED_BODY()
public:
	AAGP_ZombifiedES2Objective(const FObjectInitializer& objectInitializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float fDangerDistance;		//var(ESS) float fDangerDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float fReportDistance;		//var(ESS) float fReportDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float fObserveDistance;		//var(ESS) float fObserveDistance;
	UPROPERTY()															bool bReportable;			//var bool bReportable;
	UPROPERTY()															bool bFirstObjectFound;		//var bool bFirstObjectFound;
};
