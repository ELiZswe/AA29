// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_TriggeredObjective.h"
#include "AGP_ActivatedObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ActivatedObjective : public AAGP_TriggeredObjective
{
	GENERATED_BODY()
public:
	AAGP_ActivatedObjective(const FObjectInitializer& objectInitializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName InterruptedEvent;		//var() name InterruptedEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName StartedEvent;			//var() name StartedEvent;


	void Touch(AActor* Other);
	void Trigger(AActor* Other, APawn* Instigator);
	bool NoPickupsInsideFor(APawn* User);
	bool UsedBy(APawn* User);
	void AccomplishObjective(APawn* Instigator, AController* Killer);

};
