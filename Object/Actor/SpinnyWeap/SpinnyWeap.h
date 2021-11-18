// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinnyWeap.generated.h"

UCLASS()
class AA29_API ASpinnyWeap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinnyWeap();

	UPROPERTY()			int32				spinRate;					//var() int32 spinRate;
	UPROPERTY()			bool				bPlayRandomAnims;			//var() bool bPlayRandomAnims;
	UPROPERTY()			bool				bPlayCrouches;				//var() bool bPlayCrouches;
	UPROPERTY()			float				AnimChangeInterval;			//var() float AnimChangeInterval;
	UPROPERTY()			TArray<FString>		AnimNames;					//var() TArray<FName> AnimNames;
	UPROPERTY()			float				CurrentTime;				//var float CurrentTime;
	UPROPERTY()			float				NextAnimTime;				//var float NextAnimTime;

	void PostBeginPlay();
	void AnimEnd(int32 Channel);
	void PlayNextAnim();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
