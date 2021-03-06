// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "AA2_CommVolume.generated.h"

UCLASS()
class AAA2_CommVolume : public ATriggerVolume
{
	GENERATED_BODY()
	

protected:
	
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AAA2_CommVolume();

	// overlap begin function
	//UFUNCTION()			void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	//UFUNCTION()			void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere)		FString Location;
	UPROPERTY(EditAnywhere)		uint8 Priority;
	UPROPERTY(EditAnywhere)		FString LocationObjective;
	UPROPERTY(EditAnywhere)		bool bScoreDefender;
	UPROPERTY()										bool PlayerInside;
};
