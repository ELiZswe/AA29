// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ActivatedObjective.h"
#include "AGP_ESSObjective.generated.h"

class AHumanController;
UCLASS()
class AAGP_ESSObjective : public AAGP_ActivatedObjective
{
	GENERATED_BODY()
public:
	AAGP_ESSObjective(const FObjectInitializer& objectInitializer);

	UPROPERTY()										USoundBase*							sndESSObjectiveRadioAcknowledgement;		//var Sound sndESSObjectiveRadioAcknowledgement;
	UPROPERTY()										USoundBase*							sndESSObjectiveCompleteBadProcedure;		//var Sound sndESSObjectiveCompleteBadProcedure;
	UPROPERTY()										USoundBase*							sndESSObjectiveCompleteGoodProcedure;		//var Sound sndESSObjectiveCompleteGoodProcedure;
	UPROPERTY()										FName								hcInstigator;								//var AGP.HumanController hcInstigator;
	UPROPERTY()										TArray<FName>						moverLinkedToUnlock;						//var array<Mover> moverLinkedToUnlock;
	UPROPERTY(EditAnywhere, Category = "ES2")		TArray<TSubclassOf<AAGP_Objective>> agpoLinkedObjective;						//var(ES2) array<AGP_Objective> agpoLinkedObjective;
	UPROPERTY(EditAnywhere, Category = "ESS")		FName								nameLinkedObjectiveToActivate;				//var(ESS) name nameLinkedObjectiveToActivate;
	UPROPERTY(EditAnywhere, Category = "ESS")		FName								nameLinkedMoverToUnlock;					//var(ESS) name nameLinkedMoverToUnlock;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString								sActivatedRadioMessage;						//var(ESS) string sActivatedRadioMessage;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString								sActivationMessage;							//var(ESS) string sActivationMessage;

	void BeginPlay();
	FString GetDescriptionByController(AController* listener);
	void Reset();
	void AccomplishObjective(APawn* _Instigator, AController* Killer);
	void RadioContentAcknowledgement();
	void RadioActivationOfObject(AHumanController* HC);
	FString ReplaceCommandString(FString Text);
	FString GetCommandKey(FString cmdname);
};
