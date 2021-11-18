// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "AA29/MyStructs.h"
#include "RiskVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARiskVolume : public AAA2_PhysicsVolume
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
	//UPROPERTY(EditAnywhere)									EActorType ActorType;					//var() EActorType ActorType;

};
