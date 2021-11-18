// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "AA29/MyStructs.h"
#include "AGP_Viewpoint.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_Viewpoint : public ACameraActor
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AAGP_Viewpoint();

	UPROPERTY(EditAnywhere)			FString Description;						//var() string Description;
	UPROPERTY()						AAGP_Viewpoint*	NextViewpoint;				//var AGP_Viewpoint NextViewpoint;
	UPROPERTY(EditAnywhere)			EEndGameViewpoint EndGameViewpoint;			//var() EEndGameViewpoint EndGameViewpoint;
	UPROPERTY(EditAnywhere)			uint8 LimitYaw;								//var() byte LimitYaw;
	UPROPERTY(EditAnywhere)			uint8 LimitPitch;							//var() byte LimitPitch;
	UPROPERTY(EditAnywhere)			bool bLimitRotation;						//var() bool bLimitRotation;
	UPROPERTY(EditAnywhere)			int32 iSequence;							//var() int iSequence;
	UPROPERTY(EditAnywhere)			uint8 TeamNumber;							//var() byte TeamNumber;
	UPROPERTY(EditAnywhere)			bool bFriendlyOnly;							//var() bool bFriendlyOnly;
	UPROPERTY(EditAnywhere)			bool bSpectatorViewpoint;					//var() bool bSpectatorViewpoint;

};
