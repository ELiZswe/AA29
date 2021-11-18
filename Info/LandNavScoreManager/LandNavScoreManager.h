// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "LandNavScoreManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ALandNavScoreManager : public AAA2_Info
{
	GENERATED_BODY()
public:
		ALandNavScoreManager();

		UPROPERTY()			int32 Objectives;							//var int Objectives;

		void SetObjectiveTime(int32 Index, int32 Time);
		void GetObjectiveTime(int32 Index);
		int32 GetMaxIndex();
		void FormatTime(int32 Time);

};
