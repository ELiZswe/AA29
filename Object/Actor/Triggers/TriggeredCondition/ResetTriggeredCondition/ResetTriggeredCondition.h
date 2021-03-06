// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/TriggeredCondition/TriggeredCondition.h"
#include "ResetTriggeredCondition.generated.h"

UCLASS()
class AResetTriggeredCondition : public ATriggeredCondition
{
	GENERATED_BODY()
public:
	AResetTriggeredCondition();
	

	UPROPERTY(EditAnywhere)		bool	bResetAtRoundEnd;				//var() bool bResetAtRoundEnd;
	UPROPERTY()					bool	bSavedInitialEnabled;			//var bool bSavedInitialEnabled;

	void PostBeginPlay();
	void Reset();
	void MatchStarting();
};
