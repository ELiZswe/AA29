// All the original content belonged to the US Army


#include "AA29/Object/Actor/Keypoint/Marker/PlayerView/PlayerView.h"

APlayerView::APlayerView(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	//bHidden = false;
	//Physics = 8;
	//bShouldBaseAtStartup = true;
	//bHardAttach = true;
}



void APlayerView::PreBeginPlay()
{
	Texture = nullptr;
}