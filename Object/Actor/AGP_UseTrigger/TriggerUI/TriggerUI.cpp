// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_UseTrigger/TriggerUI/TriggerUI.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

ATriggerUI::ATriggerUI()
{
	bDebug = true;
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

bool ATriggerUI::UsedBy(APawn* User)
{
	if (bActive)
	{
		Trigger(nullptr, User);
		return true;
	}
	return false;
}

void ATriggerUI::Trigger(AActor* Other, APawn* EventInstigator)
{
	Cast<AHumanController>(EventInstigator->Controller)->ClientOpenMenu(UIPage, bDisconnect, UIParam1, UIParam2);
}
