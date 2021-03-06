// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/Action_PLAYANIM/Action_PLAYANIM.h"
#include "ACTION_FreezeOnAnimEnd.generated.h"

class AScriptedController;
UCLASS()
class UACTION_FreezeOnAnimEnd : public UAction_PLAYANIM
{
	GENERATED_BODY()
public:
	UACTION_FreezeOnAnimEnd();

	bool InitActionFor(AScriptedController* C);
	void SetCurrentAnimationFor(AScriptedController* C);
	bool PawnPlayBaseAnim(AScriptedController* C, bool bFirstPlay);
};
