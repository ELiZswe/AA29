// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_UseTrigger/TriggerURL/TriggerURL.h"

ATriggerURL::ATriggerURL()
{
	//StaticMesh = nullptr;
	//bNoDelete = true;
	//bAcceptsProjectors = false;
	//bMovable = false;
	//CollisionRadius = 22;
	//CollisionHeight = 49;
	//bCollideActors = false;
	//bBlockZeroExtentTraces = false;
	//bUseCylinderCollision = false;
	//bEdShouldSnap = false;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

bool ATriggerURL::UsedBy(APawn* User)
{
	if (bActive && (!bDisableUse))
	{
		Trigger(nullptr, User);
		return true;
	}
	return false;
}

void ATriggerURL::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (URL == "")
	{
		//Log("TriggerURL::Trigger(): Error: URL is blank");
	}
}

