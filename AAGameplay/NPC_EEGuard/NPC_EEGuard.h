// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/AAGameplay.h"
#include "AA29/MyStructs.h"
#include "NPC_EEGuard.generated.h"

class AAGP_Pawn;
class ALookTarget;
class AEEAnimHelper;
class AMultiTimer;
class ADebugSphere;

UCLASS()
class AA29_API ANPC_EEGuard : public AAAGameplay
{
	GENERATED_BODY()
public:
	ANPC_EEGuard();

	UPROPERTY()								float PlayerAudibility;								//var float PlayerAudibility;
	UPROPERTY()								float PlayerVisibility;								//var float PlayerVisibility;
	UPROPERTY()								ANPC_EEGuard* friends;								//var array<NPC_EEGuard> friends;
	UPROPERTY()								TArray<ALookTarget*> LookTargets;					//var array<LookTarget> LookTargets;
	UPROPERTY()								UMaterialInstance* DebugAudioSkin;					//var FinalBlend DebugAudioSkin;
	UPROPERTY()								UMaterialInstance* DebugVisionSkin;					//var FinalBlend DebugVisionSkin;
	UPROPERTY()								ADebugSphere* AudioDistActor;						//var AGP.DebugSphere AudioDistActor;
	UPROPERTY()								ADebugSphere* VisionDistActor;						//var AGP.DebugSphere VisionDistActor;
	UPROPERTY()								float PlayerNoise;									//var float PlayerNoise;
	UPROPERTY()								float PlayerDistance;								//var float PlayerDistance;
	UPROPERTY()								float AudioDetectDistance;							//var float AudioDetectDistance;
	UPROPERTY()								float VisualDetectDistance;							//var float VisualDetectDistance;
	UPROPERTY()								AActor* DeathCamera;								//var Actor DeathCamera;
	UPROPERTY()								AEEAnimHelper* AnimHelper;							//var EEAnimHelper AnimHelper;
	UPROPERTY()								int32 NextLookTarget;								//var int NextLookTarget;
	UPROPERTY()								AMultiTimer* MultiTimer;							//var MultiTimer MultiTimer;
	UPROPERTY()								TArray<FBoneProfile> PlayerBones;					//var array<BoneProfile> PlayerBones;
	UPROPERTY()								float DetectionInterval;							//var float DetectionInterval;
	UPROPERTY()								int32 HeardNoiseCount;								//var int HeardNoiseCount;
	UPROPERTY()								EAlertLevel AlertLevel;								//var EAlertLevel AlertLevel;
	UPROPERTY()								bool bInit;											//var bool bInit;
	UPROPERTY()								AAGP_Pawn* Player;									//var AGP.AGP_Pawn Player;
	UPROPERTY(EditAnywhere)					FName DeathEvent;									//var() name DeathEvent;
	UPROPERTY(EditAnywhere)					FName DeathCameraTag;								//var() name DeathCameraTag;
	UPROPERTY(EditAnywhere)					EDudeType DudeType;									//var() EDudeType DudeType;
	UPROPERTY(EditAnywhere)					bool bSequenceLookTargets;							//var() bool bSequenceLookTargets;
	UPROPERTY(EditAnywhere)					bool bAlertRecieve;									//var() bool bAlertRecieve;
	UPROPERTY(EditAnywhere)					bool bAlertFriends;									//var() bool bAlertFriends;
	UPROPERTY(EditAnywhere)					float AlertFriendsRadius;							//var() float AlertFriendsRadius;
	UPROPERTY(EditAnywhere)					float MaxPlayerDistance;							//var() float MaxPlayerDistance;
	UPROPERTY(EditAnywhere)					float AlertLevel_High;								//var() float AlertLevel_High;
	UPROPERTY(EditAnywhere)					float AlertLevel_Medium;							//var() float AlertLevel_Medium;
	UPROPERTY(EditAnywhere)					float AlertLevel_Low;								//var() float AlertLevel_Low;
	UPROPERTY(EditAnywhere)					bool bLookAround;									//var() bool bLookAround;
	UPROPERTY(EditAnywhere)					float LookTargetIntervalMax;						//var() float LookTargetIntervalMax;
	UPROPERTY(EditAnywhere)					float LookTargetIntervalMin;						//var() float LookTargetIntervalMin;
	UPROPERTY(EditAnywhere)					FName LookTargetTag;								//var() name LookTargetTag;
	UPROPERTY(EditAnywhere)					bool bDebug;										//var() bool bDebug;
	UPROPERTY(EditAnywhere)					bool bDisabled;										//var() bool bDisabled;
	UPROPERTY(EditAnywhere)					bool bNoGuard;										//var() bool bNoGuard;
	UPROPERTY(EditAnywhere)					float InvestigateTime;								//var() float InvestigateTime;
	UPROPERTY(EditAnywhere)					int32 NoiseMax;										//var() int NoiseMax;
	UPROPERTY(EditAnywhere)					float NoiseThreshold;								//var() float NoiseThreshold;
	UPROPERTY(EditAnywhere)					float VisionCone;									//var() float VisionCone;
	UPROPERTY(EditAnywhere)					float DetectDistanceAudioMax;						//var() float DetectDistanceAudioMax;
	UPROPERTY(EditAnywhere)					float DetectDistanceAudioMin;						//var() float DetectDistanceAudioMin;
	UPROPERTY(EditAnywhere)					float DetectDistanceVisual;							//var() float DetectDistanceVisual;



	void PostBeginPlay();
	void Destroyed();
	void GetEyePosition();
	void GetEyeRotation();
	void GetFriends();
	void GetLookTargets();
	void CreateDebugSphere(UMaterialInstance* aTexture, float YawRate);
	void SetNewLookTarget();
	void StopLookTargets();
	void TurnToActor(AActor* Actor, float Rate);
	void Tick(float DeltaTime);
	void FirstTickInit();
	void CheckPlayerDetection();
	void CheckTurning();
	void UpdateDebugSpheres();
	void ShrinkDebugSpheres();
	void AlertFriends();
	void DoAlertFriends();
	void ExtAlertedByFriend(AActor* Instigator);
	void ExtAlertedByDevice(AActor* Device, AActor* Instigator, bool bPlayerSpotted);
	void GetVisualDetectDistance();
	void GetAudioDetectDistance();
	void GetPlayerDistance();
	void PlayerIsVisible();
	void PlayerIsReallyVisible();
	int32 GetReqVisBones();
	void PlayerIsAudible();
	void GetPlayerNoise();
	void GetAlertLevelValue();
	void ExtMakeNoise(AActor* Instigator, float Loudness);
	void ExtNoiseHeard();
	void infront(FVector vec);
	void FRandS();
	void RandS(int32 Num);
	void ResetMe();
	void DisableMe();
	void EVENT_HeardSomething();
	void EVENT_SawSomething();
	void EVENT_PlayerSpotted();
	void EVENT_FalseAlarm();
	void EVENT_ExtNoiseHeard(AActor* Instigator);
	void TimerNotify(FName TimerName, AMultiTimer* Timer);
	void Landed(FVector HitNormal);


};
