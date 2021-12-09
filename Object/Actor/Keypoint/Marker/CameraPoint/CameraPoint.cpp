// All the original content belonged to the US Army


#include "AA29/Object/Actor/Keypoint/Marker/CameraPoint/CameraPoint.h"

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
	if (AttachActorTag != 'None')
	{
		AttachActor = GetActorByTag(AttachActorTag);
		if (AttachActor != None)
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
		Player = AGP_Pawn(Level.GetClientPawn());
		Return;
	}
	if (!bActive)
	{
		Return;
	}
	Switch(TrackType)
	{
			case 1:
				SetRotation(Player.Location + TrackOffset - Location);
				break;
			case 2:
				if (TrackActor != None)
				{
					SetRotation(TrackActor.Location + TrackOffset - Location);
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
