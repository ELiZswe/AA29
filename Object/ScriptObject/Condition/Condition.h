// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"
#include "Condition.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCondition : public UScriptObject
{
	GENERATED_BODY()
public:
	UCondition();

	UPROPERTY()										bool _bTrue;						//var bool _bTrue;
	UPROPERTY()										bool _bValid;						//var bool _bValid;
	//UPROPERTY()										AScreenplay* _ParentScreenplay;		//var Screenplay _ParentScreenplay;
	//UPROPERTY()										AScriptEvent* _ParentEvent;			//var ScriptEvent _ParentEvent;



	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
	void Start();
	void Finish();
	void Notify();
	//void SetParentEvent(ScriptEvent Parent);
	//void SetParentScreenplay(Screenplay Parent);
	bool IsTrue();


};
