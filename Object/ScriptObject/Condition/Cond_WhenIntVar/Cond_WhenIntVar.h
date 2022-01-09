// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "AA29/AA29.h"
#include "Cond_WhenIntVar.generated.h"

class AAGP_IntVar;

UCLASS()
class UCond_WhenIntVar : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenIntVar();

	UPROPERTY()										EComparison _Comparison;				//var EComparison _Comparison;
	UPROPERTY()										int32 _value;							//var int _value;
	UPROPERTY()										AAGP_IntVar* _IntVar;					//var AGP_Gameplay.AGP_IntVar _IntVar;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
	void update();
};
