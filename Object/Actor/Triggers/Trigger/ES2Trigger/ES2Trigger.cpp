// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/ES2Trigger/ES2Trigger.h"

AES2Trigger::AES2Trigger()
{

}

void AES2Trigger::DoTouch(AActor* Other)
{
	//Super::DoTouch(Other);
	if (ObjectiveReference != nullptr)
	{
		//ObjectiveReference.Trigger(Other, None);
	}
}
