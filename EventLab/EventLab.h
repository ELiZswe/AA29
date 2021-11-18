// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "EventLab.generated.h"

class AAGP_Pawn;
class AHumanController;

UCLASS()
class AA29_API AEventLab : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventLab();

	UPROPERTY()						float LevelBeginFadeInTime;									//var float LevelBeginFadeInTime;
	UPROPERTY()						bool bUseLevelBeginFadeIn;									//var bool bUseLevelBeginFadeIn;
	UPROPERTY()						int32 MachineID;											//var int MachineID;
	UPROPERTY()						float StartGameSpeed;										//var float StartGameSpeed;
	UPROPERTY()						float NewGameSpeed;											//var float NewGameSpeed;
	UPROPERTY()						float GameSpeedTransTime;									//var float GameSpeedTransTime;
	UPROPERTY()						bool bTransGameSpeed;										//var bool bTransGameSpeed;
	UPROPERTY()						float OldFOV;												//var float OldFOV;
	UPROPERTY()						float NewFOV;												//var float NewFOV;
	UPROPERTY()						float FOVZoomTime;											//var float FOVZoomTime;
	UPROPERTY()						bool bZoomFOV;												//var bool bZoomFOV;
	UPROPERTY()						FName RememberedStates;										//var name RememberedStates;
	UPROPERTY()						TArray<FTimerEvent> TimerEvents;							//var array<TimerEvent> TimerEvents;
	UPROPERTY()						TArray<FQueueAnimation> AnimQueue;							//var array<QueueAnimation> AnimQueue;
	UPROPERTY()						FName PreviousState;										//var name PreviousState;
	UPROPERTY()						bool bInitialized;											//var bool bInitialized;
	UPROPERTY()						TArray<FString> ParmList;									//var array<String> ParmList;
	UPROPERTY()						AAGP_Pawn* Player;											//var AGP.AGP_Pawn Player;
	UPROPERTY()						AHumanController* Controller;								//var AGP.HumanController Controller;
	UPROPERTY(EditAnywhere)			bool bDoGeneralInit;										//var() bool bDoGeneralInit;
	UPROPERTY(EditAnywhere)			bool bEventsDisabled;										//var() bool bEventsDisabled;
	UPROPERTY(EditAnywhere)			bool bShowClockAtStartup;									//var() bool bShowClockAtStartup;
	UPROPERTY(EditAnywhere)			bool bLockPlayerRotation;									//var() bool bLockPlayerRotation;
	UPROPERTY(EditAnywhere)			bool bLockPlayerMovement;									//var() bool bLockPlayerMovement;
	UPROPERTY(EditAnywhere)			bool bHack;													//var() bool bHack;
	UPROPERTY(EditAnywhere)			bool bEnableCheats;											//var() bool bEnableCheats;
	UPROPERTY(EditAnywhere)			bool bDebug;												//var() bool bDebug;
	UPROPERTY(EditAnywhere)			TArray<FLSAnim> LSAnims;									//var() array<LSAnim> LSAnims;
	UPROPERTY(EditAnywhere)			TArray<FGameSound> GameSounds;								//var() array<GameSound> GameSounds;

	UPROPERTY(EditAnywhere)													USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void LoadEditorIcon();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
