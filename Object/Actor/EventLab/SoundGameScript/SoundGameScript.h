// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "SoundGameScript.generated.h"

class AAGP_Trigger;
class AAGP_UseTrigger;
UCLASS()
class ASoundGameScript : public AEventLab
{
	GENERATED_BODY()
public:
	ASoundGameScript();

	void Init();
	void PostInit();
	bool Timer_Timer(FName Name);
	bool AGPUseTrigger_Trigger(AAGP_UseTrigger* Trigger, APawn* aInstigator);
	bool AGPUseTrigger_UnTrigger(AAGP_UseTrigger* Trigger, APawn* aInstigator);
	bool AGPTrigger_Trigger(AAGP_Trigger* Trigger, APawn* aInstigator);
	bool AGPTrigger_UnTrigger(AAGP_Trigger* Trigger, APawn* aInstigator);
};
