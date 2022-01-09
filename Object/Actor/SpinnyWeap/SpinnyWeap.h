// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinnyWeap.generated.h"

UCLASS()
class ASpinnyWeap : public AActor
{
	GENERATED_BODY()
	
public:	
	
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
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
