// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_MultiScript.generated.h"

class AEL_MultiScript;

UCLASS()
class AEL_MultiScript : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_MultiScript();

	UPROPERTY()						AEL_MultiScript*			MasterScript;						//var EL_MultiScript MasterScript;
	UPROPERTY()						bool						bActiveScriptTransition;			//var bool bActiveScriptTransition;
	UPROPERTY()						int32						LevelScriptsListIndex;				//var int LevelScriptsListIndex;
	UPROPERTY(EditAnywhere)			TArray<AEL_MultiScript*>	LevelScriptsList;					//var() array<EL_MultiScript> LevelScriptsList;
	UPROPERTY(EditAnywhere)			TArray<AEL_MultiScript*>	LevelScriptsClasses;				//var() array<class<EL_MultiScript> > LevelScriptsClasses;
	UPROPERTY(EditAnywhere)			bool						bMasterScript;						//var() bool bMasterScript;
	UPROPERTY()						bool						bDormant;							//var bool bDormant;

	void EventLabTick(float DeltaTime);
	void PostInit();
	void PostPostInit();
	void SetMasterScript();
	bool IsMasterScript();
	int32 GetLevelScriptsListIndex();
	void InitLevelScripts();
	void ResetScript(AEL_MultiScript* ScriptToReset, bool bReenterScriptAfterReset);
	AEL_MultiScript* GetActiveScript();
	void ScriptComplete(AEL_MultiScript* CompletedScript);
	void SetActiveScript(AEL_MultiScript* NewActiveScript, AEL_MultiScript* OldActiveScript, FName NewActiveState, FName NewDeactiveState, bool bForceTransition);
	void ActivateScript(AEL_MultiScript* ScriptToChange, FName NewState);
	void DeactivateScript(AEL_MultiScript* ScriptToChange, FName NewState);
	void Destroyed();
	void CreateCustomLevelScriptsLinks();
	void Reset();
	bool AllowScriptStart(AEL_MultiScript* NewActiveScript);
};
