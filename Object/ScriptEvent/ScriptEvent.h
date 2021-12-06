// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScriptEvent.generated.h"

class AScreenplay;
class UCondition;
class UDirection;
class AScreenplay;

UCLASS()
class AA29_API UScriptEvent : public UObject
{
	GENERATED_BODY()
public:
	UScriptEvent();

	UPROPERTY(EditAnywhere)		TArray<UCondition*>	Conditions;					//var() TArray<Condition> Conditions;
	UPROPERTY(EditAnywhere)		TArray<UDirection*>	Directions;					//var() TArray<Direction> Directions;
	UPROPERTY()					AScreenplay*		_ParentScreenplay;			//var Screenplay _ParentScreenplay;
	UPROPERTY()					int32				_iType;						//var int32 _iType;
	UPROPERTY()					bool				_bRunOnceGlobal;			//var bool _bRunOnceGlobal;
	UPROPERTY()					bool				_bRunOncePerScene;			//var bool _bRunOncePerScene;
	UPROPERTY()					bool				_bRanOnce;					//var bool _bRanOnce;
	UPROPERTY()					bool				_bDebug;					//var bool _bDebug;
	UPROPERTY()					bool				_bFinished;					//var bool _bFinished;

	void Destroyed();
	void EventStart();
	void EventFinish();
	void ConditionsStart();
	void ConditionsFinish();
	void ConditionFinished(UCondition* con);
	void DirectionsFinish();
	void RunDirections();
	bool AddCondition(UCondition* con);
	bool AddDirection(UDirection* Dir);
	bool SetConditionAnd();
	bool SetConditionOr();
	void SetRunOnceGlobal(bool Status);
	void SetRunOncePerScene(bool Status);
	void SetParentScreenplay(AScreenplay* Parent);
	void SetDebug(bool Debug);
	void DumpEvent();
};
