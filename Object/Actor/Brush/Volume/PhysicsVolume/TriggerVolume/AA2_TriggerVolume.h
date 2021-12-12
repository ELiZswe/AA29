// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "AA29/MyEnums.h"
#include "AA2_TriggerVolume.generated.h"

class AVolumeTimer;

UCLASS()
class AA29_API AAA2_TriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()
public:
	AAA2_TriggerVolume();

	UPROPERTY(EditAnywhere)							EActorType			ActorType;					//var() Enum EActorType ActorType;
	UPROPERTY(EditAnywhere, Category = "aaHelp")	TArray<FString>		TriggerVolumeHelp;			//var(aaHelp) const editconst FString TriggerVolumeHelp[12];
	UPROPERTY(EditAnywhere)							bool				bDoUnTrigger;				//var() bool bDoUnTrigger;
	UPROPERTY(EditAnywhere)							TArray<AActor*>		SpecificActors;				//var() TArray<class<Actor> > SpecificActors;
	UPROPERTY(EditAnywhere)							bool				bActive;					//var() bool bActive;

	void SetActive(bool Active);
	void EnableTrigger();
	void DisableTrigger();
	void ActorEnteredVolume(AActor* Other);
	void ActorLeavingVolume(AActor* Other);
	void PawnEnteredVolume(APawn* Other);
	void PawnLeavingVolume(APawn* Other);
	void PreBeginPlay();
	void BeginPlay();
	void PostBeginPlay();
	void PhysicsChangedFor(AActor* Other);
	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
	void TimerPop(AVolumeTimer* t);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void PlayEntrySplash(AActor* Other);
	void PlayExitSplash(AActor* Other);
	void CausePainTo(AActor* Other);
	bool BetterThan(AActor* Other);
	AActor* GetNearbyObjective(bool bDefender);
	void SetAssociatedActor(AActor* Other);
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void Reset();
	void MatchStarting();
};
