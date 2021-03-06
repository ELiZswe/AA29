// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ESSObjective.h"
#include "AA29/MyEnums.h"
#include "AGP_CoopESSObjective.generated.h"

class UaDamageType;
class AFlagMeshActor;

class AHumanController;
UCLASS()
class AAGP_CoopESSObjective : public AAGP_ESSObjective
{
	GENERATED_BODY()
public:
	AAGP_CoopESSObjective(const FObjectInitializer& objectInitializer);
	
	UPROPERTY(EditAnywhere, Category = "ES2")		FName					ExplosionEmitterClass;						//var(ES2) class<Emitter> ExplosionEmitterClass;
	UPROPERTY(EditAnywhere, Category = "ES2")		USoundBase*				ExplosionSound;								//var(ES2) Sound ExplosionSound;
	UPROPERTY(EditAnywhere, Category = "ES2")		float					fDamageAmount;								//var(ES2) float fDamageAmount;
	UPROPERTY(EditAnywhere, Category = "ES2")		float					fDamageRadius;								//var(ES2) float fDamageRadius;
	UPROPERTY(EditAnywhere, Category = "ES2")		bool					bDetonateOnTrigger;							//var(ES2) bool bDetonateOnTrigger;
	UPROPERTY(EditAnywhere, Category = "ES2")		FName					BecomeActiveEvent;							//var(ES2) name BecomeActiveEvent;
	UPROPERTY(EditAnywhere, Category = "ES2")		float					fShowEnemyTime;								//var(ES2) float fShowEnemyTime;
	UPROPERTY(EditAnywhere, Category = "ES2")		bool					bShowEnemysOnRadar;							//var(ES2) bool bShowEnemysOnRadar;
	UPROPERTY(EditAnywhere, Category = "ES2")		AFlagMeshActor*			FlagReference;								//var(ES2) AGP.FlagMeshActor FlagReference;
	UPROPERTY(EditAnywhere, Category = "ES2")		bool					bHideOnDestroy;								//var(ES2) bool bHideOnDestroy;
	UPROPERTY(EditAnywhere, Category = "ES2")		FName					DestroyEvent;								//var(ES2) name DestroyEvent;
	UPROPERTY(EditAnywhere, Category = "ES2")		TArray<UaDamageType*>	RecieveDamageTypes;							//var(ES2) array<class<DamageType> > RecieveDamageTypes;
	UPROPERTY(EditAnywhere, Category = "ES2")		int32					DestroyHealth;								//var(ES2) int DestroyHealth;
	UPROPERTY(EditAnywhere, Category = "ES2")		bool					bDestroyable;								//var(ES2) bool bDestroyable;
	UPROPERTY(EditAnywhere, Category = "ESS")		bool					bDummyTrainingObject;						//var(ESS) bool bDummyTrainingObject;
	UPROPERTY(EditAnywhere, Category = "ESS")		float					NextReportInSeconds;						//var(ESS) float NextReportInSeconds;
	UPROPERTY(EditAnywhere, Category = "ESS")		FName					UseEventName;								//var(ESS) name UseEventName;
	UPROPERTY(EditAnywhere, Category = "ES2")		FName					ReportEventName;							//var(ESS) name ReportEventName;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString					stReprimandForUsingAndNotReportingConsole;	//var(ESS) string stReprimandForUsingAndNotReportingConsole;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString					stReprimandForUsingAndNotReportingPopUp;	//var(ESS) string stReprimandForUsingAndNotReportingPopUp;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString					stNoReportResponseToUsingUnuseableObject;	//var(ESS) string stNoReportResponseToUsingUnuseableObject;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString					stResponseToUsingUnuseableObject;			//var(ESS) string stResponseToUsingUnuseableObject;
	UPROPERTY(EditAnywhere, Category = "ESS")		float					fDialogLength;								//var(ESS) float fDialogLength;
	UPROPERTY(EditAnywhere, Category = "ESS")		bool					bUseOnReport;								//var(ESS) bool bUseOnReport;
	UPROPERTY(EditAnywhere, Category = "ESS")		bool					bUseable;									//var(ESS) bool bUseable;
	UPROPERTY(EditAnywhere, Category = "ESS")		FName					FlagTag;									//var(ESS) name FlagTag;
	UPROPERTY(EditAnywhere, Category = "ESS")		USoundBase*				sndS2ResponseToReportingObject;				//var(ESS) Sound sndS2ResponseToReportingObject;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString					sS2ResponseToReportingObject;				//var(ESS) string sS2ResponseToReportingObject;
	UPROPERTY(EditAnywhere, Category = "ESS")		float					fDangerDistance;							//var(ESS) float fDangerDistance;
	UPROPERTY(EditAnywhere, Category = "ESS")		float					fReportDistance;							//var(ESS) float fReportDistance;
	UPROPERTY(EditAnywhere, Category = "ESS")		float					fObserveDistance;							//var(ESS) float fObserveDistance;
	UPROPERTY()										bool					bOnRadar;									//var bool bOnRadar;
	UPROPERTY()										bool					bReportable;								//var bool bReportable;
	UPROPERTY(EditAnywhere, Category = "ESS")		FString					sS2AcknowledgedObjectUsed;					//var(ESS) string sS2AcknowledgedObjectUsed;
	UPROPERTY(EditAnywhere, Category = "ESS")		USoundBase*				sndS2AcknowledgedObjectUsed;				//var(ESS) Sound sndS2AcknowledgedObjectUsed;
	UPROPERTY(EditAnywhere, Category = "ESS")		USoundBase*				sndESSCompleteBadProcedure;					//var(ESS) Sound sndESSCompleteBadProcedure;
	UPROPERTY(EditAnywhere, Category = "ESS")		USoundBase*				sndESSCompleteGoodProcedure;				//var(ESS) Sound sndESSCompleteGoodProcedure;

	void Reset();
	void AccomplishObjective(APawn* _Instigator, AController* Killer);
	void ActivateFromRadio(AHumanController* _Instigator);
	void RadioCoopContentAcknowledgement();
	float getReportDistance();
	float getObserveDistance();
	float getDangerDistance();
	bool isDangerous();
	bool isReportable();
	bool isOnRadar();
	bool isUseable();
	USoundBase* getAcknowledgeVO();
	FString getAcknowledgeText();
	FName getFlagTag();
	AFlagMeshActor* getFlagReference();
	float getDialogLength();
	FName getReportEventName();
	bool isDummyTrainingObject();
	FName getBecomeActiveEvent();
	bool isUseOnReport();
	void MakeESSObjectAppearOnRadar();
	void MakeES2ObjectiveReportable();
	bool ShouldTakeDamage(UaDamageType* DamageType);
	//void TakeDamage(int32 Damage, APawn* EventInstigator, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, EBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, AMaterial HitMaterial);
	void Trigger(AActor* Other, APawn* _Instigator);
	void RadiusDamage(float DamageAmount, float DamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation, float KillRadius);
};
