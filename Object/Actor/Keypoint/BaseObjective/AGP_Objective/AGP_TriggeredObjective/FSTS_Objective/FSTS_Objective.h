// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_TriggeredObjective.h"
#include "FSTS_Objective.generated.h"

UCLASS()
class AFSTS_Objective : public AAGP_TriggeredObjective
{
	GENERATED_BODY()
public:
	AFSTS_Objective(const FObjectInitializer& objectInitializer);

	UPROPERTY()		bool bSuccessfullyCompleted;		//var bool bSuccessfullyCompleted;

	void AccomplishObjective(APawn* aInstigator, AController* Killer);
	void SendPercentage(APawn* whocares);
	float GetPercentComplete();
};
