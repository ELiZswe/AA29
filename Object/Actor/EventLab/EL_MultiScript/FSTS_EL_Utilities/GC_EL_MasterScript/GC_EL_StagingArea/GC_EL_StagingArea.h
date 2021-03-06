// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"
#include "GC_EL_StagingArea.generated.h"

UCLASS()
class AGC_EL_StagingArea : public AGC_EL_MasterScript
{
	GENERATED_BODY()
public:
	AGC_EL_StagingArea();

	void DoReferenceLinking();
	void Reset();
};
