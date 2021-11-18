// All the original content belonged to the US Army


#include "AA29/Triggers/Trigger/AGP_MessageTrigger/AGP_MessageTrigger.h"

AAGP_MessageTrigger::AAGP_MessageTrigger()
{

}

void AAGP_MessageTrigger::Touch(AActor* Other)
{
	/*
	if (Pawn(Other) != nullptr)
	{
		Super::Trigger(this, Pawn(Other));
	}
	*/
}
void AAGP_MessageTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (HumanController(EventInstigator.Controller) != nullptr)
	{
		HumanController(EventInstigator.Controller).SetPlayTips(Line1, Line2, FadeTime);
	}
	*/
}
void AAGP_MessageTrigger::UnTouch(AActor* Other)
{
	/*
	if (bRemoveMessageOnUnTouch && Pawn(Other) != nullptr)
	{
		UnTrigger(Self, Pawn(Other));
	}
	*/
}
void AAGP_MessageTrigger::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (HumanController(EventInstigator.Controller) != nullptr)
	{
		HumanController(EventInstigator.Controller).SetPlayTips("", "", 0);
	}
	*/
}