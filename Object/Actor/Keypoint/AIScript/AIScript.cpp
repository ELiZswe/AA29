// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AIScript/AIScript.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/AIMarker/AIMarker.h"

AAIScript::AAIScript(const FObjectInitializer& objectInitializer):Super(objectInitializer)
{
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_AIScript_Mat.S_AIScript_Mat'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;
}

void AAIScript::SpawnControllerFor(APawn* p)
{
	AaAIController* C = nullptr;
	/*
	if (ControllerClass == nullptr)
	{
		if (p.ControllerClass == nullptr)
		{
			return;
		}
		C = Spawn(p.ControllerClass, , , p->GetActorLocation(), p.Rotation);
	}
	else
	{
		C = Spawn(ControllerClass, , , p->GetActorLocation(), p.Rotation);
	}
	C.MyScript = this;
	C.Possess(p);
	*/
}

AActor* AAIScript::GetMoveTarget()
{
	if (myMarker != nullptr)
	{
		return myMarker;
	}
	return this;
}

void AAIScript::TakeOver(APawn* p)
{
}
