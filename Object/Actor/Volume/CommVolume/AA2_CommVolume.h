// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "AA2_CommVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAA2_CommVolume : public ATriggerVolume
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AAA2_CommVolume();

	// overlap begin function
	//UFUNCTION()			void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	//UFUNCTION()			void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 Priority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString LocationObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bScoreDefender;
	UPROPERTY()										bool PlayerInside;
};
