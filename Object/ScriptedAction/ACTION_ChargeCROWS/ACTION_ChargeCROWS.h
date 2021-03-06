// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ChargeCROWS.generated.h"

class AScriptedController;
UCLASS()
class UACTION_ChargeCROWS : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ChargeCROWS();

	bool InitActionFor(AScriptedController* C);

};
