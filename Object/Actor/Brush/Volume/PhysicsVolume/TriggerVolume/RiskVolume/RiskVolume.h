// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "AA29/MyEnums.h"
#include "RiskVolume.generated.h"

class AVolumeTimer;

UCLASS()
class ARiskVolume : public AAA2_PhysicsVolume
{
	GENERATED_BODY()
public:
	ARiskVolume();

	UPROPERTY(EditAnywhere)									float ExitRisk;								//var() float ExitRisk;
	UPROPERTY(EditAnywhere)									float EnterRisk;							//var() float EnterRisk;
	UPROPERTY(EditAnywhere, Category = "aaHelp")			TArray<FString> RiskVolumeHelp;				//var(aaHelp) const editconst string RiskVolumeHelp;

	//From TriggerVolume
	UPROPERTY(EditAnywhere)									bool EActorType;						//var() bool EActorType;
	UPROPERTY(EditAnywhere)									TArray<AActor*> SpecificActors;			//var() array<class<Actor> > SpecificActors;
	UPROPERTY(EditAnywhere)									bool bDoUnTrigger;						//var() bool bDoUnTrigger;
	// UPROPERTY(EditAnywhere)									EActorType ActorType;					//var() EActorType ActorType;

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
	void ActorEnteredVolume(AActor* Other);
	void ActorLeavingVolume(AActor* Other);

};
