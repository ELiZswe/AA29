// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "LookTrigger.generated.h"

class AAGP_Pawn;

UCLASS()
class AA29_API ALookTrigger : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	ALookTrigger();

	UPROPERTY()							bool bPlayerIsLooking;				//var bool bPlayerIsLooking;
	UPROPERTY()							float LookTime;						//var float LookTime;
	UPROPERTY()							bool bInit;							//var bool bInit;
	UPROPERTY()							AAGP_Pawn* Player;					//var AGP.AGP_Pawn Player;
	UPROPERTY(EditAnywhere)				bool bStartOn;						//var() bool bStartOn;
	UPROPERTY(EditAnywhere)				bool bTriggerOnce;					//var() bool bTriggerOnce;
	UPROPERTY(EditAnywhere)				float TargetAngle;					//var() float TargetAngle;
	UPROPERTY(EditAnywhere)				float TargetLookTime;				//var() float TargetLookTime;
	UPROPERTY(EditAnywhere)				float TargetDistance;				//var() float TargetDistance;

	void PostBeginPlay();
	void MatchStarting();
	void Tick(float DeltaTime);
	void TrackPlayer(float DeltaTime);
	void TargetLooking(APawn* Target);
	void CanSeeTarget(APawn* Target);
	void TriggerAction();
	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
	bool PlayerIsLooking();
};
