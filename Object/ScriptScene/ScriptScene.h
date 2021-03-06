// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScriptScene.generated.h"

class UScriptEvent;
class UDirection;
class UCondition;
class AScreenplay;

UCLASS()
class UScriptScene : public UObject
{
	GENERATED_BODY()
public:
	UScriptScene();

	UPROPERTY()						bool _bFinished;						//var bool _bFinished;
	UPROPERTY()						bool _bDebug;							//var bool _bDebug;
	UPROPERTY()						FName _Tag;								//var name _Tag;
	UPROPERTY()						AScreenplay* _ParentScreenplay;			//var Screenplay _ParentScreenplay;
	UPROPERTY()						TArray<UDirection*> EndDirs;			//var() array<Direction> EndDirs;
	UPROPERTY()						TArray<UScriptEvent*> Events;			//var() array<ScriptEvent> Events;
	UPROPERTY()						TArray<UDirection*> InitDirs;			//var() array<Direction> InitDirs;

	void Destroyed();
	void SceneStart();
	void SceneFinish();
	void EventsStart();
	void EventsFinish();
	void RunInitDirs();
	void RunEndDirs();
	bool AddEvent(UScriptEvent* sEvent);
	bool AddInitDirection(UDirection* Dir);
	bool AddEndDirection(UDirection* Dir);
	bool AddEventCondition(UCondition* con);
	bool AddEventDirection(UDirection* Dir);
	bool SetEventConditionAnd();
	bool SetEventConditionOr();
	void SetEventRunOnceGlobal(bool Status);
	void SetEventRunOncePerScene(bool Status);
	void SetTag(FName Tag);
	FName GetTag();
	void SetParentScreenplay(AScreenplay* Parent);
	void SetDebug(bool Debug);
	void DumpScene();
};
