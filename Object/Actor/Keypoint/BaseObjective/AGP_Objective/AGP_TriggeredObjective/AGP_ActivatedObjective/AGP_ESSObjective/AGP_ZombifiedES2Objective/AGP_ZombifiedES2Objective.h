// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ESSObjective.h"
#include "AGP_ZombifiedES2Objective.generated.h"

class AHumanController;
UCLASS()
class AAGP_ZombifiedES2Objective : public AAGP_ESSObjective
{
	GENERATED_BODY()
public:
	AAGP_ZombifiedES2Objective(const FObjectInitializer& objectInitializer);
	
	UPROPERTY(EditAnywhere, Category = "ESS")		float	fDangerDistance;		//var(ESS) float fDangerDistance;
	UPROPERTY(EditAnywhere, Category = "ESS")		float	fReportDistance;		//var(ESS) float fReportDistance;
	UPROPERTY(EditAnywhere, Category = "ESS")		float	fObserveDistance;		//var(ESS) float fObserveDistance;
	UPROPERTY()															bool	bReportable;			//var bool bReportable;
	UPROPERTY()															bool	bFirstObjectFound;		//var bool bFirstObjectFound;

	void BeginPlay();
	FString GetDescriptionByController(AController* listener);
	void Reset();
	void AccomplishObjective(APawn* Instigator, AController* Killer);
	void RadioContentAcknowledgement();
	void RadioActivationOfObject(AHumanController* HC);
};
