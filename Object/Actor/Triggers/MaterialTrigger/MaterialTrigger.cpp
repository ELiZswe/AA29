// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/MaterialTrigger/MaterialTrigger.h"

AMaterialTrigger::AMaterialTrigger()
{
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_MaterialTrigger_Mat.S_MaterialTrigger_Mat'"), NULL, LOAD_None, NULL);
	bCollideActors = false;
}

void AMaterialTrigger::PostBeginPlay()
{
	int32 i = 0;
	for (i = 0; i < MaterialsToTrigger.Num(); i++)
	{
		if (MaterialsToTrigger[i] != nullptr)
		{
			//MaterialsToTrigger[i]->Reset();
		}
	}
}

void AMaterialTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	int32 i = 0;
	if (Other == nullptr)
	{
		Other = this;
	}
	for (i = 0; i < MaterialsToTrigger.Num(); i++)
	{
		if (MaterialsToTrigger[i] != nullptr)
		{
			//MaterialsToTrigger[i]->Trigger(Other, EventInstigator);
		}
	}
}
