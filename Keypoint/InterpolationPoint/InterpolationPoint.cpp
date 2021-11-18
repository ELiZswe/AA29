// All the original content belonged to the US Army


#include "AA29/Keypoint/InterpolationPoint/InterpolationPoint.h"

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
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 15, None, Scene.Tag);
	}
	TriggerEvent(Event, Scene, None);
	*/
}