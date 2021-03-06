// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/MyEnums.h"
#include "Action_PLAYMUSIC.generated.h"

class AScriptedController;
UCLASS()
class UAction_PLAYMUSIC : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_PLAYMUSIC();

	UPROPERTY(EditAnywhere, Category = "Action")			bool bAffectAllPlayers;				//var(Action) bool bAffectAllPlayers;
	UPROPERTY(EditAnywhere, Category = "Action")			EMusicTransition Transition;		//var(Action) Actor.EMusicTransition Transition;
	UPROPERTY(EditAnywhere, Category = "Action")			FString Song;						//var(Action) string Song;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
