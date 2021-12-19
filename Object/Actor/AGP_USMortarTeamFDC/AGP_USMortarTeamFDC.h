// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AGP_USMortarTeamFDC.generated.h"

class AAGP_USMortarTeam;

UCLASS()
class AA29_API AAGP_USMortarTeamFDC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_USMortarTeamFDC();

	UPROPERTY()																	int32 iTotalRoundsFired;							//var int iTotalRoundsFired;
	UPROPERTY()																	int32 iCurrentMissionStep;							//var int iCurrentMissionStep;
	UPROPERTY()																	bool bFireMissionCanBeRepeated;						//var bool bFireMissionCanBeRepeated;
	UPROPERTY()																	AAGP_USMortarTeam* agpusmtMortarTeam;				//var AGP_USMortarTeam agpusmtMortarTeam;
	UPROPERTY()																	float fpBaseReloadTime;								//var float fpBaseReloadTime;
	UPROPERTY()																	int32 iLastAdjustAmount;							//var int iLastAdjustAmount;
	UPROPERTY()																	FString sLastAdjustCommand;							//var string sLastAdjustCommand;
	UPROPERTY()																	FString sFOName;									//var string sFOName;
	UPROPERTY()																	bool bSmokeMission;									//var bool bSmokeMission;
	UPROPERTY()																	FString sMissionType;								//var string sMissionType;
	UPROPERTY()																	FString sTargetType;								//var string sTargetType;
	UPROPERTY()																	FString sSpotterCallSign;							//var string sSpotterCallSign;
	UPROPERTY()																	FString sMortarTeamCallSign;						//var string sMortarTeamCallSign;
	UPROPERTY()																	bool bFireMissionInProgress;						//var bool bFireMissionInProgress;
	UPROPERTY()																	float fpFartherCloser;								//var float fpFartherCloser;
	UPROPERTY()																	float fpLeftRight;									//var float fpLeftRight;
	UPROPERTY()																	bool bGridMission;									//var bool bGridMission;
	UPROPERTY()																	int32 iGridY;										//var int iGridY;
	UPROPERTY()																	int32 iGridX;										//var int iGridX;
	UPROPERTY()																	FVector vTargetArea;								//var FVector vTargetArea;
	UPROPERTY()																	FVector vSpotterLocation;							//var FVector vSpotterLocation;
	UPROPERTY()																	FRotator rotTargDirection;							//var Object.Rotator rotTargDirection;
	UPROPERTY()																	int32 iMaxRoundsPerMission;							//var int iMaxRoundsPerMission;
	UPROPERTY()																	int32 iRoundsFired;									//var int iRoundsFired;
	UPROPERTY()																	ABaseProjectile* bpMortarRoundClass;				//var class<BaseProjectile> bpMortarRoundClass;
	UPROPERTY()																	float fpDistanceToTarget;							//var float fpDistanceToTarget;
	UPROPERTY()																	USoundBase* sndFDCRecordAsTarget;					//var Sound sndFDCRecordAsTarget;
	UPROPERTY()																	USoundBase* sndFDCDrop;								//var Sound sndFDCDrop;
	UPROPERTY()																	USoundBase* sndFDCAdd;								//var Sound sndFDCAdd;
	UPROPERTY()																	USoundBase* sndFDCRight;							//var Sound sndFDCRight;
	UPROPERTY()																	USoundBase* sndFDCLeft;								//var Sound sndFDCLeft;
	UPROPERTY()																	USoundBase* sndFDCAdjustFire;						//var Sound sndFDCAdjustFire;
	UPROPERTY()																	USoundBase* sndFDCBy;								//var Sound sndFDCBy;
	UPROPERTY()																	USoundBase* sndFDCFireMissionCancelled;				//var Sound sndFDCFireMissionCancelled;
	UPROPERTY()																	USoundBase* sndFDCGuns;								//var Sound sndFDCGuns;
	UPROPERTY()																	USoundBase* sndFDCGun;								//var Sound sndFDCGun;
	UPROPERTY()																	USoundBase* sndFDCRounds;							//var Sound sndFDCRounds;
	UPROPERTY()																	USoundBase* sndFDCMeters;							//var Sound sndFDCMeters;
	UPROPERTY()																	USoundBase* sndFDCTargetVehicleDangerClose;			//var Sound sndFDCTargetVehicleDangerClose;
	UPROPERTY()																	USoundBase* sndFDCTargetVehicle;					//var Sound sndFDCTargetVehicle;
	UPROPERTY()																	USoundBase* sndFDCTargetInfantryDangerClose;		//var Sound sndFDCTargetInfantryDangerClose;
	UPROPERTY()																	USoundBase* sndFDCTargetInfantry;					//var Sound sndFDCTargetInfantry;
	UPROPERTY()																	USoundBase* sndFDCOver;								//var Sound sndFDCOver;
	UPROPERTY()																	USoundBase* sndReadyOver;							//var Sound sndReadyOver;
	UPROPERTY()																	USoundBase* sndFDCDistance;							//var Sound sndFDCDistance;
	UPROPERTY()																	USoundBase* sndFDCCheckedFire;						//var Sound sndFDCCheckedFire;
	UPROPERTY()																	USoundBase* sndFDCAtYourCommand;					//var Sound sndFDCAtYourCommand;
	UPROPERTY()																	USoundBase* sndFDCStandby;							//var Sound sndFDCStandby;
	UPROPERTY()																	USoundBase* sndFDCRepeat;							//var Sound sndFDCRepeat;
	UPROPERTY()																	USoundBase* sndFDCFireMissionComplete;				//var Sound sndFDCFireMissionComplete;
	UPROPERTY()																	USoundBase* sndFDCFireMissionCompleteNoRounds;		//var Sound sndFDCFireMissionCompleteNoRounds;
	UPROPERTY()																	USoundBase* sndFDCGridFiring;						//var Sound sndFDCGridFiring;
	UPROPERTY()																	USoundBase* sndFDCPolarFiring;						//var Sound sndFDCPolarFiring;
	UPROPERTY()																	USoundBase* sndFDCFireMissionOnWay;					//var Sound sndFDCFireMissionOnWay;
	UPROPERTY()																	USoundBase* sndFDCSmokeGrid;						//var Sound sndFDCSmokeGrid;
	UPROPERTY()																	USoundBase* sndFDCSuppressGrid;						//var Sound sndFDCSuppressGrid;
	UPROPERTY()																	USoundBase* sndFDCSmokePolar;						//var Sound sndFDCSmokePolar;
	UPROPERTY()																	USoundBase* sndFDCSuppressPolar;					//var Sound sndFDCSuppressPolar;
	UPROPERTY()																	USoundBase* sndPause;								//var Sound sndPause;
	UPROPERTY()																	USoundBase* sndRadioPopOut;							//var Sound sndRadioPopOut;
	UPROPERTY()																	USoundBase* sndRadioPopIn;							//var Sound sndRadioPopIn;
	UPROPERTY()																	TArray<USoundBase*> asndFONumbers;					//var array<Sound> asndFONumbers;
	UPROPERTY()																	TArray<USoundBase*> asndFDCNumbers;					//var array<Sound> asndFDCNumbers;
	UPROPERTY()																	TArray<USoundBase*> asndQueue;						//var array<Sound> asndQueue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeamFDC")	float fpBusyRating;									//var(USMortarTeamFDC) float fpBusyRating;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeamFDC")	int32 iTeamID;										//var(USMortarTeamFDC) int iTeamID;

	UFUNCTION()	void Reset();
	UFUNCTION()	void StartPolarFireMission(FString sMissionTypeRequest, FString sTargetType_);
	UFUNCTION()	void StartGridFireMission(FString sMissionTypeRequest, FString sTargetType_);
	UFUNCTION()	bool ValidateMissionArguments(FString sMissionTypeRequest, FString sTargetType_);
	UFUNCTION()	void ConfigureFireMission(FString sMissionTypeRequest, FString sTargetType_);
	UFUNCTION()	void TransmitRadioRequest(FString sMsg);
	UFUNCTION()	void TransmitRadioResponse(FString sMsg, bool bTransmitBeep);
	UFUNCTION()	void BadCallRadioConfirmationRequest();
	UFUNCTION()	void GridRadioConfirmationRequest();
	UFUNCTION()	void RadioConfirmationRequest();
	UFUNCTION()	void ExecuteAttack();
	UFUNCTION()	void AcknowledgeExecuteFireMission();
	UFUNCTION()	void CheckFire(bool bDisableFOAudio);
	UFUNCTION()	void CheckFireResponse();
	UFUNCTION()	void FireMissionAimingTimer();
	UFUNCTION()	void CancelFireMission();
	UFUNCTION()	void CancelFireMissionResponse();
	UFUNCTION()	void EndFireMission();
	UFUNCTION()	void EndFireMissionResponse();
	UFUNCTION()	void FireMissionInAirTimerTube1();
	UFUNCTION()	void FireMissionInAirTimerTube2();
	UFUNCTION()	void RepeatMission();
	UFUNCTION()	void RadioRepeatMissionConfirmation();
	UFUNCTION()	void AdjustFireMissionAim(FString sAdjustCmd, int32 iLeftRightMeters, int32 iFowardBackMeters);
	UFUNCTION()	void RespondToAdjustAim();
	UFUNCTION()	void LaunchGridRound();
	UFUNCTION()	void LaunchRound();
	UFUNCTION()	void PlayNextQueuedSoundTimer();
	UFUNCTION()	void TransmitAudioRadioMessage(USoundBase* sndAudioMessage);
	UFUNCTION()	void  PlayAudioRadioMessage(USoundBase* sndAudioMessage);
	UFUNCTION()	void TransmitAudioRadioNumber(int32 iNumber, bool bFDCNumber);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
