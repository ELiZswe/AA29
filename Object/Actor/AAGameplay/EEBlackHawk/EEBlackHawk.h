// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/AAGameplay.h"
#include "Components/PoseableMeshComponent.h"
#include "EEBlackHawk.generated.h"

class AEEBlackHawk_Collision;
class ABHLandingLight;
class APlayerView;
class AMarker;
class ADynLight;
class ABHCrew;
class ABHM134A;
class ABHLandingLight;
class Aaux_light_signal;

UCLASS()
class AA29_API AEEBlackHawk : public AAAGameplay
{
	GENERATED_BODY()
public:
	AEEBlackHawk();

	UPROPERTY()								USkeletalMeshComponent* PilotMesh;					//var Mesh PilotMesh;
	UPROPERTY()								bool bDoDLight;										//var bool bDoDLight;
	UPROPERTY()								FRotator TailRotorRotation;							//var Object.Rotator TailRotorRotation;
	UPROPERTY()								FRotator MainRotorRotation;							//var Object.Rotator MainRotorRotation;
	UPROPERTY()								TArray<ABHM134A*> Guns;								//var BHM134A Guns;
	UPROPERTY()								TArray<ABHCrew*> Crew;								//var BHCrew Crew;
	UPROPERTY()								ADynLight* DLight;									//var DynLight DLight;
	UPROPERTY()								APlayerView* LightPoint;							//var AGP.PlayerView LightPoint;
	UPROPERTY()								AMarker* ChaseCamB;									//var AGP.Marker ChaseCamB;
	UPROPERTY()								AMarker* ChaseCamA;									//var AGP.Marker ChaseCamA;
	UPROPERTY()								AMarker* ViewMarker;								//var AGP.Marker ViewMarker;
	UPROPERTY()								APlayerView* PlayerView;							//var AGP.PlayerView PlayerView;
	UPROPERTY()								TArray<USoundBase*> ChopperSounds;					//var array<Sound> ChopperSounds;
	UPROPERTY()								TArray<ABHLandingLight*> LandingLights;				//var array<BHLandingLight> LandingLights;
	UPROPERTY()								TArray<Aaux_light_signal*> SignalLights;			//var array<aux_light_signal> SignalLights;
	UPROPERTY()								AEEBlackHawk_Collision* CollisionActor;				//var EEBlackHawk_Collision CollisionActor;
	UPROPERTY(EditAnywhere)					bool bLandingLightsStartOn;							//var() bool bLandingLightsStartOn;

	//From Actor
	UPROPERTY()								USoundBase* AmbientSound;


	//Mine
	UPROPERTY()								UPoseableMeshComponent* PMC;


	void BeginPlay();
	void ResetAnims();
	void TurnOnLandingLights();
	void TurnOffLandingLights();
	void InitChopper();
	void InitLights();
	void InitCrew();
	void InitGuns();
	void Tick(float DeltaTime);
	void UpdateCollision();
	void UpdateDLight();
	void SpinRotors();
	void SetChopperSound(FName SoundType);
	void Destroyed();

};
