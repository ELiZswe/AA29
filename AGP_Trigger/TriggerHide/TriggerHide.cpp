// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/TriggerHide/TriggerHide.h"

ATriggerHide::ATriggerHide()
{

}

void ATriggerHide::BeginPlay()
{
	//A = GetActorByTag(HideTag);
}
void ATriggerHide::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (A != nullptr)
	{
		/*
		if (A->bHidden)
		{
			A->bHidden = false;
		}
		else
		{
			A->bHidden = true;
		}
		*/
	}
}