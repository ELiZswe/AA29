// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/AGP_MessageTrigger/AGP_MessageTrigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

AAGP_MessageTrigger::AAGP_MessageTrigger()
{

}

void AAGP_MessageTrigger::Touch(AActor* Other)
{
	/*
	if (Cast<APawn>(Other) != nullptr)
	{
		Super::Trigger(this, Pawn(Other));
	}
	*/
}
void AAGP_MessageTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (Cast<AHumanController>(EventInstigator.Controller) != nullptr)
	{
		Cast<AHumanController>(EventInstigator.Controller).SetPlayTips(Line1, Line2, FadeTime);
	}
	*/
}
void AAGP_MessageTrigger::UnTouch(AActor* Other)
{
	/*
	if (bRemoveMessageOnUnTouch && Pawn(Other) != nullptr)
	{
		UnTrigger(this, Pawn(Other));
	}
	*/
}
void AAGP_MessageTrigger::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (Cast<AHumanController>(EventInstigator.Controller) != nullptr)
	{
		Cast<AHumanController>(EventInstigator.Controller).SetPlayTips("", "", 0);
	}
	*/
}
