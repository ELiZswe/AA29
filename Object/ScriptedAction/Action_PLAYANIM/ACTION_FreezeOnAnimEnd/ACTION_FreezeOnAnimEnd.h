// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/Action_PLAYANIM/Action_PLAYANIM.h"
#include "ACTION_FreezeOnAnimEnd.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_FreezeOnAnimEnd : public UAction_PLAYANIM
{
	GENERATED_BODY()
public:
	UACTION_FreezeOnAnimEnd();

	bool InitActionFor(UScriptedController* C);
	void SetCurrentAnimationFor(UScriptedController* C);
	bool PawnPlayBaseAnim(UScriptedController* C, bool bFirstPlay);
};
