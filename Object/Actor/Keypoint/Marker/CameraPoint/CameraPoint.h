// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Marker/Marker.h"
#include "CameraPoint.generated.h"

class AAGP_Pawn;

UCLASS()
class AA29_API ACameraPoint : public AMarker
{
	GENERATED_BODY()
public:
	ACameraPoint(const FObjectInitializer& objectInitializer);

	UPROPERTY()						AActor* AttachActor;				//var Actor AttachActor;
	UPROPERTY()						AActor* TrackActor;					//var Actor TrackActor;
	UPROPERTY()						AAGP_Pawn* Player;					//var AGP.AGP_Pawn Player;
	UPROPERTY()						bool bInit;							//var bool bInit;
	UPROPERTY(EditAnywhere)			FName AttachActorTag;				//var() name AttachActorTag;
	UPROPERTY(EditAnywhere)			FVector TrackOffset;				//var() FVector TrackOffset;
	UPROPERTY(EditAnywhere)			bool bActive;						//var() bool bActive;
	UPROPERTY(EditAnywhere)			FName TrackActorTag;				//var() name TrackActorTag;
	UPROPERTY(EditAnywhere)			ETrackType TrackType;				//var() ETrackType TrackType;




	void BeginPlay();
	void SetActive(bool B);
	void Tick(float DeltaTime);
	void Trigger(AActor* Other, APawn* EventInstigator);
};
