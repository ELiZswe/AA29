// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/AAGameplay.h"
#include "EESpotLight.generated.h"

class AEESpotLightPart;
class AAGP_Pawn;
class ALookTarget;
class ANPC_EEGuard;
class ADebugSphere;
class ADynLight;
class AMultiTimer;
class ADebugSphere;
UCLASS()
class AA29_API AEESpotLight : public AAAGameplay
{
	GENERATED_BODY()
public:
	AEESpotLight();

	UPROPERTY()								float PlayerDistance;								//var float PlayerDistance;
	UPROPERTY()								FVector SpotLocation;								//var FVector SpotLocation;
	UPROPERTY()								bool bDisabled;										//var bool bDisabled;
	UPROPERTY()								bool bPlayerDetected;								//var bool bPlayerDetected;
	UPROPERTY()								TArray<FBoneProfile> PlayerBones;					//var array<BoneProfile> PlayerBones;
	UPROPERTY()								UMaterialInstance* CoronaSkin;						//var FinalBlend CoronaSkin;
	UPROPERTY()								UMaterialInstance* DebugDetectSkin;					//var FinalBlend DebugDetectSkin;
	UPROPERTY()								bool bInit;											//var bool bInit;
	UPROPERTY()								AAGP_Pawn* Player;									//var AGP.AGP_Pawn Player;
	UPROPERTY()								ADebugSphere* DetectDistActor;						//var AGP.DebugSphere DetectDistActor;
	UPROPERTY()								int32 MaxTraceDist;									//var int MaxTraceDist;
	UPROPERTY()								int32 NextLookTarget;								//var int NextLookTarget;
	UPROPERTY()								ANPC_EEGuard* MyGuard;								//var AGP_Characters.NPC_EEGuard MyGuard;
	UPROPERTY()								AMultiTimer* mT;									//var MultiTimer mT;
	UPROPERTY()								TArray<ALookTarget*> LookTargets;					//var array<LookTarget> LookTargets;
	//UPROPERTY()							ASpotHaze* SpotHaze;								//var SpotHaze SpotHaze;
	UPROPERTY()								ADynLight* DLight;									//var DynLight DLight;
	UPROPERTY()								AEESpotLightPart* Light;							//var EESpotLightPart Light;
	UPROPERTY(EditAnywhere)					bool bDebug;										//var() bool bDebug;
	UPROPERTY(EditAnywhere)					int32 DetectionFactor;								//var() int DetectionFactor;
	UPROPERTY(EditAnywhere)					float BrightnessFactor;								//var() float BrightnessFactor;
	UPROPERTY(EditAnywhere)					bool bSearchForPlayer;								//var() bool bSearchForPlayer;
	UPROPERTY(EditAnywhere)					int32 SpotScale;									//var() int SpotScale;
	UPROPERTY(EditAnywhere)					bool bMountedSideways;								//var() bool bMountedSideways;
	UPROPERTY(EditAnywhere)					int32 RotationSpeed;								//var() int RotationSpeed;
	UPROPERTY(EditAnywhere)					float LookTargetIntervalMax;						//var() float LookTargetIntervalMax;
	UPROPERTY(EditAnywhere)					float LookTargetIntervalMin;						//var() float LookTargetIntervalMin;
	UPROPERTY(EditAnywhere)					FName GuardTag;										//var() name GuardTag;
	UPROPERTY(EditAnywhere)					bool bSequenceLookTargets;							//var() bool bSequenceLookTargets;
	UPROPERTY(EditAnywhere)					bool bLookAround;									//var() bool bLookAround;
	UPROPERTY(EditAnywhere)					FName LookTargetTag;								//var() name LookTargetTag;




	void BeginPlay();
	void Init();
	void InitVolumeLight();
	void InitDLight();
	void GetLookTargets();
	void GetHost();
	ADebugSphere* CreateDebugSphere(UMaterialInstance* aTexture, float YawRate);
	void Tick(float DeltaTime);
	void CheckPlayerDetection();
	bool PlayerIsVisible();
	bool PlayerIsReallyVisible();
	int32 GetReqVisBones();
	void UpdateDebugSpheres();
	float GetDetectDistance();
	void TimerNotify(FName TimerName, AMultiTimer* Timer);
	void SetNewLookTarget();
	void StopLookTargets();
	void TurnToActor(AActor* Actor, float Rate);
	void UpdateDLight();
	void UpdateVolumeLight();
	void PlayerSpotted();
	void ResetPlayerDetected();
	


};
