// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "NPC_SpecialForces.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPC_SpecialForces : public AAGP_Character
{
	GENERATED_BODY()
public:
	ANPC_SpecialForces();


	UPROPERTY()																FRotator rNeck;									//var Object.Rotator rNeck;
	UPROPERTY()																FRotator rREyeBall;								//var Object.Rotator rREyeBall;
	UPROPERTY()																FRotator rLEyeBall;								//var Object.Rotator rLEyeBall;
	UPROPERTY()																float fTalkHandsRandomTimer;					//var float fTalkHandsRandomTimer;
	UPROPERTY()																FRotator vStartRotation;						//var Object.Rotator vStartRotation;
	UPROPERTY()																FVector vStartLocation;							//var FVector vStartLocation;
	UPROPERTY(EditAnywhere)													bool bUseDisabled;								//var() bool bUseDisabled;
	UPROPERTY(EditAnywhere)													int32 nNPCusedtime;								//var() int nNPCusedtime;
	UPROPERTY(EditAnywhere)													int32 nNPCthinktime;							//var() int nNPCthinktime;
	UPROPERTY(EditAnywhere)													bool bNPCused;									//var() bool bNPCused;
	UPROPERTY()																int32 InitialKillHealth;						//var int InitialKillHealth;
	UPROPERTY()																AAGP_Objective* DamageObjective;				//var AGP.AGP_Objective DamageObjective;
	UPROPERTY(EditAnywhere)													bool NPC_DamageOn;								//var() bool NPC_DamageOn;
	UPROPERTY()																float FSoundTimes;								//var float FSoundTimes;
	UPROPERTY()																USoundBase* SSound;								//var Sound SSound;
	UPROPERTY()																USoundBase* VSound;								//var name VSound;
	UPROPERTY()																int32 UsedCountMax;								//var int UsedCountMax;
	UPROPERTY()																int32 UsedCount;								//var int UsedCount;
	UPROPERTY()																bool bGaveGabrielDemoTalk;						//var bool bGaveGabrielDemoTalk;
	UPROPERTY()																float fLastUsedTime;							//var float fLastUsedTime;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> IntelligenceSound;			//var() Sound IntelligenceSound;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> CommunicationSound;			//var() Sound CommunicationSound;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> MedicalSound;				//var() Sound MedicalSound;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> EngineerSound;				//var() Sound EngineerSound;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> WeaponsSound;				//var() Sound WeaponsSound;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> SergeantSound;				//var() Sound SergeantSound;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> CommanderSound;				//var() Sound CommanderSound;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*> LeaderSound;				//var() Sound LeaderSound;
	UPROPERTY(EditAnywhere)													TArray<FName> SargGetInTruckLipsinc;			//var() name SargGetInTruckLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> SargGoToClassLipsinc;				//var() name SargGoToClassLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> StudentVendingMachineLipsinc;		//var() name StudentVendingMachineLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> IntelligenceLipsinc;				//var() name IntelligenceLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> CommunicationLipsinc;				//var() name CommunicationLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> MedicalLipsinc;					//var() name MedicalLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> EngineerLipsinc;					//var() name EngineerLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> WeaponsLipsinc;					//var() name WeaponsLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> SergeantLipsinc;					//var() name SergeantLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> CommanderLipsinc;					//var() name CommanderLipsinc;
	UPROPERTY(EditAnywhere)													TArray<FName> LeaderLipsinc;					//var() name LeaderLipsinc;
	UPROPERTY(EditAnywhere)													EAnimateType AnimateType;						//var() EAnimateType AnimateType;
	UPROPERTY(EditAnywhere)													EVoiceType VoiceType;							//var() EVoiceType VoiceType;
	UPROPERTY(EditAnywhere)													TArray<FAttachObject> Attachments;				//var() array<AttachObject> Attachments;


	static const int32 LEADER_IDLE_SAY = 4;
	static const int32 COMMANDER_IDLE_SAY = 4;
	static const int32 SERGEANT_IDLE_SAY = 4;
	static const int32 WEAPONS_IDLE_SAY = 4;
	static const int32 ENGINEER_IDLE_SAY = 4;
	static const int32 MEDICAL_IDLE_SAY = 4;
	static const int32 COMMUNICATION_IDLE_SAY = 4;
	static const int32 INTELLIGENCE_IDLE_SAY = 4;
	static const int32 STUDENT_VENDING_MACHINE_IDLE_SAY = 3;
	static const int32 SARG_GO_TO_CLASS_IDLE_SAY = 3;
	static const int32 SARG_GET_IN_TRUCK_IDLE_SAY = 3;


	void PossessedBy(AController* C);
	void BeginPlay();
	

	

};
