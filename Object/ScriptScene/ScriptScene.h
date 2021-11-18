// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScriptScene.generated.h"

//class UScriptEvent;
class UDirection;
class UCondition;
//class UScreenplay;

/**
 * 
 */
UCLASS()
class AA29_API UScriptScene : public UObject
{
	GENERATED_BODY()
public:
	UScriptScene();



	UPROPERTY()						bool _bFinished;						//var bool _bFinished;
	UPROPERTY()						bool _bDebug;							//var bool _bDebug;
	UPROPERTY()						FName _Tag;								//var name _Tag;
	//UPROPERTY()						UScreenplay* _ParentScreenplay;			//var Screenplay _ParentScreenplay;
	UPROPERTY()						TArray<UDirection*> EndDirs;			//var() array<Direction> EndDirs;
//	UPROPERTY()						TArray<UScriptEvent*> Events;			//var() array<ScriptEvent> Events;
	UPROPERTY()						TArray<UDirection*> InitDirs;			//var() array<Direction> InitDirs;

	void Destroyed();
	void SceneStart();
	void SceneFinish();
	void EventsStart();
	void EventsFinish();
	void RunInitDirs();
	void RunEndDirs();
//	void AddEvent(UScriptEvent* sEvent);
	void AddInitDirection(UDirection* Dir);
	void AddEndDirection(UDirection* Dir);
	void AddEventCondition(UCondition* con);
	void AddEventDirection(UDirection* Dir);
	void SetEventConditionAnd();
	void SetEventConditionOr();
	void SetEventRunOnceGlobal(bool Status);
	void SetEventRunOncePerScene(bool Status);
	void SetTag(FName Tag);
	void GetTag();
//	void SetParentScreenplay(UScreenplay* Parent);
	void SetDebug(bool Debug);
	void DumpScene();


};
