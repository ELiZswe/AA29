// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EventLab.h"
#include "EL_MultiScript.generated.h"

class AEL_MultiScript;

UCLASS()
class AA29_API AEL_MultiScript : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_MultiScript();

	UPROPERTY()						AEL_MultiScript* MasterScript;								//var EL_MultiScript MasterScript;
	UPROPERTY()						bool bActiveScriptTransition;								//var bool bActiveScriptTransition;
	UPROPERTY()						int32 LevelScriptsListIndex;								//var int LevelScriptsListIndex;
	UPROPERTY(EditAnywhere)			TArray<AEL_MultiScript*> LevelScriptsList;					//var() array<EL_MultiScript> LevelScriptsList;
	UPROPERTY(EditAnywhere)			TArray<AEL_MultiScript*> LevelScriptsClasses;				//var() array<class<EL_MultiScript> > LevelScriptsClasses;
	UPROPERTY(EditAnywhere)			bool bMasterScript;											//var() bool bMasterScript;
	UPROPERTY()						bool bDormant;												//var bool bDormant;
};
