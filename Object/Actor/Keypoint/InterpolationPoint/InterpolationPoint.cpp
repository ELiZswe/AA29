// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/InterpolationPoint/InterpolationPoint.h"
#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"

AInterpolationPoint::AInterpolationPoint(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	//DrawScale = 0.35;
	//bDirectional = true;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Interp.S_Interp'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

void AInterpolationPoint::PointReached(ASceneManager* Scene)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 15, None, Scene.Tag);
	}
	TriggerEvent(Event, Scene, None);
	*/
}
