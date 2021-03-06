// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/MyEnums.h"
#include "ACTION_SubTitles.generated.h"

class AScriptedController;
UCLASS()
class UACTION_SubTitles : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_SubTitles();

	UPROPERTY(EditAnywhere)						ESST_Mode SubTitleMode;						//var() SceneSubtitles.ESST_Mode SubTitleMode;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
