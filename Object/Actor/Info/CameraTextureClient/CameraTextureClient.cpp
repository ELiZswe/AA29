// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/CameraTextureClient/CameraTextureClient.h"

ACameraTextureClient::ACameraTextureClient()
{
	RefreshRate = 60;
	FOV = 60;
	//bNoDelete = true;
	bAlwaysRelevant = true;
}

void ACameraTextureClient::PostBeginPlay()
{
	AActor* CameraActorIt = nullptr;
	/*
	ForEach AllActors(Class'Actor', CameraActorIt, CameraTag)
	{
		CameraActor = CameraActorIt;
		GOTO JL0024;
	JL0024:
	}
	if (DestTexture != nullptr)
	{
		DestTexture.Client = this;
		SetTimer((1 / RefreshRate), true);
		Enable("Timer");
	}
	*/
}

void ACameraTextureClient::Timer()
{
	//DestTexture.Revision++;
}

/*
void ACameraTextureClient::RenderTexture(AScriptedTexture* Tex)
{
	if (CameraActor != nullptr)
	{
		Tex.DrawPortal(0, 0, Tex.USize, Tex.VSize, CameraActor, CameraActor->GetActorLocation(), CameraActor.Rotation, int(FOV));
	}
}
*/
