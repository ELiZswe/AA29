// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AGP_Sound.generated.h"

UCLASS()
class AAGP_Sound : public AActor
{
	GENERATED_BODY()
	
public:	
	
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
	
	virtual void BeginPlay() override;
	void LoadEditorIcon();
public:	
	
	virtual void Tick(float DeltaTime) override;

	void Start();
	void Finish();
	void Timer();

};
