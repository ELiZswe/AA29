// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/Marker/CameraPoint/CameraPoint.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ACameraPoint::ACameraPoint(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	//bShouldBaseAtStartup = true;
	//bHardAttach = true;
}

void ACameraPoint::BeginPlay()
{
	Super::BeginPlay();

	/*
	TrackActor = GetActorByTag(TrackActorTag);
	if (AttachActorTag != "None")
	{
		AttachActor = GetActorByTag(AttachActorTag);
		if (AttachActor != nullptr)
		{
			SetBase(AttachActor);
		}
	}
	*/
}

void ACameraPoint::SetActive(bool B)
{
	bActive = B;
}

void ACameraPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (!bInit)
	{
		bInit = true;
		Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
		return;
	}
	if (!bActive)
	{
		return;
	}
	switch(TrackType)
	{
			case 1:
				SetActorRotation(Player.Location + TrackOffset - Location);
				break;
			case 2:
				if (TrackActor != nullptr)
				{
					SetActorRotation(TrackActor.Location + TrackOffset - Location);
				}
				break;
			default:
				break;
	}
	*/
}
void ACameraPoint::Trigger(AActor* Other, APawn* EventInstigator)
{
	//TrackActor = GetActorByTag(TrackActorTag);
}
