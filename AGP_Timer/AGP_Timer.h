// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_Timer.generated.h"

UCLASS()
class AA29_API AAGP_Timer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_Timer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)											float Delay;						//var() float Delay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											bool bScreenplayOnly;				//var() bool bScreenplayOnly;
	UPROPERTY()																			bool _bValid;						//var bool _bValid;

	void Start(float Time);
	void Finish();
	void Timer();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void GetTimeTotal();
	void GetTimeExpended();
	void GetTimeRemaining();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
