// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/SoundGameScript/SoundGameScript.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"

ASoundGameScript::ASoundGameScript()
{

}

void ASoundGameScript::Init()
{
}

void ASoundGameScript::PostInit()
{
}

bool ASoundGameScript::Timer_Timer(FName Name)
{
	return true;
}

bool ASoundGameScript::AGPUseTrigger_Trigger(AAGP_UseTrigger* Trigger, APawn* aInstigator)
{
	return true;
}

bool ASoundGameScript::AGPUseTrigger_UnTrigger(AAGP_UseTrigger* Trigger, APawn* aInstigator)
{
	return true;
}

bool ASoundGameScript::AGPTrigger_Trigger(AAGP_Trigger* Trigger, APawn* aInstigator)
{
	return true;
}

bool ASoundGameScript::AGPTrigger_UnTrigger(AAGP_Trigger* Trigger, APawn* aInstigator)
{
	return true;
}
