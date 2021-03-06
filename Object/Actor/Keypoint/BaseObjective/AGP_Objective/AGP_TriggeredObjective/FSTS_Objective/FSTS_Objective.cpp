// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/FSTS_Objective/FSTS_Objective.h"

AFSTS_Objective::AFSTS_Objective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	AccomplishSound		= nullptr;
	ProgressSound		= nullptr;
	//bHidden = true;
	//bCollideActors = false;
}

void AFSTS_Objective::AccomplishObjective(APawn* aInstigator, AController* Killer)
{
	bSuccessfullyCompleted = true;
	//Super::AccomplishObjective(aInstigator);
}

void AFSTS_Objective::SendPercentage(APawn* whocares)
{
}

float AFSTS_Objective::GetPercentComplete()
{
	if (bSuccessfullyCompleted)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
