// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/ES2Trigger/ES2Trigger.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"

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
