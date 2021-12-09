// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AGP_Sound.generated.h"

UCLASS()
class AA29_API AAGP_Sound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_Sound();


	UPROPERTY()										float _timer;					//var float _timer;
	UPROPERTY()										bool _bValid;					//var bool _bValid;
	UPROPERTY(EditAnywhere)							ESoundSlot SoundSlot;			//var() Object.ESoundSlot SoundSlot;
	UPROPERTY(EditAnywhere)							USoundBase* _Sound;				//var() Sound _Sound;
	
	UPROPERTY()										APawn* _TargetPawn;				//var Pawn _TargetPawn;

	UPROPERTY()										USceneComponent* Root;
	UPROPERTY()										UTexture2D* Texture;
	UPROPERTY()										UBillboardComponent* SpriteComponent;

	//From Actor

	UPROPERTY(EditAnywhere)							USoundBase* AmbientSound;
	UPROPERTY(EditAnywhere)							float SoundVolume;
	UPROPERTY(EditAnywhere)							float SoundRadius;
	UPROPERTY(EditAnywhere)							ESoundOcclusion SoundOcclusion;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void LoadEditorIcon();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Start();
	void Finish();
	void Timer();

};
