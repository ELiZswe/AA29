// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_Timer.generated.h"

UCLASS()
class AAGP_Timer : public AActor
{
	GENERATED_BODY()
	
public:	
	AAGP_Timer();

	UPROPERTY(EditAnywhere)			float	Delay;				//var() float Delay;
	UPROPERTY(EditAnywhere)			bool	bScreenplayOnly;	//var() bool bScreenplayOnly;
	UPROPERTY()						bool	_bValid;			//var bool _bValid;

	//From Actor
	UPROPERTY()						float	TimerCounter;		//var const float TimerCounter;
	UPROPERTY()						float	TimerRate;			//var float TimerRate;


	void Start(float Time);
	void Finish();
	void Timer();
	void Trigger(AActor* Other, APawn* EventInstigator);
	float GetTimeTotal();
	float GetTimeExpended();
	float GetTimeRemaining();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
