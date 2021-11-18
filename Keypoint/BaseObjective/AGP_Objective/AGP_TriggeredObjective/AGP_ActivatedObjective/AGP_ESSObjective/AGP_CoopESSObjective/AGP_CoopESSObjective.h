// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ESSObjective.h"
#include "AGP_CoopESSObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_CoopESSObjective : public AAGP_ESSObjective
{
	GENERATED_BODY()
public:
	AAGP_CoopESSObjective(const FObjectInitializer& objectInitializer);

	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		FName ExplosionEmitterClass;						//var(ES2) class<Emitter> ExplosionEmitterClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		USoundBase* ExplosionSound;							//var(ES2) Sound ExplosionSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		float fDamageAmount;								//var(ES2) float fDamageAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		float fDamageRadius;								//var(ES2) float fDamageRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		bool bDetonateOnTrigger;							//var(ES2) bool bDetonateOnTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		FName BecomeActiveEvent;							//var(ES2) name BecomeActiveEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		float fShowEnemyTime;								//var(ES2) float fShowEnemyTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		bool bShowEnemysOnRadar;							//var(ES2) bool bShowEnemysOnRadar;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		FName FlagReference;								//var(ES2) AGP.FlagMeshActor FlagReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		bool bHideOnDestroy;								//var(ES2) bool bHideOnDestroy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		FName DestroyEvent;									//var(ES2) name DestroyEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		TArray<UDamageType*> RecieveDamageTypes;			//var(ES2) array<class<DamageType> > RecieveDamageTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		int32 DestroyHealth;								//var(ES2) int DestroyHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		bool bDestroyable;									//var(ES2) bool bDestroyable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		bool bDummyTrainingObject;							//var(ESS) bool bDummyTrainingObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float NextReportInSeconds;							//var(ESS) float NextReportInSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FName UseEventName;									//var(ESS) name UseEventName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ES2")		FName ReportEventName;								//var(ESS) name ReportEventName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FString stReprimandForUsingAndNotReportingConsole;	//var(ESS) string stReprimandForUsingAndNotReportingConsole;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FString stReprimandForUsingAndNotReportingPopUp;	//var(ESS) string stReprimandForUsingAndNotReportingPopUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FString stNoReportResponseToUsingUnuseableObject;	//var(ESS) string stNoReportResponseToUsingUnuseableObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FString stResponseToUsingUnuseableObject;			//var(ESS) string stResponseToUsingUnuseableObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float fDialogLength;								//var(ESS) float fDialogLength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		bool bUseOnReport;									//var(ESS) bool bUseOnReport;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		bool bUseable;										//var(ESS) bool bUseable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FName FlagTag;										//var(ESS) name FlagTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		USoundBase* sndS2ResponseToReportingObject;			//var(ESS) Sound sndS2ResponseToReportingObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FString sS2ResponseToReportingObject;				//var(ESS) string sS2ResponseToReportingObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float fDangerDistance;								//var(ESS) float fDangerDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float fReportDistance;								//var(ESS) float fReportDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		float fObserveDistance;								//var(ESS) float fObserveDistance;
	UPROPERTY()															bool bOnRadar;										//var bool bOnRadar;
	UPROPERTY()															bool bReportable;									//var bool bReportable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		FString sS2AcknowledgedObjectUsed;					//var(ESS) string sS2AcknowledgedObjectUsed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		USoundBase* sndS2AcknowledgedObjectUsed;			//var(ESS) Sound sndS2AcknowledgedObjectUsed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		USoundBase* sndESSCompleteBadProcedure;				//var(ESS) Sound sndESSCompleteBadProcedure;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")		USoundBase* sndESSCompleteGoodProcedure;			//var(ESS) Sound sndESSCompleteGoodProcedure;

	void Reset();
	void AccomplishObjective(APawn* _Instigator, AController* Killer);
	void ActivateFromRadio(AHumanController* _Instigator);
	void RadioCoopContentAcknowledgement();
	void getReportDistance();
	void getObserveDistance();
	void getDangerDistance();
	void isDangerous();
	void isReportable();
	void isOnRadar();
	void isUseable();
	void getAcknowledgeVO();
	void getAcknowledgeText();
	void getFlagTag();
	void getFlagReference();
	void getDialogLength();
	void getReportEventName();
	void isDummyTrainingObject();
	void getBecomeActiveEvent();
	void isUseOnReport();
	void MakeESSObjectAppearOnRadar();
	void MakeES2ObjectiveReportable();
	void ShouldTakeDamage(UaDamageType* DamageType);
	//void TakeDamage(int32 Damage, APawn* EventInstigator, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, EBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, AMaterial HitMaterial);
	void Trigger(AActor* Other, APawn* _Instigator);
	void RadiusDamage(float DamageAmount, float DamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation, float KillRadius);


};
