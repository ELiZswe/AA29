// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/MyEnums.h"
#include "NPC_SpecialForces.generated.h"

class AAGP_Objective;
UCLASS()
class ANPC_SpecialForces : public AAGP_Character
{
	GENERATED_BODY()
public:
	ANPC_SpecialForces();

	UPROPERTY()																FRotator				rNeck;							//var Object.Rotator rNeck;
	UPROPERTY()																FRotator				rREyeBall;						//var Object.Rotator rREyeBall;
	UPROPERTY()																FRotator				rLEyeBall;						//var Object.Rotator rLEyeBall;
	UPROPERTY()																float					fTalkHandsRandomTimer;			//var float fTalkHandsRandomTimer;
	UPROPERTY()																FRotator				vStartRotation;					//var Object.Rotator vStartRotation;
	UPROPERTY()																FVector					vStartLocation;					//var FVector vStartLocation;
	UPROPERTY(EditAnywhere)													bool					bUseDisabled;					//var() bool bUseDisabled;
	UPROPERTY(EditAnywhere)													int32					nNPCusedtime;					//var() int nNPCusedtime;
	UPROPERTY(EditAnywhere)													int32					nNPCthinktime;					//var() int nNPCthinktime;
	UPROPERTY(EditAnywhere)													bool					bNPCused;						//var() bool bNPCused;
	UPROPERTY()																int32					InitialKillHealth;				//var int InitialKillHealth;
	UPROPERTY()																AAGP_Objective*			DamageObjective;				//var AGP.AGP_Objective DamageObjective;
	UPROPERTY(EditAnywhere)													bool					NPC_DamageOn;					//var() bool NPC_DamageOn;
	UPROPERTY()																TArray<float>			FSoundTimes;					//var float FSoundTimes[5];
	UPROPERTY()																TArray<USoundBase*>		SSound;							//var Sound SSound[5];
	UPROPERTY()																TArray<FName>			VSound;							//var name VSound[5];
	UPROPERTY()																int32					UsedCountMax;					//var int UsedCountMax;
	UPROPERTY()																int32					UsedCount;						//var int UsedCount;
	UPROPERTY()																bool					bGaveGabrielDemoTalk;			//var bool bGaveGabrielDemoTalk;
	UPROPERTY()																float					fLastUsedTime;					//var float fLastUsedTime;
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		IntelligenceSound;				//var() Sound IntelligenceSound[4];
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		CommunicationSound;				//var() Sound CommunicationSound[4];
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		MedicalSound;					//var() Sound MedicalSound[4];
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		EngineerSound;					//var() Sound EngineerSound[4];
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		WeaponsSound;					//var() Sound WeaponsSound[4];
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		SergeantSound;					//var() Sound SergeantSound[4];
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		CommanderSound;					//var() Sound CommanderSound[4];
	UPROPERTY(EditAnywhere)													TArray<USoundBase*>		LeaderSound;					//var() Sound LeaderSound[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			SargGetInTruckLipsinc;			//var() name SargGetInTruckLipsinc[3];
	UPROPERTY(EditAnywhere)													TArray<FName>			SargGoToClassLipsinc;			//var() name SargGoToClassLipsinc[3];
	UPROPERTY(EditAnywhere)													TArray<FName>			StudentVendingMachineLipsinc;	//var() name StudentVendingMachineLipsinc[3];
	UPROPERTY(EditAnywhere)													TArray<FName>			IntelligenceLipsinc;			//var() name IntelligenceLipsinc[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			CommunicationLipsinc;			//var() name CommunicationLipsinc[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			MedicalLipsinc;					//var() name MedicalLipsinc[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			EngineerLipsinc;				//var() name EngineerLipsinc[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			WeaponsLipsinc;					//var() name WeaponsLipsinc[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			SergeantLipsinc;				//var() name SergeantLipsinc[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			CommanderLipsinc;				//var() name CommanderLipsinc[4];
	UPROPERTY(EditAnywhere)													TArray<FName>			LeaderLipsinc;					//var() name LeaderLipsinc[4];
	UPROPERTY(EditAnywhere)													EAnimateType			AnimateType;					//var() EAnimateType AnimateType;
	UPROPERTY(EditAnywhere)													EVoiceType				VoiceType;						//var() EVoiceType VoiceType;
	UPROPERTY(EditAnywhere)													TArray<FAttachObject>	Attachments;					//var() array<AttachObject> Attachments;


	float infront2(FVector vec);
	void EnableEyeTrack();
	void DisableEyeTrack();
	void BeginPlay();
	void PostBeginPlay();
	void ConfigureLinkDamage();
	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	void UndoDeath();
	void MatchStarting();
	void PostNetBeginPlay();
	void DoAnimLoop();
	bool IsFriend(APawn* Other);
	void SetVoiceType(EVoiceType VoiceType);
	void SelectHandState();
	bool UsedBy(APawn* User);
	void Touch(AActor* Other);
	void SetAttachments();
	void Tick(float DeltaTime);



};
