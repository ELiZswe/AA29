// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPCSpeechManager.generated.h"

class UBillboardComponent;
class USceneComponent;

UCLASS()
class AA29_API ANPCSpeechManager : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ANPCSpeechManager();

	UPROPERTY(EditAnywhere)												USoundBase* asndLastSoundsPlayed;							//var Sound asndLastSoundsPlayed;
	UPROPERTY(EditAnywhere)												int32 iSoundEntryIndexForTracking;							//var int iSoundEntryIndexForTracking;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleWarningSounds;				//var(NPCContextFemaleSpeech) array<Sound> asndFemaleWarningSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleWarningSounds;					//var(NPCContextMaleSpeech) array<Sound> asndMaleWarningSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleEnemySpottedSounds;			//var(NPCContextFemaleSpeech) array<Sound> asndFemaleEnemySpottedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleEnemySpottedSounds;				//var(NPCContextMaleSpeech) array<Sound> asndMaleEnemySpottedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleVehicleSpottedSounds;			//var(NPCContextFemaleSpeech) array<Sound> asndFemaleVehicleSpottedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleVehicleSpottedSounds;			//var(NPCContextMaleSpeech) array<Sound> asndMaleVehicleSpottedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleSurrenderSounds;				//var(NPCContextFemaleSpeech) array<Sound> asndFemaleSurrenderSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleSurrenderSounds;				//var(NPCContextMaleSpeech) array<Sound> asndMaleSurrenderSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleFriendDownSounds;				//var(NPCContextFemaleSpeech) array<Sound> asndFemaleFriendDownSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleFriendDownSounds;				//var(NPCContextMaleSpeech) array<Sound> asndMaleFriendDownSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleGrenadeSounds;				//var(NPCContextFemaleSpeech) array<Sound> asndFemaleGrenadeSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleGrenadeSounds;					//var(NPCContextMaleSpeech) array<Sound> asndMaleGrenadeSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleFriendWoundedSounds;			//var(NPCContextFemaleSpeech) array<Sound> asndFemaleFriendWoundedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleFriendWoundedSounds;			//var(NPCContextMaleSpeech) array<Sound> asndMaleFriendWoundedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextFemaleSpeech")		TArray<USoundBase*> asndFemaleWoundedSounds;				//var(NPCContextFemaleSpeech) array<Sound> asndFemaleWoundedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCContextMaleSpeech")			TArray<USoundBase*> asndMaleWoundedSounds;					//var(NPCContextMaleSpeech) array<Sound> asndMaleWoundedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCFemaleSpeech")				TArray<USoundBase*> asndFemaleTauntSounds;					//var(NPCFemaleSpeech) array<Sound> asndFemaleTauntSounds;
	UPROPERTY(EditAnywhere, Category = "NPCMaleSpeech")					TArray<USoundBase*> asndMaleTauntSounds;					//var(NPCMaleSpeech) array<Sound> asndMaleTauntSounds;
	UPROPERTY(EditAnywhere, Category = "NPCFemaleSpeech")				TArray<USoundBase*> asndFemaleInjuredSounds;				//var(NPCFemaleSpeech) array<Sound> asndFemaleInjuredSounds;
	UPROPERTY(EditAnywhere, Category = "NPCMaleSpeech")					TArray<USoundBase*> asndMaleInjuredSounds;					//var(NPCMaleSpeech) array<Sound> asndMaleInjuredSounds;
	UPROPERTY(EditAnywhere, Category = "NPCFemaleSpeech")				TArray<USoundBase*> asndFemaleTerrifiedSounds;				//var(NPCFemaleSpeech) array<Sound> asndFemaleTerrifiedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCMaleSpeech")					TArray<USoundBase*> asndMaleTerrifiedSounds;				//var(NPCMaleSpeech) array<Sound> asndMaleTerrifiedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCFemaleSpeech")				TArray<USoundBase*> asndFemaleAngrySounds;					//var(NPCFemaleSpeech) array<Sound> asndFemaleAngrySounds;
	UPROPERTY(EditAnywhere, Category = "NPCMaleSpeech")					TArray<USoundBase*> asndMaleAngrySounds;					//var(NPCMaleSpeech) array<Sound> asndMaleAngrySounds;
	UPROPERTY(EditAnywhere, Category = "NPCFemaleSpeech")				TArray<USoundBase*> asndFemaleConcernedSounds;				//var(NPCFemaleSpeech) array<Sound> asndFemaleConcernedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCMaleSpeech")					TArray<USoundBase*> asndMaleConcernedSounds;				//var(NPCMaleSpeech) array<Sound> asndMaleConcernedSounds;
	UPROPERTY(EditAnywhere, Category = "NPCFemaleSpeech")				TArray<USoundBase*> asndFemaleAttackingSounds;				//var(NPCFemaleSpeech) array<Sound> asndFemaleAttackingSounds;
	UPROPERTY(EditAnywhere, Category = "NPCMaleSpeech")					TArray<USoundBase*> asndMaleAttackingSounds;				//var(NPCMaleSpeech) array<Sound> asndMaleAttackingSounds;
	UPROPERTY(EditAnywhere, Category = "NPCFemaleSpeech")				TArray<USoundBase*> asndFemaleIdleSounds;					//var(NPCFemaleSpeech) array<Sound> asndFemaleIdleSounds;
	UPROPERTY(EditAnywhere, Category = "NPCMaleSpeech")					TArray<USoundBase*> asndMaleIdleSounds;						//var(NPCMaleSpeech) array<Sound> asndMaleIdleSounds;
	UPROPERTY(EditAnywhere)												float fpOveridePitch;										//var() float fpOveridePitch;
	UPROPERTY(EditAnywhere)												FString sDescription;										//var() string sDescription;
	UPROPERTY(EditAnywhere)												bool bCivilianVoice;										//var() bool bCivilianVoice;
	UPROPERTY(EditAnywhere)												int32 iVoiceIndex;											//var() int iVoiceIndex;

	UPROPERTY()								USceneComponent* Root;
	UPROPERTY()								UTexture2D* Texture;
	UPROPERTY()								UBillboardComponent* SpriteComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
